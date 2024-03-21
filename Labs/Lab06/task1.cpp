/*
 *Programmer: Layyana Junaid (23k0056)
 *Date:17th March 2024
 *Description: Lab 06 Task 1
 *
 */

#include <iostream>
#include <cstring>

class BankAccount
{
private:
    int accountId;
    double balance;
    int numTransactions;
    int *transactionHistory;

public:
    // Default constructor
    BankAccount() : accountId(0), balance(0), numTransactions(0), transactionHistory(nullptr) {}

    // Constructor
    BankAccount(int id, double bal, int transactions, int* transactionsArray)
    : accountId(id), balance(bal), numTransactions(transactions) {
        transactionHistory = new int[transactions];
        std::memcpy(transactionHistory, transactionsArray, transactions * sizeof(int));
    }

    // Copy constructor
    BankAccount(const BankAccount& other)
    : accountId(other.accountId), balance(other.balance), numTransactions(other.numTransactions) {
        transactionHistory = new int[numTransactions];
        std::memcpy(transactionHistory, other.transactionHistory, numTransactions * sizeof(int));
    }

    // Destructor
    ~BankAccount() {
        delete [] transactionHistory;
    }

    // Display function
    void Display() const {
        std::cout << "Account ID: " << accountId << std::endl;
        std::cout << "Balance: " << balance << std::endl;
        std::cout << "Transaction History: ";
        for(int i = 0; i < numTransactions; i++) {
            std::cout << transactionHistory[i] << " ";
        }
        std::cout << std::endl;
    }

    // Update transaction history
    void UpdateTransactionHistory(int* newTransaction, int transactionNum) {
        delete[] transactionHistory;
        transactionHistory = new int[transactionNum];
        std::memcpy(transactionHistory, newTransaction, transactionNum * sizeof(int));
        numTransactions = transactionNum;
    }
};

int main()
{
    int transactions[] = {1000, 2500, 5000, 500, 100};
    int numTransactions = sizeof(transactions) / sizeof(transactions[0]);

    // Object
    BankAccount account1(2456, 50000, numTransactions, transactions);

    // Copy of the original account
    BankAccount copiedAccount = account1;

    // Display details of original and copied accounts
    std::cout << "Original Account:" << std::endl;
    account1.Display();

    std::cout << "Copied Account:" << std::endl;
    copiedAccount.Display();

    // Update transaction history of the original account
    int newTransactions[] = {500, 2500};
    int newNumTransactions = sizeof(newTransactions) / sizeof(newTransactions[0]);
    account1.UpdateTransactionHistory(newTransactions, newNumTransactions);

    // Display details of the original account after update
    std::cout << "Original Account after update:" << std::endl;
    account1.Display();

    return 0;
}
