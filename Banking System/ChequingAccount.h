#pragma once

#include "BankAccount.h"
#include <iostream>

using namespace std;

class ChequingAccount : BankAccount
{
public:
	ChequingAccount(string fName, string lName, double balance);
	ChequingAccount();
	~ChequingAccount();
	void GiveCheque();
	virtual void DisplayAccountInfo();
	virtual int GetAccountNumber();
	virtual void UpdateFirstName(string newVal);
	virtual void UpdateLastName(string newVal);
	virtual void Widraw(double amount);
	virtual void Deposit(double amount);

private:
	int numberOfCheques;
	BankAccount account;
};

