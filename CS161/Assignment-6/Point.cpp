/**************************************************************
** Author: Vannear Por
** Date: February 15, 2017
** Description: This class takes two Points with an X and Y
** coordinate and uses methods to generate the distance
** between the two Points.
***************************************************************/

#include <iostream>
#include <math.h>
#include "Point.hpp"
using namespace std;

/*********************************
 * Default Constructor		 *
 ********************************/

Point::Point()
{
	coordX = 0.0;
	coordY = 0.0;
}

/********************************
 * Two Parameter Constructor    *
 *******************************/

Point::Point(double x, double y) 
{
	setXCoord(x);
	setYCoord(y);
}

/********************************
 * Point::setXCoord		*
 * Sets the X Coordinate of a   *
 * point.			*
 *******************************/

void Point::setXCoord(double x)
{
	coordX = x;
}

/**********************************
 * Point::setYCoord		  *
 * Sets the Y Coordinate of a	  *
 * point.			  *
 *********************************/

void Point::setYCoord(double y)
{
	coordY = y;
}

/**********************************
 * Point::getXCoord		  *
 * Returns the X Coordinate of a  *
 * point.			  *
 *********************************/

double Point::getXCoord()
{
	return coordX;
}

/**********************************
 * Point::getYCoord		  *
 * Returns the Y Coordinate of a  *
 * point.			  *
 *********************************/

double Point::getYCoord()
{
	return coordY;
}

/********************************************************
 * 		Point::distanceTo			*
 * This function takes a constant reference to another  *
 * point as parameter and returns the distance between  *
 * both points.						*
 *******************************************************/

double Point::distanceTo(const Point& otherPoint)
{
	double x1,
	       x2,
	       y1,
	       y2;

	double distanceX,
	       distanceY,
	       distanceSq,
	       distance;

	x1 = coordX;
	x2 = otherPoint.coordX;
	y1 = coordY;
	y2 = otherPoint.coordY;

	distanceX = x1 - x2;
	distanceY = y1 - y2;
	distanceSq = pow(distanceX, 2) + pow(distanceY, 2);
	distance = sqrt(distanceSq);

	return distance;
}			 
