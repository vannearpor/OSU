/***************************************************************
 ** Author: Vannear Por
 ** Date: June 11, 2017
 ** Description: This is the implementation file for the Lightroom
 ** derived class which will contain the function definitions
 ** for the class which will display the characteristics of each
 ** light room.
 ****************************************************************/

#include "room.hpp"
#include "lightroom.hpp"
#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

/***************************************************************
 * * Default Constructor ()                                       *
 * ****************************************************************/

Lightroom::Lightroom()
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

Lightroom::~Lightroom()
{
}

/***************************************************************
 * * Lightroom::Lightroom()                                                 *
 * ****************************************************************/

Lightroom::Lightroom(std::string name)
{
    roomName = name;
}


/***************************************************************
 * * Lightroom::light()                                           *
 * ****************************************************************/

void Lightroom::light(bool fl)
{
    std::cout << "The room is brightly lit..." << std::endl;
}

/***************************************************************
 * * Lightroom::lightroom1()                                      *
 * ****************************************************************/

void Lightroom::lightroom1()
{
    if (roomFinish == false)
    {
        std::cout << "This room is completely empty..." << std::endl;
        std::cout << "You hear weird noises, screaming from different directions." << std::endl;
        std::cout << "'HELP ME!!!' *vrrrrrrrrrr*" << std::endl;
        std::cout << "Was that a chainsaw you heard?..." << std::endl;
        std::cout << "You look around and there's a door in all 4 directions." << std::endl;
        std::cout << "No use waiting around, hurry..." << std::endl;
    }
    
    else if (roomFinish == true)
    {
        std::cout << "You're back in the empty room." << std::endl;
        std::cout << "Where will you go?" << std::endl;
    }
}

/***************************************************************
 * * Lightroom::lightroom2()                                      *
 * ****************************************************************/

bool Lightroom::lightroom2()
{
    if (roomFinish == false)
    {
        std::cout << "What... what's this?..." << std::endl;
        std::cout << "You see a man hanging with all 4 limbs pinned to the walls..." << std::endl;
        std::cout << "You want up to him... he's not alive, his face is covered with blood and is unrecognizable." << std::endl;
        std::cout << "You look around the room... there's pins and needles all over the floor." << std::endl;
        std::cout << "There's a used chainsaw on the ground, you look at it, it's dull and used. Worthless to you." << std::endl;
        std::cout << "You look back at the man, WAIT!" << std::endl;
        std::cout << "Theres. There's a flashlight holted in his mouth. This is what you need!" << std::endl;
        std::cout << "You try pulling on the flashlight but his jaw is shut..." << std::endl;
        std::cout << "You grab the dull chainsaw and slash through the man's cheeks. The flashlight falls to the floor." << std::endl;
        std::cout << "Perfect! Now you can check out those pitch black rooms..." << std::endl;
    
        roomFinish = true;
        return true;
    }
    
    else if (roomFinish == true)
    {
        std::cout << "The man still hangs there." << std::endl;
        std::cout << "There's nothing else here you should leave." << std::endl;
        return true;
    }
}

/***************************************************************
 * * Lightroom::lightroom3()                                      *
 * ****************************************************************/

void Lightroom::lightroom3()
{
    if (roomFinish == false)
    {
        std::cout << "There's a girl passed out in the corner of the room." << std::endl;
        std::cout << "You quickly run over to her to see if she's ok!" << std::endl;
        std::cout << "You try to wake her up. She looks heavily sedated..." << std::endl;
        std::cout << "Shes waking up slowly..." << std::endl;
        std::cout << "'AHHHHHH!! PLEASE. PLEASE DON'T HURT ME ANYMORE!!!'" << std::endl;
        std::cout << "The girl cowers in fear... her leg, her leg is chained to the wall..." << std::endl;
        std::cout << "You let her know that you're not here to hurt her. You want to find a way out." << std::endl;
        std::cout << "She looks at you... she grins... she laughs..." << std::endl;
        std::cout << "You're confused. You asked her why is she laughing." << std::endl;
        std::cout << "'There is no use... No one has escaped. He will find you. He will torture you and you will never see the light of day again." << std::endl;
        std::cout << "She laughs hysterically." << std::endl;
        std::cout << "You ask her if there's anything she knows that might help you escape." << std::endl;
        std::cout << "She laughs even louder... Man... This girl is crazy, you better get out of there before anyone hears her quick!" << std::endl;
        
        roomFinish = true;
    }
    
    else if (roomFinish == true)
    {
        std::cout << "You see the girl passed out again in the corner of the room." << std::endl;
        std::cout << "It's probably not a good idea to try and wake her up again. Just leave her. Save yourself." << std::endl;
    }
}

/***************************************************************
 *  * Lightroom::lightroom4()                                     *
 *   ****************************************************************/

bool Lightroom::lightroom4(bool monster)
{
    if (roomFinish == false)
    {
        if (monster == false)
        {
            std::cout << "You try to go to the room but the monster is blocking your way!" << std::endl;
            
            return false;
        }
        
        else if (monster == true)
        {
            std::cout << "You step into a really tight and small room... it smells HORRIBLE. Nothing is in the room except a table." << std::endl;
            std::cout << "You walk up to the table and you see 3 decapitated animal heads lined up... A deer. A bear. A lion." << std::endl;
            std::cout << "There's a note next to the heads: " << std::endl;
            std::cout << "'If you're reading this you've succeeded in your task... the key to your escape is somewhere in this room.'" << std::endl;
            std::cout << "Interesting... the room is brightly lit with only a table and animal heads... you don't see the key anywhere else." << std::endl;
            std::cout << "You look at the heads... you stick your hand into the deer's head... YUCK!" << std::endl;
            std::cout << "You throw the head across the room! There's maggots all over your hands and crawling across the floor." << std::endl;
            std::cout << "You proceed to stick your hand into the bear's head..." << std::endl;
            std::cout << "You nearly puke. Animal excrements filled the bear's head." << std::endl;
            std::cout << "You're beginning to wonder if the keys are even in this room..." << std::endl;
            std::cout << "You stick your hand into the lion's head, wow this one is filled with jello..." << std::endl;
            std::cout << "You feel something solid... You grab it and pull your hand out!" << std::endl;
            std::cout << "You find a rusty brown key! You place it in your bag! QUICK ESCAPE!" << std::endl;
            std::cout << "You sprint out the room..." << std::endl;
            
            roomFinish = true;
            return true;
        }
    }
    
    else if (roomFinish == true)
    {
        std::cout << "ARE YOU SERIOUS!? You've found the key and you're back in this room!?" << std::endl;
        return true;
    }
}

/***************************************************************
 *  * Override Pure Virtual Functions                             *
 *   ****************************************************************/

bool Lightroom::darkroom1(bool a, bool b)
{
}

bool Lightroom::darkroom2(bool a)
{
}

bool Lightroom::darkroom3(bool a, bool b)
{
}

bool Lightroom::escaperoom1(bool a)
{
}

