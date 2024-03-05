//Name: Vishwas Gowdihalli Mahalingappa
//Netid: vg421

// Header guards to prevent multiple inclusion of the same file
#ifndef STOCKACCOUNT__VISHWASGM_H
#define STOCKACCOUNT__VISHWASGM_H

// Include necessary header files
#include "Account_VishwasGM.h"
#include "Node_StockAccount_VishwasGM.h"
#include "Sorting_Implementation_VishwasGM.h"

// Declaration of the StockAccount class, inheriting from Account
class StockAccount : public Account {
public:
    // Constructor
    StockAccount();

    // Destructor
    ~StockAccount();

    // Implementation of the pure virtual function in the base class
    virtual string getName() const
    {
        return "Stock Portfolio Account";
    }

    // Function to get the size of the linked list
    int size() const;

    // Function to get the stock price for a given stock symbol
    double get_stock_price(string, string);

    // Function to print the stock portfolio
    void print_portfolio();

    // Function to update the linked list with stock information
    void update_list(string);

    // Function to buy shares
    void buy_shares(string, string, int, double);

    // Function to sell shares
    void sell_shares(string, string, int, double);

    // Function to store the portfolio to a file
    void store_portfolio();

    // Function to get and display the transaction history
    void get_trans_history();

    // Function to get and display the graph
    void get_graph();

private:
    Node* Head;      // Pointer to the head of the linked list
    int mySize;      // Size of the linked list
    SortImpl* impl;  // Pointer to the sorting implementation object
};


#endif
