/*************************************************************
** Author: Vannear Por
** Date: February 8, 2017
** Description: This is the BankAccount class implementation
** file.
*************************************************************/

#include <iostream>
#include <string>
#include "BankAccount.hpp"

using namespace std;

/************************************************************
 * 			 Constructor			    *
 ***********************************************************/

BankAccount::BankAccount (string name, string id, double bal)
{
	customerName = name;
	customerID = id;
	customerBalance = bal;
}

/***********************************************************
 * 		BankAccount::getCustomerName		   *
 * This function returns the Customer's name.		   *
 * ********************************************************/

string BankAccount::getCustomerName()
{
	return customerName;
}

/**********************************************************
 * 		BankAccount::getCustomerID		  *
 * This function returns the Customer's ID		  *
 * *******************************************************/

string BankAccount::getCustomerID()
{
	return customerID;
}

/*********************************************************
 * 		BankAccount::getCustomerBalance		 *
 * This function returns the Customer's Balance		 *
 * ******************************************************/

double BankAccount::getCustomerBalance()
{
	return customerBalance;
}

/********************************************************
 * 		BankAccount::withdraw()			*
 * This function decreases balance by an amount.	*
 * *****************************************************/

double BankAccount::withdraw(double withd)
{
	double newBalance = customerBalance -= withd;
	return newBalance;
}

/*******************************************************
 * 		BankAccount::deposit()		       *
 * This function increases balance by an amount.       *
 * ****************************************************/

double BankAccount::deposit(double depos)
{
	double newBalance = customerBalance += depos;
	return newBalance;
}

