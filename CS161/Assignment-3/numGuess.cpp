/***********************************************
** Author: Vannear Por
** Date: January 25, 2017
** Description: This program will ask the user
** for an integer and have a player try to guess
** the integer until they are correct
************************************************/

#include <iostream>
using namespace std;

int main()
{
	int correct_number;
	int guess;
	int tries;

	tries = 1;

	cout << "Enter the number for the player to guess.\n ";
	cin >> correct_number;

	do
	{
		cout << "Enter your guess.\n ";
		cin >> guess;

		//Guess is too high
		if (guess > correct_number)
		{
			cout << "Too high - try again.\n ";
		}
		
		//Guess is too low
		else if (guess < correct_number)
		{
			cout << "Too low - try again.\n ";
		}

		//When correct number is guessed, number of tries is displayed
		//to the player
		else
		{
			cout << "You guessed it in " << tries << " tries.\n";
		}
		tries++;
	}
	while (! (correct_number == guess));
	
	return 0;
}
