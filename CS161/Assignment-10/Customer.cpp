/*********************************************************************
** Author: Vannear Por
** Date: March 16, 2017
** Description: This program contains the member function definitions
** for the Customer class. It contains definitions for functions that 
** will create initialize values into the variables that represent
** the Customer name, their accound ID, their cart, and whether that Customer 
** is a premium member or not. The member functions will also return these
** values. There are also member functions that will add Product
** objects into the Cart vector through their Product ID. This class also
** contains a function that can empty the cart vector data.
********************************************************************/

#include <iostream>
#include <string>
#include "Customer.hpp"

/**********************************************************************
 * Customer::Customer
 * Default Constructor: This constructor takes 3 parameters and initializes
 * the member variables.
 *********************************************************************/

Customer::Customer(std::string n, std::string a, bool pm)
{
    std::string name = n;
    std::string accountID = a;
    bool premiumMember = pm;
}

/*********************************************************************
 * Customer::getAccountID
 * This member function returns the Customer Account ID.
 *********************************************************************/

std::string Customer::getAccountID()
{
    return accountID;
}

/**********************************************************************
 * Customer::getCart
 * This member function returns the cart of the Customer.
 *********************************************************************/

vector<std::string> Customer::getCart()
{
    return cart;
}

/**********************************************************************
 * Customer::addProductToCart
 * This function receives a product ID as a parameter and adds the product
 * ID code into the Customer Cart vector.
 **********************************************************************/

void Customer::addProductToCart(std::string addProductID)
{
    cart.push_back(addProductID)
}

/*********************************************************************
 * Customer::isPremiumMember
 * This function returns a boolean value which represents whether
 * the Customer is a premium member or not.
 ********************************************************************/

bool Customer::isPremiumMember()
{
    return premiumMember;
}

/*********************************************************************
 * Customer::emptyCart
 * This function deletes everything in the cart vector and clears the
 * Customer cart of all Product IDs it may contain at the moment.
 *********************************************************************/

void Customer::emptyCart
{
    cart.clear();
}
