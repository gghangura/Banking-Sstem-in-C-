#pragma once

#include "BankAccount.h"
#include <iostream>
#include <cstdio>

using namespace std;

class ChequingAccount : public BankAccount
{
public:
	ChequingAccount(std::string fName, string lName, double balance);
	~ChequingAccount();
	virtual void IncrementCheques();


private:
	int numberOfCheques;
};

