/* CS261- Assignment 1 - Q.3*/
/* Name: Vannear Por
 * Date: July 10, 2017
 * Solution description: This program will generate an array of 20 numbers, and use the sort() function
 * to sort the numbers in ascending order and display the new array order.
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include <time.h>


void sort(int* number, int n){
    int holder;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (n - i - 1); j++) //check to see if there are any numbers lower than holder
        {
            if(*(number+j) < *(number+(j+1))) //swap
            {
                holder = *(number+j);
		*(number+j) = *(number+(j+1));
                *(number+(j+1)) = holder;
            }
        }
    }
}

int main(){
    
    int n = 20;
    
    int *newArr = (int *)malloc(sizeof(int)*n);
    
    time_t t;
    
    srand((unsigned) time(&t));
    
    for (int i = 0; i < n; i++)
    {
        *(newArr+i) = rand() % 100;
    }
   
    printf("Input Array: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", *(newArr+i));
    }

    sort(newArr, n);
    
    printf("Sorted Array: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", *(newArr+i));
    }
    
    return 0;
}
