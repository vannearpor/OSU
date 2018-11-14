/***********************************************************************
** Author: Vannear Por
** Date: June 10, 2017
** Description: This program will measure and compare the run time of
** both the recursive and iterative implementations of Fibonacci
** Numbers Calculation. This program will utilize Fibonacci functions
** and clock functions to measure the run time.
************************************************************************/

#include "fibonacci.hpp"
#include <iostream>
#include <ctime>
#include <cmath>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::clock;

int main()
{
    Fibonacci test;
    int choice;
    int inputR;
    int inputNR;
    bool endProgram = false;
    
    while (endProgram == false)
    {
        std::cout << "Welcome to Vannear's Fibonacci Timer Program!" << std::endl;
        std::cout << "This program will run a Fibonacci Number Calculator and display the time it took for the Fibonacci series to run!" << std::endl;
        std::cout << "Please select which Fibonacci Number Calculator to utilize: " << std::endl;
        std::cout << "1) Recursive" << std::endl;
        std::cout << "2) Iterative" << std::endl;
        std::cout << "3) End Program" << std::endl;
        std::cin >> choice;
        
        switch (choice)
        {
            case 1:
            {
                std::cout << "You've chosen to utilize the Recursive implementation of the Fibonacci Number Calculator." << std::endl;
                std::cout << "Please enter the number of values for the Fibonacci series to run through: " << std::endl;
                
                std::cin.clear();
                std::cin.ignore();
                std::cin >> inputR;
                
                std::cout << "\nThe Fibonacci series will run for " << inputR << " number of values." << std::endl;
                 
                clock_t startR = std::clock();
                
                test.fibonacciR(inputR);
                
                double durationR = (std::clock() - startR) / (double)CLOCKS_PER_SEC;
                
                std::cout << "The recursive implementation of Fibonacci's calculator for " << inputR << " terms ran for " << durationR << " seconds." << std::endl;
                
                break;
            }
                
            case 2:
            {
                std::cout << "You've chosen to utilize the Iterative implementation of the Fibonacci Number Caclulator." << std::endl;
                std::cout << "Please enter the number of values for the Fibonacci series to run through: " << std::endl;
                
                std::cin.clear();
                std::cin.ignore();
                std::cin >> inputNR;
                
                std::cout << "\nThe Fibonacci series will run for " << inputNR << " number of values." << std::endl;
                
                clock_t startNR = std::clock();
                
                test.fibonacciNR(inputNR);
                
                double durationNR = (std::clock() - startNR) / (double)CLOCKS_PER_SEC;
                
                std::cout << "The iterative implementation of Fibonacci's calculator for " << inputNR << " terms ran for " << durationNR << " seconds." << std::endl;
                
                break;
            }
                
            case 3:
            {
                std::cout << "The program will now end. Goodbye!" << std::endl;
                
                endProgram = true;
                
                break;
            }
        }
    }
}
