// 4. Create a SavingsAccount class. Use a static data member annual-InterestRate to store
// the annual interest rate for each of the savers. Each member of the class contains a
// private data member savingsBalance indicating the amount the saver currently has on
// deposit. Provide member function calculateMonthlyInterest that calculates the monthly
// interest by multiplying the savingsBalance by annualInterestRate divided by 12; this
// interest should be added to savingsBalance. Provide a static member function
// modifyInterestRate that sets the static annualInterestRate to a new value. Write a driver
// program to test class SavingsAccount. Instantiate two different objects of class
// SavingsAccount, saver1 and saver2, with balances of $2000.00 and $3000.00,
// respectively. Set the annualInterestRate to 3 percent. Then calculate the monthly interest
// and print the new balances for each of the savers. Then set the annualInterestRate to 4
// percent, calculate the next month's interest and print the new balances for each of the
// savers.

Answer:

#include <iostream>
using namespace std;

class SavingsAccount {
private:
    static double annualInterestRate;
    double savingsBalance;

public:
    SavingsAccount(double balance) : savingsBalance(balance) {}

    void calculateMonthlyInterest() {
        double monthlyInterest = savingsBalance * (annualInterestRate / 12);
        savingsBalance += monthlyInterest;
    }

    static void modifyInterestRate(double newRate) {
        annualInterestRate = newRate;
    }

    double getBalance() const {
        return savingsBalance;
    }
};

double SavingsAccount::annualInterestRate = 0;

int main() {
    SavingsAccount saver1(2000.00);
    SavingsAccount saver2(3000.00);

    SavingsAccount::modifyInterestRate(0.03);

    cout << "Initial Balances:" << std::endl;
    cout << "Saver 1 balance: $" << saver1.getBalance() << endl;
    cout << "Saver 2 balance: $" << saver2.getBalance() << endl;

    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();

    cout << "\nBalances after 3% interest for the month:" << endl;
    cout << "Saver 1 balance: $" << saver1.getBalance() << endl;
    cout << "Saver 2 balance: $" << saver2.getBalance() << endl;

    SavingsAccount::modifyInterestRate(0.04);

    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();

    cout << "\nBalances after 4% interest for the next month:" << endl;
    cout << "Saver 1 balance: $" << saver1.getBalance() << endl;
    cout << "Saver 2 balance: $" << saver2.getBalance() << endl;

    return 0;
}

// Output -
// Initial Balances:
// Saver 1 balance: $2000
// Saver 2 balance: $3000

// Balances after 3% interest for the month:
// Saver 1 balance: $2005
// Saver 2 balance: $3007.5

// Balances after 4% interest for the next month:
// Saver 1 balance: $2011.68
// Saver 2 balance: $3017.53
