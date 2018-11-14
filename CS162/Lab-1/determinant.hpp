/****************************************************************
** Author: Vannear Por
** Date: April 8, 2017
** Description: This is the determinant header file containing
** the function prototypes for the determinant functions which
** will take 2 parameters, a pointer to a 2D array and an integer
** representing the size of the square array. The function
** will return an integer value which is the determinant of the
** matrix stored in the 2D array.
*****************************************************************/

#include <iostream>

#ifndef DETERMINANT_HPP
#define DETERMINANT_HPP

class Determinant
{

	private:
	
	public:
		Determinant ();
		int getDeterminant (int* twoDArray[], int size);

};

#endif	

