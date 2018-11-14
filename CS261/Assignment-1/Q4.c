/* CS261- Assignment 1 - Q.4*/
/* Name: Vannear Por
 * Date: July 10, 2017
 * Solution description: This program will generate an array of 10 students, generate random ID and scores
 * for the 10 students, the program will then sort the scores in ascending order using the sort() function.
 * Then the new array order of student scores will display.
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include <time.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
    int holderID;
    int holderScore;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (n - i - 1); j++) /*check to see if there are any numbers lower than holder*/
        {
            if((students+j)->score < (students+(j+1))->score) /*swap*/
            {
                holderScore = (students+j)->score;
                (students+j)->score = (students+(j+1))->score;
                (students+(j+1))->score = holderScore;
                
                /*also change the id*/
                holderID = (students+j)->id;
                (students+j)->id = (students+(j+1))->id;
                (students+(j+1))->id = holderID;
            }
        }
    }
}

int main(){
    int n = 10;
    
    struct student *tenStudents = (struct student*)malloc(sizeof(struct student)*n);
    
    time_t t;
    
    srand((unsigned) time(&t));
    
    for (int i = 0; i < n; i++)
    {
        (tenStudents+i)->id = rand() % 10 + 1;
        (tenStudents+i)->score = rand() % 101;
    }
    
    printf("Input data: \n");    
    for (int i = 0; i < n; i++)
    {
        printf("%d %d\n", (tenStudents+i)->id, (tenStudents+i)->score);
    }

    sort(tenStudents, n);
    
    printf("Sorted data: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d %d\n", (tenStudents+i)->id, (tenStudents+i)->score);
    }
    
    return 0;
}
