/***************************************************************
** Author: Vannear Por
** Date: May 13, 2017
** Description: This is the Medusa class implementation file
** which defines the member functions of the prototypes that are
** contained in the Medusa header file.
****************************************************************/

#include "medusa.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using std::string;
using std::cout;
using std::cin;
using std::endl;

/***************************************************************
* Default Constructor ()                                       *
****************************************************************/

Medusa::Medusa ()
{
    creatureType = "Medusa";
    attackPoints = 0;
    defensePoints = 0;
    armorPoints = 3;
    strengthPoints = 8;
    defeat = false;
}

/***************************************************************
* Deconstructor ()                                            *
****************************************************************/

Medusa::~Medusa ()
{
}

/***************************************************************
* Medusa::attack ()                                           *
****************************************************************/

int Medusa::attack ()
{
    attackPoints = attackRoll ();
    if (attackPoints == 12)
    {
        std::cout << "Medusa reached full power! Opponent falls under Medusa's glare and turns into stone!" << std::endl;
        return attackPoints = 100;
    }
    else
    {
        std::cout << "Medusa attacks with " << attackPoints << " attack points!" << std::endl;
        return attackPoints;
    }
}

/***************************************************************
* Medusa::defend ()                                           *
****************************************************************/

void Medusa::defend (int d)
{
    int damage = d;
    defensePoints = defenseRoll ();
    
    if (damage == 100)
    {
        std::cout << "Oh no! The Medusa has fallen under her sister's glare and turns into stone!" << std::endl;
        std::cout << "The Medusa is defeated." << std::endl;
        std::cout << "Strength Points: 0" << std::endl;
        defeat = true;
    }
    
    else
    {
        std::cout << "Medusa defends with " << defensePoints << " defense points!" << std::endl;
        damage = damage - defensePoints;
    
        std::cout << "Medusa protects itself with " << armorPoints << " armor." << std::endl;
        damage = damage - armorPoints;
    
        std::cout << "Medusa took " << damage << " points in damage." << std::endl;
   
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
            std::cout << "Medusa survives the attack!" << std::endl;
            std::cout << "Strength Points: " << strengthPoints << std::endl;
        }
        else if (strengthPoints <= 0)
        {
            std::cout << "Medusa lost all strength points! Medusa is defeated." << std::endl;
            std::cout << "Strength Points: 0" << std::endl;
            defeat = true;
        }
    }
}

/***************************************************************
* Medusa::attackRoll ()                                       *
****************************************************************/

int Medusa::attackRoll ()
{
    int atk = rand () % 6 + 1;
    atk = atk + (rand () % 6 + 1);
    return atk;
}

/***************************************************************
* Medusa::defenseRoll ()                                      *
****************************************************************/

int Medusa::defenseRoll ()
{
    int def = rand () % 6 + 1;
    return def;
}

/***************************************************************
* Medusa::getType ()                                          *
****************************************************************/

std::string Medusa::getType ()
{
    return creatureType;
}

/***************************************************************
* Medusa::getArmor ()                                         *
****************************************************************/

int Medusa::getArmor ()
{
    return armorPoints;
}

/***************************************************************
* Medusa::getStrengthPoints ()                                *
****************************************************************/

int Medusa::getStrengthPoints ()
{
    return strengthPoints;
}

/***************************************************************
* Medusa::heal ()                                            *
****************************************************************/

void Medusa::heal ()
{
    strengthPoints = (strengthPoints + (strengthPoints/2));
}

/***************************************************************
* Medusa::defeated ()                                         *
****************************************************************/

bool Medusa::defeated ()
{
    return defeat;
}



