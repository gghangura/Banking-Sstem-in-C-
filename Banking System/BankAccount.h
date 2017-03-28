#pragma once

#include <string>

using namespace std;

class BankAccount 
{
public:
	BankAccount(string fName, string lName, double balance);
	~BankAccount();
	double AvailableBalance();
	BankAccount();
	virtual int GetAccountNumber();
	virtual void DisplayAccountInfo();
	virtual void UpdateFirstName(string newVal);
	virtual void UpdateLastName(string newVal);
	virtual void Widraw(double amount);
	virtual void Deposit(double amount);
	int GetBalance();

protected:
	string firstName;
	string lastName;
	double balance;
	int accountNumber;
	int GenerateAccountNumber();
};