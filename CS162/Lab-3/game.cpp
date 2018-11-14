/*******************************************************************
 *  ** Author: Vannear Por
 *   ** Date: April 20, 2017
 *    ** Description: This is the declaration file for the game class which contains
 *     ** the member variable and functions needed to run the game successfully.
 *      ** It contains variables that holds the number of sides on the die for each
 *       ** player, the value of each player's rolls, the score of each player,
 *        ** the number of rounds, and whether the dices are loaded. This file
 *         ** contains the necessary functions to retreive the data for all the
 *          ** member variables and the member functions necessary to return the
 *           ** values stored in those member variables.
 *            ********************************************************************/

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

#include "game.hpp"

using std::cout;
using std::endl;

/***************************************************************
 *  * Default Constructor                                         *
 *   ***************************************************************/

Game::Game ()
{
}

/***************************************************************
 *  * Four Parameter Constructor                                  *
 *   ***************************************************************/

Game::Game (int rounds, int oneSide, int twoSide, bool oneLoad, bool twoLoad)
{
    setNumRounds (rounds);
    setP1Sides (oneSide);
    setP2Sides (twoSide);
    setP1Load (oneLoad);
    setP2Load (twoLoad);
    
    playerOneScore = 0;
    playerTwoScore = 0;
    
    playRound ();
}

/***************************************************************
 *  * Game::getNumRounds ()                                       *
 *   ***************************************************************/

int Game::getNumRounds ()
{
    return numberOfRounds;
}

/***************************************************************
 *  * Game::getP1Sides ()                                         *
 *   ***************************************************************/

int Game::getP1Sides ()
{
    return playerOneSides;
}

/***************************************************************
 *  * Game::getP2Sides ()                                         *
 *   ***************************************************************/

int Game::getP2Sides ()
{
    return playerTwoSides;
}

/***************************************************************
 *  * Game::getP1Load ()                                          *
 *   ***************************************************************/

bool Game::getP1Load ()
{
    return playerOneLoaded;
}

/***************************************************************
 *  * Game::getP2Load ()                                          *
 *   ***************************************************************/

bool Game::getP2Load ()
{
    return playerTwoLoaded;
}

/***************************************************************
 *  * Game::getP1Score ()                                         *
 *   ***************************************************************/

int Game::getP1Score ()
{
    return playerOneScore;
}

/***************************************************************
 *  * Game::getP2Score ()                                         *
 *   ***************************************************************/

int Game::getP2Score ()
{
    return playerTwoScore;
}

/***************************************************************
 *  * Game::setNumRounds ()                                       *
 *   ***************************************************************/

void Game::setNumRounds (int rounds)
{
    numberOfRounds = rounds;
}

/***************************************************************
 *  * Game::setP1Sides ()                                         *
 *   ***************************************************************/

void Game::setP1Sides (int oneSide)
{
    playerOneSides = oneSide;
}

/***************************************************************
 *  * Game::setP2Sides ()                                         *
 *   ***************************************************************/

void Game::setP2Sides (int twoSide)
{
    playerTwoSides = twoSide;
}

/***************************************************************
 *  * Game::setP1Load ()                                          *
 *   ***************************************************************/

void Game::setP1Load (bool oneLoad)
{
    playerOneLoaded = oneLoad;
}

/***************************************************************
 *  * Game::setP2Load ()                                          *
 *   ***************************************************************/

void Game::setP2Load (bool twoLoad)
{
    playerTwoLoaded = twoLoad;
}

/***************************************************************
 *  * Game::setP1Score ()                                         *
 *   ***************************************************************/

void Game::setP1Score (int oneScore)
{
    playerOneScore = oneScore;
}

/***************************************************************
 *  * Game::setP2Score ()                                         *
 *   ***************************************************************/

void Game::setP2Score (int twoScore)
{
    playerTwoScore = twoScore;
}

/***************************************************************
 *  * Game::playRound ()                                          *
 *   ***************************************************************/

void Game::playRound ()
{
    for (int i = 0; i < numberOfRounds; i++)
    {
        if (playerOneLoaded == true)
        {
            playerOneRollResult = p1Loaded.loadedRoll ();
        }
        else
        {
            playerOneRollResult = p1Die.rollDie ();
        }
        
        if (playerTwoLoaded == true)
        {
            playerTwoRollResult = p2Loaded.loadedRoll ();
        }
        else
        {
            playerTwoRollResult = p2Die.rollDie ();
        }
        
        std::cout << "Player 1 rolled a " << playerOneRollResult << "!" << std::endl;
        std::cout << "Player 2 rolled a " << playerTwoRollResult << "!" << std::endl;
        
        roundWinner ();
        std::cout << std::endl;
        
        std::cout << "The current score is:" << std::endl;
        std::cout << "Player 1: " << playerOneScore << "." << std::endl;
        std::cout << "Player 2: " << playerTwoScore << "." << std::endl;
        
    }
}

/****************************************************************
 * * Game::roundWinner ()                                          *
 * *****************************************************************/

void Game::roundWinner ()
{
    if (playerOneRollResult > playerTwoRollResult)
    {
        playerOneScore++;
        std::cout << "Player 1 wins this round!" << std::endl;
    }
    else if (playerTwoRollResult > playerOneRollResult)
    {
        playerTwoScore++;
        std::cout << "Player 2 wins this round!" << std::endl;
    }
    else
    {
        std::cout << "TIE! No one wins this round." << std::endl;
    }
}
