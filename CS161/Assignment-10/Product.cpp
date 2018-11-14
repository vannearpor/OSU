/*********************************************************************************
** Author: Vannear Por
** Date: March 16, 2017
** Description: This program contains the member function definitions for
** the Product class. It contains definitions for functions that will create
** the product's ID code, title, description, price, and quantity available.
** It also contains definitions for a function that is able to decreased the
** quantity available of an item.
**********************************************************************************/

#include <iostream>
#include <cmath>
#include <string>
#include "Product.hpp"

/*******************************************************************************
 * Product::Product
 * Default Constructor: This contrustor takes 5 parameters and initializes the
 * member variables.
 ******************************************************************************/

Product::Product(std::string id, std::string t, std::string d, double p, int qa)
{
    std::string idCode = id;
    std::string title = t;
    std::string description = d;
    double price = p;
    int quantityAvailable = qa;
}

/*******************************************************************************
 * Product::getIdCode
 * This member function returns the Product ID Code.
 *******************************************************************************/

std::string Product::getIdCode()
{
    return idCode;
}

/*******************************************************************************
 * Product::getTitle
 * This member function returns the Product Title.
 ******************************************************************************/

std::string Product::getTitle()
{
    return title;
}

/******************************************************************************
 * Product::getDescription
 * This member fuction returns the Product description.
 *****************************************************************************/

std::string Product::getDescription()
{
    return description;
}

/******************************************************************************
 * Product::getPrice
 * This member function returns the Product's price.
 *****************************************************************************/

double Product::getPrice()
{
    return price;
}

/******************************************************************************
 * Product::getQuantityAvailable
 * This member function returns the Product's available quantity.
 *****************************************************************************/

int Product::getQuantityAvailable()
{
    return quantityAvailable;
}

/******************************************************************************
 * Product::decreaseQuantity
 * This member function decreases the quantityAvailable member variable of 
 * a product by 1 and saves the new quantity into the variable.
 ******************************************************************************/

void Product::decreaseQuantity()
{
    int quantityAvailable -= 1;
}
