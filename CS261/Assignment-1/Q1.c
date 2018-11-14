/* CS261- Assignment 1 - Q.1*/
/* Name: Vannear Por
 * Date: July 10, 2017
 * Solution description: This program will create a structure object of student, it will then
 * allocate memory to create a pointer pointing allocated memory for the structure. The program will
 * then generate random values for the student's ID and scores, the ID and scores will be printed
 * for display on screen, the data will calculate and display the minimum, maximum, and average of the scores.
 * After the program runs, the memory will be freed and deallocated.
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include <time.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){

    struct student *tenStudents = (struct student*)malloc(sizeof(struct student)*10);
    
    return tenStudents;
}

void generate(struct student* students){

    time_t t;
    
    srand((unsigned) time(&t));
    
    for (int i = 0; i < 10; i++)
    {
        (students+i)->id = rand() % 10 + 1;
        (students+i)->score = rand () % 101;
    }
     
}

void output(struct student* students){
    
    for (int i = 0; i < 10; i++)
    {
        printf("%d %d\n", (students+i)->id, (students+i)->score);
    }
}

void summary(struct student* students){
    
    int minScore = 0;
    int maxScore = 100;
    int total = 0;
    float averageScore = 0.00;
    
    for (int i = 0; i < 10; i++)
    {
        if (minScore > ((students+i)->score))
        {
           minScore = ((students+i)->score);
        }
        
        else if (maxScore < ((students+i)->score))
        {
            maxScore = (students+i)->score;
        }
        
        total = total + (students+i)->score;
    }
    
    averageScore = (total/10.00);
    
    printf("Max Score: %d\n", maxScore);
    printf("Min Score: %d\n", minScore);
    printf("Average Score: %.2f\n", averageScore);
    
}

void deallocate(struct student* stud){

    if(stud != NULL)
    {
        free(stud);
        stud = 0;
    }
}

int main(){
    struct student* stud = NULL;
    
    stud = allocate();
    
    generate(stud);
    
    output(stud);
    
    summary(stud);
    
    deallocate(stud);

    return 0;
}
