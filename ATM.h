#ifndef ATM_H
#define ATM_H
#include <iostream>
#include "Account.h"
#include "Bank.h"

using namespace std;

class ATM {
protected:
    Bank &bank;

public:
    explicit ATM(Bank &bk);
    int start();
    void transactions(Account &acct);
};

#endif // ATM_H
