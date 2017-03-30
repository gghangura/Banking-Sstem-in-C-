#include"BankAccount.h"
#include <time.h>
#include <iostream>

using namespace std;

BankAccount::BankAccount(string fName, string lName, double bal): firstName(fName), lastName(lName), balance(bal)
{
	firstName = fName;
	lastName = lName;
	balance = bal;
	accountNumber = GenerateAccountNumber();
}

BankAccount::~BankAccount()
{

}

BankAccount::BankAccount()
{
}

int BankAccount::GenerateAccountNumber()
{
	srand(time(NULL));
	int y = rand() % 10;;
	for (int i = 1; i < 6; ++i) {
		int x = rand() % 10;
		switch (i)
		{
		case 1:
			x = x * 10;
			break;
		case 2:
			x = x * 100;
			break;
		case 3:
			x = x * 1000;
			break;
		case 4:
			x = x * 10000;
			break;
		case 5:
			x = x * 100000;
			break;
		default:
			break;
		}

		y += x;
	}


	return y;
}
double BankAccount::AvailableBalance() {
	return balance;
}
int BankAccount::GetAccountNumber() {
	return accountNumber;
}

string BankAccount::GetFirstName() {
	return firstName;
}
string BankAccount::GetLastName() {
	return lastName;
}


void BankAccount::Widraw(double amount) {
	if (balance > amount)
	{
		cout << endl << endl;
		cout << "Amount Widraw Success" << endl;
		balance -= amount;
		cout << "New Balance: " << balance << endl;
	}
	else {
		cout << "Not Enough Balance"<< endl;
	}
}
void BankAccount::Deposit(double amount) {
	cout << endl << endl;
	cout << "Amount Deposit Success" << endl;
	balance += amount;
	cout << "New Balance: " << balance << endl;
}

void BankAccount::UpdateFirstName(string newVal) {
	firstName = newVal;
	cout << "First Name Update Success" << endl;
}
void BankAccount::UpdateLastName(string newVal) {
	lastName = newVal;
	cout << "First Last Update Success" << endl;
}

int BankAccount::GetBalance() {
	return balance;
}

void BankAccount::IncrementCheques()
{
}

void BankAccount::Addprofit()
{
}


