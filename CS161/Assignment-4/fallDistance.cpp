/************************************************************
** Author: Vannear Por
** Date: February 1, 2017
** Description: This function will use the value of given
** time to determine the distance an object will fall
** due to gravity
************************************************************/

#include <iostream>
using namespace std;

/****************************************************
 *                  fallDistance                    *
 *  This function returns the fallDistance          *
 ****************************************************/

double fallDistance(double seconds)
{
	double distance,
	       gConstant,
               fallTime;

	gConstant = 9.8;
	fallTime = seconds;
	
	distance = (1.0 / 2.0)*(gConstant)*(fallTime * fallTime);

	return distance;
}


