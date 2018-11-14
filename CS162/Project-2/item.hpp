/*******************************************************************
** Author: Vannear Por
** Date: April 27, 2017
** Description: This is the header file for the Item class which
** contains it's member variables and functions. The variables will
** hold data for the item name, item unit, item quantity, and price
** of the item per unit. The member functions will allow for input
** of the data into the member variables, and will have functions
** which will allow for access to those variables.
*******************************************************************/

#ifndef ITEM_HPP
#define ITEM_HPP

#include <iostream>
#include <string>

using std::string;

class Item
{
    private:
        std::string itemName;
        std::string itemUnit;
        int itemQuantity;
        double unitPrice;
        double totalItemPrice;
    
    public:
    Item ();
    Item (std::string name, std::string unit, int quan, double price);
    ~Item ();
    void setItemName (std::string n);
    void setItemUnit (std::string u);
    void setItemQuantity (int q);
    void setUnitPrice (double p);
    void setTotalItemPrice (int q, double p);
    std::string getItemName ();
    std::string getItemUnit ();
    int getItemQuantity ();
    double getUnitPrice();
    double getTotalItemPrice ();
    void printItem ();
    
};

#endif

