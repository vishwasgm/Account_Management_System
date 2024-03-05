//Name: Vishwas Gowdihalli Mahalingappa
//Netid: vg421

#include <iostream>
#include <string>
#include <time.h>
#include <iomanip>

#include "StockAccount_VishwasGM.h"
#include "BankAccount_VishwasGM.h"

using namespace std;

// Function to generate a random file name
string generateRandomFileName();

int main()
{
    // Create instances of BankAccount and StockAccount
    BankAccount bankAccount;
    StockAccount stockAccount;

    // Array of pointers to Account objects
    Account *accounts[] = {&stockAccount, &bankAccount};

    cout << "ACCOUNT MANAGEMENT SYSTEM." << endl
         << endl;

    int option;
    int mainChoice = 0;
    int stockChoice = 0;
    int bankChoice = 0;
    int numberOfShares;
    double amount, stockPrice, maxAmountPerShare, minAmountPerShare;
    string stockSymbol;

    // Main loop for the user interface
    while (mainChoice != 3)
    {
        cout << "Please select an account to access:" << endl;
        cout << "1: Stock Portfolio Account " << endl;
        cout << "2: Bank Account" << endl;
        cout << "3: Exit " << endl;

        cout << endl << "Enter your choice: ";
        cin >> mainChoice;

        switch (mainChoice)
        {
        case 1:
            // Loop for Stock Portfolio Account options
            while (stockChoice != 7)
            {
                cout << endl;
                accounts[0]->print_type();
                cout << "1: Display the price for a stock symbol " << endl;
                cout << "2: Display the current portfolio" << endl;
                cout << "3: Buy shares" << endl;
                cout << "4: Sell shares" << endl;
                cout << "5: View a graph for the portfolio value" << endl;
                cout << "6: View transaction history" << endl;
                cout << "7: Return to previous menu " << endl;
                cout << "Please select an option:" << endl;
                cin >> option;

                switch (option)
                {
                case 1:
                    // Option to display stock price for a symbol
                    cout << endl << "Please enter the stock symbol: ";
                    cin >> stockSymbol;
                    stockPrice = stockAccount.get_stock_price(generateRandomFileName(), stockSymbol);
                    if (stockPrice != -1)
                    {
                        cout << "Company Symbol     " << "Price per share" << endl;
                        cout << stockSymbol << setw(18) << "$" << stockPrice << '\n';
                    }
                    else
                        cout << "Symbol not found!!!" << endl;
                    break;

                case 2:
                    // Option to display the current portfolio
                    stockAccount.print_portfolio();
                    break;

                case 3:
                    // Option to buy shares
                    cout << endl << "Please enter the stock symbol you want to purchase: ";
                    cin >> stockSymbol;
                    cout << endl << "Please enter the number of shares: ";
                    cin >> numberOfShares;
                    cout << endl << "Please enter the maximum amount you are willing to pay per share: ";
                    cin >> maxAmountPerShare;
                    stockAccount.buy_shares(generateRandomFileName(), stockSymbol, numberOfShares, maxAmountPerShare);
                    break;

                case 4:
                    // Option to sell shares
                    cout << endl << "Please enter the stock symbol you want to sell: ";
                    cin >> stockSymbol;
                    cout << endl << "Please enter the number of shares: ";
                    cin >> numberOfShares;
                    cout << endl << "Please enter the minimum amount you are willing to pay per share: ";
                    cin >> minAmountPerShare;
                    stockAccount.sell_shares(generateRandomFileName(), stockSymbol, numberOfShares, minAmountPerShare);
                    break;

                case 5:
                    // Placeholder for viewing a graph for the portfolio value
                    break;

                case 6:
                    // Option to view transaction history
                    stockAccount.get_trans_history();
                    break;

                case 7:
                    // Exit Stock Portfolio Account
                    stockChoice = 7;
                    cout << endl << endl;
                    break;

                default:
                    cout << "You have entered wrong choice" << endl << endl;
                    break;
                }
            }
            stockChoice = 0;
            break;

        case 2:
            // Loop for Bank Account options
            while (bankChoice != 5)
            {
                cout << endl;
                accounts[1]->print_type();
                cout << "1: View account balance " << endl;
                cout << "2: Deposit money" << endl;
                cout << "3: Withdraw money" << endl;
                cout << "4: Print out history" << endl;
                cout << "5: Return to previous menu " << endl;
                cout << "Please select an option:" << endl;
                cin >> option;
                cout << endl;

                switch (option)
                {
                case 1:
                    // Option to view bank account balance
                    cout << "You have $" << bankAccount.get_cash_balance() << " in your bank account" << endl;
                    break;

                case 2:
                    // Option to deposit money
                    cout << "Please enter the amount: ";
                    cin >> amount;
                    bankAccount.deposit(amount);
                    break;

                case 3:
                    // Option to withdraw money
                    cout << "Please enter the amount: ";
                    cin >> amount;
                    bankAccount.withdraw(amount);
                    break;

                case 4:
                    // Option to view bank transaction history
                    bankAccount.get_trans_history();
                    break;

                case 5:
                    // Exit Bank Account
                    bankChoice = 5;
                    cout << endl << endl;
                    break;

                default:
                    cout << "You have entered wrong choice" << endl << endl;
                    break;
                }
            }
            bankChoice = 0;
            break;

        case 3:
            // Exit the program
            cout << endl << "Exiting" << endl;
            mainChoice = 3;
            break;

        default:
            cout << endl << "You have entered wrong choice" << endl << endl;
            break;
        }
    }

    // Store the stock portfolio after exiting the main loop
    stockAccount.store_portfolio();

    return 0;
}

// Function to generate a random file name
string generateRandomFileName()
{
    int randomNumber;
    string fileNames[2] = {"Result_1.txt", "Result_2.txt"};

    srand(time(0));
    randomNumber = rand() % 2;

    return fileNames[randomNumber];
}
