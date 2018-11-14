/***************************************************************************
** Author: Vannear Por
** Date: April 27, 2017
** Description: This is the main file for the grocery shopping list where it
** prompts the user to choose from a menu on whether they want to add to their list,
** remove an item from their list, or display the list.
****************************************************************************/

#include "item.hpp"
#include "list.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::getline;
using std::string;
using std::endl;

int main()
{
    List cart;
    int choice;
    bool valid1 = false;
    
    std::cout << "This is your Grocery Shopping List." << std::endl;
    
    while (valid1 == false)
    {
        std::cout << "Please select one of the following options: " << std::endl;
        std::cout << "1) Add Item." << std::endl;
        std::cout << "2) Remove Item." << std::endl;
        std::cout << "3) Display Current Shopping List." << std::endl;
        std::cout << "4) Exit Program." << std::endl;
        
        std::cin >> choice;
        std::cout << "You chose option number " << choice << "." << std::endl;
        
        switch(choice)
        {
            case 1:
            {
                std::string addName;
                std::string addUnit;
                int addQTY;
                double addPrice;
                
		std::cin.clear();
		std::cin.ignore();
                std::cout << "Please Enter Item Name: " << std::endl;
                std::getline (std::cin, addName);
                std::cout << "The item you chose is " << addName << std::endl;
                std::cin.clear();
                std::cout << "Now please enter the unit of that item(can, box, pounds, ounces): " << std::endl;
                std::getline (std::cin, addUnit);
                std::cout << "The unit of the item is " << addUnit << std::endl;
                std::cin.clear();
                std::cout << "How many of " << addName << " would you like to buy?" << std::endl;
                std::cin >> addQTY;
                std::cout << "You want to buy " << addQTY << " " << addName << "." << std::endl;
                std::cin.clear();
                std::cout << "How much does each " << addName << " cost?" << std::endl;
                std::cin >> addPrice;
                std::cout << "Each " << addName << " costs $" << addPrice << std::endl;
                
                Item tempItem(addName, addUnit, addQTY, addPrice);
                if (cart.operator==(tempItem))
                {
                    std::cout << "This item already exists within the list." << std::endl;
                }
                else
                {
                    cart.addItem(addName, addUnit, addQTY, addPrice);
                }
                
                break;
                
            }
                
            case 2:
            {
                cart.removeItem();
                break;
            }
                
            case 3:
            {
                cart.displayList();
                break;
            }
                
            case 4:
            {
                std::cout << "You chose to end the program. Goodbye." << std::endl;
		valid1 = true;
		break;
            }
        }
    }
}

