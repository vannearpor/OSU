/**************************************************
 * ** Author: Vannear Por
 * ** Date: March 8, 2017
 * ** Description: This is the TicTacToe header file. This
 * ** file contains the member variables and member functions
 * ** for the TicTacToe class which runs the gameplay.
 * ***************************************************/
 
#include <iostream>
#include <cmath>
#include <string>
#include "Board.hpp"
using namespace std;

#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

class TicTacToe
{
    private:
        Board playBoard;        //Board Object
        int turnPlayer;         //Which Player's turn
    
    public:
        TicTacToe (char);       //Single Parameter Contructor
        void play();            //Start Function
};

#endif
