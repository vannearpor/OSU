/***************************************************************
** Author: Vannear Por
** Date: May 13, 2017
** Description: This is the Barbarian class implementation file
** which defines the member functions of the prototypes that are
** contained in the Barbarian header file.
****************************************************************/

#include "barbarian.hpp"
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

Barbarian::Barbarian ()
{
    creatureType = "Barbarian";
    attackPoints = 0;
    defensePoints = 0;
    armorPoints = 0;
    strengthPoints = 12;
    defeat = false;
}

/***************************************************************
* Deconstructor ()                                             *
****************************************************************/

Barbarian::~Barbarian ()
{
}

/***************************************************************
* Barbarian::attack ()                                         *
****************************************************************/

int Barbarian::attack ()
{
    attackPoints = attackRoll ();
    std::cout << "Barbarian attacks with " << attackPoints << " attack points!" << std::endl;
    return attackPoints;
}

/***************************************************************
* Barbarian::defend ()                                         *
****************************************************************/

void Barbarian::defend (int d)
{
    int damage = d;
    defensePoints = defenseRoll ();
    
    if (damage == 100)
    {
        std::cout << "Oh no! The Barbarian has fallen under Medusa's glare and turns into stone!" << std::endl;
        std::cout << "The Barbarian is defeated." << std::endl;
        std::cout << "Strength Points: 0" << std::endl;
        defeat = true;
    }
    
    else
    {
        std::cout << "Barbarian defends with " << defensePoints << " defense points!" << std::endl;
        damage = damage - defensePoints;
    
        std::cout << "Barbarian protects itself with " << armorPoints << " armor." << std::endl;
        damage = damage - armorPoints;
    
        std::cout << "Barbarian took " << damage << " points in damage." << std::endl;
   
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
            std::cout << "Barbarian survives the attack!" << std::endl;
            std::cout << "Strength Points: " << strengthPoints << std::endl;
        }
        else if (strengthPoints <= 0)
        {
            std::cout << "Barbarian lost all strength points! Barbarian is defeated." << std::endl;
            std::cout << "Strength Points: 0" << std::endl;
            defeat = true;
        }
    }
}

/***************************************************************
* Barbarian::attackRoll ()                                     *
****************************************************************/

int Barbarian::attackRoll ()
{
    int atk = rand () % 6 + 1;
    atk = atk + (rand () % 6 + 1);
    return atk;
}

/***************************************************************
* Barbarian::defenseRoll ()                                    *
****************************************************************/

int Barbarian::defenseRoll ()
{
    int def = rand () % 6 + 1;
    def = def + (rand () % 6 + 1);
    return def;
}

/***************************************************************
* Barbarian::getType ()                                        *
****************************************************************/

std::string Barbarian::getType ()
{
    return creatureType;
}

/***************************************************************
* Barbarian::getArmor ()                                       *
****************************************************************/

int Barbarian::getArmor ()
{
    return armorPoints;
}

/***************************************************************
* Barbarian::getStrengthPoints ()                              *
****************************************************************/

int Barbarian::getStrengthPoints ()
{
    return strengthPoints;
}

/***************************************************************
* Barbarian::heal ()                                            *
****************************************************************/

void Barbarian::heal ()
{
    strengthPoints = (strengthPoints + (strengthPoints/2));
}

/***************************************************************
* Barbarian::defeated ()                                       *
****************************************************************/

bool Barbarian::defeated ()
{
    return defeat;
}



