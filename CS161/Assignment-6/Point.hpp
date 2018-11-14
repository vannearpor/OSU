/***********************************************************
** Author: Vannear Por
** Date: February 15, 2017
** Description: This declares the class Point "header" file
************************************************************/

#ifndef POINT_HPP
#define POINT_HPP
#include <iostream>
#include <math.h>

//Point Class Declaration
class Point
{
	private:
		double coordX;
		double coordY;

	public:
		Point();			//Default Constructor
		Point(double, double);		//Two Parameter Constructor

		double getXCoord();		//Get Functions
		double getYCoord();

		void setXCoord(double);		//Set Functions
		void setYCoord(double);		

		double distanceTo(const Point&);	//Functions
};
#endif
