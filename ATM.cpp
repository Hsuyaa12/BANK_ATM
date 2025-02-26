#include "ATM.h"

ATM::ATM(Bank &bk) : bank(bk) {}

int ATM::start() {
    char choice;

    while (true) {
        cout << "\nPlease enter your command\n";
        cout << "Q – quit/exit\n";
        cout << "L – login to account\n";
        cin >> choice;

        if (choice == 'Q') {
            return 0;
        }

        if (choice == 'L') {
            string id, pin;
            int attempts = 0;
            while (attempts < 3) {
                cout << "Please enter Account ID" << endl;
                cin >> id;
                cout << "Please enter PIN" << endl;
                cin >> pin;

                Account &acct = bank.findAcct(id, pin);

                if (acct.getaccountID().empty()) {
                    cout << "Sorry – no match \n" << endl;
                    attempts++;
                    if(attempts == 3) {
                        return 1;
                    }
                } else {
                    cout << "Account Found" << endl;
                    transactions(acct);
                    break;
                }
            }
        }
    }
}

void ATM::transactions(Account &acct) {
    char option;

    while (true) {
        cout << "\nPlease enter your selection or Q to quit.\n";
        cout << "W - withdraw funds\n";
        cout << "D - deposit funds\n";
        cout << "B - check balance\n";
        cout << "Q - quit/exit\n";
        cin >> option;

        if (option == 'Q') {
            cout << "Goodbye." << endl;
            break;
        }

        if (option == 'W' ) {
            double amount;
            cout << "Please enter amount of withdrawal" << endl;
            cin >> amount;
            acct.Withdraw(amount);
        }
        else if (option == 'D') {
            double amount;
            cout << "Please enter amount of deposit" << endl;
            cin >> amount;
            acct.Deposit(amount);
        }
        else if (option == 'B') {
            acct.printBalance();
        }
        else {
            cout << "Unrecognized command " << option << endl;
        }
    }
}

