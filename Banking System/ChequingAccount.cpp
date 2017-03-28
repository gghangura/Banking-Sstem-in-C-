
#include "ChequingAccount.h"

ChequingAccount::ChequingAccount(string fName, string lName, double balance) : BankAccount()
{
	account = BankAccount(fName, lName, balance);
	numberOfCheques = 0;
}

ChequingAccount::~ChequingAccount()
{

}

ChequingAccount::ChequingAccount() {

}

void ChequingAccount::GiveCheque() {
	numberOfCheques++;
	cout << "One cheque Given" << endl;
	cout << "Total Cheques Given: "<< numberOfCheques << endl;
}

void ChequingAccount::DisplayAccountInfo() {
	cout << endl << endl;
	cout << "This is a Chequing Account" << endl;
	account.DisplayAccountInfo();
	cout << "Number of Cheques Used: " << numberOfCheques << endl;
}

int ChequingAccount::GetAccountNumber() {
	return account.GetAccountNumber();
}

void ChequingAccount::UpdateFirstName(string newVal) {
	account.UpdateFirstName(newVal);
}
void ChequingAccount::UpdateLastName(string newVal) {
	account.UpdateLastName(newVal);
}

void ChequingAccount::Widraw(double amount) {
	account.Widraw(amount);
	cout<< account.AvailableBalance();
}
void ChequingAccount::Deposit(double amount) {
	account.Deposit(amount);
}