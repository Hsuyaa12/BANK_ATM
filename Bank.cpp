#include "Bank.h"

Account &Bank::findAcct(const string &id, const string &pin) {
    for (Account &acct : allAccounts) {
        if (acct.getaccountID() == id && acct.getaccountPIN() == pin) {
            return acct;
        }
    }
    return dummyAccount;
}

void Bank::addAcct(const Account &acct) {
    allAccounts.push_back(acct);
}

void Bank::loadAccounts(ifstream &inf) {
    string id, pin;
    double balance;

    while (inf >> id >> pin >> balance) {
        Account newAcct(id, pin, balance);
        addAcct(newAcct);
    }
}
