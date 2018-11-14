
/******************************************************
 * ** Author: Vannear Por
 * ** Date: March 8, 2017
 * ** Description: This is the Board "header" file which
 * ** contains the array that creates the game board and
 * ** member functions involving the board.
 * ******************************************************/
 
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

#ifndef BOARD_HPP
#define BOARD_HPP

enum BoardGameStatus {X_WON, O_WON, DRAW, UNFINISHED};

class Board
{
    private:
        char gameBoard [3][3];          //Stores player move location
    
    public:
        Board ();                       //Default Constructor
        bool makeMove (int, int, int);   //Determines occupation
        BoardGameStatus gameState ();   //Returns game state
        void print ();                  //Displays cucrent board
    
};

#endif

