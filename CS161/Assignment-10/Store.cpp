/**************************************************************
** Author: Vannear Por
** Date: March 16, 2017
** Description: This program contains the member function definitions
** for the Store class. It contains definitions for functions that 
** will add Product into the Store inventory, add Customers in
** the Store members, search Product and Customer IDs to return
** pointers to matching Products and Customers, search for Products
** matching a search string, add Products to a Member's Cart, and
** allow the Customer to checkout.
***************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <locale>
#include "Store.hpp"

/**************************************************************
 * Store::addProduct
 * This function adds a Product into Store inventory vector.
 *************************************************************/

void Store::addProduct(Product* p)
{
    inventory.push_back(p);
}

/************************************************************
 * Store::addMember
 * This function adds a Custome into the Store member vector.
 ***********************************************************/

void Store::addMember(Customer* c)
{
    members.push_back(c);
}

/************************************************************
 * Store::getProductFromID
 * This function receives a string parameter and returns a
 * pointer to the Product with an ID matching the string from
 * inventory; if there is no match found, NULL is returned.
 ***********************************************************/

std::Product* Store::getProductFromID(std::string searchProductID)
{
    for (int i = 0; i < inventory.size(); i++)
    {
        if ((*inventory[i]).getIdCode() == searchProductID)
        {
            return inventory[i];
        }
        else
        {
            return NULL;
        }
    }
}

/************************************************************
 * Store::getMemberFromID
 * This function receives a string parameter and returns a
 * pointer to the Member with an ID matching the string; if 
 * there is no match found, NULL is returned.
 ***********************************************************/

std::Customer* Store::getMemberFromID(std::string searchMemberID)
{
    for (int i = 0; i < members.size(); i++)
    {
        if ((*members[i]).getAccountID() == searchMemberID)
        {
            return members[i];
        }
        else
        {
            return NULL;
        }
    }
}

/*************************************************************
 * Store::productSearch
 * This function receives a string parameter and prints out
 * the title, ID code, price, and description for every
 * Product whose title or description matches the string parameter.
 * The first letter of the search string sould be case-insensitive.
 *************************************************************/

void Store::productSearch(std::string str)
{
    str = toLowerCase(str);
    
    for (int i = 0; i < inventory.size(); i++)
    {
        string lowerCaseTitle = toLowerCase((*inventory[i].getTitle()));
        
        string lowerCaseDescription = toLowerCase((*inventory[i].getDescription()));
        
        if (lowerCaseTitle.find(str) != -1 || lowerCaseDescription.find(str) != -1)
        {
            cout << "Product Title: " << (*inventory[i]).getTitle() << endl;
            cout << "Product ID: " << (*inventory[i]).getIdCode() << endl;
            cout << "Product Price: " << (*inventory[i]).getPrice() << endl;
            cout << "Product Description: " << (*inventory[i]).getDescription() << endl;
        }
    }
}

/**************************************************************
 * Store::addProductToMemberCart
 * This function receives 2 parameters, a Product ID and a 
 * Member ID; after receiving the parameters, it will add the
 * matching Product ID into the cart vector of the matching
 * Member ID. If Product or Member IDs are not found, this 
 * function will print that they are not found. It will also
 * display whether the item is out of stock.
 *************************************************************/

void Store::addProductToMemberCart(std::string pID, std::string mID)
{
    Product* chosenProduct = getProductFromID(pID);
    Customer* chosenCustomer = getMemberFromID(mID);
    bool foundProduct = false;
    bool foundCustomer = false;
    
    if (chosenProduct != NULL)
    {
        foundProduct = true;
    }
    else
    {
        cout << "Product #" << pID << " not found." << endl;
    }
    
    if (chosenCustomer != NULL)
    {
        foundCustomer = true;
    }
    else
    {
        cout << "Member #" << mID << " not found." << endl;
    }
    
    if (foundProduct = true && foundCustomer = true)
    {
        if ((*chosenProduct).getQuantityAvailable() > 0)
        {
            (*chosenCustomer).addProductToCart(pID);
        }
        else
        {
            cout << "Sorry, product #" << pID << ", " << (*chosenProduct).getTitle() << ", is no longer available." << endl;
        }
    }
}

/****************************************************************
 * Store::checkOutMember
 * This function will receive a Member ID as a parameter and print
 * out the title and price for each product in the Customer's cart
 * and decrease the quantity of the product in the Store inventory
 * by 1. Will display if the member is not found or if the product
 * is currently sold out. It will also print out a subtotal for
 * the customer cart along with the shipping costs for premium
 * and normal members. It will then finally print out the final total
 * cost of the cart. After all calculations, the member's cart is
 * then emptied.
 ****************************************************************/

void Store::checkOutMember(std::string mID)
{
    Customer* chosenCustomer = getMemberFromID(mID);
    
    if (chosenCustomer == NULL)
    {
        cout << "Member #" << mID << " not found." << endl;
    }
    else
    {
        string pID;
        string productTitle;
        double productPrice = 0.0;
        double shippingCost = 0.0;
        double subtotal = 0.0
        double total = 0.0;
        int productQuantity = 0;
        
        for (int i = 0; i < (*chosenCustomer).getCart().size(); i++)
        {
            pID = ((*chosenCustomer).getCart())[i];
            Product* currentProduct = getProductFromID(pID);
            
            productTitle = (*currentProduct).getTitle();
            productQuantity = (*currentProduct).getQuantityAvailable();
            
            if (productQuantity < 1)
            {
                cout << "Sorry, product #" << pID << ", " << productTitle << ", is no longer available." << endl;
            }
            else
            {
                productPrice = (*chosenProduct).getPrice();
                cout << productTitle << ": $" << productPrice << endl;
                subtotal += productPrice;
                (*chosenProduct).decreaseQuantity();
            }
        }
        
        cout << "Subtotal: $" << subtotal << endl;
        
        if ((*chosenCustomer).isPremiumMember())
        {
            shippingCost = 0.0;
        }
        else
        {
            shippingCost = subtotal * 0.07;
        }
        
        cout << "Shipping Cost: $" << shippingCost << endl;
        total = subtotal + shippingCost;
        cout << "Total: $" << total << endl;
        
        (*chosenCustomer).emptyCart();
    }
}
