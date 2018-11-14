/***************************************************************
 * ** Author: Vannear Por
 * ** Date: May 13, 2017
 * ** Description: This is the Barbarian class header file derived
 * ** from the Creature base class. It contains the Barbarian
 * ** member function prototype that is specific to the Barbarian
 * ** class.
 * ****************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

#include "creature.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;

class Barbarian: public Creature
{
    public:
    Barbarian ();
    ~Barbarian ();
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
