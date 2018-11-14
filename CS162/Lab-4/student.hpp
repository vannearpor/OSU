/****************************************************************
 **Author: Vannear Por
 ** Date: April 27, 2017
 ** Description: This is the header file for the student class.
 ** It is a derived class from the people base class and will contain
 ** a member variable and functions for the GPA and hours of work done.
 *****************************************************************/

#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>

class Student: public People
{
    private:
        double gpa;
    
    public:
        void setGPA ();
        void do_work (int x);
        void displayPeople ();
};

#endif
