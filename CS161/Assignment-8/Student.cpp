/*******************************************************************
** Author: Vannear Por
** Date: March 1, 2017
** Description: This class function will take two Parameters to
** get the name and score of a Student.
*******************************************************************/

#include <iostream>
#include <string>
#include "Student.hpp"
using namespace std;

/*****************************************************************
 * Two Parameter Constructor					 *
 ****************************************************************/

Student::Student (string n, double s)
{
	name = n;
	score = s;
}

/*****************************************************************
 * Student::getName						 *
 * The function returns the name of the Student			 *
 ****************************************************************/

string Student::getName()
{
	return name;
}

/****************************************************************
 * Student::getScore()						*
 * The function returns the score of the Student		*
 ***************************************************************/

double Student::getScore()
{
	return score;
}   
