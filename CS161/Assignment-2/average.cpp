/**********************************************************************************************
** Author: Vannear Por
** Date: January 18, 2017
** Description: This program will ask the user for five numbers and will output the average
**********************************************************************************************/

#include <iostream>
using namespace std;

int main()
{
   double number1;
   double number2;
   double number3;
   double number4;
   double number5;
   int numberOfNumbers;
   double average;

   cout << "Please enter five numbers. ";
   cin >> number1;
   cin >> number2;
   cin >> number3;
   cin >> number4;
   cin >> number5;
   cout << "\nThe average of those numbers is:\n";

   //Compute and display the average of the five numbers
   numberOfNumbers = 5;
   average = (number1 + number2 + number3 + number4 + number5) / numberOfNumbers;
   cout << average << endl;
   return 0;
} 

 
