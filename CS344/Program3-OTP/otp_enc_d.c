// Author: Vannear Por
// Date: August 17, 2018
// Description: This program is a background daemon which listens for plaintext files to encrypt.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netinet/in.h>

#define TEXTSPACE 1024

// Global Variables
int server_port;
int listenSocketFD, clientConnectFD;
char keyText[TEXTSPACE], plainText[TEXTSPACE], cipherText[TEXTSPACE];
int keytext_value[TEXTSPACE], plaintext_value[TEXTSPACE], ciphertext_value[TEXTSPACE];

struct sockaddr_in serverAddress, clientAddress;


// Function Prototypes
int char_number(char input);
void getSocketAndListen();
void encrypt(int input);


int char_number(char character) {
    switch (character) {
        case 'A': return 0;
        case 'B': return 1;
        case 'C': return 2;
        case 'D': return 3;
        case 'E': return 4;
        case 'F': return 5;
        case 'G': return 6;
        case 'H': return 7;
        case 'I': return 8;
        case 'J': return 9;
        case 'K': return 10;
        case 'L': return 11;
        case 'M': return 12;
        case 'N': return 13;
        case 'O': return 14;
        case 'P': return 15;
        case 'Q': return 16;
        case 'R': return 17;
        case 'S': return 18;
        case 'T': return 19;
        case 'U': return 20;
        case 'V': return 21;
        case 'W': return 22;
        case 'X': return 23;
        case 'Y': return 24;
        case 'Z': return 25;
        case ' ': return 26;
        default:
            fprintf(stderr, "Error. Plaintext input into otp_enc_d contains invalid characters.\n");
            exit(1);
    }
}

void getSocketAndListen() {
    //Create socket
    if ((listenSocketFD = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation error.");
        exit(1);
    }
    
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(server_port);    //Sets up port
    serverAddress.sin_addr.s_addr = INADDR_ANY;     //Accepts from any address
    
    //Binds the socket to the correct port
    if (bind(listenSocketFD, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) == -1) {
        perror("Binding error.");
        exit(1);
    }
    
    //Activates the listening function, listnes for 5 possible connections
    if (listen(listenSocketFD, 5) == -1) {
        perror("Listening error.");
        exit(1);
    }
}

void encrypt(int recv_length) {
    int i;
    
    for (i = 0; i < recv_length; i++) {
        plaintext_value[i] = char_number(plainText[i]);     //Gives number value for plaintext data
        keytext_value[i] = char_number(keyText[i]);         //Gives number value to the key data
        ciphertext_value[i] = plaintext_value[i] + keytext_value[i];       //Cipher number value is sum of plaintext and key
        
        ciphertext_value[i] = ciphertext_value[i] % 27;     //In case the value is over 27, corrects the value
        
        if (ciphertext_value[i] == 26) {
            plainText[i] = ' ';
        }
        
        //Shift value over by 1 to give the correct letter.
        else {
            plainText[i] = ciphertext_value[i] + 'A';
        }
    }
}

int main (int argc, char* argv[]) {
    //Check number of arguments, if incorrect print error message and give exit value
    if (argc < 2) {
        fprintf(stderr, "Syntax Error. To run otp_enc_d, please enter: otp_enc_d listening_port\n");
        exit(1);
    }
    
    server_port = atoi(argv[1]);
    
    int i;
    int pid, status;
    int recv_confirm, recv_length;
    int send_cipher;
    socklen_t clientDataLength;
    char send_message[] = "toEncDaemon";
    char recv_message[] = "fromEncDaemon";
    char reject[] = "NOT HAPPENING... NOT CONNECTING";
    
    getSocketAndListen();
    
    while(1) {
        clientDataLength = sizeof(clientAddress);
        
        //Accepts socket connection
        if ((clientConnectFD = accept(listenSocketFD, (struct sockaddr*) &clientAddress, &clientDataLength)) == -1) {
            perror("Connection acceptance error.");
        }
        
        pid = fork();
        if (pid == -1) {
            perror("Fork Error.");
            exit(1);
        }
        
        else if (pid == 0) {
            //Receive confirmation from otp_enc connection
            memset(plainText, '\0', sizeof(plainText));
            recv_confirm = recv(clientConnectFD, plainText, sizeof(plainText), 0);
            plainText[recv_confirm] = '\0';  //null terminator at end
            
            if (strcmp(plainText, send_message) == 0) {
                sprintf(plainText, "%s", recv_message);
                send(clientConnectFD, plainText, strlen(plainText), 0);
            }
            
            else {
                sprintf(plainText, "%s", reject);
                send(clientConnectFD, plainText, strlen(plainText), 0);
                exit(1);
            }
            
            //Set the pointers to the beginning
            memset(plainText, '\0', sizeof(plainText));
            memset(keyText, '\0', sizeof(keyText));
            memset(cipherText, '\0', sizeof(cipherText));
            
            //Stores the plaintext
            while ((recv_length = recv(clientConnectFD, plainText, TEXTSPACE, 0)) > 0) {
                if (recv_length == -1) {
                    perror("Recv Plaintext Error.");
                    exit(1);
                }
                
                plainText[recv_length] = '\0';
                
                //Receives and stores key
                if (recv(clientConnectFD, keyText, recv_length, 0) == -1) {
                    perror("Recv Key Error.");
                    exit(1);
                }
                
                keyText[recv_length] = '\0';
                
                //Encrypts plainText into cipherText
                encrypt(recv_length);
                
                send_cipher = send(clientConnectFD, plainText, recv_length, 0);
                if (send_cipher == -1) {
                    perror("Error sending ciphertext data back.");
                    exit(1);
                }
            }
            
            break;
        }
        
        else {
            do {
                pid = waitpid(-1, &status, WNOHANG);
            } while (pid > 0);
        }
    }
    
    exit(0);
}
