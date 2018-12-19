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
FILE *plainText_file;
FILE *keyText_file;
int server_port;
int socketFD;
struct sockaddr_in serverAddress;
struct hostent* serverHost;

char plainText[TEXTSPACE], cipherText[TEXTSPACE], keyText[TEXTSPACE];
char plainText_temp[TEXTSPACE], keyText_temp[TEXTSPACE];

// Prototypes
void createAndConnect();
void setCursor();
void sendPlainAndKey(int length);

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
        fprintf(stderr, "Connection Error. Client failed to connect with otp_enc_d on port %i\n", server_port);
        exit(2);
    }
}

void setCursor() {
    memset(plainText_temp, '\0', sizeof(plainText_temp));
    memset(keyText_temp, '\0', sizeof(keyText_temp));
    memset(cipherText, '\0', sizeof(cipherText));
}

void sendPlainAndKey (int input) {
    //Sends plaintext to otp_enc_d
    if ((send(socketFD, plainText_temp, input, 0)) == -1) {
        perror("Error sending plaintext to otp_enc_d");
        exit(1);
    }
    
    //Sends key to otp_enc_d
    if ((send(socketFD, keyText_temp, input, 0)) == -1) {
        perror("Error sending key to otp_enc_d");
        exit(1);
    }
}

int main (int argc, char *argv[]) {
    //Checks syntax
    if (argc < 4) {
        fprintf (stderr, "Syntax Error. To run, please use: otp_end plaintext key port \n");
        exit(1);
    }
    
    //Checks if plaintext file is empty
    if ((plainText_file = fopen(argv[1], "r")) == NULL) {
        perror("Plaintext File Open Error.");
        exit(1);
    }
    
    //Checks if key file is empty
    if ((keyText_file = fopen(argv[2], "r")) == NULL) {
        perror("Key File Open Error.");
        exit(1);
    }
    
    server_port = atoi(argv[3]);
    
    int i;
    int recv_temp;
    int recv_length, cipherText_length;
    
    char send_message[] = "toEncDaemon";
    char recv_message[] = "fromEncDaemon";
    char reject[] = "CONNECTION REJECTEDDDD. TRY AGAIN";
    
    //Function to make sure plaintext and key aren't empty.
    //textFileCheck(&argv);
    
    //Fills plaintext array with the file contents and checks for invalid characters
    if (fgets(plainText, TEXTSPACE, plainText_file) != NULL) {
        for (i = 0; i < strlen(plainText); i++) {
            if ((plainText[i] != ' ') && (plainText[i] < 'A' || plainText[i] > 'Z')) {
                if (plainText[i] != '\n') {
                    fprintf(stderr, "Error, %s contains invalid characters\n", argv[1]);
                    exit(1);
                }
            }
        }
    }
    
    //Fills keyText variable with the key file contents
    fgets(keyText, TEXTSPACE, keyText_file);
    
    //Makes sure that the key and plaintext match in length
    if (strlen(keyText) < strlen(plainText)) {
        fprintf(stderr, "Error, key %s is too short!\n", argv[2]);
        exit(1);
    }
    
    fseek(plainText_file, 0, SEEK_SET);
    fseek(keyText_file, 0, SEEK_SET);
    
    //Function creates socket and connects client
    createAndConnect();
    
    //Sends confirmation to otp_enc_d
    memset(plainText_temp, '\0', sizeof(plainText_temp));
    sprintf(plainText_temp, "%s", send_message);
    send(socketFD, plainText_temp, strlen(plainText_temp), 0);
    
    //Receives confirmation from otp_enc_d
    memset(plainText_temp, '\0', sizeof(plainText_temp));
    recv_temp = recv(socketFD, plainText_temp, sizeof(plainText_temp), 0);
    plainText_temp[recv_temp] = '\0';
    
    //Checks message received to make sure it matches
    if (strcmp(plainText_temp, recv_message) != 0) {
        fprintf(stderr, "Connection Error. Note - Connection to otp_dec_d prohibited!\n");
        exit(1);
    }
    
    //Resets cursor on all of the string arrays
    setCursor();
    
    //Receives plaintext file, reads it, and stores into plainText_temp
    while ((recv_length = read(fileno(plainText_file), plainText_temp, TEXTSPACE)) > 0) {
        if (recv_length == -1) {
            perror("Error reading plaintext file");
            exit(1);
        }
        
        //Precaution for extra spaces at the end
        if (plainText_temp[recv_length - 1] == '\n') {
            recv_length--;
            plainText_temp[recv_length] = '\0';
        }
        else {
            plainText_temp[recv_length] = '\0';
        }
        
        //Receives the keytext file into the keyText_temp string.
        if (read(fileno(keyText_file), keyText_temp, recv_length) == -1) {
            perror("Error reading keytext file into string");
            exit(1);
        }
        
        keyText_temp[recv_length] = '\0';
        
        sendPlainAndKey(recv_length);
        
        if ((cipherText_length = recv(socketFD, cipherText, recv_length, 0)) == -1) {
            perror("Error receiving ciphertext");
            exit(1);
        }
        
        cipherText[cipherText_length] = '\0';
        
        //sends cipherText to stdout
        fprintf(stdout, "%s\n", cipherText);
    }
    
    exit(0);
}


