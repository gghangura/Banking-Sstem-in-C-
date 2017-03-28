
#include "SavingAccount.h"

SavingsAccount::SavingsAccount(string fName, string lName, double balance) : BankAccount()
{
	account = BankAccount(fName, lName, balance);
}

SavingsAccount::~SavingsAccount()
{

}

SavingsAccount::SavingsAccount() {

}

void SavingsAccount::DisplayAccountInfo() {
	cout << endl << endl;
	cout << "This is a Saving Account" << endl;
	account.DisplayAccountInfo();
}

int SavingsAccount::GetAccountNumber() {
	return account.GetAccountNumber();
}

void SavingsAccount::UpdateFirstName(string newVal) {
	account.UpdateFirstName(newVal);
}
void SavingsAccount::UpdateLastName(string newVal) {
	account.UpdateLastName(newVal);
}
void SavingsAccount::Widraw(double amount) {
	account.Widraw(amount);
}
void SavingsAccount::Deposit(double amount) {
	account.Deposit(amount);
}
void SavingsAccount::AddProfit(){
	cout << "Another Month Passed by" << endl;
	double profit = account.GetBalance() * 0.025;
	account.Deposit(profit);
	cout << "Profit Added" << endl;
}

