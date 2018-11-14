/********************************************************
 * ** Author: Vannear Por
 * ** Date: March 8, 2017
 * ** Description: This program provides the member function
 * ** declarations for the TicTacToe class which determines
 * ** who the first move will belong to and also run the
 * ** gameplay rules smoothly utilizing the Board class and it's functions.
 * ********************************************************/
 
#include <iostream>
#include <string>
#include "Board.hpp"
#include "TicTacToe.hpp"
using namespace std;

/******************************************
 * TicTacToe::TicTacToe
 * Constructor to pick first move.
 *****************************************/

TicTacToe::TicTacToe (char firstMove)
{
    if (firstMove == 'X')
    {
        turnPlayer = 1;
    }
    else if (firstMove == 'O')
    {
        turnPlayer = 2;
    }
}

/********************************************
 * TicTacToe::play
 * Starts gameplay and runs until there is a winner or draw.
 *******************************************/

void TicTacToe::play()
{
    int xCoord;
    int yCoord;
    bool validMove;	    
    BoardGameStatus currentStatus = UNFINISHED;
    
    while (currentStatus == UNFINISHED)
    {
        cout << "Player " << turnPlayer << ", please enter the coordinates of your next move." << endl;
        
        playBoard.print();
       
	cout << "Enter the X coordinate." << endl; 
        cin >> xCoord;
	cout << "Enter the Y coordinate." << endl;
        cin >> yCoord; 
        validMove = playBoard.makeMove(xCoord, yCoord, turnPlayer);
 
        
    //Move validity check
	if (validMove == true)
	{
		if (turnPlayer == 1)
		{
			turnPlayer = 2;
		}
		else if (turnPlayer == 2)
		{
			turnPlayer = 1;
		}
	}
	else
	{
		cout << "This location is occupied, please make a different move." << endl;
	}

	currentStatus = playBoard.gameState();   
    }

    
    //Winner is Player 1
    if (currentStatus == X_WON)
    {
         playBoard.print();
	 cout << "Player 1 Wins." << endl;
    }

    //Winner is Player 2
    else if (currentStatus == O_WON)
    {
	playBoard.print();
        cout << "Player 2 Wins." << endl;
    }

    //Game ends in a draw.
    else if (currentStatus == DRAW)
    {
	playBoard.print();
        cout << "This game ends with a draw." << endl;
    }
}

//Main Function
int main ()
{
    char firstPlayer;
    
    cout << "Please enter which player will go first, X or O?" << endl;
    cin >> firstPlayer;
    
    TicTacToe playGame(firstPlayer);
    playGame.play();
    
    return 0;
}
