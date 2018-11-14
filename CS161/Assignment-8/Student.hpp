/************************************************************
** Author: Vannear Por
** Date: March 1, 2017
** Description: This is the Student class declaration
** "header" file.
************************************************************/

#ifndef STUDENT_HPP
#define STUDENT_HPP
#include <iostream>
#include <string>
using namespace std;

class Student
{
	private:
		string name;
		double score;

	public:
		Student();			//Default Constructor
		Student(string n, double s);	//Two Parameter Constructor

		string getName();		//Get Functions
		double getScore();
};

#endif 
