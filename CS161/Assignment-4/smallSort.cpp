/**************************************************************
** Author: Vannear Por
** Date: February 1, 2017
** Description: This function will sort the three parameters
** into ascending order from lowest to highest value
**************************************************************/

#include <iostream>
using namespace std;

/*****************************************
 * 		smallSort		 *
 * This function will sort parameters    *
 *****************************************/

void smallSort(int &num1,int &num2,int &num3)
{
	int first, second, third;
	if (num1 > num2)
	{
		num1 = num2;
		num2 = first;
	}

	if (num2 > num3)
	{
		second = num2;
		num2 = num3;
		num3 = second;
	}

	if (num1 > num2)
	{
		third = num1;
		num1 = num2;
		num2 = third;
	}
}


