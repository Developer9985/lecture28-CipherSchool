#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    // Private members
    string accountNumber;
    double balance;

protected:
    // Protected member
    string accountHolderName;

public:
    // Constructor
    BankAccount(string accNum, string accHolderName, double initialBalance) {
        accountNumber = accNum;
        accountHolderName = accHolderName;
        balance = initialBalance;
    }

    // Getter for account number (no setter, as account number should not change)
    string getAccountNumber() const {
        return accountNumber;
    }

    // Getter for balance
    double getBalance() const {
        return balance;
    }

    // Setter for balance
    void setBalance(double newBalance) {
        balance = newBalance;
    }

    // Getter for account holder name
    string getAccountHolderName() const {
        return accountHolderName;
    }

    // Setter for account holder name
    void setAccountHolderName(const string& newName) {
        accountHolderName = newName;
    }

    // Public method to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited $" << amount << ". New balance: $" << balance << endl;
        } else {
            cout << "Deposit amount must be positive!" << endl;
        }
    }

    // Public method to withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew $" << amount << ". New balance: $" << balance << endl;
        } else {
            cout << "Insufficient funds or invalid withdrawal amount!" << endl;
        }
    }
};

int main() {
    // Creating a new bank account
    BankAccount myAccount("123456789", "John Doe", 1000.0);

    // Accessing and modifying account details using getter and setter functions
    cout << "Account Number: " << myAccount.getAccountNumber() << endl;
    cout << "Account Holder: " << myAccount.getAccountHolderName() << endl;
    cout << "Initial Balance: $" << myAccount.getBalance() << endl;

    // Depositing money
    myAccount.deposit(500.0);

    // Withdrawing money
    myAccount.withdraw(200.0);

    // Changing account holder name
    myAccount.setAccountHolderName("Jane Doe");
    cout << "Updated Account Holder: " << myAccount.getAccountHolderName() << endl;

    return 0;
}
