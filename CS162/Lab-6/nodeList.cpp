/********************************************************
 * ** Author: Vannear Por
 * ** Date: May 13, 2017
 * ** Description: This file contains the NodeList class
 * ** implementation file which will contain the member 
 * ** function declarations. These member functions will
 * ** add new nodes to the head or tail of a list, delete 
 * ** nodes from the head of tail of a list, and display
 * ** the list in reverse order from tail to head.
 * *********************************************************/

#include "nodeList.hpp"
#include <iostream>
#include <cstdlib>
#include <cstdio>

using std::string;
using std::cout;
using std::cin;
using std::endl;

/********************************************************
 * * Default Constructor ()                                *
 * *********************************************************/

NodeList::NodeList ()
{
}

/********************************************************
 * * Deconstructor ()                                      *
 * *********************************************************/

NodeList::~NodeList ()
{
}

/********************************************************
 * * NodeList::addToHead ()                                *
 * *********************************************************/

void NodeList::addToHead ()
{
    int headNum;
    
    std::cout << "Enter a positive integer to be added to the head of the list: " << std::endl;
    std::cin >> headNum;
    
    while (headNum < 0)
    {
        std::cin.clear();
        std::cin.ignore();
        
        std::cout << "You've entered an invalid integer, please enter a positive integer." << std::endl;
        std::cin >> headNum;
    }
    
    struct intNode *holder;
    holder = new (struct intNode);
    holder->nextNode = NULL;
    holder->data = headNum;
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
    
    displayList ();
}


/********************************************************
 * * NodeList::addToTail ()                                *
 * *********************************************************/

void NodeList::addToTail ()
{
    int tailNum;
    
    std::cout << "Enter a positive integer to be added to the tail of the list: " << std::endl;
    std::cin >> tailNum;
    
    while (tailNum < 0)
    {
        std::cin.clear();
        std::cin.ignore();
        
        std::cout << "You've entered an invalid integer, please enter a positive integer." << std::endl;
        std::cin >> tailNum;
    }
    
    struct intNode *holder;
    holder = new (struct intNode);
    holder->prevNode = NULL;
    holder->data = tailNum;
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
    
    displayList ();
}

/********************************************************
 * * NodeList::deleteHead ()                               *
 * *********************************************************/

void NodeList::deleteHead ()
{
    if (head == NULL)
    {
        std::cout << "Linked list is currently empty." << std::endl;
    }
    
    else
    {
        struct intNode *holder;
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
    
    displayList ();
}

/********************************************************
 * * NodeList::deleteTail ()                               *
 * *********************************************************/

void NodeList::deleteTail ()
{
    if (tail == NULL)
    {
        std::cout << "Linked list is currently empty." << std::endl;
    }
    
    else
    {
        struct intNode *holder;
        holder = tail;
        
        if (tail->prevNode == NULL)
        {
            tail = NULL;
            free(holder);
        }
        
        else
        {
            tail = tail->prevNode;
            tail->nextNode = NULL;
            free(holder);
        }
    }
    
    displayList ();
}

/********************************************************
 * * NodeList::reverseList ()                              *
 * *********************************************************/

void NodeList::reverseList ()
{
    struct intNode *print;
    
    if (tail == NULL)
    {
        std::cout << "The List is currently empty." << std::endl;
    }
    
    else
    {
        std::cout << "Here is the list in reverse order from tail to head: " << std::endl;
        print = tail;
        
        while (print != NULL)
        {
            std::cout << print->data << " : ";
            print = print->prevNode;
        }
    }
}

/********************************************************
 * * NodeList::printHeadNode ()                            *
 * *********************************************************/

void NodeList::printHeadNode ()
{
    if (head == NULL)
    {
        std::cout << "The head node is empty." << std::endl;
    }
    
    else
    {
        std::cout << "The head node contains the integer: " << head->data << std::endl;
    }
}

/********************************************************
 * * NodeList::printTailNode ()                            *
 * *********************************************************/

void NodeList::printTailNode ()
{
    if (tail == NULL)
    {
        std::cout << "The tail node is empty." << std::endl;
    }
    
    else
    {
        std::cout << "The tail node contains the integer: " << tail->data << std::endl;
    }
}

/********************************************************
 * * NodeList::displayList ()                              *
 * *********************************************************/

void NodeList::displayList ()
{
    struct intNode *holder;
    holder = head;
    
    if (head == NULL)
    {
        std::cout << "The list is currently empty." << std::endl;
    }
    
    else
    {
        std::cout << "Here is the current list from head to tail: " << std::endl;
        
        while (holder != NULL)
        {
            std::cout << holder->data << " : ";
            holder = holder->nextNode;
        }
    }
}

