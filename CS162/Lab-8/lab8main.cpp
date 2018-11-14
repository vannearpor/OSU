/*********************************************************
** Author: Vannear Por
** Date: May 27, 2017
** Description: This is the main function for the Search
** and Sort Program which will utilize .txt files to 
** display the functions of different search and sort
** methods.
**********************************************************/

#include "searchsort.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <vector>

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main()
{
    int choice;
    bool endProgram = false;
    Searchsort test;
    
    std::cout << "Welcome to Vannear's Search and Sort Algorithm Program!" << std::endl;
    
    while (endProgram == false)
    {
        std::cout << "\nPlease select from the following options: " << std::endl;
        std::cout << "1) Linear Search of A Target Value" << std::endl;
        std::cout << "2) Bubble Sort A List of Values" << std::endl;
        std::cout << "3) Binary Search" << std::endl;
        std::cout << "4) Exit Program" << std::endl;
        
        std::cin >> choice;
        
        switch (choice)
        {
            case 1:
            {
                int target;
                
                std::cout << "\nPlease enter a target integer to utilize a Linear Search: " << std::endl;
                
                std::cin.clear();
                std::cin.ignore();
                std::cin >> target;
                
                test.linearSearch(target, "original.txt");
                test.linearSearch(target, "early.txt");
                test.linearSearch(target, "middle.txt");
                test.linearSearch(target, "end.txt");
                break;
            }
            case 2:
            {
                std::string inFile;
                std::string outFile;
                
                std::cout << "Please type in the name of the file that you want to bubble sort?" << std::endl;
                std::cout << "early.txt" << std::endl;
                std::cout << "middle.txt" << std::endl;
                std::cout << "end.txt" << std::endl;
               
		std::cin.clear();
		std::cin.ignore(); 
                std::cin >> inFile;
                
                std::cout << "Please name the output file." << std::endl;
		std::cin.clear();
		std::cin.ignore();
                std::cin >> outFile;
                
                test.bubbleSort(inFile, outFile);
                break;
            }
            case 3:
            {
                std::string binaryFile;
                int binaryTarget;
                
                std::cout << "The file 'original.txt' is already sorted and will be utilized for a binary search." << std::endl;
                std::cout << "\nPlease select a target integer to utilize binary search: " << std::endl;
                std::cin.clear();
		std::cin.ignore();
		std::cin >> binaryTarget;
                test.binarySearch(binaryTarget, "original.txt");
                break;
            }
            case 4:
            {
                endProgram = true;
                break;
            }
        }
        
    }
    
}

