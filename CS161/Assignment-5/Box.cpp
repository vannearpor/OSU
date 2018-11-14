/**************************************************************
** Author: Vannear Por
** Date: February 8, 2017
** Description: This is the Box class implementation file.
**************************************************************/

#include "Box.hpp"

/**************************************************************
 * 			Default Constructor		      *
 *************************************************************/

Box::Box()
{
	height = 1.0;
	width = 1.0;
	length = 1.0;
}

/**************************************************************
 * 	        	Three Parameters Constructor	      *
 *************************************************************/

Box::Box(double hei, double w, double len)
{
	setHeight(hei);
	setWidth(w);
	setLength(len);
} 

/**************************************************************
*			Box::setHeight			      *
* If the argument passed to the setHeight function is greater *
* than zero, it is copied into the member variable height,    *
* and true is returned. If the argument is zero or negative,  *
* the value of height remains unchanged and false is returned.*
* ************************************************************/

bool Box::setHeight(double hei)
{
	bool validData = true;
	
	//checks if hei is valid and copies into height
	if (hei > 0)	
		height = hei;
	//else leave height unchanged
	else
		validData = false;

	return validData;
} 

/**************************************************************
 * 			Box::setWidth			      *
 * If the argument passed to the setWidth fuction is greater  *
 * than zero, it is copied into the member variable width,    *
 * and true is returned. If the argument is zero or negative, *
 * the value of width remains unchanged and false is returned.*
 * ***********************************************************/

bool Box::setWidth(double w)
{
	bool validData = true;

	//checks if w is valid and copies into width
	if (w > 0)
		width = w;
	//else leave width unchanged
	else
		validData = false;

	return validData;
}

/***************************************************************
 * 			Box::setLength			       *
 * If the argument passed to the setLength function is greater *
 * than zero, it is copied into the member variable length,    *
 * and true is returned. If the argument is zero or negative,  *
 * the value of length remains unchanged and false is returned.*
 * ************************************************************/

bool Box::setLength(double len)
{
	bool validData = true;

	//checks if len is valid and copies into length
	if (len > 0)
		length = len;
	//else leave length unchanged
	else
		validData = false;

	return validData;
}

/**************************************************************
 * 			Box::getVolume			      *
 * This function calculates and returns the volume of the box.*
 * ***********************************************************/

double Box::getVolume()
{
	return (length * width * height);
}

/**************************************************************
 * 			Box::getSurfaceArea		      *
 * This function calculates and returns the surface area      *
 * of the box.						      *
 * ***********************************************************/

double Box::getSurfaceArea()
{
	return ((2*length*width) + (2*length*height) + (2*width*height));
}

