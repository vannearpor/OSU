/***************************************************************
 * ** Author: Vannear Por
 * ** Date: May 13, 2017
 * ** Description: This is the main file for the fantasy combat
 * ** game which will prompt the user to pick 2 creatures from a
 * ** menu to engage in combat.
 * ****************************************************************/

#include "creature.hpp"
#include "barbarian.hpp"
#include "bluemen.hpp"
#include "harrypotter.hpp"
#include "medusa.hpp"
#include "vampire.hpp"

#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main ()
{
    int choice;
    int choice2;
    int choice3;
    int firstMove;
    int attackPower;
    bool p1Victory = false;
    bool p2Victory = false;
    Creature * player1;
    Creature * player2;
    Barbarian barb1;
    Barbarian barb2;
    Bluemen blue1;
    Bluemen blue2;
    Harrypotter hp1;
    Harrypotter hp2;
    Medusa med1;
    Medusa med2;
    Vampire vamp1;
    Vampire vamp2;
    
    bool endGame = false;
    
    while (endGame == false)
    {
        std::cout << "Welcome to Vannear's Fantasy Combat Game!" << std::endl;
        std::cout << "In this realm, Mythical Creatures from different worlds will fight to the death." << std::endl;
        std::cout << "Please select a Mythical Creature for Player 1: " << std::endl;
        std::cout << "1) Barbarian" << std::endl;
        std::cout << "2) Blue Men" << std::endl;
        std::cout << "3) Harry Potter" << std::endl;
        std::cout << "4) Medusa" << std::endl;
        std::cout << "5) Vampire" << std::endl;
        
        std::cin >> choice;
        
        switch (choice)
        {
            case 1:
            {
                std::cout << "Player 1, you have chosen the mighty Barbarian!" << std::endl;
                player1 = &barb1;
                break;
            }
                
            case 2:
            {
                std::cout << "Player 1, you have chosen the Blue Men, there are strength in numbers!" << std::endl;
                player1 = &blue1;
                break;
            }
                
            case 3:
            {
                std::cout << "Player 1, you have chosen the powerful wizard Harry Potter!" << std::endl;
                player1 = &hp1;
                break;
            }
                
            case 4:
            {
                std::cout << "Player 1, you have chosen the woman that you should fear more than your own mom! Medusa!" << std::endl;
                player1 = &med1;
                break;
            }
                
            case 5:
            {
                std::cout << "Player 1, you have chosen the suave and blood-thirsty, the Vampire!" << std::endl;
                player1 = &vamp1;
                break;
            }
        }
        
        std::cin.clear();
        std::cin.ignore();
        
        std::cout << "Please select a Mythical Creature for Player 2: " << std::endl;
        std::cout << "1) Barbarian" << std::endl;
        std::cout << "2) Blue Men" << std::endl;
        std::cout << "3) Harry Potter" << std::endl;
        std::cout << "4) Medusa" << std::endl;
        std::cout << "5) Vampire" << std::endl;
        
        std::cin >> choice2;
        
        switch (choice2)
        {
            case 1:
            {
                std::cout << "Player 2, you have chosen the mighty Barbarian!" << std::endl;
                player2 = &barb2;
                break;
            }
                
            case 2:
            {
                std::cout << "Player 2, you have chosen the Blue Men, there are strength in numbers!" << std::endl;
                player2 = &blue2;
                break;
            }
                
            case 3:
            {
                std::cout << "Player 2, you have chosen the powerful wizard Harry Potter!" << std::endl;
                player2 = &hp2;
                break;
            }
                
            case 4:
            {
                std::cout << "Player 2, you have chosen the woman that you should fear more than your own mom! Medusa!" << std::endl;
                player2 = &med2;
                break;
            }
                
            case 5:
            {
                std::cout << "Player 2, you have chosen the suave and blood-thirsty, the Vampire!" << std::endl;
                player2 = &vamp2;
                break;
            }
        }
        
        std::cin.clear();
        std::cin.ignore();
        
        std::cout << "Here are your fighters: " << std::endl;
       
	std::cout << "Player 1: " << player1->getType() << std::endl;
        std::cout << "Strength: " << player1->getStrengthPoints() << std::endl;
        std::cout << "Player 2: " << player2->getType() << std::endl;
        std::cout << "Strength: " << player2->getStrengthPoints() << std::endl;
 
        firstMove = rand () % 2 + 1;
        if (firstMove == 1)
        {
            std::cout << "Player 1, " << player1->getType() << " will have first move!" << std::endl;
        }
        else
        {
            std::cout << "Player 2, " << player2->getType() << " will have first move!" << std::endl;
        }
        
        if (firstMove == 1)
        {
            while ((p1Victory == false) && (p2Victory == false))
            {
                std::cout << "Player 1 " << player1->getType() << " attacks the opponent!" << std::endl;
                attackPower = player1->attack();
                player2->defend(attackPower);
                p1Victory = player2->defeated();
                
                if (p1Victory == false)
                {
                    std::cout << "Player 2 " << player2->getType() << " attacks the opponent!" << std::endl;
                    attackPower = player2->attack();
                    player1->defend(attackPower);
                    p2Victory = player1->defeated();
                }
            }
        }
        else
        {
            while ((p1Victory == false) && (p2Victory == false))
            {
                std::cout << "Player 2 " << player2->getType() << " attacks the opponent!" << std::endl;
                attackPower = player2->attack();
                player1->defend(attackPower);
                p2Victory = player1->defeated();
                
                if (p2Victory == false)
                {
                    std::cout << "Player 1 " << player1->getType() << " attacks the opponent!" << std::endl;
                    attackPower = player1->attack();
                    player2->defend(attackPower);
                    p1Victory = player2->defeated();
                }
            }
        }
        
        if (p1Victory == true)
        {
            std::cout << "Player 1 " << player1->getType() << " is Victorious!" << std::endl;
        }
        else
        {
            std::cout << "Player 2 " << player2->getType() << " is Victorious!" << std::endl;
        }
        
        std::cout << "Would you like to play again?" << std::endl;
        std::cout << "1) Yes. Play Again." << std::endl;
        std::cout << "2) No. Exit Game." << std::endl;
        
        std::cin >> choice3;
        
        switch (choice3)
        {
            case 1:
            {
                std::cout << "Game will restart!" << std::endl;
                endGame = false;
		p1Victory = false;
		p2Victory = false;
                break;
            }
                
            case 2:
            {
                std::cout << "Game will exit. Goodbye." << std::endl;
                endGame = true;
                break;
            }
        }
    }
}
