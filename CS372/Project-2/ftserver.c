//Author: Vannear Por
//Date: November 25, 2018
//Description: This program serves as a server which will listen for connections called upon by
//a client. After creating a connection, the server will be able to send data to the client
//through the created connection.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

//Gets the location information of the socket using the address and port number
struct addrinfo * create_socket_address(char* address, char* portNum) {
    int errorFlag;
    struct addrinfo hints;
    struct addrinfo * sockAddr;
    
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    
    if((errorFlag = getaddrinfo(address, portNum, &hints, &sockAddr)) != 0) {
        fprintf(stderr, "Error! Port number is incorrect\n");
        exit(1);
    }
    
    return sockAddr;
}

//Creates the socket for connection
int create_socket(struct addrinfo * address) {
    int sockFD;
    
    if((sockFD = socket((struct addrinfo *)(address)->ai_family, address->ai_socktype, address->ai_protocol)) == -1) {
        fprintf(stderr, "Error! Failed to create socket\n");
        exit(1);
    }
    
    return sockFD;
}

//Boolean to check is a file exists within the directory
bool check_file(char ** currentFiles, int fileNum, char * reqFile) {
    bool flag = false;
    int i;
    
    //run through all files
    for (i = 0; i < fileNum; i++) {
        if (strcmp(currentFiles[i], reqFile) == 0) {
            flag = true;
        }
    }
    
    return flag;
}

//Retrieves the current working directory
int getDirectory(char ** currentDirectory) {
    int count;
    DIR* directory;
    struct dirent * temp;
    directory = opendir(".");
    
    count = 0;
    
    if(directory) {
        while ((temp = readdir(directory)) != NULL) {
            if (temp->d_type == DT_REG) {
                count++;
                strcpy(currentDirectory[count], temp->d_name);
            }
        }
        closedir(directory);
    }
    return count;
}

//Sends the requested file through the connection
void send_data(char* connection, char* portNum, char* reqFile) {
    sleep(2);
    
    struct addrinfo * address = create_socket_address(connection, portNum);
    
    int sockFD_instance = create_socket(address);
    int connectErrorFlag;
    
    if ((connectErrorFlag = connect(sockFD_instance, address->ai_addr, address->ai_addrlen)) == -1) {
        fprintf(stderr, "Error! Socket failed to connect\n");
        exit(1);
    }
    
    char fileHolder[1500];
    memset(fileHolder, 0, sizeof(fileHolder));
    
    int tempFD = open(reqFile, O_RDONLY);
    while(1)
    {
        int fileSize = read(tempFD, fileHolder, sizeof(fileHolder) - 1);
        
        if(fileSize == 0) {
            break;
        }
        
        if(fileSize < 0) {
            fprintf(stderr, "Error! File is not found.\n");
            return;
        }
        
        void* buffer = fileHolder;
        
        while(fileSize > 0) {
            int sendFile = send(sockFD_instance, buffer, sizeof(fileHolder), 0);
            
            if (sendFile < 0) {
                fprintf(stderr, "Error! File could not be written.\n");
                return;
            }
            
            fileSize -= sendFile;
            buffer += sendFile;
        }
        memset(fileHolder, 0, sizeof(fileHolder));
    }
    memset(fileHolder, 0, sizeof(fileHolder));
    strcpy(fileHolder, "__done__");
    send(sockFD_instance, fileHolder, sizeof(fileHolder), 0);
    
    close(sockFD_instance);
    freeaddrinfo(address);
}

//Sends the contents of the directory through the connection
void send_directory (char* connection, char* portNum, char ** payload, int total) {
    int i;
    sleep(2);
    
    struct addrinfo * address = create_socket_address(connection, portNum);
    int sockFD_instance = create_socket(address);
    int connectErrorFlag;
    
    if ((connectErrorFlag = connect(sockFD_instance, address->ai_addr, address->ai_addrlen)) == -1) {
        fprintf(stderr, "Error! Socket failed to connect\n");
        exit(1);
    }
    
    for (i = 0; i < total; i++) {
        send(sockFD_instance, payload[i], 100, 0);
    }
    
    char* completeMessage = "DIRECTORYSENT";
    
    send(sockFD_instance, completeMessage, strlen(completeMessage), 0);
    
    close(sockFD_instance);
    freeaddrinfo(address);
}

char ** create_file_string(int length) {
    int i;
    char** stringArr = malloc(length*sizeof(char *));
    
    for(i = 0; i < length; i++) {
        stringArr[i] = malloc(100*sizeof(char));
        memset(stringArr[i], 0, sizeof(stringArr[i]));
    }
    return stringArr;
}

/*void receive_client_input(int FD, char input) {
    memset(input, 0, sizeof(input));
    recv(FD, input, sizeof(input)-1, 0);
}*/

