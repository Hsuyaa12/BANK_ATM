#ifndef BANK_H
#define BANK_H
#include <vector>
#include <fstream>
#include "Account.h"

using namespace std;

class Bank {
protected:
   vector<Account> allAccounts;
   Account dummyAccount;

public:

   Account &findAcct(const string &, const string &);

   void addAcct(const Account &acct);

   void loadAccounts(ifstream &inf);
};

#endif // BANK_H
