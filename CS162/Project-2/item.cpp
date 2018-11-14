/*******************************************************************
** Author: Vannear Por
** Date: April 27, 2017
** Description: This is the implementation file for the Item class
** which contains the member function declarations.
*******************************************************************/

#include "item.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>

using std::string;
using std::cout;
using std::endl;

/***************************************************************
* Default Constructor                                         *
***************************************************************/

Item::Item ()
{
    itemName = " ";
    itemUnit = " ";
    itemQuantity = 0;
    unitPrice = 0.00;
}

/***************************************************************
* 4 Parameter Constructor                                     *
***************************************************************/

Item::Item (std::string name, std::string unit, int quan, double price)
{
    setItemName (name);
    setItemUnit (unit);
    setItemQuantity (quan);
    setUnitPrice (price);
    setTotalItemPrice (quan, price);
}

/***************************************************************
* Default Deconstructor                                       *
***************************************************************/

Item::~Item ()
{
}

/***************************************************************
* Item::setItemName ()                                        *
***************************************************************/

void Item::setItemName (std::string n)
{
    itemName = n;
}

/***************************************************************
* Item::setItemUnit ()                                        *
***************************************************************/

void Item::setItemUnit (std::string u)
{
    itemUnit = u;
}

/***************************************************************
* Item::setItemQuantity ()                                    *
***************************************************************/

void Item::setItemQuantity (int q)
{
    itemQuantity = q;
}

/***************************************************************
* Item::setUnitPrice ()                                       *
***************************************************************/

void Item::setUnitPrice (double p)
{
    unitPrice = p;
}

/***************************************************************
* Item::setTotalItemPrice ()                                  *
***************************************************************/

void Item::setTotalItemPrice (int q, double p)
{
    totalItemPrice = static_cast<double>(q * p);
}

/***************************************************************
* Item::getItemName ()                                        *
***************************************************************/

std::string Item::getItemName ()
{
    return itemName;
}

/***************************************************************
* Item::getItemUnit ()                                        *
***************************************************************/

std::string Item::getItemUnit ()
{
    return itemUnit;
}

/***************************************************************
* Item::getItemQuantity ()                                    *
***************************************************************/

int Item::getItemQuantity ()
{
    return itemQuantity;
}

/***************************************************************
* Item::getUnitPrice ()                                       *
***************************************************************/

double Item::getUnitPrice ()
{
    return unitPrice;
}

/***************************************************************
* Item::getTotalItemPrice ()                                  *
***************************************************************/

double Item::getTotalItemPrice ()
{
    return totalItemPrice;
}

/***************************************************************
* Item::printItem ()                                          *
***************************************************************/

void Item::printItem ()
{
    std::cout << "Item Name: " << itemName << std::endl;
    std::cout << "Item Unit: " << itemUnit << std::endl;
    std::cout << "Item Quantity: " << itemQuantity << std::endl;
    std::cout << "Item Price per Unit: $" << unitPrice << std::endl;
    std::cout << "Total Price: $" << totalItemPrice << std::endl;
}

