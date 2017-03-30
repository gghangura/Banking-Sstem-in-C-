
#include "SavingAccount.h"

SavingsAccount::SavingsAccount(string fName, string lName, double balance) : BankAccount(fName, lName, balance)
{

}

SavingsAccount::~SavingsAccount()
{

}

void SavingsAccount::Addprofit()
{
	cout << "Another Month Passed By" << endl;
	double profit = balance * 0.025;
	balance += profit;
	cout << "Profit Added: "<< profit << endl;
	cout << "Updated Balance: " << balance << endl;
}

