//Name: Vishwas Gowdihalli Mahalingappa
//Netid: vg421

// Header guards to prevent multiple inclusion of the same file
#ifndef NODE_STOCKACCOUNT_VISHWASGM_H
#define NODE_STOCKACCOUNT_VISHWASGM_H

#include <string>

using namespace std;

// Declaration of the Node class
class Node {
    // Friend classes that can access private members of this class
    friend class StockAccount;
    friend class SortImpl;
    friend class SortSelection;
    friend class SortBubble;

public:
    // Constructor to initialize Node with stock details
    Node(string name, int no, double pps)
        : stock_symbol(name), num_of_shares(no), price_per_share(pps)
    {
        // Initialize pointers to NULL
        this->pre = NULL;
        this->next = NULL;
    }

private:
    string stock_symbol; // Stock symbol
    int num_of_shares;    // Number of shares
    double price_per_share; // Price per share
    Node* next;  // Pointer to the next Node
    Node* pre;   // Pointer to the previous Node
};

// End of header guard
#endif