void request_handler (int newFD) {
    int i;
    char * mAccept, mReject;
    char clientInput[500];
    char portNumber[100];
    char connect_IP[100];
    
    mAccept = "Accepted.";
    mReject = "Rejected.";
    
    /*receive_client_input(newFD, portNumber);
    send(newFD, mAccept, strlen(mAccept), 0);
    receive_client_input(newFD, clientInput);
    send(newFD, mAccept, strlen(mAccept), 0);
    
    receive_client_input(newFD, connect_IP);*/
    
    memset(portNumber, 0, sizeof(portNumber));
    //receives the port number for connection
    recv(newFD, portNumber, sizeof(portNumber)-1, 0);
    
    //confirmation accepting port number
    send(newFD, mAccept, strlen(mAccept), 0);
    
    //receives client request
    memset(clientInput, 0, sizeof(clientInput));
    recv(newFD, clientInput, sizeof(clientInput)-1, 0);
    
    //confirms client request
    send(newFD, mAccept, strlen(mAccept),0);
    
    memset(connect_IP, 0, sizeof(connect_IP));
    recv(newFD, connect_IP, sizeof(connect_IP)-1, 0);
    
    printf("Connection established with %s\n", connect_IP);
    
    //If client requests a file
    if (strcmp(clientInput, "g") == 0) {
        send(newFD, mAccept, strlen(mAccept), 0);
        
        char reqFile[100];
        //receive_client_input(newFD, reqFile);
        memset(reqFile, 0, sizeof(reqFile));
        recv(newFD, reqFile, sizeof(reqFile)-1, 0);
        
        printf("Client has requested File \"%s\".\n", reqFile);
        
        //creates a temporary holder to utilize to check through the files
        char** tempHolder = create_file_string(500);
        int fileCount = getDirectory(tempHolder);
        
        //Checks to see if file exists
        bool checkFile = check_file(tempHolder, fileCount, reqFile);
        
        //if file exists
        if (checkFile == true) {
            printf("Requested File Found. Sending \"%s\" to the client\n", reqFile);
            
            //sends confirmation to client that the file has been found on serverside
            char* fileConfirmation = "File Found!";
            send(newFD, fileConfirmation, strlen(fileConfirmation), 0);
            
            char newFileName[100];
            memset(newFileName, 0, sizeof(newFileName));
            strcpy(newFileName, "./");
            
            char* end = newFileName + strlen(newFileName);
            
            end += sprintf(end, "%s", reqFile);
            
            send_data(connect_IP, portNumber, newFileName);
        }
        else {
            printf("Error! Cannot located file.\n");
            char* noFile = "File not found";
            send(newFD, noFile, 100, 0);
        }
        
        //free up malloc'd data that was used to search for file
        for(i = 0; i < 500; i++) {
            free(tempHolder[i]);
        }
        free(tempHolder);
    }
    
    //if client requests directory list
    else if(strcmp(clientInput, "l") == 0) {
        send(newFD, mAccept, strlen(mAccept), 0);
        
        printf("Client has requested the directory list. Sending to %s\n", connect_IP);
        
        //temporary holder to hold the directory data to send
        char** tempHolder = create_file_string(500);
        int fileCount = getDirectory(tempHolder);
        
        send_directory(connect_IP, portNumber, tempHolder, fileCount);
        
        //free up malloc'd data that was used to hold the directory list
        for(i = 0; i < 500; i++) {
            free(tempHolder[i]);
        }
        free(tempHolder);
    }
}

//creates new connection and utilizes the request handler
void new_connection(int sockFD) {
    struct sockaddr_storage connAddr;
    socklen_t addrSize;
    int newFD;
    
    while(1) {
        addrSize = sizeof(connAddr);
        newFD = accept(sockFD, (struct addrinfo *)&connAddr, &addrSize);
        
        if(newFD == -1) {
            continue;
        }
        
        request_handler(newFD);
        close(newFD);
    }
}

int main(int argc, char *argv[]) {
    
    //makes sure the correct syntax is used when calling
    if (argc != 2) {
        fprintf(stderr, "Error! Please use the correct syntax: ./ftserver <Server Port>\n");
        exit(1);
    }
    
    int socketErrorFlag, socketBindFlag, socketListenFlag;
    struct addrinfo hints;
    struct addrinfo * address;
    
    
    //server listens for connections by creating, binding, and listening through socket
    printf("Server Listening initiated on Port %s\n", argv[1]);

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    
    if((socketErrorFlag = getaddrinfo(NULL, argv[1], &hints, &address)) != 0) {
        fprintf(stderr, "Error! Port number is incorrect\n");
        exit(1);
    }
    
    int sockFD = create_socket(address);
    
    socketBindFlag = bind(sockFD, address->ai_addr, address->ai_addrlen);
    
    if (socketBindFlag == -1) {
        close(sockFD);
        fprintf(stderr, "Error! Socket failed to bind\n");
        exit(1);
    }
    
    socketListenFlag = listen(sockFD, 5);
        
    if(socketListenFlag == -1) {
        close(sockFD);
        fprintf(stderr, "Error! Listening failure\n");
        exit(1);
    }
    
    //creates new connection and handles request from client
    new_connection(sockFD);
    freeaddrinfo(address);
}
