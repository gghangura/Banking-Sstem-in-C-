#pragma once

#include "BankAccount.h"
#include <iostream>

using namespace std;

class SavingsAccount : BankAccount
{
public:
	SavingsAccount(string fName, string lName, double balance);
	~SavingsAccount();
	SavingsAccount();
	virtual void DisplayAccountInfo();
	virtual int GetAccountNumber();
	virtual void UpdateFirstName(string newVal);
	virtual void UpdateLastName(string newVal);
	virtual void Widraw(double amount);
	virtual void Deposit(double amount);
	void AddProfit();

private:
	BankAccount account;

};

