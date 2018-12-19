// Author: Vannear Por
// Date: October 28, 2018
// Description: This is Project 1 for CS 372 - Intro to Networking.
// This program implements a simple chat system that will
// work for a pair of users: one hostServer, one client. It will
// utilize API sockets and TCP protocol.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdbool.h>

int socketFD;           //Socket File Descriptor
int portNum;            //Port Number
bool connectionFlag = true; //Flag to open or close connection
int message;

struct sockaddr_in serverAddress;   //hostServer address
struct hostent *hostServer;             //Points to hostServer

char userInput[501];  //Array containing the message w/ char limit
char inputHolder[490];       //inputHolder for input
char userHandle[10];        //Handle for user

void error(const char *errorOutput) {
    perror(errorOutput);
    exit(0);
}

//Remove newline from the end of user handle so that the message is appended to the same line
void clearNewline(char string[], int length) {
    int i;
    for (i = 0; i < length; i++) {
        if (string[i] == '\n') {
            string[i] = '\0';
        }
    }
}

void handshake(char *server, int port) {
    portNum = port;                 //sets port to user input
    hostServer = gethostbyname(server);   //retreives hostname
    socketFD = socket(AF_INET, SOCK_STREAM, 0); //create socket
    
    if(socketFD < 0) {
        error("Error! Failed to create socket.");
    }
    
    if(hostServer == NULL) {
        fprintf(stderr, "ERROR! Cannot find host hostServer\n");
        exit(0);
    }
    
    bzero((char *) &serverAddress, sizeof(serverAddress));  //clears hostServer address
    
    serverAddress.sin_family = AF_INET; //sets hostServer address field
    bcopy((char *)hostServer->h_addr, (char *)&serverAddress.sin_addr.s_addr, hostServer->h_length);
    
    serverAddress.sin_port = htons(portNum);    //Converts port number to byte order
    
    if(connect(socketFD, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) < 0) {
        error("Error! Failed to connect to hostServer");
    }
}

void send_message() {
    int i;
    printf("%s> ", userHandle); //user prompt
    bzero(inputHolder, 489);    //clears message holder
    fgets(inputHolder, 488, stdin); //user inputs message
    
    clearNewline(inputHolder, 489);
    
    if(strcmp(inputHolder, "\\quit\n") == 0) {
        connectionFlag = false;
        message = write(socketFD, inputHolder, strlen(inputHolder));
        
        if(message < 0) {
            error("Error! Message failed to write.");
        }
        
        close(socketFD);
    }
    else {
        bzero(userInput, 501);
        strcat(userInput, userHandle);  //Adds the user's handle into the message
        strcat(userInput, "> ");    //Adds : after the handle
        strcat(userInput, inputHolder);  //Adds the message to show after the user handle
        
        message = write(socketFD, userInput, strlen(userInput));    //Writes message to send to hostServer
        
        if(message < 0) {
            error("Error! Message failed to write.");
        }
    }
}

void receive_message() {
    bzero(userInput, 501);
    message = read(socketFD, userInput, 500); //reads message received from hostServer
    
    if(message < 0) {
        error("Error! Failed to read message.");
    }
    
    if(strcmp(userInput, "\\quit\n") == 0) {
        connectionFlag = false;     //Closes the connection
        close(socketFD);
    }
    else {
        printf("%s\n", userInput);
    }
}

void getHandle() {
    printf("\e[1;1H\e[2J"); //Clears the command line
    bzero(userHandle, 10);  //Clears the user handle so the user and provide handle input
    printf("Please provide your User Handle: ");
    fgets(userHandle, 10, stdin); //user inputs handle
}

int main(int argc, char *argv[]) {
    int i;
    //Checks the arguments to make sure the right syntax is used.
    if(argc < 3) {
        fprintf(stderr, "Error! Cannot connect to hostname and port\n");
        exit(0);
    }
    
    getHandle();
    clearNewline(userHandle, 11);
    
    handshake(argv[1], atoi(argv[2]));
    printf("\e[1;1H\e[2J");     //clear command line
    printf("\n");
    
    //Retrieve the user's message input and send to chat hostServer, waits for reply and repeat until \quit is sent.
    
    while(connectionFlag == true) {
        if(connectionFlag == true) {
            send_message();
        }
        if(connectionFlag == true) {
            receive_message();
        }
    }
    
    return 0;
    
}
