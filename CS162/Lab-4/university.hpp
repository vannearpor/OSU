/****************************************************************
**Author: Vannear Por
** Date: April 27, 2017
** Description: This is the header file for the University
** class which will contain the member variables of the name,
** number of buildings, number of people. It will also contain
** the Building and People class as members. It contains the member
** functions that will provide methods that will print the info
** of all buildings and print the name of all people.
*****************************************************************/

#ifndef UNIVERSITY_HPP
#define UNIVERSITY_HPP

#include <iostream>
using std::cout;
using std::endl;
using std::string;

class University
{
    private:
        std::string universityName;
        int n;
        int m;
        Building b1, b2, b3;
        Student student1, student2, student3;
        Instructor instructor1, instructor2, instructor3;
    
    public:
        University();
        ~University();
        void setUniversityName (std::string name);
        void setBuildingNumber (int);
        void setPeopleNumber (int);
        void displayAllBuildings ();
        void displayAllPeople ();
        void setB1 (std::string name, int size, std::string address);
        void setB2 (std::string name, int size, std::string address);
        void setB3 (std::string name, int size, std::string address);
        void setS1 (std::string n, int a);
        void setS2 (std::string n, int a);
        void setS3 (std::string n, int a);
        void setI1 (std::string n, int a);
        void setI2 (std::string n, int a);
        void setI3 (std::string n, int a);
        void s1DoWork ();
        void s2DoWork ();
        void s3DoWork ();
        void i1DoWork ();
        void i2DoWork ();
        void i3DoWork ();
};

#endif
