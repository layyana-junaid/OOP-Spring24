/*
 *Programmer: Layyana Junaid (23k0056)
 *Date: 22nd Feb 2024
 *Description: task 4 (lab task)
 */

#include <iostream>
#include <string>

using namespace std;

// creating a bankaccount class
class BankAccount
{
private:
    int accountNumber;
    string accountHoldersName;
    double balance;

public:
    // create constructor that will be parameterized constructor
    BankAccount(int accountNumber, string accountHoldersName, double balance)
    {
        this->accountNumber = accountNumber;
        this->accountHoldersName = accountHoldersName;
        this->balance = balance;
    }

    // creating deposit function
    void Deposit(double amount)
    {
        // adding amount to be deposited in balance
        balance += amount;
        cout << "Deposit Successful! Your Current balance is: " << balance << endl;

    }

    // creating withdraw function
    void Withdraw(double amount) {
        if(amount > balance) {
            cout << "Withdrawl Failed! Balance is insufficient: " << balance << endl;
        }
        else if(amount < balance) {
            double withdraw = balance - amount;
            cout << "Withdrawl Successful! Your balance is: " << withdraw << endl;

        }
    }

        // display function
        void Display() {
            cout << "Account Number: " << accountNumber << endl;
            cout << "Account Holders Name: " << accountHoldersName << endl;
            cout << "Balance: " << balance << endl; 
        }
    


};
// end of class

int main(int argc, char const *argv[])
{
    BankAccount accounts[3] = {
        BankAccount(230055, "Muhammad Ali", 2000),
        BankAccount(230025, "Alisha Zaidi", 70000),
        BankAccount(230056, "Layyana Juanid", 50000)
    };

    //display accounts details
    for(int i = 0; i < 3; i++) {
        cout << "Account" << i + 1 << "Details: " << endl;
        accounts[i].Display();
    }
    

    // calling deposit and withdraw function

    cout << "Account 1 Details: " << endl;
    accounts[0].Deposit(100);
    accounts[0].Withdraw(5000);
    
    return 0;
}

