/**********************************************************
** Author: Vannear Por
** Date: June 4, 2017
** Description: This project will utilize linear data structures
** using STL containers. It will allow a user to simulate a buffer
** using Queue and create a palindrome using a Stack.
***********************************************************/

#include "stackqueue.hpp"
#include <iostream>
#include <queue>
#include <stack>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stack;
using std::queue;

int main ()
{
    Stackqueue test;
    int choice;
    int inPercent;
    int outPercent;
    int rounds;
    std::string palinStr;
    bool endProgram = false;
    
    while (endProgram == false)
    {
        std::cout << "Welcome to Vannear's Stack and Queue Program!" << std::endl;
        std::cout << "Please select an option: " << std::endl;
        std::cout << "1) Utilize Queue to simulate a buffer" << std::endl;
        std::cout << "2) Utilize Stack to create a palindrome" << std::endl;
        std::cout << "3) End Program" << std::endl;
        std::cin >> choice;
        
        switch (choice)
        {
            case 1:
            {
                std::cout << "You've chosen to utilize Queue to simulate a buffer!" << std::endl;
                std::cout << "Please enter the number of rounds you'd like the buffer to run for: " << std::endl;
                
                std::cin.clear();
                std::cin.ignore();
                std::cin >> rounds;
                std::cout << "The buffer will run for " << rounds << " rounds!" << std::endl;
                
                std::cout << "Please enter a number between 1 - 100 to determine the percentage that a random number will be placed into the buffer." << std::endl;
                
                std::cin.clear();
                std::cin.ignore();
                std::cin >> inPercent;
                std::cout << "Random numbers will have a " << inPercent << " percent chance of being added into the buffer each round." << std::endl;
                
                std::cout << "Please enter a number between 1 - 100 to determine the percentrage that the first number in the buffer will be removed." << std::endl;
                
                std::cin.clear();
                std::cin.ignore();
                std::cin >> outPercent;
                std::cout << "There is a " << outPercent << " percent chance that the first number in the buffer will be removed each round." << std::endl;
                
                std::cout << "The buffer will now begin running for " << rounds << " rounds..." << std::endl;
                
                test.useQueue(inPercent, outPercent, rounds);
                
                break;
            }
                
            case 2:
            {
                std::cout << "You've chosen to utilize Stack to create a palindrome!" << std::endl;
                std::cout << "Please enter a string that you'd like to turn into a palindrome: " << std::endl;
                
                std::cin.clear();
                std::cin.ignore();
                std::cin >> palinStr;
                
                std::cout << "Your string is " << palinStr << ", let's turn it into a palindrome..." << std::endl;
                
                std::cout << test.palindrome(palinStr) << std::endl;
                
                break;
            }
                
            case 3:
            {
                std::cout << "Ending Program. Goodbye!" << std::endl;
                endProgram = true;
                
                break;
            }
	}
    }	
}

