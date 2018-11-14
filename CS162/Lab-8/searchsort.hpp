/***************************************************************
** Author: Vannear Por
** Date: May 27, 2017
** Description: This is the Searchsort class header file which
** contains the class member function prototyeps which will
** search and sort values in created .txt files containing
** integer values .
****************************************************************/

#ifndef SEARCHSORT_HPP
#define SEARCHSORT_HPP

#include <iostream>
#include <fstream>

using std::string;

class Searchsort
{
    public:
        void linearSearch (int, string);
        void bubbleSort (string, string);
        void binarySearch (int, string);
};

#endif


