/***************************************************************
** Author: Vannear Por
** Date: June 11, 2017
** Description: This is the implementation file for the Darkroom
** derived class which will contain the function definitions
** for the class which will display the characteristics of each
** dark room.
****************************************************************/

#include "room.hpp"
#include "darkroom.hpp"
#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

/***************************************************************
 * * Default Constructor ()                                       *
 * ****************************************************************/

Darkroom::Darkroom()
{
    roomFinish = false;
    northRoom = NULL;
    southRoom = NULL;
    westRoom = NULL;
    eastRoom = NULL;
}

/***************************************************************
 * * Deconstructor ()                                             *
 * ****************************************************************/

Darkroom::~Darkroom()
{
}

/***************************************************************
 * * Darkroom::Darkroom()                                                 *
 * ****************************************************************/

Darkroom::Darkroom(std::string name)
{
    roomName = name;
}


/***************************************************************
 * * Darkroom::light()                                            *
 * ****************************************************************/

void Darkroom::light(bool fl)
{
    std::cout << "You have entered the room..." << std::endl;
    
    if (fl == false)
    {
        std::cout << "The room is currently pitch black... if only you had a flashlight..." << std::endl;
        std::cout << "Leave the room from where you came from: " << std::endl;
    }
    else if (fl == true)
    {
        std::cout << "The room is pitch black... you pull out your flashlight to illuminate the room" << std::endl;
    }
}

/***************************************************************
 * * Darkroom::darkroom1()                                        *
 * ****************************************************************/

bool Darkroom::darkroom1(bool fl, bool matches)
{
    if (roomFinish == false)
    {
        if (fl == false)
        {
            return false;
        }
    
        if (fl == true)
        {
            std::cout << "You look around the room... it's cold." << std::endl;
            std::cout << "What's this? There's a wooden crate in the corner, you go check it out." << std::endl;
            std::cout << "There is a note on the box: " << std::endl;
            std::cout << "Note: From a spark, may ignite your escape... or will you burn in the end?" << std::endl;
            std::cout << "There's a fuse attached to the box...." << std::endl;
        
            if (matches == false)
            {
                std::cout << "It looks like you might need something to light the fuse, you should go find it" << std::endl;
                
                return false;
            }
        
            else if (matches == true)
            {
                std::cout << "You noticed the fuse sticking out of the box... you look into your bag for your matches..." << std::endl;
                std::cout << "You grab a match, ignited it, and lit the fuse! Quick run to the other side!" << std::endl;
                std::cout << "BOOM! *cough* *cough* There's smoke everywhere." << std::endl;
                std::cout << "You walk towards the rubble after the smoke clears..." << std::endl;
                std::cout << "There a large Machete laying in the rubble, there's some dried up blood on it." << std::endl;
                std::cout << "This may come in handy, you place the Machete in your bag." << std::endl;
                std::cout << "Time is running out, time to get going." << std::endl;
                
                roomFinish = true;
                return true;
            }
        }
    }
    
    else if (roomFinish == true)
    {
        std::cout << "The room still smells of smoke, there's nothing else here." << std::endl;
        
        return true;
    }
}

/***************************************************************
 * * Darkroom::darkroom2()                                        *
 * ****************************************************************/

bool Darkroom::darkroom2(bool fl)
{
    if (roomFinish == false)
    {
        if (fl == false)
        {
            return false;
        }
        
        else if (fl == true)
        {
            std::cout << "You look around... there's blood on the walls and it reeks of urine..." << std::endl;
            std::cout << "There's a disgusting bed off to the side, you see a bucket with feces and urine..." << std::endl;
            std::cout << "Someone must have been held captive here." << std::endl;
            std::cout << "Look there's a table! You walk towards it." << std::endl;
            std::cout << "There's nail scratches etched into the table. You notice a brown notebook in the corner." << std::endl;
            std::cout << "You brush off the dead rat on top of the book, and proceed to open it..." << std::endl;
            std::cout << "*thump* Oh. A packet of matches fell out of the book. You might need this... you place the matches in your bag." << std::endl;
            
            std::cout << "It looks like a diary..." << std::endl;
            std::cout << "'Day 265: I've lost hope now. I've seen many others come and go, I don't know why he's kept me here for this long...'" << std::endl;
            std::cout << "'He's cut off my left arm. My right leg is paralyzed. I don't know how much torture I can take.'" << std::endl;
            std::cout << "'I'm going to leave a packet of matches for anyone that finds this. I hope it will help anyone else that's captured by this madman." << std::endl;
            std::cout << "...You decide to keep the diary. You place the diary in your backpack." << std::endl;
            std::cout << "Time is running out, time to get going." << std::endl;
            
            roomFinish = true;
            return true;
        }
    }
    
    else if (roomFinish == true)
    {
        std::cout << "The room is quiet, there is an imprint in the dust on the table of where the notebook once was... there's nothing else here." << std::endl;
        
        return true;
    }
}

/***************************************************************
 * * Darkroom::darkroom3()                                        *
 * ****************************************************************/

bool Darkroom::darkroom3(bool fl, bool knife)
{
    if (roomFinish == false)
    {
        if (fl == false)
        {
            return false;
        }
        
        else if (fl == true)
        {
            std::cout << "You're come immediately face-to-face with a gruesome monster..." << std::endl;
            std::cout << "You see a door behind the beast, but it completely blocks your path." << std::endl;
            std::cout << "It has 3 blood-shot eyes, blood dripping down it's face, sharp fangs dripping saliva." << std::endl;
            std::cout << "It stares back at you... it speaks... '...eat. EAT. EEEEAT!'" << std::endl;
            
            if (knife == false)
            {
                std::cout << "QUICK! You don't have anything to defend yourself with. Run out from where you came from!" << std::endl;
                
                return false;
            }
            
            else if (knife == true)
            {
                std::cout << "It runs sprints towards you!" << std::endl;
                std::cout << "You quickly pull out your Machete and stab the beast through it's heart!" << std::endl;
                std::cout << "The beast freeze in it's tracks and collapses." << std::endl;
                std::cout << "You kick his body to the side to clear your path." << std::endl;
                std::cout << "That door might be your key out of here, hurry! Go check it out." << std::endl;
                
                roomFinish = true;
                return true;
            }
        }
    }
    
    else if (roomFinish == true)
    {
        std::cout << "The corpse of the monster says in the corner. It smells like rotting flesh." << std::endl;
        std::cout << "There is nothing else here." << std::endl;
        
        return true;
    }
}

/***************************************************************
 *  * Override Pure Virtual Functions                             *
 *   ****************************************************************/

void Darkroom::lightroom1()
{
}

bool Darkroom::lightroom2()
{
}

void Darkroom::lightroom3()
{
}

bool Darkroom::lightroom4(bool a)
{
}

bool Darkroom::escaperoom1(bool a)
{
}

