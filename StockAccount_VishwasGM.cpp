//Name: Vishwas Gowdihalli Mahalingappa
//Netid: vg421

#include <iostream>
#include <fstream>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <stdio.h>
#include <vector>

using namespace std;

#include "StockAccount_VishwasGM.h"
#include "BankAccount_VishwasGM.h"

// Constructor for StockAccount class
StockAccount::StockAccount()
    : Head(0) // Initialize Head to null pointer
{
    mySize = 0; // Initialize the size of the list to 0

    // Create an instance of the SortSelection class and assign it to the 'impl' pointer
    impl = new SortSelection;

    // Read stock portfolio data from the file "stock_portfolio.txt"
    ifstream file("stock_portfolio.txt");
    if (file.is_open() == 0)
    {
        file.close();
    }
    else
    {
        int count = 0;
        string l, stock_symbol;
        int num_of_shares;
        double price_per_share;
        Node *current_ptr = NULL;

        if (file.is_open())
        {
            // Read data from the file and create nodes to store the stock portfolio
            while (file >> l)
            {
                stock_symbol = l;
                file >> l;
                num_of_shares = stoi(l);
                file >> l;
                price_per_share = stod(l);

                // Create a new node with the read data
                Node *new_node = new Node(stock_symbol, num_of_shares, price_per_share);

                // Update the linked list
                if (count == 0)
                {
                    Head = new_node;
                    current_ptr = Head;
                    count++;
                    mySize++;
                }
                else
                {
                    current_ptr->next = new_node;
                    new_node->pre = current_ptr;
                    current_ptr = current_ptr->next;
                    mySize++;
                }
            }

            file.close();
        }
    }
}

// Destructor for StockAccount class
StockAccount::~StockAccount()
{
    // Destructor cleans up allocated memory
    if (size() != 0)
    {
        Node *current_ptr = Head;
        Node *temp_ptr;

        // Traverse the linked list and delete each node
        while (current_ptr != 0)
        {
            temp_ptr = current_ptr;
            current_ptr = current_ptr->next;
            delete temp_ptr;
        }
    }
}

// Function to return the size of the linked list
int StockAccount::size() const
{
    return mySize;
}

// Function to get the stock price of a given stock symbol from a file
double StockAccount::get_stock_price(string fileName, string stock_symbol)
{
    string l;
    ifstream file1(fileName);
    if (file1.is_open())
    {
        // Read data from the file to find the stock symbol and its price
        while (file1 >> l)
        {
            if (l == stock_symbol)
            {
                file1 >> l;
                return stod(l);
            }
        }

        file1.close();
    }
    else
    {
        cout << "Error in opening file" << endl;
    }

    return -1; // Return -1 if the stock symbol is not found
}

// Function to print the stock portfolio
void StockAccount::print_portfolio()
{
    double total = 0.0;
    if (size() == 0)
    {
        cout << endl
             << "Cash balance= $" << get_cash_balance() << endl
             << endl;
        cout << "The stock portfolio is empty" << endl;
        cout << "Total portfolio value= $" << get_cash_balance() << endl;
        return;
    }
    else
    {
        Node *current_ptr = Head;
        cout << endl
             << "Cash balance= $" << get_cash_balance() << endl
             << endl;
        cout << left << setw(18) << "Company Symbol" << left << setw(11) << "Number" << left << setw(19) << "Price per share" << "Total value" << endl;

        // Iterate through the linked list and print each node's information
        while (current_ptr != 0)
        {
            cout << setprecision(2) << fixed;
            cout << left << setw(18) << current_ptr->stock_symbol << left << setw(11) << current_ptr->num_of_shares << left << setw(1) << "$" << left << setw(18) << current_ptr->price_per_share << left << setw(1) << "$" << current_ptr->num_of_shares * current_ptr->price_per_share << endl;
            total += current_ptr->num_of_shares * current_ptr->price_per_share;
            current_ptr = current_ptr->next;
        }
        cout << "Total portfolio value= $" << get_cash_balance() + total << endl;
    }
}

// Function to update the stock prices in the linked list based on a file
void StockAccount::update_list(string fileName)
{
    Node *current_ptr = Head;
    while (current_ptr != 0)
    {
        // Update each node's price_per_share with the latest stock price
        current_ptr->price_per_share = get_stock_price(fileName, current_ptr->stock_symbol);
        current_ptr = current_ptr->next;
    }
}

