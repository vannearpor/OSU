/****************************************************************
 * ** Author: Vannear Por
 * ** Date: April 20, 2017
 * ** Description: This is the header file for the "Die" class
 * ** which will contain member variables holding the data
 * ** of the number of sides a player's die will have. It
 * ** also contains member function prototypes which will retreive
 * ** the number of sides thru user input and a function
 * ** which will return a random number between 1 and the
 * ** number of sides it has.
 * *****************************************************************/

#include <iostream>
#ifndef DIE_HPP
#define DIE_HPP

class Die
{
    protected:
        int dieSides;
    
    public:
        Die ();
        Die (int);
        int getSides ();
        void setSides (int);
        int rollDie ();
};

#endif

