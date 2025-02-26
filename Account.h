//
// Created by Ayush Bhandari on 2/6/25.
//

#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <string>

using namespace std;

class Account {
protected:
    string accountID;
    string accountPIN;
    double accountBalance;

public:
    Account();
    Account(const string &, const string &, double);

    string getaccountID();
    string getaccountPIN();
    [[nodiscard]] double getaccountBalance() const;

    void setaccountID(const string &);
    void setaccountPIN(const string &);
    void setaccountBalance(double);

    void printBalance() const;
    void Deposit(double);
    void Withdraw(double);
};

#endif
