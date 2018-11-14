/***************************************************************
 * ** Author: Vannear Por
 * ** Date: May 13, 2017
 * ** Description: This program will create double linked structures
 * ** that consists of Node objects. This program will demonstrate
 * ** functions that will add new nodes to the head and tail node,
 * ** delete the head and tail node, and print the list of nodes from
 * ** tail to head.
 * ****************************************************************/

#include <iostream>
#include "nodeList.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main ()
{
    int choice;
    bool endList = false;
    NodeList test;
 
    std::cout << "Welcome to Vannear's Linked List Program!" << std::endl;
    
    while (endList == false)
    {
        std::cout << "\nPlease select from the following options: " << std::endl;
        std::cout << "1) Add a new node to the head." << std::endl;
        std::cout << "2) Add a new node to the fail." << std::endl;
        std::cout << "3) Delete head node." << std::endl;
        std::cout << "4) Delete tail node." << std::endl;
        std::cout << "5) Traverse the List Reversely." << std::endl;
        std::cout << "6) Print the head node." << std::endl;
        std::cout << "7) Print the tail node." << std::endl;
        std::cout << "8) Exit Program." << std::endl;
        
        std::cin >> choice;
        
        switch (choice)
        {
            case 1:
            {
                std::cin.clear();
                std::cin.ignore();
                std::cout << "You've chosen to add a new node to the head." << std::endl;
                test.addToHead();
                break;
            }
                
            case 2:
            {
                std::cin.clear();
                std::cin.ignore();
                std::cout << "You've chosen to add a new node to the tail." << std::endl;
                test.addToTail();
                break;
            }
                
            case 3:
            {
                std::cin.clear();
                std::cin.ignore();
                std::cout << "You've chosen to delete the head node." << std::endl;
                test.deleteHead();
                break;
            }
                
            case 4:
            {
                std::cin.clear();
                std::cin.ignore();
                std::cout << "You've chosen to delete the tail node." << std::endl;
                test.deleteTail();
                break;
            }
                
            case 5:
            {
                std::cin.clear();
                std::cin.ignore();
                std::cout << "You've decided to traverse the list reversely." << std::endl;
                test.reverseList();
                break;
            }
                
            case 6:
            {
                std::cin.clear();
                std::cin.ignore();
                std::cout << "You've decided to print the head node." << std::endl;
                test.printHeadNode();
                break;
            }
                
            case 7:
            {
                std::cin.clear();
                std::cin.ignore();
                std::cout << "You've decided to print the tail node." << std::endl;
                test.printTailNode();
                break;
            }
                
            case 8:
            {
                std::cout << "Exiting program. Goodbye!" << std::endl;
                endList = true;
                break;
            }
        }
    }
}    
