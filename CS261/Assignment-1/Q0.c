/* CS261- Assignment 1 - Q. 0*/
/* Name: Vannear Por
 * Date: July 10, 2017
 * Solution description: This program intializes x and gives it a value,
 * then it prints the address of x, and will utilize the function foo, and then print the value of x.
 */
 
#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
    
    printf("%d", *iptr);
    
    printf("%p", iptr);
    
    printf("%p", &iptr);
}

int main(){
    
    int x = 10;
    
    printf("%p", &x);
    
    fooA(&x);
    
    printf("%d", x);
    
    return 0;
}

