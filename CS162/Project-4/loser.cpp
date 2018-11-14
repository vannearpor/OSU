/********************************************************************
 * ** Author: Vannear Por
 * ** Date: May 25, 2017
 * ** Description: This is the Loser class implementation file which 
 * ** contains the Loser class member function definitions. These 
 * ** member functions will allow for manipulation of the Loser Linked
 * ** Structure in which will add to the head, and display the Losers
 * ** on the screen from most recent to first placed into the structure.
 * *********************************************************************/

#include "loser.hpp"
#include <iostream>
#include <cstdlib>
#include <cstdio>

using std::string;
using std::cout;
using std::cin;
using std::endl;

/********************************************************************
* Default Constructor ()                                            *
*********************************************************************/

Loser::Loser ()
{
}

/********************************************************************
* Deconstructor ()                                                  *
*********************************************************************/

Loser::~Loser ()
{
}

/********************************************************************
 * Loser::addToHead ()                                               *
*********************************************************************/

void Loser::addToHead (Creature *ctr)
{
    struct LoserNode *holder;
    holder = new (struct LoserNode);
    holder->nextNode = NULL;
    holder->data = ctr;
    holder->prevNode = NULL;
    
    if (head == NULL)
    {
        head = tail = holder;
    }
    
    else
    {
        head->prevNode = holder;
        holder->nextNode = head;
        head = holder;
    }
}

/********************************************************************
* Loser::displayLosers ()                                           *
*********************************************************************/

void Loser::displayLosers ()
{
    struct LoserNode *holder;
    holder = head;
    
    if (head == NULL)
    {
        std::cout << "There are no creatures in the Loser's List." << std::endl;
    }
    
    else
    {
        std::cout << "Here is list of losers: " << std::endl;
        
        while (holder != NULL)
        {
            std::cout << holder->data->getType() << std::endl;
            holder = holder->nextNode;
        }
    }
}

