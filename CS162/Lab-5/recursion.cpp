/*********************************************************
** Author: Vannear Por
** Date: May 7, 2017
** Description: This is the implementation file for the 
** Recursion class which will contain the function definitions
** for the class member functions.
**********************************************************/

#include "recursion.hpp"
#include <iostream>
#include <cmath>

using std::string;

/*********************************************************
 * Default Constructor                                   *
 *********************************************************/

Recursion::Recursion ()
{
}

/*********************************************************
 * Default Deconstructor                                 *
 *********************************************************/

Recursion::~Recursion()
{
}

/*********************************************************
 * Recursion::reverseString ()                           *
 *********************************************************/

std::string Recursion::reverseString (std::string str)
{
    std::string reverse;
    
    if (str.length()==1)
    {
        return str;
    }
    
    else
    {
        reverse = reverseString (str.substr(1, str.length())) + str.at(0);
        return reverse;
    }
}

/*********************************************************
 * Recursion::arraySum ()                           *
 *********************************************************/

int Recursion::arraySum (int a[], int size)
{
    int sum;
    
    if (size == 1)
    {
        return a[0];
    }
    
    else
    {
        sum = a[0] + arraySum ((a + 1), (size - 1));
        
        return sum;
    }
}

/*********************************************************
 * Recursion::triangularNum ()                           *
 *********************************************************/

int Recursion::triangularNum (int n)
{
    int triNumber;
    
    if (n == 1)
    {
        return n;
    }
    
    else
    {
        triNumber = n + (triangularNum (n - 1));
        
        return triNumber;
    }
}
