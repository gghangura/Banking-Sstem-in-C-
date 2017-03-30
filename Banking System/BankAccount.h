#pragma once

#include <string>
#include <cstdio>

using namespace std;

class BankAccount 
{
public:
	
	double AvailableBalance();
	string GetFirstName();
	string GetLastName();
	int GetAccountNumber();
	void UpdateFirstName(string newVal);
	void UpdateLastName(string newVal);
	void Widraw(double amount);
	void Deposit(double amount);
	int GetBalance();
	virtual void IncrementCheques();
	virtual void Addprofit();

protected:

	BankAccount(string fName, string lName, double bal);
	virtual ~BankAccount();
	BankAccount();
	string firstName;
	string lastName;
	double balance;
	int accountNumber;
	int GenerateAccountNumber();
};