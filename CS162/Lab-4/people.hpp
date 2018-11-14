/****************************************************************
**Author: Vannear Por
** Date: April 27, 2017
** Description: This is the header file for the people abstract
** class which will serve as the base class for the derived 
** student class and instructor class. It will contain the base
** member variables and member functions.
*****************************************************************/

#ifndef PEOPLE_HPP
#define PEOPLE_HPP

#include <iostream>
using std::string;


class People
{
    protected:
        std::string name;
        int age;
    
    public:
        People() {};
        ~People() {};
        void setValues (std::string n, int a)
            { name = n; age = a;}
        virtual void do_work (int x) = 0;
        virtual void displayPeople () = 0;
};

#endif
