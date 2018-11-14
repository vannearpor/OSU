/**************************************************************
 * ** Author: Vannear Por
 * ** Date: May 20, 2017
 * ** Description: This is the Queue class implementation file which
 * ** contains the class function definitions which will allow for 
 * ** a node to be added to the back, to remove the front node, and to 
 * ** display the front node.
 * ***************************************************************/

#include "queue.hpp"
#include <iostream>
#include <cstdlib>
#include <cstdio>

using std::cout;
using std::cin;
using std::endl;
using std::string;

/**************************************************************
 * * Default Constructor ()                                      *
 * ***************************************************************/

Queue::Queue ()
{
}

/**************************************************************
 * * Deconstructor ()                                            *
 * ***************************************************************/

Queue::~Queue ()
{
    struct QueueNode *holder;
    holder = front;
    
    while (holder != back)
    {
        back->nextNode = front->nextNode;
        front = front->nextNode;
        front->prevNode = back;
        free(holder);
        holder = front;
    }
    
    free(back);
}

/**************************************************************
 * * Queue::addBack ()                                           *
 * ***************************************************************/

void Queue::addBack (int val)
{
    int addNum = val;
    
    struct QueueNode *holder;
    holder = new (struct QueueNode);
    holder->value = addNum;
    holder->nextNode = NULL;
    holder->prevNode = NULL;
    
    if (back == NULL)
    {
        std::cout << "Integer is inserted into an empty list." << std::endl;
        front = back = holder;
        front->nextNode = back->nextNode = NULL;
        front->prevNode = back->prevNode = NULL;
    }
    
    else
    {
        back->nextNode = holder;
        holder->prevNode = back;
        back = holder;
        front->prevNode = back;
        back->nextNode = front;
    }
}

/**************************************************************
 * * Queue::getFront ()                                          *
 * ***************************************************************/

int Queue::getFront ()
{
    int showFront;
    
    if (front == NULL)
    {
        std::cout << "The front node is currently empty." << std::endl;
        return 0;
    }
    
    else
    {
        showFront = front->value;
        return showFront;
    }
}

/**************************************************************
 * * Queue::removeFront ()                                       *
 * ***************************************************************/

void Queue::removeFront ()
{
    struct QueueNode *holder;
    holder = front;
    
    if (front == NULL)
    {
        std::cout << "List is currently empty." << std::endl;
    }
    
    if (front->nextNode == NULL)
    {
        front = NULL;
        back = front;
        back->nextNode = front->nextNode = NULL;
        back->prevNode = front->prevNode = NULL;
        free(holder);
        std::cout << "Front node removed, list is currently empty." << std::endl;
    }
    
    else
    {
        back->nextNode = front->nextNode;
        front = front->nextNode;
        front->prevNode = back;
        free(holder);
        std::cout << "Front node has been removed. New Front node established." << std::endl;
    }
}

/**************************************************************
 * * Queue::displayNodes ()                                      *
 * ***************************************************************/

void Queue::displayNodes ()
{
    struct QueueNode *holder;
    holder = front->nextNode;
    
    if (front == NULL)
    {
        std::cout << "List is currently empty. Nothing to display." << std::endl;
    }
    
    else
    {
        std::cout << front->value << " -> ";
        
        while (holder != front)
        {
            std::cout << holder->value << " -> ";
            holder = holder->nextNode;
        }
        
        std::cout << front->value << "(First Node)" << std::endl;
        
    }
}