// Function to buy shares of a stock
void StockAccount::buy_shares(string fileName, string stock_symbol, int num_of_shares, double max_amt_per_share)
{
    double curr_amt_per_share; // Variable to store the current price per share
    int choice, count = 0; // Variables for user choice and counting shares

    // Check if the total cost of shares exceeds available cash balance
    if (num_of_shares * max_amt_per_share > get_cash_balance())
    {
        // TRANSACTION FAIL
    }
    else
    {
        // Get the current price per share for the specified stock symbol
        curr_amt_per_share = get_stock_price(fileName, stock_symbol);

        // Check if the stock symbol is found
        if (curr_amt_per_share == -1)
            cout << "Symbol not found!!!" << endl
                 << endl;
        else
        {
            // Check if the current price per share is within the allowed maximum
            if (curr_amt_per_share > max_amt_per_share)
            {
                cout << "Transaction failed because the price per share is higher than the maximum amount you are willing to pay" << endl
                     << endl;
            }
            else
            {
                // Create a new node for the purchased shares
                Node *new_node = new Node(stock_symbol, num_of_shares, curr_amt_per_share);

                // If the portfolio is empty, add the new node
                if (size() == 0)
                {
                    Head = new_node;
                    mySize++;

                    // Update cash balance and perform a bank withdrawal
                    set_cash_balance(get_cash_balance() - (num_of_shares * curr_amt_per_share));
                    BankAccount *b = new BankAccount();
                    b->withdraw(num_of_shares * curr_amt_per_share);
                    delete b;

                    // Display purchase details and update transaction history
                    cout << "You have purchased " << num_of_shares << " shares of " << stock_symbol << " at $" << curr_amt_per_share << " each for a total of $" << num_of_shares * curr_amt_per_share << endl;

                    ofstream file2;
                    file2.open("stock_transaction_history.txt", ios::app);
                    time_t seconds;
                    seconds = time(NULL);
                    char time[9];
                    tm *timeinfo;
                    timeinfo = localtime(&seconds);
                    strftime(time, 100, "%X", timeinfo);
                    file2 << setprecision(2) << fixed;
                    file2 << left << setw(10) << "Buy" << left << setw(16) << stock_symbol << left << setw(8) << num_of_shares << left << left << setw(1) << "$" << setw(19) << curr_amt_per_share << left << setw(1) << "$" << left << setw(15) << num_of_shares * curr_amt_per_share << time << endl;
                    file2.close();
                }
                else
                {
                    // If the portfolio is not empty, update existing shares or add new shares
                    Node *current_ptr = Head;

                    while (current_ptr != NULL)
                    {
                        if (current_ptr->stock_symbol == new_node->stock_symbol)
                        {
                            // Update existing shares
                            current_ptr->num_of_shares += new_node->num_of_shares;
                            count = 1;

                            // Update cash balance and perform a bank withdrawal
                            set_cash_balance(get_cash_balance() - (num_of_shares * curr_amt_per_share));
                            BankAccount *b = new BankAccount();
                            b->withdraw(num_of_shares * curr_amt_per_share);
                            delete b;

                            // Display purchase details and update transaction history
                            cout << "You have purchased " << num_of_shares << " shares of " << stock_symbol << " at $" << curr_amt_per_share << " each for a total of $" << num_of_shares * curr_amt_per_share << endl;

                            ofstream file2;
                            file2.open("stock_transaction_history.txt", ios::app);
                            time_t seconds;
                            seconds = time(NULL);
                            char time[9];
                            tm *timeinfo;
                            timeinfo = localtime(&seconds);
                            strftime(time, 100, "%X", timeinfo);
                            file2 << setprecision(2) << fixed;
                            file2 << left << setw(10) << "Buy" << left << setw(16) << stock_symbol << left << setw(8) << num_of_shares << left << left << setw(1) << "$" << setw(19) << curr_amt_per_share << left << setw(1) << "$" << left << setw(15) << num_of_shares * curr_amt_per_share << time << endl;
                            file2.close();
                        }

                        current_ptr = current_ptr->next;
                    }

                    if (count == 0)
                    {
                        // Add new shares if the stock symbol is not already in the portfolio
                        Node *current_ptr = Head;

                        while (current_ptr->next != NULL)
                            current_ptr = current_ptr->next;

                        current_ptr->next = new_node;
                        new_node->pre = current_ptr;
                        mySize++;

                        // Update cash balance and perform a bank withdrawal
                        set_cash_balance(get_cash_balance() - (num_of_shares * curr_amt_per_share));
                        BankAccount *b = new BankAccount();
                        b->withdraw(num_of_shares * curr_amt_per_share);
                        delete b;

                        // Display purchase details and update transaction history
                        cout << "You have purchased " << num_of_shares << " shares of " << stock_symbol << " at $" << curr_amt_per_share << " each for a total of $" << num_of_shares * curr_amt_per_share << endl;

                        ofstream file2;
                        file2.open("stock_transaction_history.txt", ios::app);
                        time_t seconds;
                        seconds = time(NULL);
                        char time[9];
                        tm *timeinfo;
                        timeinfo = localtime(&seconds);
                        strftime(time, 100, "%X", timeinfo);
                        file2 << setprecision(2) << fixed;
                        file2 << left << setw(10) << "Buy" << left << setw(16) << stock_symbol << left << setw(8) << num_of_shares << left << left << setw(1) << "$" << setw(19) << curr_amt_per_share << left << setw(1) << "$" << left << setw(15) << num_of_shares * curr_amt_per_share << time << endl;
                        file2.close();
                    }
                }
            }
        }
    }

    // Update stock prices in the portfolio
    update_list(fileName);

    // If there is more than one stock, prompt the user to select a sorting algorithm
    if (size() > 1)
    {
        cout << endl
             << "Select the sorting algorithm that you would like to use" << endl;
        cout << "1: Selection sort" << endl;
        cout << "2: Bubble sort" << endl;
        cout << "Enter your choice" << endl;
        cin >> choice;

        // Select the chosen sorting algorithm and sort the portfolio
        switch (choice)
        {
        case 1:
            delete impl;
            impl = new SortSelection;
            Head = impl->sort(Head);
            break;

        case 2:
            delete impl;
            impl = new SortBubble;
            Head = impl->sort(Head);
            break;

        default:
            cout << "You have entered the wrong choice" << endl;
            break;
        }
    }

    // Print the updated portfolio and store it
    print_portfolio();
    store_portfolio();
}

