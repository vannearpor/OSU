/************************************************************************************************************************
** Author: Vannear Por
** Date: January 18, 2017
** Description: This program will ask the user to enter a temperature in Celsius and convert that number into Fahrenheit
*************************************************************************************************************************/
 
#include <iostream>
using namespace std;

int main()
{
   double celsius;
   double fahrenheit;

   cout << "Please enter a Celsius temperature. ";
   cin >> celsius;
   cout << "\nThe equivalent Fahrenheit temperature is:\n";

   //Compute and display the new temperature in Fahrenheit
   fahrenheit = ((9.0 / 5.0) * celsius) + 32.0;
   cout << fahrenheit << endl;
   return 0;
}
