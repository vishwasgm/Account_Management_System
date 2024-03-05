//Name: Vishwas Gowdihalli Mahalingappa
//Netid: vg421
// Header guards to prevent multiple inclusion of the same file
#ifndef ACCOUNT_VISHWASGM_H
#define ACCOUNT_VISHWASGM_H

// Include necessary libraries
#include <iostream>
#include <string>

using namespace std;



// Declaration of the Account class
class Account {

private:
    double cash_balance; // Private member variable to store the cash balance

public:
    // Constructor
    Account();

    // Pure virtual function to get the name (implemented by derived classes)
    virtual string getName() const = 0;

    // Member function to print the type (calls getName)
    void print_type()
    {
        cout << getName() << endl;
    }

    // Setter for cash balance
    void set_cash_balance(double);

    // Getter for cash balance
    double get_cash_balance() const;
};

// End of header guard
#endif
