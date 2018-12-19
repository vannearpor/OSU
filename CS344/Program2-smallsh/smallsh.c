//  Author: Vannear Por
//  Date: August 6, 2018
//  Description: This program creates a small shell. The shell will prompt the
//  user for commands, run command line instructions, and return expected results.
//  The shell will have stdin and stdout and will support both foreground and background
//  command processes.

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>

//  Variables
bool terminate = false;
bool background_process = false;
bool null_check = false;
int exit_status;
int background_process_counter = 0;
int bPID_holder[512];
char command_line_input[2048];

//  Function Prototypes
void checkBackground();
void resetCommandLine();
void changeDirectory(char commandLine[]);
void getProcessID(char commandLine[], pid_t pidinput);

void checkBackground() {
    int i;
    int process_exit_status;
    
    for (i=0; i < background_process_counter; i++) {
        if (waitpid(bPID_holder[i], &process_exit_status, WNOHANG) > 0) {
            if (WIFEXITED(process_exit_status)) {
                printf("Background Process #%d completed: Exit value %d\n", bPID_holder[i], WEXITSTATUS(process_exit_status));
            }
            
            if (WIFSIGNALED(process_exit_status)) {
                printf("Background Process #%d completed: Exit value %d\n", bPID_holder[i], WTERMSIG(process_exit_status));
            }
        }
    }
}

void resetCommandLine() {
    fflush(stdin);
    fflush(stdout);
    printf(": ");       //Prints the command line prompt
    fflush(stdin);      //Cleans out stdin for user input
}

void changeDirectory(char input[]) {
    if (input[2] == ' ') {
        char current_directory[1024];
        getcwd(current_directory, sizeof(current_directory));
        char *newPath = strstr(input, " ");
        if(newPath) {
            char *temp;
            newPath += 1;   //Deletes the space after "cd"
            temp = malloc(strlen(newPath));     //allocates memory
            memcpy(temp, newPath, strlen(newPath));
            sprintf(current_directory, "%s/%s", current_directory, temp);   //Creates path to new directory
            free(temp);     //Free allocated memory
        }
        chdir(current_directory);   //Change to new directory
    }
    
    else {
        char *newPath = getenv("HOME"); //Leads path to HOME directory
        chdir(newPath);     //Change to new directory
    }
}

void getProcessID(char input[], pid_t pidinput) {
    //User input "$$" will reveal the pid
    if (strcmp(input, "$$") == 0) {
        sprintf(input, "%d", pidinput);
    }
}

