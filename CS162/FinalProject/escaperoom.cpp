/***************************************************************
 ** Author: Vannear Por
 ** Date: June 11, 2017
 ** Description: This is the implementation file for the Escaperoom
 ** derived class which will contain the function definitions
 ** for the class which will display the characteristics of each
 ** escape room.
 ****************************************************************/

#include "room.hpp"
#include "escaperoom.hpp"
#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

/***************************************************************
 * * Default Constructor ()                                       *
 * ****************************************************************/

Escaperoom::Escaperoom()
{
    roomFinish = false;
    northRoom = NULL;
    southRoom = NULL;
    westRoom = NULL;
    eastRoom = NULL;
}

/***************************************************************
 * * Deconstructor ()                                             *
 * ****************************************************************/

Escaperoom::~Escaperoom()
{
}

/***************************************************************
 * * Escaperoom::Escaperoom()                                                 *
 * ****************************************************************/

Escaperoom::Escaperoom(std::string name)
{
    roomName = name;
}


/***************************************************************
 * * Escaperoom::light()                                          *
 * ****************************************************************/

void Escaperoom::light(bool fl)
{
    std::cout << "The room is very dim, the only light is coming from the escape door..." << std::endl;
}

/***************************************************************
 * * Escaperoom::escaperoom1()                                    *
 * ****************************************************************/

bool Escaperoom::escaperoom1(bool key)
{
    if (key == false)
    {
        std::cout << "You look at the escape door, you turn the knob... nothing." << std::endl;
        std::cout << "You have to find a way out!" << std::endl;
        
        return false;
    }
    
    else if (key == true)
    {
        std::cout << "You run towards the door! You grab the key from your bag and fumble it in your hands!" << std::endl;
        std::cout << "You insert the key and turn the knob... IT OPENS!" << std::endl;
        std::cout << "You open the door..." << std::endl;
        
        return true;
    }
}

/***************************************************************
 *  * Override Pure Virtual Functions                             *
 *   ****************************************************************/

void Escaperoom::lightroom1()
{
}

bool Escaperoom::lightroom2()
{
}

void Escaperoom::lightroom3()
{
}

bool Escaperoom::lightroom4(bool a)
{
}

bool Escaperoom::darkroom1(bool a, bool b)
{
}

bool Escaperoom::darkroom2(bool a)
{
}

bool Escaperoom::darkroom3(bool a, bool b)
{
}

