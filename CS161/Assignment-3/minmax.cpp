/***********************************************************
** Author: Vannear Por
** Date: January 25, 2017
** Description: This program will ask the user how many integers they 
** would like to enter, prompt the user to enter that many integers,
** and will display the minimum and maximum numbers.
***********************************************************/

#include <iostream>
using namespace std;

int main()
{
	//Establish variables
	int min;
	int max;
	int number_of_integers;
	int num;

	cout << "How many integers would you like to enter?\n ";
	cin >> number_of_integers;
	cout << "Please enter " << number_of_integers << " integers.\n";
	cin >> num;

	//Set first number entered to both min and max
	min = max = num;

	//Compare numbers as they are being entered
	for (int i = 1; i < number_of_integers; i++)
	{
		cin >> num;

		if (num < min)
			min = num;

		if (num > max)
			max = num;
	}
	
	cout << "min: " << min << endl;
	cout << "max: " << max << endl;
	return 0;
}
