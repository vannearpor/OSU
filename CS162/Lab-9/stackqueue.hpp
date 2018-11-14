/**************************************************************
** Author: Vannear Por
** Date: June 4, 2017
** Description: This is the Stackqueue class header file which
** will contain the class member function prototypes for functions
** that will allow for the use of Stack and Queue data structures.
***************************************************************/

#ifndef STACKQUEUE_HPP
#define STACKQUEUE_HPP

#include <iostream>
#include <stack>
#include <queue>
#include <cstdlib>
#include <ctime>

using std::string;
using std::queue;

class Stackqueue
{
    public:
        Stackqueue();
	~Stackqueue();
	int getNumber();
        int inRoll ();
        int outRoll ();
        void displayQueue(std::queue<int>);
        void useQueue(int, int, int);
        std::string palindrome(std::string input);
};

#endif


