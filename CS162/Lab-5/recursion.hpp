/******************************************************************
** Author: Vannear Por
** Date: May 7, 2017
** Description: This is the header file for the recursion class
** which will contain the prototypes for the member functions of the
** class which will run
*******************************************************************/

#ifndef RECURSION_HPP
#define RECURSION_HPP

#include <iostream>
#include <cstdio>
using std::string;


class Recursion
{
    private:
    
    public:
        Recursion ();
        ~Recursion ();
    
        std::string reverseString (std::string s);
        int arraySum (int a[], int size);
        int triangularNum (int n);
};

#endif
