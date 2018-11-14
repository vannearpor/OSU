/****************************************************************
** Author: Vannear Por
** Date: April 27, 2017
** Description: This is the implementation file for the instructor class.
** It will contain the function definitions that will set the 
** instructor rating, display the hours of work, and a function
** that will display the data of the class object.
*****************************************************************/

#include "instructor.hpp"
#include <iostream>
using std::cout;
using std::endl;

/*****************************************************************
* Instructor::setRating ()                                       *
******************************************************************/

void Instructor::setRating ()
{
    rating = rand() % 5.00;
}

/*****************************************************************
* Instructor::do_work()                                          *
******************************************************************/

void Instructor::do_work (int x)
{
    int hours;
    hours = rand() % x + 1;
    
    std::cout << "Instructor " << name << " graded papers for " << hours << " hours." << std::endl;
}

/*****************************************************************
* Instructor::displayPeople ()                                   *
******************************************************************/

void Instructor::displayPeople ()
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Instructor Rating: " << rating << std::endl;
}

