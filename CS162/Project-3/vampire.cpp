/***************************************************************
 * ** Author: Vannear Por
 * ** Date: May 13, 2017
 * ** Description: This is the Vampire class implementation file
 * ** which defines the member functions of the prototypes that are
 * ** contained in the Vampire header file.
 * ****************************************************************/

#include "vampire.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using std::string;
using std::cout;
using std::cin;
using std::endl;

/***************************************************************
 *  * Default Constructor ()                                       *
 *   ****************************************************************/

Vampire::Vampire ()
{
    creatureType = "Vampire";
    attackPoints = 0;
    defensePoints = 0;
    armorPoints = 1;
    strengthPoints = 12;
    defeat = false;
}

/***************************************************************
 *  * Deconstructor ()                                            *
 *   ****************************************************************/

Vampire::~Vampire ()
{
}

/***************************************************************
 *  * Vampire::attack ()                                          *
 *   ****************************************************************/

int Vampire::attack ()
{
    attackPoints = attackRoll ();
    std::cout << "Vampire attacks with " << attackPoints << " attack points!" << std::endl;
    return attackPoints;
}

/***************************************************************
 *  * Vampire::defend ()                                          *
 *   ****************************************************************/

void Vampire::defend (int d)
{
    int damage = d;
    defensePoints = defenseRoll ();
    
    int charmChance = rand () % 2 + 1;
    
    if ((damage == 100) && (charmChance == 1))
    {
        std::cout << "The Vampire stares at Medusa in the eyes, Medusa is charmed." << std::endl;
        std::cout << "Medusa does not attack." << std::endl;
        std::cout << "Strength Points: " << strengthPoints << std::endl;
        defeat = false;
    }
    
    else if ((damage == 100) && (charmChance != 1))
    {
        std::cout << "Oh no! The Vampire has fallen under Medusa's glare and turns into stone!" << std::endl;
        std::cout << "The Vampire is defeated." << std::endl;
        std::cout << "Strength Points: 0" << std::endl;
        strengthPoints = 0;
        defeat = true;
    }
    
    else if ((damage != 100) && (charmChance == 1))
    {
        std::cout << "Vampire uses special ability Charm! Opponent does not attack." << std::endl;
        std::cout << "Strength Points: " << strengthPoints << std::endl;
        damage = 0;
    }
    
    else
    {
        std::cout << "Vampire defends with " << defensePoints << " defense points!" << std::endl;
        damage = damage - defensePoints;
    
        std::cout << "Vampire protects itself with " << armorPoints << " armor." << std::endl;
        damage = damage - armorPoints;
    
        std::cout << "Vampire took " << damage << " points in damage." << std::endl;
   
        if (damage > 0)
        {
         strengthPoints = strengthPoints - damage;
        }
        else
        {
         strengthPoints = strengthPoints;
        }
 
        if (strengthPoints > 0)
        {
            std::cout << "Vampire survives the attack!" << std::endl;
            std::cout << "Strength Points: " << strengthPoints << std::endl;
        }
        else if (strengthPoints <= 0)
        {
            std::cout << "Vampire lost all strength points! Vampire is defeated." << std::endl;
            std::cout << "Strength Points: 0" << std::endl;
            defeat = true;
        }
    }
}

/***************************************************************
 *  * Vampire::attackRoll ()                                      *
 *   ****************************************************************/

int Vampire::attackRoll ()
{
    int atk = rand () % 12 + 1;
    return atk;
}

/***************************************************************
 *  * Vampire::defenseRoll ()                                     *
 *   ****************************************************************/

int Vampire::defenseRoll ()
{
    int def = rand () % 6 + 1;
    return def;
}

/***************************************************************
 *  * Vampire::getType ()                                         *
 *   ****************************************************************/

std::string Vampire::getType ()
{
    return creatureType;
}

/***************************************************************
 *  * Vampire::getArmor ()                                        *
 *   ****************************************************************/

int Vampire::getArmor ()
{
    return armorPoints;
}

/***************************************************************
 *  * Vampire::getStrengthPoints ()                               *
 *   ****************************************************************/

int Vampire::getStrengthPoints ()
{
    return strengthPoints;
}

/***************************************************************
 *  * Vampire::defeated ()                                        *
 *   ****************************************************************/

bool Vampire::defeated ()
{
    return defeat;
}

