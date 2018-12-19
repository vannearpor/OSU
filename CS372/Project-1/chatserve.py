#!/usr/bin/env python

# Author: Vannear Por
# Date: October 28, 2018
# Description: This program implements a chat server. The server runs
# and listens for any client connections.

import os
import sys
import socket

def send_message(connection):
    server_output = raw_input("Vannear's Server> ") #server's message to send to client
    connection.send("Vannear's Server> " + server_output)   #sends message with Server name
    return server_output

def listen():
    port_number = int(sys.argv[1])  #get port number
    socketFD = socket.socket(socket.AF_INET, socket.SOCK_STREAM) #create socket
    socketFD.bind(('',port_number)) #Bind port number to socket
    socketFD.listen(1)  #server starts listening
    return socketFD

if len(sys.argv) < 2:
    print "Error! Please use the correct syntax to run, must specify the port number."
    sys.exit();

server_instance = listen()  #starts the new server run

while 1:
    os.system('clear')  #clears commandline
    print "Server is ready to receive messages from connected client."

    listen_flag = True  #boolean to stay open for connection
    estConnection, estAddress = server_instance.accept()    #accepts connection

    while 1:
        incoming_message = estConnection.recv(501)   #receives message from connection

        #if message is quit, skip to connection close
        if "\quit" in incoming_message:
            break
        if listen_flag:
            os.system('clear')

        listen_flag = False #message received from client

        print incoming_message

        output_message = send_message(estConnection)    #send message to connection

        #if message is quit, skip to connection close
        if "\quit" in output_message:
            break;
    estConnection.close()
