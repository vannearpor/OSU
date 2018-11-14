/*************************************************************
** Author: Vannear Por
** Date: February 22, 2017
** Description: This program contains a function that takes
** an array and it's size and the parameters and returns a
** vector that contains the mode(s).
*************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findMode (int array[], int size)
{
	//Vector declaration
	vector<int> modesFound;

	//Array declaration that holds numbers
	int numberValue[size];

	//Array declaration that holds count of the numbers
	int numberCount[size];

	//Initialize Arrays
	for (int i=0; i < size; i++)
	{
		numberValue[i] = NULL;
		numberCount[i] = NULL;
	}

	//Loop that goes through array for numbers
	for (int i=0; i < size; i++)
	{
		bool intPresent = false;
		for (int j=0; j < size; j++)
		{
			if(numberValue[j] == array[i])
			{
				intPresent = true;
			}
		}

		//save the number if isn't already present
		if (intPresent == false)
		{
			numberValue[i] = array[i];
		}
	}

	//Loop that goes through array and counts numbers present
	for (int i=0; i < size; i++)
	{
		for (int j=0; j < size; j++)			//for every number
		{
			if (numberValue[i] == array[j])		//count occurance of number
			{
				numberCount[i]++;
			}
		}
	}
	
	//Now find the highest number
	int highNum = 0;
	int highNumPlace = 0;
	for (int i=0; i < size; i++)
	{
		if (numberCount[i] > highNum)
		{
			highNum = numberCount[i];
			highNumPlace = i;
		}
	}	

	//Input items into the vector
	for (int i=0; i < size; i++)
	{
		if(numberCount[i] == highNum)
		{
			modesFound.push_back (numberValue[i]);
		}
	}

	sort(modesFound.begin(), modesFound.end());

	return modesFound;
}