// Function to sell shares of a stock
void StockAccount::sell_shares(string fileName, string stock_symbol, int num_of_shares, double min_amt_per_share)
{
    double curr_amt_per_share; // Variable to store the current price per share
    int choice, count = 0; // Variables for user choice and counting shares

    // Get the current price per share for the specified stock symbol
    curr_amt_per_share = get_stock_price(fileName, stock_symbol);

    Node *current_ptr = Head;
    Node *temp = NULL; // Temporary pointer to delete nodes

    // Check if the portfolio is empty
    if (size() == 0)
        cout << "The stock portfolio is empty" << endl;
    else
    {
        // Traverse the portfolio to find the specified stock symbol
        while (current_ptr != NULL)
        {
            if (current_ptr->stock_symbol == stock_symbol)
            {
                // Check if the number of shares to sell is greater than the available shares
                if (num_of_shares > current_ptr->num_of_shares)
                {
                    cout << "Transaction failed due to insufficient number of shares" << endl;
                }
                else
                {
                    // Check if the price per share is greater than the minimum amount allowed
                    if (current_ptr->price_per_share < min_amt_per_share)
                        cout << "Transaction failed because the price per share is less than the amount you are willing to sell" << endl;
                    else
                    {
                        // Update the number of shares and handle node deletion if necessary
                        current_ptr->num_of_shares -= num_of_shares;

                        if (current_ptr->num_of_shares == 0)
                        {
                            temp = current_ptr;

                            if (Head == current_ptr)
                                Head = current_ptr->next;

                            if (current_ptr->next != NULL)
                                current_ptr->next->pre = current_ptr->pre;

                            if (current_ptr->pre != NULL)
                                current_ptr->pre->next = current_ptr->next;

                            mySize--;
                        }

                        // Update cash balance and perform a bank deposit
                        set_cash_balance(get_cash_balance() + (num_of_shares * curr_amt_per_share));
                        BankAccount *b = new BankAccount();
                        b->deposit(num_of_shares * curr_amt_per_share);
                        delete b;

                        // Display sale details and update transaction history
                        cout << "You have sold " << num_of_shares << " shares of " << stock_symbol << " at $" << curr_amt_per_share << " each for a total of $" << num_of_shares * curr_amt_per_share << endl;

                        ofstream file2;
                        file2.open("stock_transaction_history.txt", ios::app);
                        time_t seconds;
                        seconds = time(NULL);
                        char time[9];
                        tm *timeinfo;
                        timeinfo = localtime(&seconds);
                        strftime(time, 100, "%X", timeinfo);
                        file2 << setprecision(2) << fixed;
                        file2 << left << setw(10) << "Sell" << left << setw(16) << stock_symbol << left << setw(8) << num_of_shares << left << left << setw(1) << "$" << setw(19) << curr_amt_per_share << left << setw(1) << "$" << left << setw(15) << num_of_shares * curr_amt_per_share << time << endl;
                        file2.close();
                    }
                }
                count = 1;
            }
            current_ptr = current_ptr->next;
        }

        // Display an error message if the stock symbol is not found
        if (count == 0)
            cout << "Symbol not found!!!" << endl;
    }

    // Update stock prices in the portfolio
    update_list(fileName);

    // If there is more than one stock and the stock symbol was found, prompt the user to select a sorting algorithm
    if (size() > 1 && count != 0)
    {
        cout << endl
             << "Select the sorting algorithm that you would like to use" << endl;
        cout << "1: Selection sort" << endl;
        cout << "2: Bubble sort" << endl;
        cout << "Enter your choice" << endl;
        cin >> choice;

        // Select the chosen sorting algorithm and sort the portfolio
        switch (choice)
        {
        case 1:
            delete impl;
            impl = new SortSelection;
            Head = impl->sort(Head);
            break;
        case 2:
            delete impl;
            impl = new SortBubble;
            Head = impl->sort(Head);
            break;

        default:
            cout << "You have entered the wrong choice" << endl;
            break;
        }
    }

    // Print the updated portfolio and store it
    print_portfolio();
    store_portfolio();
    delete temp; // Delete the temporary pointer
}

