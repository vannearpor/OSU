/*****************************************************
 * ** Author: Vannear Por
 * ** Date: May 13, 2017
 * ** Description: This is the Vampire class header file derived
 * ** from the Creature base class. It contains the Vampire
 * ** member function prototype that is specific to the Vampire
 * ** class.
 * ****************************************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

#include "creature.hpp"

using std::string;

class Vampire: public Creature
{
public:
    Vampire ();
    ~Vampire ();
    int attack ();
    void defend (int damage);
    int attackRoll ();
    int defenseRoll ();
    std::string getType ();
    int getArmor ();
    int getStrengthPoints ();
    void heal ();
    bool defeated ();
};

#endif


