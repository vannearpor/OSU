/*******************************************************************
 * ** Author: Vannear Por
 * ** Date: April 20, 2017
 * ** Description: This is the header file for the game class which contains
 * ** the member variable and functions needed to run the game successfully.
 * ** It contains variables that holds the number of sides on the die for each
 * ** player, the value of each player's rolls, the score of each player,
 * ** the number of rounds, and whether the dices are loaded. It also 
 * ** contains the necessary functions to retreive the data for all the
 * ** member variables and the member functions necessary to return the
 * ** values stored in those member variables.
 * ********************************************************************/

#include "die.hpp"
#include "loadedDie.hpp"

#ifndef GAME_HPP
#define GAME_HPP

class Game
{
    private:
        int playerOneSides;
        int playerTwoSides;
        bool playerOneLoaded;
        bool playerTwoLoaded;
        int playerOneRollResult;
        int playerTwoRollResult;
        int playerOneScore;
        int playerTwoScore;
        int numberOfRounds;
    	LoadedDie p1Loaded, p2Loaded;
	Die p1Die, p2Die;
    public:
        Game ();
        Game (int, int, int, bool, bool);
        int getNumRounds ();
        int getP1Sides ();
        int getP2Sides ();
        bool getP1Load ();
        bool getP2Load ();
        int getP1Score ();
        int getP2Score ();
        void setNumRounds (int);
        void setP1Sides (int);
        void setP2Sides (int);
        void setP1Load (bool);
        void setP2Load (bool);
        void setP1Score (int);
        void setP2Score (int);
        void playRound ();
        void roundWinner ();
};

#endif

