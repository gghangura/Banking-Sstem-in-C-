#pragma once

#include "BankAccount.h"
#include <iostream>
#include <cstdio>

using namespace std;

class SavingsAccount : public BankAccount
{
public:
	SavingsAccount(string fName, string lName, double balance);
	~SavingsAccount();
	virtual void Addprofit();

private:
};

