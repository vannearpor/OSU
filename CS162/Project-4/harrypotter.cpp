/***************************************************************
** Author: Vannear Por
** Date: May 13, 2017
** Description: This is the Harry Potter class implementation file
** which defines the member functions of the prototypes that are
** contained in the Harry Potter header file.
****************************************************************/

#include "harrypotter.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using std::string;
using std::cout;
using std::cin;
using std::endl;

/***************************************************************
* Default Constructor ()                                      *
****************************************************************/

Harrypotter::Harrypotter ()
{
    creatureType = "Harry Potter";
    attackPoints = 0;
    defensePoints = 0;
    armorPoints = 0;
    strengthPoints = 10;
    defeat = false;
}

/***************************************************************
* Deconstructor ()                                            *
****************************************************************/

Harrypotter::~Harrypotter ()
{
}

/***************************************************************
* Harrypotter::attack ()                                      *
****************************************************************/

int Harrypotter::attack ()
{
    attackPoints = attackRoll ();
    std::cout << "Harry Potter attacks with " << attackPoints << " attack points!" << std::endl;
    return attackPoints;
}

/***************************************************************
 * Harrypotter::defend ()                                      *
****************************************************************/

void Harrypotter::defend (int d)
{
    int damage = d;
    bool hogwarts = true;
    defensePoints = defenseRoll ();
    
    if (damage == 100)
    {
        std::cout << "Oh no! Harry Potter has fallen under Medusa's glare and turns into stone!" << std::endl;
        std::cout << "Harry Potter is defeated." << std::endl;
        std::cout << "Strength Points: 0" << std::endl;
        strengthPoints = 0;
        
        if (hogwarts == true)
        {
            std::cout << "Wait... There's a light coming from the Harry Potter stone!" << std::endl;
            std::cout << "Harry Potter's special ability HOGWARTS activates! The stone bursts!" << std::endl;
            std::cout << "Harry Potter rises from the rubble and is revived with 20 strength points!" << std::endl;
            strengthPoints = 20;
            hogwarts = false;
            defeat = false;
        }
        else if (hogwarts == false)
        {
            std::cout << "Harry Potter attempts special ability HOGWARTS. FAILS." << std::endl;
            defeat = true;
        }
    }
    
    else
    {
        std::cout << "Harry Potter defends with " << defensePoints << " defense points!" << std::endl;
        damage = damage - defensePoints;
    
        std::cout << "Harry Potter protects itself with " << armorPoints << " armor." << std::endl;
        damage = damage - armorPoints;
    
        std::cout << "Harry Potter took " << damage << " points in damage." << std::endl;
   
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
            std::cout << "Harry Potter survives the attack!" << std::endl;
            std::cout << "Strength Points: " << strengthPoints << std::endl;
        }
        else if ((strengthPoints <= 0) && (hogwarts == true))
        {
            std::cout << "Harry Potter lost all strength points! Harry Potter is defeated." << std::endl;
            std::cout << "Strength Points: 0" << std::endl;
            std::cout << "Harry Potter's special ability HOGWARTS activates. Harry Potter is revived with 20 strength points!" << std::endl;
            strengthPoints = 20;
            std::cout << "Strength Points: 20" << std::endl;
            defeat = false;
            hogwarts = false;
        }
        else if ((strengthPoints <= 0) && (hogwarts == false))
        {
            std::cout << "Harry Potter lost all strength points! Harry Potter is defeated." << std::endl;
            std::cout << "Harry Potter attempts special ability HOGWARTS. FAILS." << std::endl;
            std::cout << "Strength Points: 0" << std::endl;
            defeat = true;
        }
    }
}

/***************************************************************
* Harrypotter::attackRoll ()                                  *
****************************************************************/

int Harrypotter::attackRoll ()
{
    int atk = rand () % 6 + 1;
    atk = atk + (rand () % 6 + 1);
    return atk;
}

/***************************************************************
* Harrypotter::defenseRoll ()                                 *
****************************************************************/

int Harrypotter::defenseRoll ()
{
    int def = rand () % 6 + 1;
    def = def + (rand () % 6 + 1);
    return def;
}

/***************************************************************
* Harrypotter::getType ()                                     *
****************************************************************/

std::string Harrypotter::getType ()
{
    return creatureType;
}

/***************************************************************
* Harrypotter::getArmor ()                                    *
****************************************************************/

int Harrypotter::getArmor ()
{
    return armorPoints;
}

/***************************************************************
* Harrypotter::getStrengthPoints ()                           *
****************************************************************/

int Harrypotter::getStrengthPoints ()
{
    return strengthPoints;
}


/***************************************************************
* Harrypotter::heal ()                                            *
****************************************************************/

void Harrypotter::heal ()
{
    strengthPoints = (strengthPoints + (strengthPoints/2));
}

/***************************************************************
* Harrypotter::defeated ()                                     *
****************************************************************/

bool Harrypotter::defeated ()
{
    return defeat;
}



