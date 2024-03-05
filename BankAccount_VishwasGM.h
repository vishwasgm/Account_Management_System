//Name: Vishwas Gowdihalli Mahalingappa
//Netid: vg421

// Header guards to prevent multiple inclusion of the same file
#ifndef BANKACCOUNT__VISHWASGM_H
#define BANKACCOUNT__VISHWASGM_H

// Include the base class header file
#include "Account_VishwasGM.h"

// Declaration of the BankAccount class, inheriting from the Account class
class BankAccount : public Account {

public:
    // Implementation of the pure virtual function in the base class
    virtual string getName() const
    {
        return "Bank Account";
    }

    // Function to withdraw money from the bank account
    void withdraw(double);

    // Function to deposit money into the bank account
    void deposit(double);

    // Function to get and display the transaction history
    void get_trans_history() const;
};

// End of header guard
#endif
