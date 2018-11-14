/*****************************************************
 * ** Author: Vannear Por
 * ** Date: May 20, 2017
 * ** Description: This is the Queue class header file
 * ** which will contain the class member variables and
 * ** member function prototypes for the Queue class.
 * ******************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>

struct QueueNode
{
    int value;
    QueueNode *prevNode;
    QueueNode *nextNode;
};

class Queue
{
    private:
        QueueNode *front = NULL;
        QueueNode *back = NULL;
    public:
        Queue ();
        ~Queue ();
        void addBack (int val);
        int getFront ();
        void removeFront ();
        void displayNodes ();
};

#endif
