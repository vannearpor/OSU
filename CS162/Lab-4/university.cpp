/****************************************************************
**Author: Vannear Por
** Date: April 27, 2017
** Description: This is the implementation file for the University
** class which will contain the function declarations of the
** member functions which will set the University name, set the number
** of buildings and people, and will also create the objects for 
** the Building and People class.
*****************************************************************/

#include "university.hpp"
#include <iostream>

using std::string;
using std::cout;
using std::endl;

/***************************************************************
* Default Constructor                                          *
****************************************************************/

University::University ()
{
}

/***************************************************************
* Default Deconstructor                                        *
****************************************************************/

University::~University ()
{
}

/***************************************************************
* University::setUniversityName ()                             *
****************************************************************/

void University::setUniversityName (std::string name)
{
    universityName = name;
}

/****************************************************************
 * University::setBuildingNumber ()                             *
 ****************************************************************/

void University::setBuildingNumber (int x)
{
    n = x;
}

/****************************************************************
 * University::setPeopleNumber ()                             *
 ****************************************************************/

void University::setPeopleNumber (int y)
{
    m = y;
}

/***************************************************************
* University::displayAllBuildings ()                           *
****************************************************************/

void University::displayAllBuildings ()
{
    std::cout << "All University Buildings: " << std::endl;
    std::cout << b1.displayBuilding() << std::endl;
    std::cout << b2.displayBuilding() << std::endl;
    std::cout << b3.displayBuilding() << std::endl;
}

/***************************************************************
* University::displayAllPeople ()                              *
****************************************************************/

void University::displayAllPeople ()
{
    std::cout << "All University Students: " << std::endl;
    std::cout << student1.displayPeople() << std::endl;
    std::cout << student2.displayPeople() << std::endl;
    std::cout << student3.displayPeople() << std::endl;
    std::endl;
    std::cout << "All University Instructors: " << std::endl;
    std::cout << instructor1.displayPeople() << std::endl;
    std::cout << instructor2.displayPeople() << std::endl;
    std::cout << instructor3.displayPeople() << std::endl;
}

/***************************************************************
* University::setB1 ()                                         *
****************************************************************/

void University::setB1 (std::string name, int size, std::string address)
{
    b1.setBuildingName(name);
    b1.setBuildingSize(size);
    b1.setBuildingAddress(address);
}


/***************************************************************
 * University::setB2 ()                                         *
 ****************************************************************/

void University::setB2 (std::string name, int size, std::string address)
{
    b2.setBuildingName(name);
    b2.setBuildingSize(size);
    b2.setBuildingAddress(address);
}

/***************************************************************
 * University::setB3 ()                                         *
 ****************************************************************/

void University::setB3 (std::string name, int size, std::string address)
{
    b3.setBuildingName(name);
    b3.setBuildingSize(size);
    b3.setBuildingAddress(address);
}

/***************************************************************
 * University::setS1 ()                                         *
 ****************************************************************/

void University::setS1 (std::string n, int a)
{
    student1.setValues (n, a);
    student1.setGPA();
}

/***************************************************************
 * University::setS2 ()                                         *
 ****************************************************************/

void University::setS2 (std::string n, int a)
{
    student2.setValues (n, a);
    student2.setGPA();
}

/***************************************************************
 * University::setS3 ()                                         *
 ****************************************************************/

void University::setS3 (std::string n, int a)
{
    student3.setValues (n, a);
    student3.setGPA();
}

/***************************************************************
 * University::setI1 ()                                         *
 ****************************************************************/

void University::setI1 (std::string n, int a)
{
    instructor1.setValues (n, a);
    instructor1.setRating();
}

/***************************************************************
 * University::setI2 ()                                         *
 ****************************************************************/

void University::setI2 (std::string n, int a)
{
    instructor2.setValues (n, a);
    instructor2.setRating();
}

/***************************************************************
 * University::setI3 ()                                         *
 ****************************************************************/

void University::setI3 (std::string n, int a)
{
    instructor3.setValues (n, a);
    instructor3.setRating();
}

/***************************************************************
* University::s1DoWork()                                       *
****************************************************************/

void University::s1DoWork ()
{
    student1.do_work(10);
}

/***************************************************************
 * University::s2DoWork()                                       *
 ****************************************************************/

void University::s2DoWork ()
{
    student2.do_work(10);
}

/***************************************************************
 * University::s3DoWork()                                       *
 ****************************************************************/

void University::s3DoWork ()
{
    student3.do_work(10);
}

/***************************************************************
 * University::i1DoWork()                                       *
 ****************************************************************/

void University::i1DoWork ()
{
    instructor1.do_work(10);
}

/***************************************************************
 * University::i2DoWork()                                       *
 ****************************************************************/

void University::i2DoWork ()
{
    instructor2.do_work(10);
}

/***************************************************************
 * University::i3DoWork()                                       *
 ****************************************************************/

void University::i3DoWork ()
{
    instructor3.do_work(10);
}
