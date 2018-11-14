/********************************************************
 * ** Author: Vannear Por
 * ** Date: May 13, 2017
 * ** Description: This file contains the NodeList class
 * ** header file while will contain the member function 
 * ** prototypes for the NodeList class.
 * *********************************************************/

#ifndef NODELIST_HPP
#define NODELIST_HPP

#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

class NodeList
{
    private:
	struct intNode
	{
    		int data;
    		intNode *prevNode;
    		intNode *nextNode;
	};
		intNode *head = NULL;
		intNode *tail = NULL;	
 
    public:
        NodeList ();
        ~NodeList ();
        void addToHead ();
        void addToTail ();
        void deleteHead ();
        void deleteTail ();
        void reverseList ();
        void printHeadNode ();
        void printTailNode ();
        void displayList ();
};

#endif

