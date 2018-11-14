/*****************************************************************
 ** Author: Vannear Por
 ** Date: June 11, 2017
 ** Description: This is the implementation file for the Room
 ** abstract class which will contain the shared common function 
 ** definitions for the derived classes.
 ****************************************************************/

#include "room.hpp"
#include <iostream>

using std::string;

/***************************************************************
 * * Default Constructor ()                                       *
 * ****************************************************************/

Room::Room()
{
}

/***************************************************************
 * * Deconstructor ()                                             *
 * ****************************************************************/

Room::~Room()
{
}

/***************************************************************
 * * Room::Room()                                                 *
 * ****************************************************************/

Room::Room(std::string name)
{
    roomName = name;
}

/***************************************************************
 * * Room::getNorth()                                             *
 * ****************************************************************/

Room* Room::getNorth()
{
    return northRoom;
}

/***************************************************************
 * * Room::getSouth()                                             *
 * ****************************************************************/

Room* Room::getSouth()
{
    return southRoom;
}

/***************************************************************
 * * Room::getWest()                                              *
 * ****************************************************************/

Room* Room::getWest()
{
    return westRoom;
}

/***************************************************************
 * * Room::getEast()                                              *
 * ****************************************************************/

Room* Room::getEast()
{
    return eastRoom;
}

/***************************************************************
 * * Room::moveChar()                                             *
 * ****************************************************************/

Room* Room::moveChar(Room* current, int dir)
{
    Room* next;
    
    switch (dir)
    {
        case 1:
        {
            next = current->getNorth();
            break;
        }
            
        case 2:
        {
            next = current->getWest();
            break;
        }
            
        case 3:
        {
            next = current->getSouth();
            break;
        }
            
        case 4:
        {
            next = current->getEast();
            break;
        }
    }
    
    if (next == NULL)
    {
        std::cout << "There is not door there, you cannot move in that direction." << std::endl;
        
        return current;
    }
    
    else
    {
        std::cout << "You open the door and walk into the next room..." << std::endl;
        std::cout << "You're now in room " << next->roomName << "." << std::endl;
        
        return next;
    }
}

/***************************************************************
 * * Room::setNorth()                                             *
 * ****************************************************************/

void Room::setNorth(Room* next)
{
    northRoom = next;
}

/***************************************************************
 * * Room::setSouth()                                             *
 * ****************************************************************/

void Room::setSouth(Room* next)
{
    southRoom = next;
}

/***************************************************************
 * * Room::setWest()                                              *
 * ****************************************************************/

void Room::setWest(Room* next)
{
    westRoom = next;
}

/***************************************************************
 * * Room::setEast()                                              *
 * ****************************************************************/

void Room::setEast(Room* next)
{
    eastRoom = next;
}



