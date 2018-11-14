/***********************************************************************
** Author: Vannear Por
** Date: June 10, 2017
** Description: This is the implementation file for the Fibonacci class which
** will contain the member function definitions for functions which will
** implement Fibonacci Number Calculations recursively and iteratively.
************************************************************************/

#include "fibonacci.hpp"
#include <iostream>
#include <cmath>

using std::string;
using std::cout;
using std::cin;
using std::endl;

/***********************************************************************
* Default Constructor                                                 *
***********************************************************************/

Fibonacci::Fibonacci()
{
}

/***********************************************************************
* Deconstructor                                                       *
***********************************************************************/

Fibonacci::~Fibonacci()
{
}

/***********************************************************************
* Fibonacci::fibonacciR() - Recursive                                 *
***********************************************************************/

int Fibonacci::fibonacciR(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return fibonacciR(n-1) + fibonacciR(n-2);
    }
}

/***********************************************************************
* Fibonacci::fibonacciNR() - Iterative                                 *
***********************************************************************/

int Fibonacci::fibonacciNR(int n)
{
    int first = 0;
    int second = 1;
    int counter = 2;
    
    while (counter < n)
    {
        int temp = second;
        second = first + second;
        first = temp;
        ++counter;
    }
    
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return first + second;
    }
}

