/****************************************************************
 **Author: Vannear Por
 ** Date: April 27, 2017
 ** Description: This is the header file for the instructor class.
 ** It is a derived class from the people base class and will contain
 ** a member variable and functions for the instructor rating
 ** and hours of work done.
 *****************************************************************/

#ifndef INSTRUCTOR_HPP
#define INSTRUCTOR_HPP

#include <iostream>

class Instructor: public People
{
    private:
        double rating;
    
    public:
        void setRating ();
        void do_work (int x);
        void displayPeople ();
    
};

#endif
