/***************************************************************
 ** Author: Vannear Por
 ** Date: June 11, 2017
 ** Description: This is the header file for the Lightroom
 ** derived class which contains the member function prototypes
 ** of the Lightroom functions.
 ****************************************************************/

#ifndef LIGHTROOM_HPP
#define LIGHTROOM_HPP

#include "room.hpp"
#include <iostream>

class Lightroom: public Room
{
    public:
        Lightroom();
        ~Lightroom();
	Lightroom(std::string);
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




