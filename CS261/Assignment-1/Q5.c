/* CS261- Assignment 1 - Q.5*/
/* Name: Vannear
 * Date: July 10, 2017
 * Solution description: This program will prompt the user to enter a word less than 10 letters long
 * and use a sticky() function to display the word in alternating Uppercase and Lowercase characters,
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

void sticky(char* word){
    int length = strlen(word);
    
    for (int i = 0; i < length; i++)
    {
        if ((i%2) == 0) /*find uppercase letter spots*/
        {
            if (islower(*(word+i))) /*check to see if letter is lowercase*/
            {
                *(word+i) = toUpperCase(*(word+i));
            }
        }
        
        else if ((i%2) == 1) /*fine lowercase letter spots*/
        {
            if (isupper(*(word+i))) /*check to see if letter is uppercase*/
            {
                *(word+i) = toLowerCase(*(word+i));
            }
        }
    }
}

int main(){
    char stickyWord[10];
    printf("Please enter a word that is less than 10 letters: \n");
    
    scanf("%s", stickyWord);
    
    sticky(stickyWord);
    
    printf("%s", stickyWord);
    
    return 0;
}

