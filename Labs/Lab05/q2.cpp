/*
 *Programmer: Layyana Junaid (23k0056)
 *Date: 4th March 2023
 *Description: creating a class called Loanhelper to help the user keep track of his loan progress
 */

#include <iostream>

//creating a Loan helper class
class LoanHelper
{
private:
    const float interestRate;
    double amountTaken;
    int months;

public:
    LoanHelper(float rate, double amount, int mon) : interestRate(rate), amountTaken(amount), months(mon) {}

//function to calculate loan thingy
    void LoanPayment()
    {
        double remainingAmount = amountTaken;
        double totalPayment = 0;

        for (int i = 0; i < months; i++)
        {
            double interest = remainingAmount * interestRate;
            double monthlyPayment = remainingAmount / months;
            totalPayment += monthlyPayment + interest;
            remainingAmount -= monthlyPayment;
        }

        std::cout << "You have to pay " << totalPayment << " every month for " << months << " months to repay your loan." << std::endl;
    }

};

int main(int argc, char const *argv[])
{
    float interestRate = 0.004;
    double amountTaken = 5000;
    int months = 12;

    LoanHelper loan(interestRate, amountTaken, months);
    loan.LoanPayment();

    return 0;
}
