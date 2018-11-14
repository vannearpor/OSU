/*********************************************************************
** Author: Vannear Por
** Date: March 1, 2017
** Description: This fuction will take two parameters, an array of
** pointers to Students and the size of the array, and return the
** standard deviation of the student scores.
*********************************************************************/

#include <iostream>
#include <string>
#include <cmath>
#include "Student.hpp"
using namespace std;

double stdDev (Student *studentArray[], int size);

double stdDev (Student *studentArray[], int size)
{
	int i;
	double scoreTotal, scoreAverage, standardDeviation;

	scoreTotal = 0.0;
	scoreAverage = 0.0;
	standardDeviation = 0.0;

	for (int i = 0; i < size; i++)		//Get Total of Scores
	{
		scoreTotal += studentArray[i] -> getScore();
	}

	scoreAverage = scoreTotal/size;		//Get Average of Scores

	//Calculate Standard Deviation of Scores
	for (int i = 0; i < size; i++)
	{
		standardDeviation += pow ((studentArray[i] -> getScore()) - scoreTotal, 2);
	}

	return sqrt(standardDeviation/size);	//Complete Standard Deviation Calculation
}

