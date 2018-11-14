/********************************************************************
 * ** Author: Vannear Por
 * ** Date: May 25, 2017
 * ** Description: This file contains the Loser class header file which
 * ** will contain the Linked Structure that holds the losers of the
 * ** tournament. This file will contain the Loser class member variables
 * ** and member function prototypes which will allow for manipulation
 * ** of the Loser Linked Structure.
 * *********************************************************************/

#ifndef LOSER_HPP
#define LOSER_HPP

#include "creature.hpp"
#include <iostream>

struct LoserNode
{
    Creature *data;
    LoserNode *prevNode;
    LoserNode *nextNode;
};

class Loser
{
    private:
        LoserNode *head = NULL;
        LoserNode *tail = NULL;
    
    public:
        Loser ();
        ~Loser ();
        void addToHead (Creature *ctr);
        void displayLosers ();
};

#endif

