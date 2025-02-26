//
// Created by Ayush Bhandari on 2/6/25.
//

#include "Account.h"
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <iomanip>

using namespace std;


Account::Account() {
    accountID = "";
    accountPIN = "";
    accountBalance = 0.0;
}

Account::Account(const string &acc, const string &acc_pin, double acc_bal) {
   if (acc.length() == 8 && acc_pin.length() == 4 &&
       std::all_of(acc_pin.begin(), acc_pin.end(), ::isdigit) && acc_bal >= 0.0) {

       accountID = acc;
       accountPIN = acc_pin;
       accountBalance = acc_bal;
   }
   else {
        accountID = "";
        accountPIN = "";
        accountBalance = 0.0;
   }
}


string Account::getaccountID() {
    return accountID;
}

string Account::getaccountPIN() {
    return accountPIN;
}

double Account::getaccountBalance() const {
    return accountBalance;
}

void Account::setaccountID(const string &acc) {
    if (acc.length() == 8) {
        accountID = acc;
    } else {
        cout << "Invalid Account ID! Must be 8 characters." << endl;
    }
}

void Account::setaccountPIN(const string &acc_pin) {
    if (acc_pin.length() == 4 && std::all_of(acc_pin.begin(), acc_pin.end(), ::isdigit)) {
        accountPIN = acc_pin;
    } else {
        cout << "Invalid PIN! Must be exactly 4 digits." << endl;
    }
}

void Account::setaccountBalance(double acc_bal) {
    if (acc_bal >= 0.0) {
        accountBalance = acc_bal;
    } else {
        cout << "Invalid balance! Cannot be negative." << endl;
    }
}

void Account::printBalance() const {
    cout << fixed << setprecision(2);
    cout << "Balance: $" << getaccountBalance() << endl;
}

void Account::Deposit(double amt) {
    if (amt >= 0.0) {
        setaccountBalance(amt + getaccountBalance());
    }
    else {
        cout << "Deposit unsuccessful. Amount must be greater than or equal to 0." << endl;
    }
}

void Account::Withdraw(double amt) {
    if (amt > 0.0 && amt <= getaccountBalance()) {
        double new_balance = getaccountBalance() - amt;
        setaccountBalance(new_balance);
    } else {
        cout << "Withdrawal failed. Insufficient funds or invalid amount." << endl;
    }
}
