# 🚀 Bank ATM System

## 📌 Overview
This project is a **simple Bank ATM system** implemented in C++ that allows users to log into their accounts, check balances, deposit funds, and withdraw money. It utilizes **file I/O, vectors, and classes** to simulate an ATM interface with fundamental banking functionalities.

## 🎯 Features
✅ **Account Management**: Load, find, and manage bank accounts.  
✅ **User-Friendly ATM Interface**:
   - 🔑 Secure login with up to 3 attempts.
   - 💰 Withdraw money with balance validation.
   - 💵 Deposit money with error handling.
   - 🏦 Check account balance instantly.
   - 🔄 Allows multiple transactions before exiting.
✅ **File-Based Data Handling**: Loads accounts from an external file.

## 📂 Project Structure
The project consists of **seven essential files**:

```
📜 Account.h        # Account class definition
📜 Account.cpp      # Account class implementation
📜 Bank.h           # Bank class definition
📜 Bank.cpp         # Bank class implementation
📜 ATM.h            # ATM class definition
📜 ATM.cpp          # ATM class implementation
📜 prog2.cpp        # Main program file
```

## 🏛️ Class Descriptions
### 1️⃣ **Account Class (`Account.h`, `Account.cpp`)**
🔹 Manages individual bank accounts.
- **Data Members:**
  - 🆔 `accountID` (8-character string)
  - 🔢 `accountPIN` (4-digit string)
  - 💳 `accountBalance` (double)
- **Key Methods:**
  - 📌 Constructors (default & parameterized with validation).
  - 🔄 Getters & Setters for account data.
  - 💵 `Deposit(double amt)` - Adds money to the account.
  - 🏧 `Withdraw(double amt)` - Validates and withdraws funds.
  - 📊 `printBalance()` - Displays account balance.

### 2️⃣ **Bank Class (`Bank.h`, `Bank.cpp`)**
🔹 Handles multiple accounts via a vector.
- **Data Members:**
  - 📋 `allAccounts`: Vector storing `Account` objects.
  - ❌ `dummyAccount`: Default invalid account.
- **Key Methods:**
  - 🔍 `findAcct(string id, string pin)`: Finds an account by credentials.
  - ➕ `addAcct(Account &acct)`: Adds an account.
  - 📥 `loadAccounts(ifstream &inf)`: Loads accounts from a file.

### 3️⃣ **ATM Class (`ATM.h`, `ATM.cpp`)**
🔹 Manages user interaction with the ATM system.
- **Data Members:**
  - 🏦 `bank`: Reference to a `Bank` object.
- **Key Methods:**
  - 🎭 `start()`: Handles user login and menu.
  - 💰 `transactions(Account &acct)`: Allows deposit, withdrawal, balance check, and exit.

### 4️⃣ **Main Program (`prog2.cpp`)**
🚀 The **entry point** of the application.
- 📂 Prompts user for an account file path.
- 📥 Loads accounts into `Bank`.
- 🏧 Initializes the ATM and starts transactions.
- 🔄 Manages exit conditions.

## ⚙️ Compilation & Execution
### 🔨 **Compilation**
Use `g++` to compile:
```sh
 g++ -o atm_system prog2.cpp Bank.cpp Account.cpp ATM.cpp
```

### ▶️ **Execution**
Run the compiled program:
```sh
 ./atm_system
```

## 📜 Input File Format
The system reads account data from a **structured file**:
```txt
QWE23456 5543 2345.65
QSD22314 3417 3445.67
AASD6651 8890 123.50
HJHW5578 3333 1233.33
```

## 🖥️ Sample Execution
```
Enter path for account information: accounts.txt
Loading Data...
6 Accounts loaded.
Please enter your command
Q – quit/exit
L – login to account
L
Please enter Account ID: AASD6651
Please enter PIN: 8890
Account Found
Please enter your selection or Q to quit.
W - withdraw funds
D - deposit funds
B - check balance
Q - quit/exit
B
Balance: $123.50
```

## ⚠️ Error Handling
🔴 Invalid login attempts **limited to 3 tries**.  
🔴 Withdrawals are denied if **insufficient balance**.  
🔴 Deposits **must be non-negative**.  
🔴 Unrecognized commands prompt an **error message**.  

## 👤 Author
✍️ **Ayush Bhandari** - BANK_ATM_SYSTEM

## 📜 License
📄 This project is licensed under the **MIT License**.

