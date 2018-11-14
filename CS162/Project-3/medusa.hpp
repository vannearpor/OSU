/***************************************************************
 * ** Author: Vannear Por
 * ** Date: May 13, 2017
 * ** Description: This is the Medusa class header file derived
 * ** from the Creature base class. It contains the Medusa
 * ** member function prototype that is specific to the Medusa
 * ** class.
 * ****************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

#include "creature.hpp"

using std::string;

class Medusa: public Creature
{
public:
    Medusa ();
    ~Medusa ();
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

