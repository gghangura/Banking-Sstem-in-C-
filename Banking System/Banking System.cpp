// Banking System.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SavingAccount.h"
#include "ChequingAccount.h"
#include <cstdio>
#include <iostream>

using namespace std;

void MakeNewAccount();
char DisplayMenu();
void ShowOptions(BankAccount *acc);
void updateAccount(BankAccount *acc, int index, char userInput);
bool IsType(BankAccount* src);
//void DisplayAccountInfo(BankAccount *acc);



BankAccount **accounts = new BankAccount*[5];
int noOfAccounts = 0;

int main()
{
	cout << "Welcome to Your Bank" << endl;

	for (;;)
	{
		char input = DisplayMenu();
		if (input == 'a')
		{
			if (noOfAccounts == 0)
			{
				cout << "Add Accounts First";
			}
			else
			{
				for (int i = 0; i < noOfAccounts; i++)
				{
					//DisplayAccountInfo(accounts[i]);
					cout << accounts[i];
				}
			}
		}
		else if (input == 'b')
		{
			if (noOfAccounts < 5)
			{
				MakeNewAccount();
			}
			else
			{
				cout << "Cannot Add new Account";
			}

		}
		else if (input == 'c')
		{
			if (noOfAccounts > 0)
			{
				bool accountFound = false;
					int userInputForAccNo;
					cout << "Enter Account Number" << endl;
					cin >> userInputForAccNo;
					char userResponse;
					for (int i = 0; i < noOfAccounts; i++)
					{
						if (accounts[i]->GetAccountNumber() == userInputForAccNo) {
							accountFound = true;
							for (;;) {
								//DisplayAccountInfo(accounts[i]);
								cout << accounts[i];
								ShowOptions(accounts[i]);
								cin >> userResponse;
								if (userResponse == 'f')
								{
									break;
								}
								else
								{
									updateAccount(accounts[i], i, userResponse);
								}
							}
						}
					}
					if (!accountFound)
					{
						cout << "No Account Found!!" << endl;
					}
			}
			else
			{
				cout << "No Accounts";
			}
		}
		else if (input == 'd')
		{
			break;
		}
	}

    return 0;
}

char DisplayMenu() {
	cout << endl << endl;
	cout << "Please Choose One Of the Options Below" << endl;
	cout << "a: Display all Accounts" << endl;
	cout << "b: Add a new Bank Account" << endl;
	cout << "c: Edit an existing Bank Account" << endl;
	cout << "d: Exit" << endl;
	char userInput;
	cin >> userInput;

	return userInput;
}

void MakeNewAccount() {
	cout << endl << endl;
	string fName, lName;
	char typeOfAcc;
	double initialBalance;
	cout << "Enter First Name" << endl;
	cin >> fName;
	cout << "Enter Last Name" << endl;
	cin >> lName;
	cout << "Enter the Balance to keep after opening the Account" << endl;
	cin >> initialBalance;
	cout << "Select the type of Account" << endl;
	cout << "\t a: Chequing" << endl;
	cout << "\t b: Saving" << endl;
	
	cin >> typeOfAcc;
	if (typeOfAcc == 'a')
	{
		accounts[noOfAccounts] = new ChequingAccount(fName, lName, initialBalance);
		cout << "Your Account Number is:" << accounts[noOfAccounts]->GetAccountNumber() << endl;

		noOfAccounts++;
	}
	else
	{
		accounts[noOfAccounts] = new SavingsAccount(fName, lName, initialBalance);
		cout << "Your Account Number is:" << accounts[noOfAccounts]->GetAccountNumber() << endl;
		noOfAccounts++;
	}
	cout << "ACCOUNT OPENED" << endl;
}

void ShowOptions(BankAccount *acc) {
	cout << endl << endl;
	cout << "a:Edit First Name" << endl;
	cout << "b:Edit Last Name" << endl;
	cout << "c:Deposit Money" << endl;
	cout << "d:Withdraw Money" << endl;

	if (IsType(acc))
	{
		cout << "e:Add Profit" << endl;
	}
	else
	{
		cout << "e:Increment Cheques Written" << endl;
	}
	cout << "f:Return to Main Menu" << endl;
}

void updateAccount(BankAccount *acc, int index, char userInput) {
	string newVal;
	double amount;
	switch (userInput)
	{
	case 'a':
		cout << "Enter New First Name" << endl;
		cin >> newVal;
		acc->UpdateFirstName(newVal);
		break;
	case 'b':
		cout << "Enter New Last Name" << endl;
		cin >> newVal;
		acc->UpdateLastName(newVal);
		break;
	case 'c':
		cout << "Enter the amount to Deposit" << endl;
		cin >> amount;
		acc->Deposit(amount);
		break;
	case 'd':
		cout << "Enter the amount to Withdraw" << endl;
		cin >> amount;
		acc->Widraw(amount);
		break;
	case 'e':
		if (IsType(acc))
		{
			acc->Addprofit();
		}
		else
		{
			acc->IncrementCheques();
		}
		break;
	default:
		break;
	}
	accounts[index] = acc;
}


//void DisplayAccountInfo(BankAccount *acc) {
//
//	cout << endl << endl;
//	if (IsType(acc))
//	{
//		cout << "This is a Savings Account" << endl;
//	}
//	else
//	{
//		std::cout << "This is a Chequing Account" << std::endl;
//		
//	}
//
//	cout << "First Name is: " << acc->GetFirstName() << endl;
//	cout << "Last Name is: " << acc->GetLastName() << endl;
//	cout.precision(17);
//	cout << "Current Balance is: " << acc->GetBalance() << endl;
//	cout << "Account Number is: " << acc->GetAccountNumber() << endl;
//
//}

bool IsType(BankAccount* src)
{
	return dynamic_cast<const SavingsAccount*>(src) != 0;
}



