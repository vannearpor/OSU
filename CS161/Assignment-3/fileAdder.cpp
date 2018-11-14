/*****************************************************
** Author: Vannear Por
** Date: January 25, 2017
** Description: This program will prompt the user for
** a name of a file and try to open that file; if the 
** file can be opened, the program will read the list
** of integers in the file
*******************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

int main ()
{
	//Set up variables and files
	ifstream input_file;
	ofstream output_file;
	string file_name;
	int num;
	double total = 0.0;

	//Asks user to enter the file name
	cout << "Please enter the name of the file.\n ";
	cin >> file_name;

	input_file.open(file_name.c_str());

	//Add up integers within file
	if (input_file)
	{
		while (input_file >> num)
		{
			total += num;
		}
	}
	
	else
	{
		cout << "could not access file\n ";
		return 0;
	}

	//Close input file
	input_file.close();

	//Open output file
	output_file.open("sum.txt");

	//Write the sum of integers in file
	output_file << total;

	//Close output file
	output_file.close();

	return 0;
} 
