/***********************************************************
** Author: Vannear Por
** Date: February 1, 2017
** Description: This function will take a starting integer
** as a parameter and create a hailstone sequence which
** will return the number of steps it takes to reach 1
***********************************************************/

#include <iostream>
using namespace std;

/**********************************************************
 * 			hailstone			  *
 * This function will produce a hailstone sequence and    *
 * will return the number of steps it takes to reach 1    *
 **********************************************************/
 
int hailstone(int start) 
{
	int count = 0;

	while (start != 1)
	{
	       if (start % 2 == 0)
	       {
		   start = (start / 2);
		   count++;
	       }
	       else if (start % 2 == 1)
	       {
		   start = (start * 3) + 1;
	           count++;
	       }
	}
	return count;
}			 	
