/*
*Programmer: Layyana Junaid (23k0056)
*Date: 5th May 2024
*Description: managing different type of bank acounts 
*/

#include <iostream>

class Account
{
private:
    int accountNumber;
    double balance;

public:
    Account(int a, double b) : accountNumber(a), balance(b) {}

    int getAccountNumber() const { return accountNumber; }
    void setAccountNumber(int a) { accountNumber = a; }

    double getBalance() const { return balance; }
    void setBalance(double b) { balance = b; }

    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
    virtual void calculateInterest() = 0;
};

class SavingsAccount : public Account
{
private:
    double interestRate;

public:
    SavingsAccount(int a, double b, double i) : interestRate(i), Account(a, b) {}

    void deposit(double amount) override
    {
        setBalance(getBalance() + amount);
    }

    void withdraw(double amount) override
    {
        setBalance(getBalance() - amount);
    }

    void calculateInterest() override
    {
        std::cout << "Interest Calculation....." << std::endl;
    }
};

class CurrentAccount : public Account
{
private:
    double overdraftLimit;

public:
    CurrentAccount(int a, double b, double o) : overdraftLimit(o), Account(a, b) {}

    void deposit(double amount) override
    {
        setBalance(getBalance() + amount);
    }

    void withdraw(double amount) override
    {
        if (getBalance() - amount >= -overdraftLimit)
        {
            setBalance(getBalance() - amount);
        }
        else
        {
            std::cout << "Withdrawal amount exceeds overdraft limit." << std::endl;
        }
    }

    void calculateInterest() override
    {
        std::cout << "Interest Calculation....." << std::endl;
    }
};

int main()
{
    Account* acc;

    SavingsAccount acc1(213, 50000, 3);
    acc1.deposit(2000);

    std::cout << "Account Number: " << acc1.getAccountNumber() << std::endl;
    std::cout << "Balance: " << acc1.getBalance() << std::endl;

    CurrentAccount acc2(214, 10000, 2000);
    acc2.withdraw(3000);

    std::cout << "Account Number: " << acc2.getAccountNumber() << std::endl;
    std::cout << "Balance: " << acc2.getBalance() << std::endl;

    return 0;
}
