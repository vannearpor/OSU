/***************************************************************
 * ** Author: Vannear Por
 * ** Date: April 20, 2017
 * ** Description: This is a declaration file for the LoadedDie class
 * ** which inherits the Die class and all it's member variables and
 * ** member functions. It includes the member functions unique to
 * ** the LoadedDie class which will retreive the number of sides on
 * ** the loaded die and a function that will roll the die with a 
 * ** higher average output than a regular die.
 * ****************************************************************/

#include <iostream>
#include <cstdlib>
#include "die.hpp"
#include "loadedDie.hpp"

/***************************************************************
 *  * Default Constructor                                         *
 *   ***************************************************************/

LoadedDie::LoadedDie ()
{
}

/***************************************************************
 *  * One Parameter Constructor                                   *
 *   ***************************************************************/

LoadedDie::LoadedDie (int sides)
{
    setSides (sides);
}

/***************************************************************
 *  * LoadedDie::loadedRoll()                                     *
 *   ***************************************************************/

int LoadedDie::loadedRoll ()
{
    int rollResult = ( rand () % (dieSides - 1) + 1);
    
    if (rollResult < dieSides)
    {
        rollResult += 1;
    }
    
    return rollResult;
}

