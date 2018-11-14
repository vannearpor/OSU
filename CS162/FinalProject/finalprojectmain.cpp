/***************************************************************
** Author: Vannear Por
** Date: June 11, 2017
** Description: This is my final project in which will implement
** a map of 3 different types of rooms. The player will have 30
** turns to try and navigate around the room to find the series 
** items of items necessary to escape. 
****************************************************************/

#include "room.hpp"
#include "darkroom.hpp"
#include "lightroom.hpp"
#include "escaperoom.hpp"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main()
{
    Room* roomA = new Darkroom("Room A");
    Room* roomB = new Darkroom("Room B");
    Room* roomC = new Escaperoom("Room C");
    Room* roomD = new Lightroom("Room D");
    Room* roomE = new Lightroom("Room E");
    Room* roomF = new Lightroom("Room F");
    Room* roomG = new Darkroom("Room G");
    Room* roomH = new Lightroom("Room H");
    Room* character = roomC;
    
    roomA->setSouth(roomC);
    roomB->setSouth(roomD);
    roomC->setNorth(roomA);
    roomC->setEast(roomD);
    roomC->setSouth(roomF);
    roomD->setNorth(roomB);
    roomD->setWest(roomC);
    roomD->setSouth(roomG);
    roomD->setEast(roomE);
    roomE->setWest(roomD);
    roomF->setNorth(roomC);
    roomG->setNorth(roomD);
    roomG->setSouth(roomH);
    roomH->setNorth(roomG);
    
    bool knife = false;
    bool matches = false;
    bool key = false;
    bool fl = false;
    bool monster = false;
    bool escape = false;
    int choice;
    int moveChoice;
    int counter = 0;
    
    std::cout << "Welcome to Vannear's Escape from Torture Game." << std::endl;
    std::cout << "Warning: The descriptions in the game may frighten you..." << std::endl;
    std::cout << "Do you wish to play? Please select from the options below" << std::endl;
    std::cout << "1) Play" << std::endl;
    std::cout << "2) Exit Program" << std::endl;
    std::cin >> choice;
    
    switch (choice)
    {
        case 1:
        {
            std::cout << "You've chosen the play my Escape from Torture Game... how brave." << std::endl;
            std::cout << "..." << std::endl;
            std::cout << "..." << std::endl;
            std::cout << "..." << std::endl;
            std::cout << "You wake up dazed and confused..." << std::endl;
            std::cout << "You look around the room, you hear screaming from a distance." << std::endl;
            std::cout << "The room is very dim, *static* what's that?" << std::endl;
            std::cout << "*Over an Intercom* 'Welcome... I followed you home, knocked you unconscious and brought you back to my mansion.'" << std::endl;
            std::cout << "'I'm the infamous serial killer, Cannibal the Animal, if you wish to find out how I got my name... then stay put.'" << std::endl;
            std::cout << "'But you see... I like to have a little fun with my food before I torture them and ultimately consume them.'" << std::endl;
            std::cout << "'That door behind you is your only exist out of here... but it's locked right now.'" << std::endl;
            std::cout << "'You have 30 moves to find the key within my mansion and escape, when time runs up... gas will fill the room and it will knock you unconscious again!'" << std::endl;
            std::cout << "'If you exit those doors within 30 moves, I will let you off free without problem.'" << std::endl;
            std::cout << "'Are you ready?... Begin.'" << std::endl;
            std::cout << "Uh oh, you're in the hands of Cannibal the Animal, the most wanted cannibal serial killer in the world." << std::endl;
            std::cout << "You have 30 moves to find the key and exit through the doors behind you! GO!" << std::endl;
            
            while ((counter < 31) && (escape == false))
            {
                counter++;
                std::cout << "Move #" << counter << std::endl;
                
                std::cout << "Please select a number for the direction you want to move: " << std::endl;
                std::cout << "1 - North" << std::endl;
                std::cout << "2 - West" << std::endl;
                std::cout << "3 - South" << std::endl;
                std::cout << "4 - East" << std::endl;
                std::cin >> moveChoice;
                
                switch (choice)
                {
                    case 1:
                    {
                        character = character->moveChar(character, 1);
                        
                        if (character == roomA)
                        {
                            roomA->light(fl);
                            knife = roomA->darkroom1(fl, matches);
                        }
                        
                        else if (character == roomB)
                        {
                            roomB->light(fl);
                            matches = roomB->darkroom2(fl);
                        }
                        
                        else if (character == roomC)
                        {
                            roomC->light(fl);
                            escape = roomC->escaperoom1(key);
                        }
                        
                        else if (character == roomD)
                        {
                            roomD->light(fl);
                            roomD->lightroom1();
                        }
                        
                        else if (character == roomE)
                        {
                            roomE->light(fl);
                            fl = roomE->lightroom2();
                        }
                        
                        else if (character == roomF)
                        {
                            roomF->light(fl);
                            roomF->lightroom3();
                        }
                        
                        else if (character == roomG)
                        {
                            roomG->light(fl);
                            monster = roomG->darkroom3(fl, knife);
                        }
                        
                        else if (character == roomH)
                        {
                            roomH->light(fl);
                            key = roomH->lightroom4(monster);
                        }
                    }
                        
                    case 2:
                    {
                        character = character->moveChar(character, 2);
                        
                        if (character == roomA)
                        {
                            roomA->light(fl);
                            knife = roomA->darkroom1(fl, matches);
                        }
                        
                        else if (character == roomB)
                        {
                            roomB->light(fl);
                            matches = roomB->darkroom2(fl);
                        }
                        
                        else if (character == roomC)
                        {
                            roomC->light(fl);
                            escape = roomC->escaperoom1(key);
                        }
                        
                        else if (character == roomD)
                        {
                            roomD->light(fl);
                            roomD->lightroom1();
                        }
                        
                        else if (character == roomE)
                        {
                            roomE->light(fl);
                            fl = roomE->lightroom2();
                        }
                        
                        else if (character == roomF)
                        {
                            roomF->light(fl);
                            roomF->lightroom3();
                        }
                        
                        else if (character == roomG)
                        {
                            roomG->light(fl);
                            monster = roomG->darkroom3(fl, knife);
                        }
                        
                        else if (character == roomH)
                        {
                            roomH->light(fl);
                            key = roomH->lightroom4(monster);
                        }
                    }
                        
                    case 3:
                    {
                        character = character->moveChar(character, 3);
                        
                        if (character == roomA)
                        {
                            roomA->light(fl);
                            knife = roomA->darkroom1(fl, matches);
                        }
                        
                        else if (character == roomB)
                        {
                            roomB->light(fl);
                            matches = roomB->darkroom2(fl);
                        }
                        
                        else if (character == roomC)
                        {
                            roomC->light(fl);
                            escape = roomC->escaperoom1(key);
                        }
                        
                        else if (character == roomD)
                        {
                            roomD->light(fl);
                            roomD->lightroom1();
                        }
                        
                        else if (character == roomE)
                        {
                            roomE->light(fl);
                            fl = roomE->lightroom2();
                        }
                        
                        else if (character == roomF)
                        {
                            roomF->light(fl);
                            roomF->lightroom3();
                        }
                        
                        else if (character == roomG)
                        {
                            roomG->light(fl);
                            monster = roomG->darkroom3(fl, knife);
                        }
                        
                        else if (character == roomH)
                        {
                            roomH->light(fl);
                            key = roomH->lightroom4(monster);
                        }
                    }
                        
                    case 4:
                    {
                        character = character->moveChar(character, 4);
                        
                        if (character == roomA)
                        {
                            roomA->light(fl);
                            knife = roomA->darkroom1(fl, matches);
                        }
                        
                        else if (character == roomB)
                        {
                            roomB->light(fl);
                            matches = roomB->darkroom2(fl);
                        }
                        
                        else if (character == roomC)
                        {
                            roomC->light(fl);
                            escape = roomC->escaperoom1(key);
                        }
                        
                        else if (character == roomD)
                        {
                            roomD->light(fl);
                            roomD->lightroom1();
                        }
                        
                        else if (character == roomE)
                        {
                            roomE->light(fl);
                            fl = roomE->lightroom2();
                        }
                        
                        else if (character == roomF)
                        {
                            roomF->light(fl);
                            roomF->lightroom3();
                        }
                        
                        else if (character == roomG)
                        {
                            roomG->light(fl);
                            monster = roomG->darkroom3(fl, knife);
                        }
                        
                        else if (character == roomH)
                        {
                            roomH->light(fl);
                            key = roomH->lightroom4(monster);
                        }
                    }
                }
            }
            
            if (escape == true)
            {
                std::cout << "You sprint out to the other side of the door!..." << std::endl;
                std::cout << "What's this? You look around..." << std::endl;
                std::cout << "You see daylight... but, there's plant hedges 20 feet high surrounding you..." << std::endl;
                std::cout << "'So I see you've manage to escape my chamber. Congratulations... But you didn't think I'd let you escape that easy'" << std::endl;
                std::cout << "'You're now stuck in my Labyrinth Maze...Let me explain this next escape I have planned for you...'" << std::endl;
                std::cout << "TO BE CONTINUED..." << std::endl;
            }
            
            else if (escape == false)
            {
                std::cout << "'AHEM!!! LOOKS LIKE YOUR TIME IS UP BUDDY.... WAIT TILL YOU SEE WHAT I HAVE IN STORED FOR YOU!!!'" << std::endl;
                std::cout << "*hiss* Oh no, you hear and see green gas shoot up from the floors" << std::endl;
                std::cout << "*cough *cough* You try to stay awake... *thump* You fell unconscious..." << std::endl;
                std::cout << "GAME OVER. YOU LOSE." << std::endl;
            }
            
            break;
        }
            
        case 2:
        {
            std::cout << "The program will now end. Goodbye." << std::endl;
            break;
        }
    }
}





