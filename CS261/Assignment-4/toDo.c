/*
 * CS 261 Assignment 4
 * Name: Vannear Por
 * Date: August 7, 2017 
 */

#include "dynamicArray.h"
#include "task.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * Loads into heap a list from a file with lines formatted like
 * "priority, name".
 * @param heap
 * @param file
 */
void listLoad(DynamicArray* heap, FILE* file)
{
    const int FORMAT_LENGTH = 256;
    char format[FORMAT_LENGTH];
    snprintf(format, FORMAT_LENGTH, "%%d, %%%d[^\n]", TASK_NAME_SIZE);
    
    Task temp;
    while (fscanf(file, format, &temp.priority, &temp.name) == 2)
    {
        dyHeapAdd(heap, taskNew(temp.priority, temp.name), taskCompare);
    }
}

/**
 * Writes to a file all tasks in heap with lines formatted like
 * "priority, name".
 * @param heap
 * @param file
 */
void listSave(DynamicArray* heap, FILE* file)
{
    for (int i = 0; i < dySize(heap); i++)
    {
        Task* task = dyGet(heap, i);
        fprintf(file, "%d, %s\n", task->priority, task->name);
    }
}

/**
 * Prints every task in heap.
 * @param heap
 */
void listPrint(DynamicArray* heap)
{
    DynamicArray* temp = dyNew(1);
    dyCopy(heap, temp);
     while (dySize(temp) > 0)
    {
        Task* task = dyHeapGetMin(temp);
        printf("\n");
        taskPrint(task);
        printf("\n");
        dyHeapRemoveMin(temp, taskCompare);
    }
    dyDelete(temp);
}

/**
 * Handles the given command.
 * @param list
 * @param command
 */
void handleCommand(DynamicArray* list, char command)
{
    int taskPriority;
    char *listFile = malloc (sizeof(char) * 256);
    char *newtask = malloc (sizeof(char) * 256);
    
    switch(command)
    {
            case 'l':
            {
                printf("Enter the name of the file to be loaded: ");
                fgets(listFile, 100, stdin);
                
                if (listFile[strlen(listFile) - 1] == '\n')
                {
                    listFile[strlen(listFile) - 1] = 0;
                }
                
                FILE * readFile = fopen(listFile, "r");
                listLoad(list, readFile);
                printf("The list is loaded from the file.\n");
                printf("\n");
                fclose(readFile);
                break;
            }
            
            case 's':
            {
                printf("Enter the name of the file to be saved: ");
                fgets(listFile, 100, stdin);
                
                if (listFile[strlen(listFile) - 1] == '\n')
                {
                    listFile[strlen(listFile) - 1] = 0;
                }
                
                FILE * writeFile = fopen (listFile, "w+");
                listSave(list, writeFile);
                printf("The list was successfully saved into the file '%s'.\n", listFile);
                printf("\n");
                fclose(writeFile);
                break;
            }
            
            case 'a':
            {
                printf("Enter the task to be added into the list: ");
                fgets(newtask, 100, stdin);
                
                if (newtask[strlen(newtask) - 1] == '\n')
                {
                    newtask[strlen(newtask) - 1] = 0;
                }
                
                printf("Please enter the priority of this task between 0 - 999: ");
                scanf("%d", &taskPriority);
                while (getchar() != '\n');
                Task * addedTask = taskNew(taskPriority, newtask);
                dyHeapAdd(list, addedTask, taskCompare);
                printf("Task '%s' has been added to the list.\n", newtask);
                printf("\n");
                break;
            }
            
            case 'g':
            {
                if (dySize(list) != 0)
                {
                    printf ("The first task on the list is %s\n", ((struct Task *)dyHeapGetMin(list))->name);
                }
                
                else
                {
                    printf("Your to do list is currently empty.\n");
                }
                
                printf("\n");
                break;
            }
            
            case 'r':
            {
                if (dySize(list) == 0)
                {
                    printf("Your to do list is currently empty.\n");
                }
                
                else
                {
                    struct Task * firstTask = (struct Task *)dyHeapGetMin(list);
                    printf("Your first task %s is now removed from your list.\n", firstTask->name);
                    dyHeapRemoveMin(list, taskCompare);
                    taskDelete(firstTask);
                }
                printf("\n");
                break;
            }
            
            case 'p':
            {
                if (dySize(list) == 0)
                {
                    printf("Your to do list is currently empty.\n");
                }
                
                else
                {
                    listPrint(list);
                }
                
                printf("\n");
                break;
            }
            
            case 'e':
            {
                printf("The program will now exit. Goodbye.\n");
                break;
            }
    }
    
    free(newtask);
    free(listFile);
}

int main()
{
    /* Implement */
    printf("\n\n** TO-DO LIST APPLICATION **\n\n");
    DynamicArray* list = dyNew(8);
    char command = ' ';
    do
    {
        printf("Press:\n"
               "'l' to load to-do list from a file\n"
               "'s' to save to-do list to a file\n"
               "'a' to add a new task\n"
               "'g' to get the first task\n"
               "'r' to remove the first task\n"
               "'p' to print the list\n"
               "'e' to exit the program\n"
        );
        command = getchar();
        /* Eat newlines */
        while (getchar() != '\n');
        handleCommand(list, command);
    }
    while (command != 'e');
    for (int i = 0; i < dySize(list); i++)
    {
        Task * deleteTasks = dyGet(list, i);
        taskDelete(deleteTasks);
    }
    
    dyDelete(list);
    return 0;
}
