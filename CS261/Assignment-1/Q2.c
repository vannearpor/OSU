/* CS261- Assignment 1 - Q.2*/
/* Name: Vannear Por
 * Date: July 10. 2017
 * Solution description: This program will display how a value can change by being passed as an
 * argument into a function. It will display the 3 values of x, y, and z; the x and y values will be passed
 *  by reference into function foo(), however z will be passed by value. foo will return a value that is different
 * than the z value.
 */
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    *a = (*a * 2);
    
    *b = (*b/2);
    
    c = (*a+*b);
    
    return c;
}

int main(){
    int x = 5;
    int y = 6;
    int z = 7;
    
    printf("X Value: %d\n", x);
    printf("Y Value: %d\n", y);
    printf("Z Value: %d\n", z);
    
    int value = foo(&x, &y, z);
    
    printf("Foo function returns the value: %d\n", value);
    
    printf("X Value: %d\n", x);
    printf("Y Value: %d\n", y);
    printf("Z Value: %d\n", z);
 
    /*Is the return value different than the value of z?  Why?*/
    /* The return value is different than the original value of z because the value of z was never changed by the foo function. z was only passed as an argument to the foo function by value, not by reference, therefore the value of z outside of the function never changes, like x and y does. */
    
    return 0;
}
    
    

