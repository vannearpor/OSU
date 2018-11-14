/*************************************************************************
 * ** Author: Vannear Por
 * ** Date: April 20, 2017
 * ** Description: This is the main file which will prompt the user for 
 * ** questions regarding their setup of the game and will call upon the 
 * ** Game class to start the game. After the Game class functions run, it
 * ** will conclude the game.
 * **************************************************************************/

#include <iostream>

#include "game.hpp"
#include "die.hpp"
#include "loadedDie.hpp"

using std::cout;
using std::cin;
using std::endl;

void mainMenu ();

int main()
{
    int p1Side, p2Side;
    int rounds;
    bool p1Load, p2Load;
    bool valid1 = false;
    bool valid2 = false;
    
    mainMenu ();

    return 0;	
}

//Game menu
void mainMenu ()
{
	int p1Side, p2Side;
	int rounds;
	bool p1Load, p2Load;
	bool valid1 = false;        //bool tests for input validation
	bool valid2 = false;
	bool validload1 = false;
	bool validload2 = false;       

	 int choice;
            
        std::cout << "Would you like to play a game of War?" << std::endl;
        std::cout << " 1 - Yes. Let's Play." << std::endl;
        std::cout << " 2 - No. Exit." << std::endl;     //Ends program
        std::cout << "Enter the number of your choice between 1 - 2 and press [Enter]:" << std::endl;
            
        std::cin >> choice;
            
        switch (choice)
        {
            case 1:
                std::cout << "Let's begin!" << std::endl;
                
                std::cout << "Player 1, how many sides will your die have?" << std::endl;
                std::cin >> p1Side;
                std::cout << std::endl;
                std::cout << "Is your die loaded? Enter 1 for true or 0 for false." << std::endl;
                std::cin >> p1Load;
                
                //Input validation
                while (valid1 == false)
                {
                    if (p1Load == true || p1Load == false)
                    {
                        valid1 = true;
                    }
                    else
                    {
                        std::cout << "Please enter a valid answer. 1 for true or 0 for false." << std::endl;
                    }
                }
                //Set player 1 die depending on true and false answer
                while (validload1 == false)
		{
			if (p1Load == true)
               		{
                    		LoadedDie p1Loaded;
                    		std::cout << "Player 1 has a loaded die." << std::endl;
                	}
               		else
                	{
                    		Die p1Die;
                    		std::cout << "Player 1 has a regiular die." << std::endl;
                	}
			validload1 = true;
                }

                std::cout << std::endl;
                std::cin.clear(); 
                std::cin.ignore();
		std::cout << "Player 2, how many sides will your die have?" << std::endl;
		std::cin >> p2Side;
                std::cout << std::endl;
                std::cout << "Is your die loaded? Enter 1 for true or 0 for false." << std::endl;
                std::cin >> p2Load;
                
                //Input validation
                while (valid2 == false)
                {
                    if (p2Load == true || p2Load == false)
                    {
                        valid2 = true;
                    }
                    else
                    {
                        std::cout << "Please enter a valid answer. 1 for true or 0 for false." << std::endl;
                    }
                }
                //Sets player 2 die depending on true and false answer
                while (validload2 == false)
		{
			if (p2Load == true)
                	{
                    		LoadedDie p2Loaded;
                    		std::cout << "Player 2 has a loaded die." << std::endl;
                	}
                	else
                	{
                    		Die p2Die;
                    		std::cout << "Player 2 has a regular die." << std::endl;
                	}
			validload2 = true;
		}
                
                std::cout << std::endl;
                //Select number of rounds
                std::cout << "Please enter the amount of rounds to play." << std::endl;
                std::cin >> rounds;
                std::cout << std::endl;
                
                std::cout << "Game start." << std::endl;
                
                Game dieWar (rounds, p1Side, p2Side, p1Load, p2Load);       //call game class
                break;
            Default:
                std::cout << "End of Program." << std::endl;
                break;
        }
    }
