/******************************************************************
** Author: Vannear Por
** Date: February 8, 2017
** Description: This is the BankAccount class declaration 
** "header" file.			
******************************************************************/

#ifndef BANKACCOUNT_HPP
#define BANKACCOUNT_HPP

#include <string>
using namespace std;

// BankAccount Class Declaration
class BankAccount
{
	private:
		string customerName;
		string customerID;
		double customerBalance;

	public:
		BankAccount(string, string, double);	//Three Parameter Constructor

		string getCustomerName();		//Get Functions
		string getCustomerID();
		double getCustomerBalance();

		double withdraw (double);
		double deposit (double);
};
#endif

