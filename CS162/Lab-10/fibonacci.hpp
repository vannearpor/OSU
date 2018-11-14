/**********************************************************************
** Author: Vannear Por
** Date: June 10, 2017
** Description: This is the header file for the Fibonacci class which
** will contain the member function prototypes for functions which will
** implement Fibonacci Number Calculations recursively and iteratively.
************************************************************************/

#ifndef FIBONACCI_HPP
#define FIBONACCI_HPP
#include <iostream>

class Fibonacci
{
    public:
        Fibonacci();
        ~Fibonacci();
        int fibonacciR(int n);
        int fibonacciNR(int n);
};

#endif
