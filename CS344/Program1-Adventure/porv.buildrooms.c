/******************************************************************
 * Author: Vannear Por
 * Date: July 23, 2018
 * Description: This program is will create the 7 rooms that is required
 * along with connections for the adventure program to utilize for
 * a game where the user will try to get to the END_ROOM and complete the game.
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>

//Global Variables
#define MIN_CONNECTIONS 3
#define MAX_CONNECTIONS 6
#define NUMBER_ROOMS 7

//Room Structure
struct Room {
    char* name;         //holds specific room name
    char* type;         //holds the room type
    int number_connections;     //holds the number of connections the room has
    int connection[MAX_CONNECTIONS];        //array holding the actual connections of the room
};

//List of Possible Room Names
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

//Prototypes
void createGameRooms(struct Room rooms[NUMBER_ROOMS]);
void createRoomConnections(int currentRoom, struct Room rooms[NUMBER_ROOMS]);

//Function generates the rooms
void createGameRooms(struct Room rooms[NUMBER_ROOMS]){
    int i, j, k;
    int currentName;
    bool name_flag = true;
    
    for(i = 0; i < NUMBER_ROOMS; i++){
        while(name_flag){
            name_flag = false;
            currentName = rand() % 10;  //select random name from the list of possible names
            
            for(j = 0; j < NUMBER_ROOMS; j++){
                if(rooms[j].name == roomNames[currentName]){
                    name_flag = true;       //runs through created rooms to see if picked name is already used
                }
            }
        }
        
        rooms[i].name = roomNames[currentName];
            
        if(i == 0){
            rooms[i].type = "START_ROOM";
        }
        else if(i == 1){
            rooms[i].type = "END_ROOM";
        }
        else{
            rooms[i].type = "MID_ROOM";
        }
        
        name_flag = true;
    }
}

//Creates room connections
void createRoomConnections(int roomNum, struct Room rooms[NUMBER_ROOMS]){
    bool dup_flag;
    int room1 = roomNum;
    int room2, i;
    int room1_connections = rooms[room1].number_connections;     //number of connections in the argument room
    
    dup_flag = true;
    
    while(dup_flag){
        //printf("%s\n", "duptest");
        
        dup_flag = false;
        
        room2 = rand() % 7;        //selects a room 0-6 in the room array to connect to
        
        if(room2 == room1){
            dup_flag = true;
            //printf("test1: %d\n", dup_flag);
        }
        
        for(i = 0; i < rooms[roomNum].number_connections; i++){
            if(rooms[roomNum].connection[i] == room2){
                dup_flag = true;
                //printf("test 2: %d\n", dup_flag);
            }
        }

    }
    
    int room2_connections = rooms[room2].number_connections; //number of connections in the second room

    //creates connection to and from both rooms
    rooms[room1].connection[room1_connections] = room2;
    rooms[room2].connection[room2_connections] = room1;
    rooms[room1].number_connections++;
    rooms[room2].number_connections++;
}

int main() {
    srand(time(NULL));
    
    int i, j, k;
    int printR_counter;
    int printC_counter;
    int currentConnectionNum, tempConnectHolder;
    char roomDirectory[100];        //Creates directory variable
    char roomNameHolder[7];
    int pid = getpid();             //retrieves process id
    sprintf(roomDirectory, "porv.rooms.%d", pid);   //Write name of directory with process id appended
    
    //printf("%s\n", "test00");
    
    mkdir(roomDirectory, 0777);     //creates new directory
    
    //printf("%s\n", "test1");
    
    struct Room rooms[NUMBER_ROOMS];       //Creates array to hold rooms
    
    //printf("%s\n", "test2");
    
    //initialize all room connections to 0
    for(i = 0; i < NUMBER_ROOMS; i++) {
        rooms[i].number_connections = 0;
    }
    
    //printf("%s\n", "test3");
    
    createGameRooms(rooms);     //generates 7 rooms within room struct
    
    //printf("%s\n", "test4");

    for(j = 0; j < NUMBER_ROOMS; j++) {
        
        currentConnectionNum = rand() % 4 + 3;  //assigns number of connections between 3 and 6
        
        while(rooms[j].number_connections < currentConnectionNum){
            createRoomConnections(j, rooms);
        }
    }
    
    chdir(roomDirectory);           //Change to new directory for room files
    
    //Writes all the room info into files in the directory after all the creation
    for(printR_counter = 0; printR_counter < NUMBER_ROOMS; printR_counter++){
        FILE* newFile = fopen(rooms[printR_counter].name, "w+");
        fprintf(newFile, "ROOM NAME: %s\n", rooms[printR_counter].name);
        
        for(printC_counter = 0; printC_counter < rooms[printR_counter].number_connections; printC_counter++){
            fprintf(newFile, "CONNECTION %d: %s\n", printC_counter+1, rooms[rooms[printR_counter].connection[printC_counter]].name);
        }
        
        fprintf(newFile, "ROOM TYPE: %s\n", rooms[printR_counter].type);
                    
        fclose(newFile);    //close file
    }

    return 0;
}


