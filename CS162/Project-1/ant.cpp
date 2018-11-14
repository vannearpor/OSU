/***********************************************************
 * ** Author: Vannear Por
 * ** Date: April 15, 2017
 * ** Description: This program contains the member function
 * ** definition for the Ant class. The member functions will
 * ** determine the Ant's direction, current and new color of 
 * ** the matrix cell, current and new row, and current and new
 * ** column if the cell the Ant is occupying.
 * ************************************************************/

#include <iostream>
#include "ant.hpp"

/***********************************************************
 *  * Default Contructor                                      *
 *   ***********************************************************/

Ant::Ant()
{
}

/***********************************************************
 *  * Ant::Ant Two Parameter Constructor                      *
 *   ***********************************************************/

Ant::Ant(int startRow, int startColumn)
{
    setDirection(up);
    setColor(' ');
    setCurrentRow(startRow);
    setCurrentColumn(startColumn);
    setNewRow(startRow);
    setNewColumn(startColumn);
}

/************************************************************
 *  * Ant::getColor ():                                        *
 *   * This function returns the current color.                 *
 *    ************************************************************/

char Ant::getColor()
{
    return color;
}

/************************************************************
 *  * Ant::setColor ():                                        *
 *   * This function takes a character as a parameter and uses  *
 *    * it to set the current color.                             *
 *     ************************************************************/

void Ant::setColor(char newColor)
{
    color = newColor;
}

/************************************************************
 *  * Ant::getDirection ():                                    *
 *   * This function returns the current direction the Ant is   *
 *    * facing at the time of call.                              *
 *     ************************************************************/

Direction Ant::getDirection()
{
    return direct;
}

/************************************************************
 *  * Ant::setDirection ():                                    *
 *   * This function sets the new Direction that the Ant is     *
 *    * facing.                                                  *
 *     ************************************************************/

void Ant::setDirection(Direction newDirection)
{
    direct = newDirection;
}

/************************************************************
 *  * Ant::getCurrentRow ():                                   *
 *   * This function takes a returns the current row of the     *
 *    * matrix that the Ant is in.                               *
 *     ************************************************************/

int Ant::getCurrentRow()
{
    return currentRow;
}

/************************************************************
 *  * Ant::setCurrentRow ():                                   *
 *   * This function takes an integer as a parameter and uses   *
 *    * it to set the current row of the Ant.                    *
 *     ************************************************************/

void Ant::setCurrentRow(int cRow)
{
    currentRow = cRow;
}

/************************************************************
 *  * Ant::getCurrentColumn ():                                *
 *   * This function returns an integer that represents the     *
 *    * current column the Ant is in.                            *
 *     ************************************************************/

int Ant::getCurrentColumn()
{
    return currentColumn;
}

/************************************************************
 *  * Ant::setCurrentColumn ():                                *
 *   * This function takes an integer as a parameter and uses   *
 *    * it to set the current column of the Ant.                 *
 *     ************************************************************/

void Ant::setCurrentColumn(int cColumn)
{
    currentColumn = cColumn;
}

/************************************************************
 *  * Ant::getNewRow ():                                       *
 *   * This function returns an integer that represents the new *
 *    * row for the Ant.                                         *
 *     ************************************************************/

int Ant::getNewRow()
{
    return newRow;
}

/************************************************************
 *  * Ant::setNewRow ():                                       *
 *   * This function takes an integer as a parameter and uses   *
 *    * it to set the new Row.                                   *
 *     ************************************************************/

void Ant::setNewRow(int nRow)
{
    newRow = nRow;
}

/************************************************************
 *  * Ant::getNewColumn ():                                    *
 *   * This function returns an integer that represents the new *
 *    * column for the Ant.                                      *
 *     ************************************************************/

int Ant::getNewColumn()
{
    return newColumn;
}

/************************************************************
 *  * Ant::setNewColumn ():                                    *
 *   * This function takes an integer as a parameter and uses   *
 *    * it to set the new Column for the Ant.                    *
 *     ************************************************************/

void Ant::setNewColumn(int nColumn)
{
    newColumn = nColumn;
}
