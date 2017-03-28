// Banking System.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SavingAccount.h"
#include "ChequingAccount.h"
#include <iostream>

using namespace std;

void MakeNewAccount();
char DisplayMenu();
void ShowSavingOptions();
void ShowChequingOptions();
void ShowCommonOptions();
void updateSavingsAccount(SavingsAccount acc, int index, char userInput);
void updateChequingAccount(ChequingAccount acc, int index, char userInput);

ChequingAccount *chequingAccounts = new ChequingAccount[3];

SavingsAccount *savingAccounts = new SavingsAccount[3];

int nOfChequingAccounts = 0;

int nOfSavingAccounts = 0;

int main()
{
	cout << "Welcome to Your Bank" << endl;

	for (;;)
	{
		char input = DisplayMenu();
		if (input == 'a')
		{
			if (nOfChequingAccounts + nOfSavingAccounts == 0)
			{
				cout << "Add Accounts First";
			}
			else
			{
				for (int i = 0; i < nOfChequingAccounts ; i++)
				{
					chequingAccounts[i].DisplayAccountInfo();
				}
				for (int i = 0; i < nOfSavingAccounts; i++)
				{
					savingAccounts[i].DisplayAccountInfo();
				}
			}
		}
		else if (input == 'b')
		{
			if (nOfChequingAccounts + nOfSavingAccounts < 5)
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
			if (nOfChequingAccounts + nOfSavingAccounts > 0)
			{
				bool accountFound = false;
					int userInputForAccNo;
					cout << "Enter Account Number" << endl;
					cin >> userInputForAccNo;
					char userResponse;
					for (int i = 0; i < nOfChequingAccounts; i++)
					{
						if (chequingAccounts[i].GetAccountNumber() == userInputForAccNo) {
							accountFound = true;
							for (;;) {
								chequingAccounts[i].DisplayAccountInfo();
								ShowCommonOptions();
								ShowChequingOptions();
								cin >> userResponse;
								if (userResponse == 'f')
								{
									break;
								}
								else
								{
									updateChequingAccount(chequingAccounts[i], i, userResponse);
								}
							}
						}
					}
					for (int i = 0; i < nOfSavingAccounts; i++)
					{
						if (savingAccounts[i].GetAccountNumber() == userInputForAccNo) {
							accountFound = true;
							for (;;) {
								savingAccounts[i].DisplayAccountInfo();
								ShowCommonOptions();
								ShowSavingOptions();
								cin >> userResponse;
								if (userResponse == 'f')
								{
									break;
								}
								else
								{
									updateSavingsAccount(savingAccounts[i], i, userResponse);
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
	switch (typeOfAcc)
	{
	case 'a':
		chequingAccounts[nOfChequingAccounts] = ChequingAccount(fName, lName, initialBalance);
		cout << "Your Account Number is:" << chequingAccounts[nOfChequingAccounts].GetAccountNumber() << endl;

		nOfChequingAccounts++;
		break;
	case 'b':
		savingAccounts[nOfSavingAccounts] = SavingsAccount(fName, lName, initialBalance);
		cout << "Your Account Number is:" << savingAccounts[nOfSavingAccounts].GetAccountNumber() << endl;
		nOfSavingAccounts++;
		break;
	default:
		break;
	}
	cout << "ACCOUNT OPENED" << endl;
}

void ShowCommonOptions() {
	cout << endl << endl;
	cout << "a:Edit First Name" << endl;
	cout << "b:Edit Last Name" << endl;
	cout << "c:Deposit Money" << endl;
	cout << "d:Withdraw Money" << endl;
}

void ShowSavingOptions() {
	cout << "e:Add Profit" << endl;
	cout << "f:Return to Main Menu" << endl;
}
void ShowChequingOptions() {
	cout << "e:Increment Cheques Written" << endl;
	cout << "f:Return to Main Menu" << endl;
}

void updateSavingsAccount(SavingsAccount acc, int index, char userInput) {
	string newVal;
	double amount;
	switch (userInput)
	{
	case 'a':
		cout << "Enter New First Name" << endl;
		cin >> newVal;
		acc.UpdateFirstName(newVal);
		break;
	case 'b':
		cout << "Enter New Last Name" << endl;
		cin >> newVal;
		acc.UpdateLastName(newVal);
		break;
	case 'c':
		cout << "Enter the amount to Deposit" << endl;
		cin >> amount;
		acc.Deposit(amount);
		break;
	case 'd':
		cout << "Enter the amount to Withdraw" << endl;
		cin >> amount;
		acc.Widraw(amount);
		break;
	case 'e':
		acc.AddProfit();
		break;
	default:
		break;
	}
	savingAccounts[index] = acc;
}

void updateChequingAccount(ChequingAccount acc, int index, char userInput) {
	string newVal;
	double amount;
	switch (userInput)
	{
	case 'a':
		cout << "Enter New First Name" << endl;
		cin >> newVal;
		acc.UpdateFirstName(newVal);
		break;
	case 'b':
		cout << "Enter New Last Name" << endl;
		cin >> newVal;
		acc.UpdateLastName(newVal);
		break;
	case 'c':
		cout << "Enter the amount to Deposit" << endl;
		cin >> amount;
		acc.Deposit(amount);
		break;
	case 'd':
		cout << "Enter the amount to Withdraw" << endl;
		cin >> amount;
		acc.Widraw(amount);
		break;
	case 'e':
		acc.GiveCheque();
		break;
	default:
		break;
	}
	chequingAccounts[index] = acc;
}