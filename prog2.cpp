#include <iostream>
#include <fstream>
#include "Bank.h"
#include "ATM.h"
#include "Account.h"

using namespace std;

int main() {
    string filePath;
    ifstream inf;

    cout << "Enter path for account information: ";
    cin >> filePath;

    inf.open(filePath);
    if (!inf) {
        cout << "Error opening file. Please check the path and try again." << endl;
        return 1;
    }

    cout << "Loading Data..." << endl;

    Bank bk;
    int accountCount = 0;

    string id, pin;
    double balance;
    while (inf >> id >> pin >> balance) {
        Account newAcct(id, pin, balance);
        bk.addAcct(newAcct);
        accountCount++;
    }

    inf.close();


    cout << accountCount << " Accounts loaded." << endl;

    ATM atm(bk);
    int result = atm.start();

    switch (result) {
        case 0:
            cout << "Normal Exit";
            break;
        case 1:
            cout << "Account not found – system shutting down" << endl;
        break;
        default:
            cout << "Unexpected error occurred. Exiting." << endl;
    }

    return 0;
}
