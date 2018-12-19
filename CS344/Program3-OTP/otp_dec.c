// Author: Vannear Por
// Date: August 17, 2018
// Description: This program will connect to otp_enc_d daemon to receive plaintext and
// encrypt the plaintext into ciphertext.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <netdb.h>
#include <signal.h>

#define TEXTSPACE 1024

// Global Variables
FILE *cipherText_file;
FILE *keyText_file;
int server_port;
int socketFD;
struct sockaddr_in serverAddress;
struct hostent* serverHost;

char plainText[TEXTSPACE], cipherText[TEXTSPACE], keyText[TEXTSPACE];
char cipherText_temp[TEXTSPACE], keyText_temp[TEXTSPACE];

// Prototypes
void createAndConnect();
void setCursor();
void sendCipherAndKey(int length);


//Creates socket and connects the client to the server
void createAndConnect() {
    //Creation of socket
    if ((socketFD = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }
    
    //Sets the server settings
    serverHost = gethostbyname("localhost");
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(server_port);
    memcpy(&serverAddress.sin_addr.s_addr, serverHost->h_addr, serverHost->h_length);
    
    //Connects the client to server socket
    if (connect(socketFD, (struct sockaddr*) &serverAddress, sizeof(serverAddress)) == -1) {
        fprintf(stderr, "Connection Error. Client failed to connect with otp_dec_d on port %i\n", server_port);
        exit(2);
    }
}

void setCursor() {
    memset(cipherText_temp, '\0', sizeof(cipherText_temp));
    memset(keyText_temp, '\0', sizeof(keyText_temp));
    memset(plainText, '\0', sizeof(plainText));
}

void sendCipherAndKey (int input) {
    //Sends plaintext to otp_enc_d
    if ((send(socketFD, cipherText_temp, input, 0)) == -1) {
        perror("Error sending ciphertext to otp_dec_d");
        exit(1);
    }
    
    //Sends key to otp_enc_d
    if ((send(socketFD, keyText_temp, input, 0)) == -1) {
        perror("Error sending key to otp_dec_d");
        exit(1);
    }
}

int main (int argc, char *argv[]) {
    //Checks syntax
    if (argc < 4) {
        fprintf (stderr, "Syntax Error. To run, please use: otp_dec ciphertext key port \n");
        exit(1);
    }
    
    server_port = atoi(argv[3]);
    
    //Checks if plaintext file is empty
    if ((cipherText_file = fopen(argv[1], "r")) == NULL) {
        perror("Ciphertext File Open Error.");
        exit(1);
    }
    
    //Checks if key file is empty
    if ((keyText_file = fopen(argv[2], "r")) == NULL) {
        perror("Key File Open Error.");
        exit(1);
    }
    
    int i;
    int recv_temp;
    int recv_length, plainText_length;
    
    char send_confirm[] = "toDec";
    char recv_confirm[] = "fromDec";
    char reject[] = "CANNOT CONNECT DUDE";
    
    //Function to make sure plaintext and key aren't empty.
    //textFileCheck(argv);
    
    //Fills plaintext array with the file contents and checks for invalid characters
    if (fgets(cipherText, TEXTSPACE, cipherText_file) != NULL) {
        for (i = 0; i < strlen(cipherText); i++) {
            if ((cipherText[i] != ' ') && (cipherText[i] < 'A' || cipherText[i] > 'Z')) {
                if (cipherText[i] != '\n') {
                    fprintf(stderr, "Error, %s contains invalid characters\n", argv[1]);
                    exit(1);
                }
            }
        }
    }
    
    //Fills keyText variable with the key file contents
    fgets(keyText, TEXTSPACE, keyText_file);
    
    //Makes sure that the key and plaintext match in length
    if (strlen(keyText) < strlen(cipherText)) {
        fprintf(stderr, "Error, key %s is too short!\n", argv[2]);
        exit(1);
    }
    
    fseek(cipherText_file, 0, SEEK_SET);
    fseek(keyText_file, 0, SEEK_SET);
    
    //Function creates socket and connects client
    createAndConnect();
    
    //Sends confirmation to otp_enc_d
    memset(cipherText_temp, '\0', sizeof(cipherText_temp));
    sprintf(cipherText_temp, "%s", send_confirm);
    send(socketFD, cipherText_temp, strlen(cipherText_temp), 0);
    
    //Receives confirmation from otp_enc_d
    memset(cipherText_temp, '\0', sizeof(cipherText_temp));
    recv_temp = recv(socketFD, cipherText_temp, sizeof(cipherText_temp), 0);
    cipherText_temp[recv_temp] = '\0';
    
    //Checks message received to make sure it matches
    if (strcmp(cipherText_temp, recv_confirm) != 0) {
        fprintf(stderr, "Connection Error. Note - Connection to otp_enc_d prohibited!\n");
        exit(1);
    }
    
    //Resets cursor on all of the string arrays
    setCursor();
    
    //Receives plaintext file, reads it, and stores into plainText_temp
    while ((recv_length = read(fileno(cipherText_file), cipherText_temp, TEXTSPACE)) > 0) {
        if (recv_length == -1) {
            perror("Error reading ciphertext file");
            exit(1);
        }
        
        //Precaution for extra spaces at the end
        if (cipherText_temp[recv_length - 1] == '\n') {
            recv_length--;
            cipherText_temp[recv_length] = '\0';
        }
        else {
            cipherText_temp[recv_length] = '\0';
        }
        
        //Receives the keytext file into the keyText_temp string.
        if (read(fileno(keyText_file), keyText_temp, recv_length) == -1) {
            perror("Error reading keytext file into string");
            exit(1);
        }
        
        keyText_temp[recv_length] = '\0';
        
        sendCipherAndKey(recv_length);
        
        if ((plainText_length = recv(socketFD, plainText, recv_length, 0)) == -1) {
            perror("Error receiving plaintext");
            exit(1);
        }
        
        plainText[plainText_length] = '\0';
        
        //sends cipherText to stdout
        fprintf(stdout, "%s\n", plainText);
    }
    
    exit(0);
}
