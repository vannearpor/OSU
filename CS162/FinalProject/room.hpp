/********************************************************
 ** Author: Vannear Por
 ** Date: June 11, 2017
 ** Description: This is the header file for the Room
 ** abstract class which contains the member function prototypes
 ** of the room derived class functions.
 *********************************************************/

#ifndef ROOM_HPP
#define ROOM_HPP

#include <iostream>

using std::string;

class Room
{
    protected:
        std::string roomName;
        bool roomFinish = false;
        Room* northRoom = NULL;
        Room* southRoom = NULL;
        Room* westRoom = NULL;
        Room* eastRoom = NULL;
    
    public:
        Room();
        ~Room();
        Room(std::string);
        Room* getNorth();
        Room* getSouth();
        Room* getWest();
        Room* getEast();
        Room* moveChar(Room* current, int dir);
        void setNorth(Room *next);
        void setSouth(Room *next);
        void setWest(Room *next);
        void setEast(Room *next);
        virtual void light (bool fl) = 0;
	virtual bool darkroom1(bool, bool) = 0;
 	virtual bool darkroom2(bool) = 0;
	virtual bool darkroom3(bool, bool) = 0;
	virtual void lightroom1() = 0;
	virtual bool lightroom2() = 0;
	virtual void lightroom3() = 0;
	virtual bool lightroom4(bool) = 0;
	virtual bool escaperoom1(bool) = 0; 
};

#endif

