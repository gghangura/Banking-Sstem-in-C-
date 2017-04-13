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

	inline friend ostream& operator<< (ostream& stream, BankAccount* acc) {
		return stream << endl << "First Name : " << acc->GetFirstName() << endl << "Last Name : " << acc->GetLastName() << endl << "Account Number : " << acc->GetAccountNumber() << endl << "Balance : " << acc->GetBalance() << endl << endl;
	}

	template <typename T>
	inline bool Max(T const& a, T const& b) {
		return a <= b ? false : true;
	}

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