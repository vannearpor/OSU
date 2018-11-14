/***************************************************************
 * ** Author: Vannear Por
 * ** Date: May 13, 2017
 * ** Description: This is the Creature abstract base class file which
 * ** will serve as the base class for other creature sub-classes. This
 * ** header file will contain the member variables for all creatures
 * ** that represent their attack, defense, amor, and strength point
 * ** data. It will also contain member functions that will be
 * ** more specifically defined in the creature sub-classes.
 * ****************************************************************/

#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using std::string;

class Creature
{
    protected:
        std::string creatureType;
        int attackPoints;
        int defensePoints;
        int armorPoints;
        int strengthPoints;
        bool defeat;
    
    public:
        virtual int attack () = 0;
        virtual void defend (int damage) = 0;
        virtual int attackRoll () = 0;
        virtual int defenseRoll () = 0;
        virtual std::string getType () = 0;
        virtual int getArmor () = 0;
        virtual int getStrengthPoints () = 0;
        virtual bool defeated () = 0;
};

#endif

