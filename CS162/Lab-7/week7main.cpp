/********************************************************
 * ** Author: Vannear Por
 * ** Date: May 13, 2017
 * ** Description: This is the main file which will display
 * ** a menu that will allow the user to utilize a doubly-linked
 * ** circulat structure list. This main file will utilize
 * ** the Queue class and it's member variables and member
 * ** functions. It will allow the user to add a node to the 
 * ** back, display the front node, remove the front node,
 * ** and display the whole Queue.
 * *********************************************************/

#include "queue.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::string;
using std::endl;

int main()
{
    int choice;
    bool endList = false;
    Queue list;
    
    std::cout << "Welcome to Vannear's Queue Program!" << std::endl;
    
    while (endList == false)
    {
        std::cout << "\nPlease select from the following options: " << std::endl;
        std::cout << "1) Enter a value to be added to the queue." << std::endl;
        std::cout << "2) Display first node (front) value." << std::endl;
        std::cout << "3) Remove first node (front) value." << std::endl;
        std::cout << "4) Display the queue contents." << std::endl;
        std::cout << "5) Exit." << std::endl;
        
        std::cin >> choice;
        
        switch (choice)
        {
            case 1:
            {
                std::cin.clear();
                std::cin.ignore();
                int addValue;
                
                std::cout << "You've chosen to add a value to the back of the queue." << std::endl;
                std::cout << "Please enter an integer to add to the back of the queue: " << std::endl;
                std::cin >> addValue;
                
                list.addBack(addValue);
                break;
            }
                
            case 2:
            {
                std::cin.clear();
                std::cin.ignore();
                std::cout << "You've chosen to display the first node (front) value." << std::endl;
                std::cout << list.getFront() << std::endl;
                break;
            }
                
            case 3:
            {
                std::cin.clear();
                std::cin.ignore();
                std::cout << "You've chosen to remove the first node (front) value." << std::endl;
                list.removeFront();
                break;
            }
                
            case 4:
            {
                std::cin.clear();
                std::cin.ignore();
                std::cout << "You've chosen to display the contents of the entire queue." << std::endl;
                list.displayNodes();
                break;
            }

                
            case 5:
            {
                std::cout << "Exiting program. Goodbye!" << std::endl;
                endList = true;
                break;
            }
        }
    }
}
