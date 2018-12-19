#!/bin/python

#Name: Vannear Por
#Date: November 25, 2018
#Description: This program is the client side of a File Transfer System between a Server & Client.


import sys
from socket import *

#Retrieve Directory list
def receive_directory(connect_sockFD):
    currentDirectory = connect_sockFD.recv(100)
    
    #loops until server confirms that the whole directory has been sent
    while currentDirectory!= "DIRECTORYSENT":
        print currentDirectory
        currentDirectory = connect_sockFD.recv(100)


#Request a File from the Server
def req_file(connect_sockFD):
    currentFile = open(sys.argv[4], "w")
    tempHolder = connect_sockFD.recv(1000)
    
    #loops until confirmation received
    while "__done__" not in tempHolder:
        currentFile.write(tempHolder)
        tempHolder = connect_sockFD.recv(1000)

#Creates Connection Socket
def create_socket():
    if sys.argv[3] == "-g":
        argNum = 5
    
    if sys.argv[3] == "-l":
        argNum = 4

    portNum = int(sys.argv[argNum])

    sockFD = socket(AF_INET, SOCK_STREAM)
    sockFD.bind(('', portNum))
    sockFD.listen(1)

    #accepts connection
    sockFD_instance, address = sockFD.accept()
    return sockFD_instance

#Gets connection address
def get_connection():
    c_sockFD = socket(AF_INET, SOCK_DGRAM)
    c_sockFD.connect(("8.8.8.8", 80))
    return c_sockFD.getsockname()[0]

#Retreives the requested data from the Server
def receive_request(sockFD):
    
    #Receives the name of the file from the argument
    if sys.argv[3] == "-g":
        print "Requesting {}".format(sys.argv[4])
        port_Num = 5

    #Requests directory contents
    if sys.argv[3] == "-l":
        print "Requesting directory list"
        port_Num = 4

    #Sends port number to the server
    sockFD.send(sys.argv[port_Num])

    sockFD.recv(1024)

    #Sends command to the server
    if sys.argv[3] == "-g":
        sockFD.send("g")
    
    if sys.argv[3] == "-l":
        sockFD.send("l")
    
    sockFD.recv(1024)

    sockFD.send(get_connection())
    recv_file = sockFD.recv(1024)

    #If server doesn't recognize command, will reject request
    if recv_file == "mReject":
        print "Invalid command from server"
        exit(1)

    #sends file argument to server and server will return whether it is found or not
    if sys.argv[3] == "-g":
        sockFD.send(sys.argv[4])
        recv_file = sockFD.recv(1024)
        #Receives 'not found' message
        if recv_file != "File Found!":
            print "File was not found in server"
            return

    sockFD_instance = create_socket()

    #receives directory from the connection with server
    if sys.argv[3] == "-l":
        receive_directory(sockFD_instance)

    #receives file, if exists in server directory
    elif(sys.argv[3] == "-g"):
        req_file(sockFD_instance)

    #close the connection
    sockFD_instance.close()

if __name__ == "__main__":
    
    #ALL THE SYNTAX ARGUMENTS to make sure this program is ran using correct arguments
    #checks argument number
    if  len(sys.argv) > 6 or len(sys.argv) < 5:
        print "Error! Invalid number of arguments. Please enter 5-6 arguments."
        exit(1)

    #checks server name for flip servers
    elif(sys.argv[1] != "flip1" and sys.argv[1] != "flip2" and sys.argv[1] != "flip3"):
        print "Error! Flip server not specified."
        exit(1)

    #checks request command
    elif(sys.argv[3] != "-l" and sys.argv[3] != "-g"):
        print "Error! Please use commands -l or -g."
        exit(1)

    #checks port numbers
    if(int(sys.argv[2]) < 1024 or int(sys.argv[2]) > 65535):
        print "Error! Port number invalid, please use Ports 1024-65535"
        exit(1)

    #checks port number at location if file requested
    if(sys.argv[3] == "-g"):
        if(int(sys.argv[5]) < 1024 or int(sys.argv[5]) > 65535):
            print "Error! Incorrect port number."
            exit(1)
    #checks port number at location if directory requested
    if(sys.argv[3] == "-l"):
        if(int(sys.argv[4])  < 1024 or int(sys.argv[4]) > 65535):
            print "Error! Incorrect port number."
            exit(1)

    #creates full server name
    serverName = sys.argv[1]+".engr.oregonstate.edu"
    #turns argument into int for processing port number
    portNum = int(sys.argv[2])

    #creates and connects socket
    c_sockFD = socket(AF_INET,SOCK_STREAM)
    c_sockFD.connect((serverName, portNum))

    #receives data requested
    receive_request(c_sockFD)
