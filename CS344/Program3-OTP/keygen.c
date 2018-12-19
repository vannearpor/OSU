// Author: Vannear Por
// Date: August 17, 2018
// Description: This is the key generator that will be used for
// the encryption and decryption of the text.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main (int argc, char* argv[]){
    //Error response for incorrect number of arguments input.
    if (argc != 2){
        fprintf(stderr, "Error. Please follow correct keygen syntax.\n");
        exit(1);
    }
    
    int i;
    srand(time(NULL));
    
    //Create key length utilizing the given argument.
    int key_length = atoi(argv[1]);
    char key_holder[key_length+1];
    
    //For each value in the key_holder array, choose a randomized value.
    for (i = 0; i < key_length; i++){
        key_holder[i] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ "[rand()%27];
    }
    
    //Null terminator for the last value in the array.
    key_holder[key_length] = '\0';
    
    printf("%s\n", key_holder);
}
