//Name: Vishwas Gowdihalli Mahalingappa
//Netid: vg421


#include "Account_VishwasGM.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// Constructor for the Account class
Account::Account()
{
    // Try to open the file for reading
    ifstream file1("bank_account_cash_balance.txt");

    // If the file doesn't exist or cannot be opened
    if (file1.is_open() == 0)
    {
        // Initialize cash_balance to 10000.00
        cash_balance = 10000.00;

        // Create the file and write the initial balance
        ofstream file2;
        file2.open("bank_account_cash_balance.txt");
        file2 << setprecision(2) << fixed;
        file2 << cash_balance << endl;
        file2.close();

        // Close the input file stream
        file1.close();
    }
    else
    {
        // If the file exists, read the cash balance from the file
        double readValue;
        ifstream file1("bank_account_cash_balance.txt");
        file1 >> readValue;
        cash_balance = readValue;
        file1.close();
    }
}

// Function to set the cash balance
void Account::set_cash_balance(double b)
{
    // Open the file for writing
    ofstream file2;
    file2.open("bank_account_cash_balance.txt");

    // Write the new balance and close the file
    file2 << b << endl;
    file2.close();
}

// Function to get the cash balance
double Account::get_cash_balance() const
{
    // Variable to store each line of the file
    string l;

    // Open the file for reading
    ifstream file1("bank_account_cash_balance.txt");

    // If the file is open
    if (file1.is_open())
    {
        // Read each line (there should be only one) and convert it to a double
        while (getline(file1, l))
        {
            return stod(l);
        }

        // Close the file
        file1.close();
    }
    else
    {
        // If the file cannot be opened, print an error message
        cout << "Error in opening file" << endl;
    }

    // Return -1 if there is an error
    return -1;
}

