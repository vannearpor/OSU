/****************************************************************
 *  ** Author: Vannear Por
 *   ** Date: April 20, 2017
 *    ** Description: This is the declaration file for the "Die" class
 *     ** which will contain member variables holding the data
 *      ** of the number of sides a player's die will have. It
 *       ** contains member function which will retreive
 *        ** the number of sides thru user input and a function
 *         ** which will return a random number between 1 and the
 *          ** number of sides it has.
 *           *****************************************************************/

#include "die.hpp"
#include <cstdlib>

/***************************************************************
 *  * Default Constructor                                         *
 *   ***************************************************************/

Die::Die ()
{
}

/***************************************************************
 *  * One Parameter Constructor                                   *
 *   ***************************************************************/

Die::Die (int sides)
{
    setSides (sides);
}

/***************************************************************
 *  * Die::getSides ()                                            *
 *   ***************************************************************/

int Die::getSides ()
{
    return dieSides;
}

/***************************************************************
 *  * Die::setSides ()                                            *
 *   ***************************************************************/

void Die::setSides (int sides)
{
    dieSides = sides;
}

/***************************************************************
 *  * Die::rollDie ()                                             *
 *   ***************************************************************/

int Die::rollDie ()
{
    int rollResult = ( rand () % (dieSides - 1) +1);
    
    return rollResult;
}


