/***************************************************************
** Author: Vannear Por
** Date: June 11, 2017
** Description: This is the header file for the Darkroom
** derived class which contains the member function prototypes
** of the Darkroom functions.
****************************************************************/

#ifndef DARKROOM_HPP
#define DARKROOM_HPP

#include "room.hpp"
#include <iostream>

class Darkroom: public Room
{
    public:
        Darkroom();
        ~Darkroom();
	Darkroom(std::string);
        void light(bool fl);
        void lightroom1();
        bool lightroom2();
        void lightroom3();
        bool lightroom4(bool);
        bool darkroom1(bool, bool);
        bool darkroom2(bool);
        bool darkroom3(bool, bool);
        bool escaperoom1(bool);
};

#endif
