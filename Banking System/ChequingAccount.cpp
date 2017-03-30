
#include "ChequingAccount.h"

ChequingAccount::ChequingAccount(std::string fName, string lName, double balance) : BankAccount(fName, lName, balance)
{
	numberOfCheques = 0;
}

ChequingAccount::~ChequingAccount()
{

}

void ChequingAccount::IncrementCheques()
{
	numberOfCheques++;
	cout << "Number of Cheques used is: " << numberOfCheques << endl;
}
