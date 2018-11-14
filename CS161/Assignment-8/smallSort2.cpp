/*********************************************************************
** Author: Vannear Por
** Date: March 1, 2017
** Description: This function will take the address of three
** integer variables and sort the values in the addresses in
** ascending order.
*********************************************************************/

#include <iostream>
#include <string>
using namespace std;

void smallSort2 (int *num1, int *num2, int *num3);

/*********************************************************************
** smallSort: This function takes the address of three integer       *
** variables and sort the values in the address in ascending order.  *
*********************************************************************/

void smallSort2 (int *num1, int *num2, int *num3)
{
	int testHold1, testHold2, testHold3, testHold4; 

	if (*num1 > *num2)
	{
		testHold1 = *num1;
		*num1 = *num2;
		*num2 = testHold1;
	}

	if (*num2 > *num3)
	{
		testHold2 = *num2;
		*num2 = *num3;
		*num3 = testHold2;
	}

	if (*num1 > *num2) 
	{
		testHold3 = *num1;
		*num1 = *num2;
		*num2 = testHold3;
	}

	if (*num2 > *num3)
	{
		testHold4 = *num2;
		*num2 = *num3;
		*num3 = testHold4;
	}
}

//int main ()
//{
//	int a = 14;
//	int b = -90;
//	int c = 2;
//
//	smallSort2 (&a, &b, &c);
//
//	cout << a << ", " << b << ", " << c << endl;
//}
//	
