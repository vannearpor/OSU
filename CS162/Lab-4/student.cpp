/****************************************************************
**Author: Vannear Por
** Date: April 27, 2017
** Description: This is the implementation file for the student class.
** It will contain the function definitions that will set the 
** student GPA, display the hours of work they've done, and
** a function that will display the data of the class object.
*****************************************************************/

#include "student.hpp"
#include <iostream>
using std::cout;
using std::endl;


/*****************************************************************
* Student::setGPA ()                                             *
******************************************************************/

void Student::setGPA ()
{
    gpa = rand() % 4.00;
}

/*****************************************************************
* Student::do_work ()                                            *
******************************************************************/

void Student::do_work (int x)
{
    int hours;
    hours = rand() % x + 1;
    
    std::cout << name << " did " << hours << " hours of homework." << std::endl;
}

/*****************************************************************
* Student::displayPeople ()                                      *
******************************************************************/

void Student::displayPeople ()
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "GPA: " << gpa << std::endl;
}