// Function to display transaction history
void StockAccount::get_trans_history()
{
    string l; // Variable to store each line of the file
    ifstream file1("stock_transaction_history.txt"); // Open the transaction history file
    cout << left << setw(10) << "Event" << left << setw(16) << "Company Symbol" << left << setw(8) << "Number" << left << setw(20) << "Price per share" << left << setw(16) << "Total value" << "Time" << endl;

    // Check if the file is open
    if (file1.is_open())
    {
        // Read each line from the file and display it
        while (getline(file1, l))
        {
            cout << l << endl;
        }

        file1.close(); // Close the file
    }
    else
    {
        cout << "Error in opening file" << endl; // Display an error message if the file cannot be opened
    }
}

// Function to store the current portfolio and total value
void StockAccount::store_portfolio()
{
    double total = 0.0; // Variable to store the total value of the portfolio

    Node *current_ptr = Head; // Pointer to traverse the linked list

    // Check if the portfolio is empty
    if (size() == 0)
    {
        // If empty, remove the existing portfolio file
        remove("stock_portfolio.txt");
    }
    else
    {
        // If not empty, remove the existing portfolio file
        remove("stock_portfolio.txt");

        // Traverse the linked list to calculate the total value and store each stock's information in the portfolio file
        while (current_ptr != 0)
        {
            total += current_ptr->num_of_shares * current_ptr->price_per_share;

            ofstream file2;
            file2.open("stock_portfolio.txt", ios::app);
            file2 << setprecision(2) << fixed;
            file2 << left << setw(10) << current_ptr->stock_symbol << left << setw(10) << current_ptr->num_of_shares << left << setw(16) << current_ptr->price_per_share << endl;
            file2.close();

            current_ptr = current_ptr->next;
        }
    }

    // Open the file to store the total portfolio value
    ofstream file2;
    file2.open("total_portfolio_value.txt", ios::app);
    time_t seconds;
    seconds = time(NULL);
    char date[9];
    tm *timeinfo;
    timeinfo = localtime(&seconds);
    strftime(date, 100, "%D", timeinfo);
    file2 << setprecision(2) << fixed;
    file2 << left << setw(16) << get_cash_balance() + total << left << setw(16) << seconds << date << endl;
    file2.close();
}
