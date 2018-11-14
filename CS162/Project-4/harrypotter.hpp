/***************************************************************
 * ** Author: Vannear Por
 * ** Date: May 13, 2017
 * ** Description: This is the Harry Potter class header file derived
 * ** from the Creature base class. It contains the Harry Potter
 * ** member function prototype that is specific to the Harry Potter
 * ** class.
 * ****************************************************************/

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

#include "creature.hpp"

using std::string;

class Harrypotter: public Creature
{
public:
    Harrypotter ();
    ~Harrypotter ();
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



