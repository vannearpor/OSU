/***************************************************************
 * ** Author: Vannear Por
 * ** Date: May 13, 2017
 * ** Description: This is the BlueMen class header file derived
 * ** from the Creature base class. It contains the BlueMen
 * ** member function prototype that is specific to the BlueMen
 * ** class.
 * ****************************************************************/

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

#include "creature.hpp"

using std::string;

class Bluemen: public Creature
{
public:
    Bluemen ();
    ~Bluemen ();
    int attack ();
    void defend (int damage);
    int attackRoll ();
    int defenseRoll ();
    std::string getType ();
    int getArmor ();
    int getStrengthPoints ();
    bool defeated ();
};

#endif

