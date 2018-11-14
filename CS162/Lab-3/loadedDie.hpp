/***************************************************************
 * ** Author: Vannear Por
 * ** Date: April 20, 2017
 * ** Description: This is the header file for the LoadedDie class
 * ** which inherits the Die class and all it's member variables and
 * ** member functions. It also includes it's own member function
 * ** where it's average output is higher than  regular die.
 * ****************************************************************/

#include <iostream>
#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP
#include "die.hpp"

class LoadedDie: public Die
{
    public:
        LoadedDie ();
        LoadedDie (int);
        int loadedRoll ();
};

#endif

