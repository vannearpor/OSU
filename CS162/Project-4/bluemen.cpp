/***************************************************************
** Author: Vannear Por
** Date: May 13, 2017
** Description: This is the BlueMen class implementation file
** which defines the member functions of the prototypes that are
** contained in the BlueMen header file.
****************************************************************/

#include "bluemen.hpp"
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

Bluemen::Bluemen ()
{
    creatureType = "Blue Men";
    attackPoints = 0;
    defensePoints = 0;
    armorPoints = 3;
    strengthPoints = 12;
    defeat = false;
}

/***************************************************************
* Deconstructor ()                                             *
****************************************************************/

Bluemen::~Bluemen ()
{
}

/***************************************************************
* Bluemen::attack ()                                         *
****************************************************************/

int Bluemen::attack ()
{
    attackPoints = attackRoll ();
    std::cout << "Blue Men attacks with " << attackPoints << " attack points!" << std::endl;
    return attackPoints;
}

/***************************************************************
* Bluemen::defend ()                                         *
****************************************************************/

void Bluemen::defend (int d)
{
    int damage = d;
    defensePoints = defenseRoll ();
    
    if (damage == 100)
    {
        std::cout << "Oh no! The Blue Men have fallen under Medusa's glare and turn into stone!" << std::endl;
        std::cout << "The Blue Men are defeated." << std::endl;
        std::cout << "Strength Points: 0" << std::endl;
        defeat = true;
    }
    
    else
    {
        std::cout << "Blue Men defends with " << defensePoints << " defense points!" << std::endl;
        damage = damage - defensePoints;
    
        std::cout << "Blue Men protects itself with " << armorPoints << " armor." << std::endl;
        damage = damage - armorPoints;
    
        std::cout << "Blue Men took " << damage << " points in damage." << std::endl;
       
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
            std::cout << "Blue Men survives the attack!" << std::endl;
            std::cout << "Strength Points: " << strengthPoints << std::endl;
        }
        else if (strengthPoints <= 0)
        {
            std::cout << "Blue Men lost all strength points! Blue Men is defeated." << std::endl;
            std::cout << "Strength Points: 0" << std::endl;
            defeat = true;
        }
    }
}

/***************************************************************
* Bluemen::attackRoll ()                                     *
****************************************************************/

int Bluemen::attackRoll ()
{
    int atk = rand () % 10 + 1;
    atk = atk + (rand () % 10 + 1);
    return atk;
}

/***************************************************************
* Bluemen::defenseRoll ()                                    *
****************************************************************/

int Bluemen::defenseRoll ()
{
    if ((strengthPoints <= 12) && (strengthPoints >=9))
    {
        std::cout << "*Mob: The Blue Men are all standing strong! Three defense dice used." << std::endl;
        int def = rand () % 6 + 1;
        def = def + (rand () % 6 + 1);
        def = def + (rand () % 6 + 1);
        return def;
    }
    
    else if ((strengthPoints <= 8) && (strengthPoints >= 5))
    {
        std::cout << "*Mob: One of the Blue Men has fallen! Lost One defense die." << std::endl;
        int def = rand () % 6 + 1;
        def = def + (rand () % 6 + 1);
        return def;
    }
        
    else if ((strengthPoints <= 4) && (strengthPoints >= 0))
    {
        std::cout << "*Mob: Two of the Blue Men has fallen! Lost Two defense die." << std::endl;
        int def = rand () % 6 + 1;
        return def;
    }
}

/***************************************************************
* Bluemen::getType ()                                        *
****************************************************************/

std::string Bluemen::getType ()
{
    return creatureType;
}

/***************************************************************
* Bluemen::getArmor ()                                       *
****************************************************************/

int Bluemen::getArmor ()
{
    return armorPoints;
}

/***************************************************************
* Bluemen::getStrengthPoints ()                              *
****************************************************************/

int Bluemen::getStrengthPoints ()
{
    return strengthPoints;
}

/***************************************************************
* Bluemen::heal ()                                            *
****************************************************************/

void Bluemen::heal ()
{
    strengthPoints = (strengthPoints + (strengthPoints/2));
}


/***************************************************************
* Bluemen::defeated ()                                       *
****************************************************************/

bool Bluemen::defeated ()
{
    return defeat;
}



