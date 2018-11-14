/**********************************************************
** Author: Vannear Por
** Date: May 7, 2017
** Description: This is the main function for a program that
** will display a menu to the user and give choices that 
** will utilize the Recursion class. The menu will have the
** options of calling 1 of 3 functions within the Recursion
** class: reversing a string, calculating the sum of an
** array, or calculating the triangular number for an inputted
** value.
***********************************************************/

#include "recursion.hpp"
#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main ()
{
    std::string inputStr;
    int arraySize;
    int arrayFill;
    int triRows;
    bool loopOut = false;
    
    while (loopOut == false)
    {
        std::cout << "Welcome to the Recursive Functions program!" << std::endl;
        std::cout << "Please select from one of the follow options to utilize my recursive functions: " << std::endl;
        std::cout << "1) Reverse a String." << std::endl;
        std::cout << "2) Calculate the Sum of an Array." << std::endl;
        std::cout << "3) Calculate the Triangular Number for an Integer." << std::endl;
        std::cout << "4) Exit Program." << std::endl;
        
        std::cin >> choice;
        std::cout << "You chose option number " << choice << "." << std::endl;
        
        switch (choice)
        {
            case 1:
            {
                std::cout << "You've decided to reverse a string." << std::endl;
                std::cout << "Please enter a string you would like to reverse." << std::endl;
                std::cin >> inputStr;
                std::cout << "Your string is: " << inputStr << std::endl;
                std::cout << "Here is the reverse." << std::endl;
                std::cout << reverseString (inputStr) << "\n" << std::endl;
                break;
            }
                
            case 2:
            {
                std::cout << "You've decided to calculate the sum of an array." << std::endl;
                std::cout << "Please enter an integer representing the number of elements in your array: " << std::endl;
                std::cin >> arraySize;
                int inputArray[arraySize];
                
                std::cout << "Now enter the integers you want to get the sum of, press [Enter] after each integer." << std::endl;
                
                for (int i = 0; i < arraySize; i++)
                {
                    cin >> arrayFill;
                    inputArray[i] = arrayFill;
                }
                
                std::cout << "You've completed your array, here is the total sum: " << std::endl;
                std::cout << arraySum (inputArray [], arraySize) << std::endl;
                break;
            }
                
            case 3:
            {
                std::cout << "You've decided to calculate the triangular number of an integer number of rows." << std::endl;
                std::cout << "Please enter the number of rows for your triangle." << std::endl;
                std::cin >> triRows;
                std::cout << "You chose the number " << triRows << std::endl;
                std::cout << "The Triangular number is: " << triangularNum (triRows) << std::endl;
                break;
            }
                
            case 4:
            {
                std::cout << "You've decided to Exit this Program. Goodbye!" << std::endl;
                
                loopOut = true;
                break;
            }
        }
}