//  Main
int main (int argc, char *argv[], char *envp[]) {
    while (terminate == false) {
        
        checkBackground();
        resetCommandLine();
        
        if (fgets(command_line_input, sizeof(command_line_input), stdin) != NULL) {
            char *prompt;   //creates the prompt position
            prompt = strchr(command_line_input, '\n');
            *prompt = '\0';
            
            if (prompt = strchr(command_line_input, '&')) {
                *prompt = '\0';
                background_process = true;
            }
            
            else {
                background_process = false;
            }
        }
        
        else {
            return 0;  //input was null, return 0 and start over
        }
        
        //User wants to enter a comment
        if (strstr(command_line_input, "#")) {
            continue;
        }
        
        //User input "status" will display last exit status OR error.
        else if (strcmp(command_line_input, "status") == 0) {
            printf("Exit Status %d\n", exit_status);
            continue;
        }
        
        //User input "cd" will cause the user to change to their specified directory
        else if (strncmp("cd", command_line_input, strlen("cd")) == 0) {
            changeDirectory(command_line_input);
            continue;
        }
        
        //User input "exit" will exit the small shell
        else if (strcmp(command_line_input, "exit") == 0) {
            terminate = true;
            return 0;
        }
        
        //User input doesn't contain a built in command.
        else {
            pid_t pid;
            char *user_command;
            char *command_input[512];
            int inputTotal;
            bool redirection = false;
            
            getProcessID(command_line_input, pid);
            
            user_command = strtok(command_line_input, " ");
            if (user_command == NULL) {
                continue;
            }
            
            //Sets up the command input
            command_input[0] = user_command;
            inputTotal = 1;
            
            //Breaks down the command input and tokenizes it one char at a time to fill the array
            command_input[inputTotal] = strtok(NULL, " ");
            
            while(command_input[inputTotal] != NULL) {
                inputTotal += 1;
                command_input[inputTotal] = strtok(NULL, " ");
            }
            
            //Background process handling
            if(background_process == true) {
                int i;
                
                //Forking Error.
                if((pid = fork()) < 0) {
                    perror("Error. Child fork failed.");
                    exit(1);
                }
                
                //Background - Child Process
                if(pid == 0) {
                    redirection = false;
                    for(i = 0; i < inputTotal; i++) {
                        if(strcmp(command_input[i], "<") == 0) { //Input
                            //file can't be read
                            if(access(command_input[i+1], R_OK) == -1) {
                                printf("Error. File %s unreadable.\n", command_input[i+1]);
                                redirection = true;
                                exit(1);
                            }
                            
                            else {
                                int redirectFileIn = open(command_input[i+1], O_RDONLY, 0);
                                dup2(redirectFileIn, STDIN_FILENO);
                                close(redirectFileIn);
                                redirection = true;
                                execvp(user_command, &user_command);
                            }
                        }
                        //Creates new file, executes
                        else if(strcmp(command_input[i], ">") == 0) { //Output
                            int redirectFileOut = open(command_input[i+1], O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
                            dup2(redirectFileOut, STDOUT_FILENO);
                            close(redirectFileOut);
                            redirection = true;
                            execvp(user_command, &user_command); //Execute the command
                        }
                    }
                    
                    //No redirection, executes command
                    if(redirection == false) {
                        execvp(user_command, command_input);
                    }
                    
                    //When nothing ends up executing
                    printf("Error. %s not recognized.\n", user_command);
                    exit(1);
                }
                
                //Background - Parent Process
                else {
                    int parentStatus;
                    int parentProcess;
                    printf("PID of current background process: %d\n", pid);
                    bPID_holder[background_process_counter] = pid;
                    background_process_counter += 1;
                    parentProcess = waitpid(pid, &parentStatus, WNOHANG);
                    continue;
                }
            }
            
            //Foreground Process Handling
            else {
                int i;
                
                //Fork fail
                if((pid = fork()) < 0) {
                    perror("Error. Child process fork failed.");
                    exit(1);
                }
                
                //Foreground - Child Process
                if(pid == 0) {
                    redirection = false;
                    for(i = 0; i < inputTotal; i++) {
                        
                        //Reads file for execution
                        if(strcmp(command_input[i], "<") == 0) { //Input
                            //if file can't be read
                            if(access(command_input[i+1], R_OK) == -1) {
                                printf("Error. File %s unreadable.\n", command_input[i+1]);
                                redirection = true;
                                exit(1);
                            }
                            
                            else {
                                int redirectFileIn = open(command_input[i+1], O_RDONLY, 0);
                                dup2(redirectFileIn, STDIN_FILENO);
                                close(redirectFileIn);
                                redirection = true;
                                execvp(user_command, &user_command);
                            }
                        }
                        //Creates new file and executes
                        else if(strcmp(command_input[i], ">") == 0) { //Output
                            int redirectFileOut = open(command_input[i+1], O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
                            dup2(redirectFileOut, STDOUT_FILENO);
                            close(redirectFileOut);
                            redirection = true;
                            execvp(user_command, &user_command);
                        }
                    }
                    
                    //No redirection, executes.
                    if(redirection == false) {
                        execvp(user_command, command_input);
                    }
                    
                    //If command fails to execute
                    printf("Error. %s not recognized.\n", user_command);
                    exit(1);
                }
                
                //Foreground - Parent Process
                else {
                    int parent_status;
                    waitpid(pid, &parent_status, 0); //Wait for the process
                    if(WIFEXITED(parent_status)) {
                        exit_status = WEXITSTATUS(parent_status);
                    }
                }
            }
        }
    }
    return 0;
}
