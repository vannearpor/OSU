/********************************************************
 ** Author: Vannear Por
 ** Date: March 8, 2017
 ** Description: This program contains the member function definitions
 ** for the Board class. It contains the definitions for functions that
 ** will create the game board array, determine if moves are valid,
 ** determine the state of the current game, and display the board.
 *********************************************************/
 
#include <iostream>
#include <cmath>
#include <string>
#include "Board.hpp"
using namespace std;

/**********************************************************
 * Board::Board
 * Default Constructor: Creates and initializes the array.
 **********************************************************/

Board::Board ()
{
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            gameBoard[i][j] = '.';     //Initialize Array
        }
    }
}

/*********************************************************
 * Board::makeMove
 ********************************************************/

bool Board::makeMove (int xCoord, int yCoord, int playerNumber)
{
    
    if (gameBoard [xCoord][yCoord] != 'X' && gameBoard[xCoord][yCoord] != 'O')  //Not Occupied
    {
        if (playerNumber == 1)
        {
            gameBoard [xCoord][yCoord] = 'X';
            return true;
        }
        else if (playerNumber == 2)
        {
            gameBoard [xCoord][yCoord] = 'O';
            return true;
        }
    }
    else                            //Occupied
    {
        return false;
    }
}

/**********************************************************
 *Board::gameState
 *********************************************************/

BoardGameStatus Board::gameState ()
{
    BoardGameStatus currentState = UNFINISHED;
    
    //Determine if there is a winner.
    if ((gameBoard[0][0] == gameBoard[0][1] && gameBoard[0][1] == gameBoard[0][2]) ||
        (gameBoard[1][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[1][2]) ||
        (gameBoard[2][0] == gameBoard[2][1] && gameBoard[2][1] == gameBoard[2][2]) ||
        (gameBoard[0][0] == gameBoard[1][0] && gameBoard[1][0] == gameBoard[2][0]) ||
        (gameBoard[0][1] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][1]) ||
        (gameBoard[0][2] == gameBoard[1][2] && gameBoard[1][2] == gameBoard[2][2]) ||
        (gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2]) ||
        (gameBoard[0][2] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][0]))
    {
  
        if ((gameBoard[0][0]=='X' && gameBoard[0][1]=='X' && gameBoard[0][2]=='X') ||
            (gameBoard[1][0]=='X' && gameBoard[1][1]=='X' && gameBoard[1][2]=='X') ||
            (gameBoard[2][0]=='X' && gameBoard[2][1]=='X' && gameBoard[2][2]=='X') ||
            (gameBoard[0][0]=='X' && gameBoard[1][0]=='X' && gameBoard[2][0]=='X') ||
            (gameBoard[0][1]=='X' && gameBoard[1][1]=='X' && gameBoard[2][1]=='X') ||
            (gameBoard[0][2]=='X' && gameBoard[1][2]=='X' && gameBoard[2][2]=='X') ||
            (gameBoard[0][0]=='X' && gameBoard[1][1]=='X' && gameBoard[2][2]=='X') ||
            (gameBoard[0][2]=='X' && gameBoard[1][1]=='X' && gameBoard[2][0]=='X'))
        {
            currentState = X_WON;
        }

        else if ((gameBoard[0][0]=='O' && gameBoard[0][1]=='O' && gameBoard[0][2]=='O') ||
                 (gameBoard[1][0]=='O' && gameBoard[1][1]=='O' && gameBoard[1][2]=='O') ||
                 (gameBoard[2][0]=='O' && gameBoard[2][1]=='O' && gameBoard[2][2]=='O') ||
                 (gameBoard[0][0]=='O' && gameBoard[1][0]=='O' && gameBoard[2][0]=='O') ||
                 (gameBoard[0][1]=='O' && gameBoard[1][1]=='O' && gameBoard[2][1]=='O') ||
                 (gameBoard[0][2]=='O' && gameBoard[1][2]=='O' && gameBoard[2][2]=='O') ||
                 (gameBoard[0][0]=='O' && gameBoard[1][1]=='O' && gameBoard[2][2]=='O') ||
                 (gameBoard[0][2]=='O' && gameBoard[1][1]=='O' && gameBoard[2][0]=='O'))
        {
            currentState = O_WON;
        }
    }
    
    //Game is a draw
    else if (gameBoard[0][0]!='.')
    {
        if (gameBoard[0][1]!='.')
        {
            if (gameBoard[0][2]!='.')
            {
                if (gameBoard[1][0]!='.')
                {
                    if (gameBoard[1][1]!='.')
                    {
                        if (gameBoard[1][2]!='.')
                        {
                            if (gameBoard[2][0]!='.')
                            {
                                if (gameBoard[2][1]!='.')
                                {
                                    if (gameBoard[2][2]!='.')
                                    {
                                        currentState = DRAW;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    //If no winner or draw, keep unfinished.
    else
    {
        currentState = UNFINISHED;
    }
    
    return currentState;
}

/****************************************************
 *  Board::print
 ****************************************************/

void Board::print()
{
    cout << "  " << "0" << " " << "1" << " " << "2" << endl;
    cout << "0 " << gameBoard[0][0] << " " << gameBoard[0][1] << " " << gameBoard[0][2] << endl;
    cout << "1 " << gameBoard[1][0] << " " << gameBoard[1][1] << " " << gameBoard[1][2] << endl;
    cout << "2 " << gameBoard[2][0] << " " << gameBoard[2][1] << " " << gameBoard[2][2] << endl;
}
            


