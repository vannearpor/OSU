/*******************************
** Author: Vannear Por
** Date: April 27, 2017
** Description: Main.cpp
********************************/ 
#include "people.hpp"
#include "student.hpp"
#include "instructor.hpp"
#include "university.hpp"
#include "building.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::string;


int main()
{
    University osu;
    
    osu.setUniversityName ("Oregon State University");
    
    osu.setB1 ("Adams Hall", 11168, "606 SW 15th St., Corvallis, OR 97331");
    osu.setB2 ("Arnold Dining Center", 28577, "681 SW 26th St., Corvallis, OR 97331");
    osu.setB3 ("Oxford House", 10817, "957 SW Jefferson Ave., Corvallis, OR 97331");
    
    osu.setS1 ("Vinh Le", 18);
    osu.setS2 ("Jackie Fan", 20);
    osu.setS3 ("Alex Chia", 19);
    
    osu.setI1 ("Jessica Tran", 42);
    osu.setI2 ("Peter Lam", 50);
    osu.setI3 ("Paul George", 30);
    
    int choice1;
    int choice2;
    bool valid1 = false;
    bool valid2 = false;
    
    while (valid1 == false)
    {
        std::cout << "Please select from the following options: " << std::endl;
        std::cout << "1) Print Information of All Buildings." << std::endl;
        std::cout << "2) Print Information of Everybody in the University." << std::endl;
        std::cout << "3) Choose a Person To Do Work." << std::endl;
        std::cout << "4) Exit Program." << std::endl;
        
        std::cin >> choice1;
        std::endl;
        std::cout << "You chose option number " << choice1 << "." << std::endl;
        
        if (choice1 == 1)
        {
            osu.displayAllBuildings ();
            valid1 = true;
        }
        else if (choice1 == 2)
        {
            osu.displayAllPeople ();
            valid1 = true;
        }
        else if (choice1 == 3)
        {
            while (valid2 == false)
            {
                std::cout << "Please select a person to do work: " << std::endl;
                std::cout << "1) Vinh Le" << std::endl;
                std::cout << "2) Jackie Fan" << std::endl;
                std::cout << "3) Alex Chia" << std::endl;
                std::cout << "4) Jessica Tran" << std::endl;
                std::cout << "5) Peter Lam" << std::endl;
                std::cout << "6) Paul George" << std::endl;
                
                std::cin >> choice2;
                std::endl;
                std::cout << "You chose option number " << choice2 << "." << std::endl;
                
                if (choice2 == 1)
                {
                    osu.s1DoWork();
                    valid2 = true;
                }
                else if (choice2 == 2)
                {
                    osu.s2DoWork();
                    valid2 = true;
                }
                else if (choice2 == 3)
                {
                    osu.s3DoWork();
                    valid2 = true;
                }
                else if (choice2 == 4)
                {
                    osu.i1DoWork();
                    valid2 = true;
                }
                else if (choice2 == 5)
                {
                    osu.i2DoWork();
                    valid2 = true;
                }
                else if (choice2 == 6)
                {
                    osu.i3DoWork();
                    valid2 = true;
                }
                else
                {
                    return 0;
                }
            }
            
            valid1 = true;
        }
        else if (choice1 == 4)
        {
            std::cout << "You chose to exit the program. Goodbye." << std::endl;
            valid1 = true;
        }
        else
        {
            return 0;
        }
    }
}
