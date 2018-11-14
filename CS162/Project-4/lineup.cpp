/********************************************************************
** Author: Vannear Por
** Date: May 25, 2017
** Description: This is the Lineup Class implementation file which
** will contain the Lineup Class member function definitions. These
** member functions will allow changes to the Lineup Linked Structure
** through adding onto the tail, deleting the head, moving the head
** node to the tail node, displaying the head for fight rounds, and
** displaying the full Lineup for each team.
*********************************************************************/

#include "lineup.hpp"
#include <iostream>
#include <cstdlib>
#include <cstdio>

using std::string;
using std::cout;
using std::cin;
using std::endl;

/********************************************************************
* Default Constructor ()                                            *
**********************************************************************/

Lineup::Lineup ()
{
    
}

/********************************************************************
* Deconstructor ()                                                  *
*********************************************************************/

Lineup::~Lineup ()
{
    
}

/********************************************************************
* Lineup::addToTail ()                                              *
*********************************************************************/

void Lineup::addToTail (Creature *ctr)
{
    struct LineupNode *holder;
    holder = new (struct LineupNode);
    holder->prevNode = NULL;
    holder->data = ctr;
    holder->nextNode = NULL;
    
    if (tail == NULL)
    {
        head = tail = holder;
    }
    
    else
    {
        holder->prevNode = tail;
        tail->nextNode = holder;
        tail = holder;
    }
}

/********************************************************************
 * Lineup::getHeadPointer()					    *
 *******************************************************************/

LineupNode* Lineup::getHeadPointer()
{
	return head;
} 

/********************************************************************
* Lineup::getHead ()                                               *
*********************************************************************/

Creature* Lineup::getHead ()
{
    return head->data;
}

/********************************************************************
* Lineup::deleteHead ()                                             *
*********************************************************************/

void Lineup::deleteHead ()
{
    if (head == NULL)
    {
        std::cout << "This team has no Creatures left." << std::endl;
    }
        
    else
    {
        struct LineupNode *holder;
        holder = head;
        
        if (head->nextNode == NULL)
        {
            head = NULL;
            free(holder);
        }
        
        else
        {
            head = head->nextNode;
            head->prevNode = NULL;
            free(holder);
        }
    }
}

/********************************************************************
* Lineup::headToTail ()                                             *
*********************************************************************/

void Lineup::headToTail ()
{
    struct LineupNode *holder;
    holder = new (struct LineupNode);
    holder->prevNode = NULL;
    holder->nextNode = NULL;
    holder->data = head->data;
    holder->data->heal();
    
    if (head == tail)
    {
        holder->prevNode = NULL;
        holder->nextNode = NULL;
        tail = head = holder;
    }
    
    else
    {
        head = head->nextNode;
        head->prevNode = NULL;
        holder->prevNode = tail;
        tail->nextNode = holder;
        tail = holder;
        free(holder);
    }
}

/********************************************************************
* Lineup::displayHead ()                                            *
*********************************************************************/

void Lineup::displayHead ()
{
    if (head == NULL)
    {
        std::cout << "There are no Creatures left on this team." << std::endl;
    }
    
    else
    {
        std::cout << std::endl << "Fighter: " << head->data->getType();
        std::cout << std::endl << "Strength: " << head->data->getStrengthPoints();
    }
}

/********************************************************************
* Lineup::headAttack ()                                             *
*********************************************************************/

int Lineup::headAttack ()
{
    struct LineupNode *holder;
    holder = head;
    
    if (head == NULL)
    {
        std::cout << "There are no Creatures left on this team." << std::endl;
    }
    
    else
    {
        return holder->data->attack();
    }
}

/********************************************************************
* Lineup::headDefend ()                                             *
*********************************************************************/

void Lineup::headDefend (int damage)
{
    struct LineupNode *holder;
    holder = head;
    
    if (head == NULL)
    {
        std::cout << "There are no Creatures left on this team." << std::endl;
    }
    
    else
    {
        holder->data->defend(damage);
    }
}

/********************************************************************
* Lineup::headDefeated ()                                          *
*********************************************************************/

bool Lineup::headDefeated ()
{
    struct LineupNode *holder;
    holder = head;
    
    return holder->data->defeated();
}

/********************************************************************
* Lineup::displayLineup ()                                          *
*********************************************************************/

void Lineup::displayLineup ()
{
    struct LineupNode *holder;
    holder = head;
    
    if (head == NULL)
    {
        std::cout << "There are no Creatures left on this team." << std::endl;
    }
    
    else
    {
        std::cout << "List team: " << std::endl;
        
        while (holder != NULL)
        {
            std::cout << std::endl << holder->data->getType();
            std::cout << std::endl << holder->data->getStrengthPoints();
            holder = holder->nextNode;
        }
    }
}

