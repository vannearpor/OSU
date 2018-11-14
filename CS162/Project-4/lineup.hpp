/************************************************************************
 * ** Author: Vannear Por
 * ** Date: May 25, 2017
 * ** Description: This file contains the Lineup class header file which
 * ** contains the structure for the Lineup Node List along with the 
 * ** Lineup class member variables and member functions which will
 * ** allow for manipulation of the Linked Structure containing the 
 * ** Lineups to be filled with objects from the Creature class.
 * *********************************************************************/

#ifndef LINEUP_HPP
#define LINEUP_HPP

#include "creature.hpp"
#include <iostream>

struct LineupNode
{
    Creature *data;
    LineupNode *prevNode;
    LineupNode *nextNode;
};

class Lineup
{
    private:
        LineupNode *head = NULL;
        LineupNode *tail = NULL;
    
    public:
        Lineup ();
        ~Lineup ();
        void addToTail (Creature *ctr);
	LineupNode* getHeadPointer ();
        Creature* getHead ();
	void deleteHead ();
        void headToTail ();
        void displayHead ();
        int headAttack ();
        void headDefend (int damage);
        bool headDefeated ();
        void displayLineup ();
};

#endif


