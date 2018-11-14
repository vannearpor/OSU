/******************************************************************************
** Author: Vannear Por
** Date: February 8, 2017
** Description: This is the Box class declaration "header" file.
******************************************************************************/

#ifndef BOX_HPP
#define BOX_HPP

// Box Class Declaration
class Box
{
	private:
		double height;
		double width;
		double length;

	public:
		Box();				//Default Construtor
		Box(double, double, double);	//Three Parameter Constructor

		bool setHeight(double);		//Set Functions
		bool setWidth(double);
		bool setLength(double);

		double getVolume();		//Functions
		double getSurfaceArea();
};
#endif
