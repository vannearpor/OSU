/**********************************************************************************************************************
** Author: Vannear Por
** Date: January 18, 2017
** Description: This program will ask the user for an integer number of cents and will return the number of each coin
**********************************************************************************************************************/

#include <iostream>
using namespace std;

int main()
{
   int cents;
   int quarters;
   int dimes;
   int nickels;
   int pennies;
   int changeAfterQuarters;
   int changeAfterDimes;
   int changeAfterNickels;

   cout << "Please enter an amount in cents less than a dollar. ";
   cin >> cents;
   cout << "\nYour change will be:\n";

   //Compute and display the change
   //Quarters
   quarters = cents / 25;
   changeAfterQuarters = cents % 25;
   //Dimes
   dimes = changeAfterQuarters / 10;
   changeAfterDimes = changeAfterQuarters % 10;
   //Nickels
   nickels = changeAfterDimes / 5;
   changeAfterNickels = changeAfterDimes % 5;
   //Pennies
   pennies = changeAfterNickels;
  
   //Display Results
   cout << "Q: " << quarters << endl;
   cout << "D: " << dimes << endl;
   cout << "N: " << nickels << endl;
   cout << "P: " << pennies << endl;
   return 0;
}
