/*
  Author: Elisee MUGIRANEZA
  https://github.com/Elisee-M
  mugiranezaelisee0@gmail.com

  Loan Calculator (Object-Oriented Version)
*/

#include <iostream>
#include <iomanip>
using namespace std;

class LoanCalculator {
private:
    double principal;
    double annualRate;
    int months;

public:
    void getInput() {
        cout << "Enter loan amount (Frw): ";
        cin >> principal;

        cout << "Enter annual interest rate (%): ";
        cin >> annualRate;

        cout << "Enter loan duration (in months): ";
        cin >> months;
    }

    double calculateInterest() const {
        return principal * (annualRate / 100) * (months / 12.0);
    }

    double calculateTotalPayment() const {
        return principal + calculateInterest();
    }

    double calculateMonthlyPayment() const {
        return calculateTotalPayment() / months;
    }

    void displaySummary() const {
        double interest = calculateInterest();
        double total = calculateTotalPayment();
        double monthly = calculateMonthlyPayment();

        cout << fixed << setprecision(2);
        cout << "\nLoan Summary:\n";
        cout << "-------------------------\n";
        cout << "Loan Amount:      Frw " << principal << endl;
        cout << "Interest Rate:    " << annualRate << "% per year\n";
        cout << "Loan Duration:    " << months << " months\n";
        cout << "Monthly Payment:  Frw " << monthly << endl;
        cout << "Total Payment:    Frw " << total << endl;
        cout << "Total Interest:   Frw " << interest << endl;
    }
};

int main() {
    LoanCalculator loan;
    loan.getInput();
    loan.displaySummary();

    return 0;
}
