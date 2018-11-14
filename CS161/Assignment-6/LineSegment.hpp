/***************************************************************************
** Author: Vannear Por
** Date: February 15, 2017
** Description: This is the LineSegment class declaration "header" file.
***************************************************************************/

#ifndef LINESEGMENT_HPP
#define LINESEGMENT_HPP
#include <iostream>
#include <math.h>
#include "Point.hpp"

//LineSegment Class Declaration
class LineSegment
{
	private:
		Point p1;
		Point p2;

	public:
		LineSegment();			//Default Constructor
		LineSegment(Point, Point);	//Two Parameter Constructor

		void setEnd1(double, double);	//Set Functions
		void setEnd2(double, double);

		Point getEnd1();		//Get Functions
		Point getEnd2();		

		double length();
		double slope();
};

#endif
