/*****************************************************************
** Author: Vannear Por
** Date: May 25, 2017
** Description: This is the main file for the Fantasy Combat
** Game Tournament Program. This program will allow for one user
** to create 2 teams of Creatures. The teams will be in a lineup
** and the head of each lineup will fight each round. After the round
** the loser will be moved to the loser's list and the winner will
** return to their team lineup in the back of the line. The winner
** will be determined when the other team's Creatures have all
** been defeated.
******************************************************************/

#include "creature.hpp"
#include "barbarian.hpp"
#include "bluemen.hpp"
#include "harrypotter.hpp"
#include "medusa.hpp"
#include "vampire.hpp"
#include "lineup.hpp"
#include "loser.hpp"

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cmath>

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main ()
{
    int teamNum;
    int menuFighter1;
    int menuFighter2;
    int firstMove;
    int attackPower;
    bool p1Victory = false;
    bool p2Victory = false;
    int team1Score = 0;
    int team2Score = 0;
    Creature * team1creature;
    LineupNode * check1Victory;
    LineupNode * check2Victory; 
    Creature * team2creature;
    Lineup team1;
    Lineup team2;
    Loser loser1;
    Loser loser2;
    bool team1Victory = false;
    bool team2Victory = false;
    
    std::cout << "Welcome to Vannear's Fantasy Combat Game Tournament!" << std::endl;
    std::cout << "Please enter the amount of Creatures between 1 - 10 that each team will have: " << std::endl;
    std::cin >> teamNum;
    
    std::cout << "\nEach team will have " << teamNum << " Creatures." << std::endl;
    
    std::cout << "We will now pick the Creatures for Team 1." << std::endl;
    
    for (int i = 0; i < teamNum; i++)
    {
        std::cout << "Please select Mythical Creature Number " << i+1 << " for Team 1: " << std::endl;
        std::cout << "1) Barbarian" << std::endl;
        std::cout << "2) Blue Men" << std::endl;
        std::cout << "3) Harry Potter" << std::endl;
        std::cout << "4) Medusa" << std::endl;
        std::cout << "5) Vampire" << std::endl;
        
        std::cin.clear();
        std::cin.ignore();
        std::cin >> menuFighter1;
        
        switch (menuFighter1)
        {
            case 1:
            {
                std::cout << "Team 1, you have chosen to add the mighty Barbarian" << std::endl;
                team1creature = new Barbarian;
                team1.addToTail(team1creature);
                break;
            }
                
            case 2:
            {
                std::cout << "Team 1, you have chosen to add the Blue Men, there are strength in numbers!" << std::endl;
                team1creature = new Bluemen;
                team1.addToTail(team1creature);
                break;
            }
                
            case 3:
            {
                std::cout << "Team 1, you have chosen to add the powerful wizard Harry Potter!" << std::endl;
                team1creature = new Harrypotter;
                team1.addToTail(team1creature);
                break;
            }
                
            case 4:
            {
                std::cout << "Team 1, you have chosen the woman of the snakes, Medusa!" << std::endl;
                team1creature = new Medusa;
                team1.addToTail(team1creature);
                break;
            }
                
            case 5:
            {
                std::cout << "Team 1, you have chosen the blood-thirsday Vampire!" << std::endl;
                team1creature = new Vampire;
                team1.addToTail(team1creature);
                break;
            }
        }
    }
    
    std::cout << "Team 1 Lineup has been completed." << std::endl;
    
    std::cout << "We will now pick the creatures for Team 2." << std::endl;
    
    for (int i = 0; i < teamNum; i++)
    {
        std::cout << "Please select Mythical Creature Number " << i+1 << " for Team 2: " << std::endl;
        std::cout << "1) Barbarian" << std::endl;
        std::cout << "2) Blue Men" << std::endl;
        std::cout << "3) Harry Potter" << std::endl;
        std::cout << "4) Medusa" << std::endl;
        std::cout << "5) Vampire" << std::endl;
        
        std::cin.clear();
        std::cin.ignore();
        std::cin >> menuFighter2;
        
        switch (menuFighter2)
        {
            case 1:
            {
                std::cout << "Team 2, you have chosen to add the mighty Barbarian" << std::endl;
                team2creature = new Barbarian;
                team2.addToTail(team2creature);
                break;
            }
                
            case 2:
            {
                std::cout << "Team 2, you have chosen to add the Blue Men, there are strength in numbers!" << std::endl;
                team2creature = new Bluemen;
                team2.addToTail(team2creature);
                break;
            }
                
            case 3:
            {
                std::cout << "Team 2, you have chosen to add the powerful wizard Harry Potter!" << std::endl;
                team2creature = new Harrypotter;
                team2.addToTail(team2creature);
                break;
            }
                
            case 4:
            {
                std::cout << "Team 2, you have chosen the woman of the snakes, Medusa!" << std::endl;
                team2creature = new Medusa;
                team2.addToTail(team2creature);
                break;
            }
                
            case 5:
            {
                std::cout << "Team 2, you have chosen the blood-thirsday Vampire!" << std::endl;
                team2creature = new Vampire;
                team2.addToTail(team2creature);
                break;
            }
        }
    }
    
    std::cout << "Here is the Lineup for Team 1: " << std::endl;
    team1.displayLineup ();
    std::cout << "\nHere is the Lineup for Team 2: " << std::endl;
    team2.displayLineup ();
    
    std::cout << "\nThe tournament will now begin. The head of the line of each team will fight." << std::endl;
    std::cout << "The winner of the round will return to the back of the line with 50% of the total health restored." << std::endl;
    std::cout << "The loser of the round will be thrown into the Loser's container, never to be seen again." << std::endl;
    
    while ((team1Victory == false) && (team2Victory == false))
    {
        std::cout << "Here are your fighters: " << std::endl;
    
        std::cout << "Team 1: ";
	team1.displayHead();
        std::cout << std::endl << "Team 2: ";
	team2.displayHead();
        
        firstMove = rand () % 2 + 1;
        if (firstMove == 1)
        {
            std::cout << "Team 1, ";
	    team1.displayHead();
	    std::cout <<  " will have first move!" << std::endl;
        }
        else
        {
            std::cout << "Team 2, ";
	    team2.displayHead();
	    std::cout << " will have first move!" << std::endl;
        }
    
        if (firstMove == 1)
        {
            while ((p1Victory == false) && (p2Victory == false))
            {
                std::cout << "Team 1 ";
		team1.displayHead();
		std::cout << " attacks the opponent!" << std::endl;
                attackPower = team1.headAttack();
                team2.headDefend(attackPower);
                p1Victory = team2.headDefeated();
            
                if (p1Victory == false)
                {
                    std::cout << "Team 2 "; 
		    team2.displayHead(); 
		    std::cout << " attacks the opponent!" << std::endl;
                    attackPower = team2.headAttack();
                    team1.headDefend(attackPower);
                    p2Victory = team1.headDefeated();
                }
            }
        }
        else
        {
            while ((p1Victory == false) && (p2Victory == false))
            {
                std::cout << "Team 2 ";
		team2.displayHead();
		std::cout << " attacks the opponent!" << std::endl;
                attackPower = team2.headAttack();
                team1.headDefend(attackPower);
                p2Victory = team1.headDefeated();
            
                if (p2Victory == false)
                {
                    std::cout << "Team 1 ";
		    team1.displayHead();
		    std::cout << " attacks the opponent!" << std::endl;
                    attackPower = team1.headAttack();
                    team2.headDefend(attackPower);
                    p1Victory = team2.headDefeated();
                }
            }
        }
    
        if (p1Victory == true)
        {
            team1Score = team1Score + 1;
            std::cout << "Team 1 ";
	    team1.displayHead();
	    std::cout << " is Victorious!" << std::endl;
            team1.headToTail();
	    team2creature = team2.getHead();
            loser2.addToHead(team2creature);
            team2.deleteHead();
	    check1Victory = team2.getHeadPointer();
        }
        else
        {
            team2Score = team2Score + 1;
            std::cout << "Team 2 ";
	    team2.displayHead();
	    std::cout << " is Victorious!" << std::endl;
            team2.headToTail();
	    team1creature = team1.getHead();
            loser1.addToHead(team1creature);
            team1.deleteHead();
	    check2Victory = team1.getHeadPointer();
        }
        
        if (check2Victory == NULL)
        {
            team2Victory = true;
        }
        else if (check1Victory == NULL)
        {
            team1Victory = true;
        }
	else
	{
	    team1Victory = false;
	    team2Victory = false;
	}
    }
    
    if (team1Victory == true)
    {
        std::cout << "Team 1 comes out victorious!" << std::endl;
        std::cout << "Score: " << std::endl;
        std::cout << "Team 1: " << team1Score << std::endl;
        std::cout << "Team 2: " << team2Score << std::endl;
    }
    else
    {
        std::cout << "Team 2 comes out victorious!" << std::endl;
        std::cout << "Score: " << std::endl;
        std::cout << "Team 1: " << team1Score << std::endl;
        std::cout << "Team 2: " << team2Score << std::endl;
    }
}
