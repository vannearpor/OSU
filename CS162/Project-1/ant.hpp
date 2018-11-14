/***************************************************************
 * ** Author: Vannear Por
 * ** Date: April 15, 2017
 * ** Description: This program contains the Ant class header file that
 * ** contain the function prototype for the Ant functions that will
 * ** set and get the Ant's current row and column, new row and column,
 * ** current color, and new color. It will also return the direction
 * ** that the Ant is facing.
 * *****************************************************************/

#include <iostream>
#ifndef ANT_HPP
#define ANT_HPP

enum Direction { down, up, right, left };

class Ant
{
    private:
        Direction direct;
        char color;
        int currentRow, currentColumn, newRow, newColumn;
    
    public:
        Ant();
        Ant(int startRow, int startColumn);
        char getColor();
        void setColor(char newColor);
        Direction getDirection();
        void setDirection(Direction newDirection);
        int getCurrentRow();
        void setCurrentRow(int cRow);
        int getCurrentColumn();
        void setCurrentColumn(int cColumn);
        int getNewRow();
        void setNewRow(int nRow);
        int getNewColumn();
        void setNewColumn(int nColumn);
};

#endif

