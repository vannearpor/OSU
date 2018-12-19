/******************************************************************
 * Author: Vannear Por
 * Date: July 23, 2018
 * Description: This program is an adventure game which will utilize
 * the rooms and connections created by the file from the
 * buildroom program. The player will try to navigate to the END_ROOM
 * to complete the game using the interface created.
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <pthread.h>
#include <string.h>
#include <stdbool.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

//Global Variables
#define MIN_CONNECTIONS 3
#define MAX_CONNECTIONS 6
#define NUMBER_ROOMS 7

//The 10 Room Names
char* roomNames[10] = {
    "Incubator",
    "Westworld",
    "NorfNorf",
    "ShadowRealm",
    "Crystalize",
    "Hyrule",
    "Village",
    "Sea",
    "SkyTower",
    "Gaia"
};

//Establish Room Types
enum roomTypes {
    START_ROOM,
    MID_ROOM,
    END_ROOM
};

//Room structure
struct Room {
    enum roomTypes type;
    char name[100];
    int number_connections;
    struct Room *connections[MAX_CONNECTIONS];
};

//Global variables
struct Room rooms[NUMBER_ROOMS];
char roomDirectory[512];
char* timeOutput = "currentTime.txt";
pthread_mutex_t mutex;

//Prototypes
void makeRoom_Connect();
void initializeRooms();
int  returnPos(char* name);
int  getFirstRoom();
void start();
void* getTimeFile();

//Defaults all rooms and their values
void initializeRooms(){
    int i, j;
    int counter = 0;
    DIR* currentDirectory;
    struct dirent* tempDirectory;
    
    //Default all rooms
    for (i = 0; i < NUMBER_ROOMS; i++){
        memset(rooms[i].name, '\0', sizeof(rooms[i].name));    //defaults all room names to NULL
        rooms[i].number_connections = 0;        //defaults all room connection totals to 0
        
        for (j = 0; j < MAX_CONNECTIONS; j++){
            rooms[i].connections[j] = NULL;     //defauls all connections to NULL
        }
    }
    
    if ((currentDirectory = opendir (roomDirectory)) != NULL) {
        while ((tempDirectory = readdir(currentDirectory)) != NULL) {
            if (strlen(tempDirectory->d_name) >= 3) {       //ignores (..) and (.)
                strcpy (rooms[counter].name, tempDirectory->d_name);       //Writes room names into room struct
                counter++;
            }
        }
    }
}

//Establish rooms and their connections
void makeRoom_Connect(){
    int i;
    FILE* inputFile;     //File to be read
    char line[512];      //Line read buffer
    char valueType[512];    //Type read buffer
    
    for (i = 0; i < NUMBER_ROOMS; i++) {
        inputFile = fopen(rooms[i].name, "r");       //Opens each file in read mode
        
        //clear buffers
        memset (line, '\0', sizeof(line));
        memset (valueType, '\0', sizeof(valueType));
        
        while (fgets(line, sizeof(line), inputFile) != NULL) {       //checks that file isn't null
            int cursor = 0;
            int j;
            
            //clean up read variables
            strtok(line, ":");
            strcpy(valueType, strtok(NULL,""));
            valueType[strlen(valueType) - 1] = '\0';
            line[strlen(line) - 1] = '\0';
            
            for (j = 0; j < strlen(valueType); j++) {
                valueType[j] = valueType[j+1];
            }
            
            //Reads room type from file to assign room type to struct
            if (strcmp(line, "ROOM TYP") == 0) {
                
                if (strcmp(valueType, "START_ROOM") == 0) {
                    rooms[i].type = START_ROOM;
                }
                
                else if (strcmp(valueType, "END_ROOM") == 0) {
                    rooms[i].type = END_ROOM;
                }
                
                else {
                    rooms[i].type = MID_ROOM;
                }
            }
            
            //Reads the connections and creates the connections
            else if (strcmp(line, "CONNECTION ") == 0) {
                int room2Pos = returnPos(valueType);
                int room1ConnTotal = rooms[i].number_connections;
                
                rooms[i].connections[room1ConnTotal] = &rooms[room2Pos];  //Creates the room connection
                rooms[i].number_connections++;
            }
        }
        fclose(inputFile);       //Closes file that was read
    }
    chdir("..");        //Exit to previous directory
}

//Find the positions of the rooms by reading their name
int returnPos(char* name) {
    int pos;
    int notFound = -1;
    
    for (pos = 0; pos < NUMBER_ROOMS; pos++) {
        if (strcmp(rooms[pos].name, name) == 0) {     //Returns the position
            return pos;
        }
    }
    
    return notFound;    //returns error -1 if room name isn't found.
}

//Finds START_ROOM as starting point
int getFirstRoom(){
    int i;
    int notFound = -1;
    for (i = 0; i < NUMBER_ROOMS; i++) {
        if (rooms[i].type == START_ROOM) {
            return i;
        }
    }
    
    return notFound;    //returns error -1 if room name isn't found.
}

//Creates currentTime.txt file
void* getTimeFile(){
    FILE* temp;
    char timeBuffer[512];
    time_t current_time;
    struct tm * timeHolder;
    
    memset (timeBuffer, '\0', sizeof(timeBuffer));      //Clears buffer
    
    time(&current_time);
    timeHolder = localtime(&current_time);
    strftime(timeBuffer, 512, "%I: %M%P %A, %B %d, %Y", timeHolder);  //Sets up time display
    
    temp = fopen(timeOutput, "w");        //Opens output variable
    fprintf(temp, "%s\n", timeBuffer);    //Writes the time into currentTime.txt
    fclose(temp);
    
    return NULL;    //returns NULL as an argument
}

//Starts the game
void start(){
    int steps[1028];    //holds all the steps taken for display at the end
    char input[512];    //takes in user input
    struct Room currentRoom;
    int i, j, currentPosition;
    bool validRoom = false;
    int turn = 0;       //counts the number of turns taken

    steps[turn] = getFirstRoom();       //step 0 will be the START_ROOM
    
    do{
        currentPosition = steps[turn];      //gets current room the user is in
        currentRoom = rooms[currentPosition];   //retreives that room's name
        
        //print
        printf("CURRENT LOCATION: %s\n", currentRoom.name);
        printf("POSSIBLE CONNECTIONS:");
        
        for (i = 0; i < currentRoom.number_connections - 1; i++) {
            printf (" %s,", currentRoom.connections[i]->name);
        }
        
        printf(" %s.\n", currentRoom.connections[i]->name);        //Last connection option has a .
        
        memset (input, '\0', sizeof(input));
        printf ("WHERE TO? >");
        scanf ("%511s", input);
        printf("\n");
        
        validRoom = false;
        
        //Checks if user input is a valid room in the options
        for (i = 0; i < currentRoom.number_connections; i++) {
            if (strcmp(input, currentRoom.connections[i]->name) == 0) {
                turn++;
                steps[turn] = returnPos(input);
                currentPosition = steps[turn];
                currentRoom = rooms[currentPosition];
                validRoom = true;
                
                //User reaches the END_ROOM
                if (currentRoom.type == END_ROOM) {
                    printf ("YOU HAVE FOUND THE END ROOM. CONGRATULATIONS!\n");
                    printf ("YOU TOOK %d STEPS. YOUR PATH TO VICTORY WAS:\n", turn);
                    
                    //prints out the path taken =
                    for (j = 0; j < turn + 1; j++) {
                        printf("%s\n", rooms[steps[j]].name);
                    }
                    
                    return;
                }
            }
        }
        
        //Displays the time if user asks for time
        if (strcmp(input, "time") == 0 && validRoom == false) {
            pthread_t threaded;
            pthread_mutex_init(&mutex, NULL);
            pthread_mutex_lock(&mutex);
            
            int tid = pthread_create(&threaded, NULL, getTimeFile, NULL);
            pthread_mutex_unlock(&mutex);
            pthread_mutex_destroy(&mutex);
            
            usleep(50);
            char holder[512];
            FILE* tempFile;
            
            memset(holder, '\0', sizeof(holder));
            
            tempFile = fopen(timeOutput, "r");        //reads output
            if (tempFile == NULL) {
                printf("%s failed to read.\n", timeOutput);
                return;
            }
            
            while (fgets(holder, 512, tempFile) != NULL) {
                printf("%s\n", holder);
            }
            
            fclose(tempFile);       //close time file
        }
        
        //If user enters invalid input
        else if (validRoom == false) {
            printf ("HUH? I DON'T UNDERSTAND THAT ROOM. TRY AGAIN.\n\n");
        }
    }
    while(true);
}

//main
int main(void){
    char *directorySearch = "porv.rooms.";  //finds directory
    char tempDirectory[100];
    DIR *directory; //current directory
    struct dirent *dp;
    struct stat *buffer;
    time_t t;
    time_t tStart = 0;
    
    buffer = malloc(sizeof(struct stat));
    dp = malloc(sizeof(struct dirent));
    
    //clears tempdirectory
    memset(tempDirectory, '\0', sizeof(tempDirectory));
    getcwd(tempDirectory, sizeof(tempDirectory));
    directory = opendir(tempDirectory);
    
    //finds newest created room folder to set as directory
    if (directory != NULL) {
        while (dp= readdir(directory)) {
            if (strstr(dp->d_name,directorySearch) != NULL){
                stat(dp->d_name, buffer);
                t = buffer->st_mtime;
                
                if(t > tStart){ // set folder as youngest if new
                    tStart = t;
                    strcpy(roomDirectory,dp->d_name);
                }
            }
        }
    }
    
    initializeRooms();         //create rooms within room struct and default all values to NULL
    
    chdir(roomDirectory);  //Enter directory to hold files

    makeRoom_Connect();     //creates rooms and connections within the game
    
    start();    //starts the game
    
    return 0;
}
