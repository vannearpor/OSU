/***
 * Author: Vannear Por
** Date: April 8, 2017
** Description: This program contains the determinant functions 
** which will receive a matrix and return the determinant value.
******************************************************************/

#include "determinant.hpp"
#include <iostream>

/*****************************************************************
 *  * Default Constructor                                           *
 *   *****************************************************************/

Determinant::Determinant ()
{
}

/*****************************************************************
 *  * Determinant::getDeterminant                                   *
 *   * This function will receive the values in a matrix and return  *
 *    * the determinant of the values.                                *
 *     *****************************************************************/

int Determinant::getDeterminant (int* twoDArray[], int size)
{
    int determinant;
    
    if (size == 2)
    {
        determinant = (twoDArray[0][0] * twoDArray[1][1]) - (twoDArray[0][1] * twoDArray[1][0]);
    }
    
    else if (size == 3)
    {
        int num1, num2, num3;
        
        num1 = (twoDArray[0][0]) * ((twoDArray[1][1] * twoDArray[2][2]) - (twoDArray[1][2] * twoDArray[2][1]));
        num2 = (twoDArray[0][1]) * ((twoDArray[1][0] * twoDArray[2][2]) - (twoDArray[2][0] * twoDArray[1][2]));
        num3 = (twoDArray[0][2]) * ((twoDArray[1][0] * twoDArray[2][1]) - (twoDArray[2][0] * twoDArray[1][1]));
        
        determinant = num1 - num2 + num3;
    }
    
    return determinant;
}
