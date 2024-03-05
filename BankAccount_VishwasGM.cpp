//Name: Vishwas Gowdihalli Mahalingappa
//Netid: vg421

#include <iostream>
#include <iomanip>
#include <fstream>
#include <time.h>
#include <string>

#include "BankAccount_VishwasGM.h"

using namespace std;

// Function to withdraw money from the bank account
void BankAccount::withdraw(double amt)
{
    // Check if the withdrawal amount is greater than the available cash balance
    if (amt > get_cash_balance())
        cout << "Transaction failed due to insufficient cash balance in bank account" << endl;
    else
    {
        // Update the cash balance after successful withdrawal
        set_cash_balance(get_cash_balance() - amt);
        cout << "You have successfully withdrawn $" << amt << " from your bank account" << endl;

        // Log the withdrawal transaction in the history file
        ofstream file2;
        file2.open("bank_transaction_history.txt", ios::app);
        time_t seconds;
        seconds = time(NULL);
        char date[9];
        tm* timeinfo;
        timeinfo = localtime(&seconds);
        strftime(date, 100, "%D", timeinfo);
        file2 << setprecision(2) << fixed;
        file2 << left << setw(10) << "Withdraw" << left << setw(1) << "$" << setw(11) << amt << left << setw(10) << date << left << setw(1) << "$" << left << setw(19) << get_cash_balance() << endl;
        file2.close();
    }
}

// Function to deposit money into the bank account
void BankAccount::deposit(double amt)
{
    // Update the cash balance after successful deposit
    set_cash_balance(get_cash_balance() + amt);
    cout << "You have successfully deposited $" << amt << " to your bank account" << endl;

    // Log the deposit transaction in the history file
    ofstream file2;
    file2.open("bank_transaction_history.txt", ios::app);
    time_t seconds;
    seconds = time(NULL);
    char date[9];
    tm* timeinfo;
    timeinfo = localtime(&seconds);
    strftime(date, 100, "%D", timeinfo);
    file2 << setprecision(2) << fixed;
    file2 << left << setw(10) << "Deposit" << left << setw(1) << "$" << setw(11) << amt << left << setw(10) << date << left << setw(1) << "$" << left << setw(19) << get_cash_balance() << endl;
    file2.close();
}

// Function to get and display the transaction history from the file
void BankAccount::get_trans_history() const
{
    // Variable to store each line of the transaction history file
    string l;

    // Open the transaction history file for reading
    ifstream file1("bank_transaction_history.txt");

    // Display column headers for the transaction history
    cout << left << setw(10) << "Event" << left << setw(12) << "Amount" << left << setw(10) << "Date" << left << setw(20) << "Balance" << endl;

    // Check if the file is open
    if (file1.is_open())
    {
        // Read each line of the file and display it
        while (getline(file1, l))
        {
            cout << l << endl;
        }

        // Close the file
        file1.close();
    }
    else
    {
        // Display an error message if the file cannot be opened
        cout << "Error in opening file" << endl;
    }
}
