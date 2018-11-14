/********************************************************************
** Author: Vannear Por
** Date: February 15, 2017
** Description: This class will take two Point parameters as its
** endpoints and use methods to calculate the length of the line
** segment using the distanceTo method on its endpoints. It also
** will use a method to calculate the slope of the line segment.
********************************************************************/

#include "LineSegment.hpp"
#include <iostream>
#include <math.h>
using namespace std;

/********************************************************************
* Two Parameter Constructor					    *
********************************************************************/

LineSegment::LineSegment(Point point1, Point point2)
{
	setEnd1(point1.getXCoord(), point1.getYCoord());
	setEnd2(point2.getXCoord(), point2.getYCoord());
}

/*******************************************************************
* LineSegment::setEnd1						   *
* The argument passed are saved into the member class p1.	   *
*******************************************************************/

void LineSegment::setEnd1(double coordX, double coordY)
{
	p1.setXCoord(coordX);
	p1.setYCoord(coordY);
} 

/*******************************************************************
* LineSegment::setEnd2						   *
* The argument passed are saved into the member class p2.	   *
*******************************************************************/

void LineSegment::setEnd2(double coordX, double coordY)
{
	p2.setXCoord(coordX);
	p2.setYCoord(coordY);
}

/******************************************************************
* LineSegment::getEnd1						  *
* This function returns the first point of the line segment.      *
******************************************************************/

Point LineSegment::getEnd1()
{
	return p1;
}

/******************************************************************
* LineSegment::getEnd2						  *
* This function returns the second point of the line segment.     *
******************************************************************/

Point LineSegment::getEnd2()
{
	return p2;
}

/******************************************************************
* LineSegment::length						  *
* This function returns the length of the line segment.		  *
******************************************************************/

double LineSegment::length()
{
	double distance;
	
	distance = p1.distanceTo(p2);

	return distance;
}

/******************************************************************
* LineSegment::slope						  *
* This function returns the slope of the line segment.		  *
******************************************************************/

double LineSegment::slope()
{
	double slope;

	slope = ((p1.getYCoord() - p2.getYCoord()) / (p1.getXCoord() - p2.getXCoord()));

	return slope;
}
