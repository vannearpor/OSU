/*******************************************************************
** Author: Vannear Por
** Date: April 27, 2017
** Description: This is the implementation file for the List class
** which contains the member function definitions which will determine
** the tasks done to the list. The default constructor will create a
** default array with a maximum capacity of 4. The functions will
** allow the user to add and remove/delete items from the list. There
** is also a function that will display the list as a whole.
*******************************************************************/

#include "list.hpp"
#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::getline;

/***************************************************************
* Default Constructor                                         *
***************************************************************/

List::List ()
{
    listSize = 0;
    listMaximum = 4;
    priceAllItems = 0.00;
    itemList = new Item[4];
}

/***************************************************************
* Default Deconstructor                                       *
***************************************************************/

List::~List ()
{
}

/***************************************************************
* List::addItem ()                                            *
***************************************************************/

void List::addItem (std::string name, std::string unit, int qty, double price)
{
    if (listSize == listMaximum)
    {
        listMaximum *= 2;
        Item * itemListAddOn = new Item[listMaximum];
        for (int i = 0; i < listSize; i++)
        {
            itemListAddOn[i] = itemList[i];
        }
        
        itemList = itemListAddOn;
    }
    
    itemList[listSize] = Item (name, unit, qty, price);
    priceAllItems += (static_cast<double>(qty * price));
    listSize++;
}

/***************************************************************
* List::deleteSpace ()                                        *
***************************************************************/

void List::deleteSpace (int ii)
{
    for (int i = ii; i < listSize; i++)
    {
        itemList[i] = itemList[i + 1];
    }
}

/***************************************************************
* List::removeItem ()                                         *
***************************************************************/

void List::removeItem ()
{
    std::string removeItemName;
    
    std::cout << "What is the name of the item you would like to remove?" << std::endl;
    std::getline (std::cin, removeItemName);
    for (int i = 0; i < listSize; i++)
    {
        if ( (itemList[i]).getItemName() == removeItemName)
        {
            deleteSpace (i);
        }
    }
    listSize--;
}

/***************************************************************
* List::displayList ()                                        *
***************************************************************/

void List::displayList ()
{
    for (int i = 0; i < listSize; i++)
    {
        std::cout << "Grocery List: " << std::endl;
        itemList[i].printItem();
    }
    
    std::cout << "The total price for this whole list is a whopping $" << getPriceAllItems () << std::endl;
}

/***************************************************************
* List::getPriceAllItems ()                                   *
***************************************************************/

double List::getPriceAllItems ()
{
    priceAllItems = 0;
    
    for (int i = 0; i < listSize; i++)
    {
        priceAllItems += itemList[i].getTotalItemPrice ();
    }
    
    return priceAllItems;
}

/***************************************************************
* List::operator == ()                                        *
***************************************************************/

bool List::operator==(Item checkItem)
{
    int size = listSize;
    
    for (int i = 0; i < size; i++)
    {
        if ( (itemList[i]).getItemName() == checkItem.getItemName())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}





