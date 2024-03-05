Name: Vishwas Gowdihalli Mahalingappa

Account Management System


Description:

The Account Management System is a program that facilitates the management of both stock portfolios and bank accounts. It provides users with a user-friendly interface to perform various financial transactions, view account details, and track their investment portfolio. The system is designed to handle stock-related operations, such as buying and selling shares, and bank-related actions, including deposits and withdrawals.
	
Project Functionalities

Stock Portfolio Management

•	The StockAccount class facilitates the management of stock portfolios, allowing users to perform various operations related to buying and selling stocks. Key functionalities include:

Loading Portfolio from File:
•	Reads the stock portfolio from the "stock_portfolio.txt" file during program initialization.

Displaying Portfolio:
•	Prints the current stock portfolio, including details like company symbols, the number of shares, and price per share.

Buying Shares:
•	Enables users to buy a specified number of shares for a given stock, considering a maximum amount per share.
•	Updates the portfolio and transaction history accordingly.
•	Implements error checks for insufficient cash balance and stock symbol validation.

Selling Shares:
•	Allows users to sell a specified number of shares for a given stock, considering a minimum amount per share.
•	Updates the portfolio and transaction history accordingly.
•	Implements error checks for insufficient shares and stock symbol validation.

Updating Stock Prices:
•	Periodically updates the stock prices in the portfolio based on real-time or file-based data.

Sorting Portfolio:
•	Supports sorting the portfolio using either selection sort or bubble sort, based on user preference.

Displaying Transaction History:
•	Presents a transaction history log showing buy and sell events with relevant details.

Storing Portfolio:
•	Persists the stock portfolio in the "stock_portfolio.txt" file.

Storing Total Portfolio Value:
•	Logs the total portfolio value in the "total_portfolio_value.txt" file.

Bank Account Management

The BankAccount class manages bank account functionalities, including cash balance, depositing, withdrawing, and transaction history. Key functionalities include:

Viewing Account Balance:
•	Displays the current cash balance in the bank account.

Depositing Money:
•	Allows users to deposit a specified amount into the bank account.
•	Updates the cash balance and transaction history accordingly.

Withdrawing Money:
•	Permits users to withdraw a specified amount from the bank account.
•	Updates the cash balance and transaction history accordingly.
•	Implements error checks for insufficient funds.

Displaying Transaction History:
•	Shows a log of all transactions, including deposits and withdrawals.

Sorting Algorithms

•	Two sorting algorithms, namely selection sort and bubble sort, are implemented to allow users to choose their preferred sorting method for the stock portfolio.

Graph Display (Not Implemented)
•	While currently a placeholder option, future iterations may include a graphical representation of the portfolio value over time.

Main Functionality
•	The main function serves as the user interface, allowing users to interact with both the StockAccount and BankAccount functionalities. It provides a menu-driven approach for users to select their desired actions.

Initialization:
•	Creates instances of the StockAccount and BankAccount classes.
•	Utilizes an array of Account pointers to manage both types of accounts.

User Interaction Loop:
•	Allows users to select between Stock Portfolio Account, Bank Account, or Exit options.
•	Based on the chosen account type, further options are presented for user interaction.

Stock Portfolio Account Options:
•	Display the price for a stock symbol.
•	Display the current portfolio.
•	Buy shares.
•	Sell shares.
•	View a graph for the portfolio value (not implemented).
•	View transaction history.
•	Return to the previous menu.

Bank Account Options:
•	View account balance.
•	Deposit money.
•	Withdraw money.
•	Print out history.
•	Return to the previous menu.

File Name Selection:
•	Uses the getFileName function to randomly select a stock data file from a predefined array.

Exit:
•	Terminates the program.


Data Structures Used

Doubly Linked List (StockAccount Class):
•	Represents the stock portfolio, where each node stores information about a specific stock.

Array of Account Pointers (main Function):
•	Facilitates the management of both StockAccount and BankAccount instances.

Text Files Generated

"stock_portfolio.txt":
•	Stores the current stock portfolio, including company symbols, the number of shares, and price per share.
•	Updated during portfolio updates and purchases/sales.

"total_portfolio_value.txt":
•	Logs the total portfolio value over time, including the timestamp.
•	Updated during portfolio updates and purchases/sales.

"stock_transaction_history.txt":
•	Records all buy and sell transactions with relevant details, including event type, company symbol, number of shares, price per share, total value, and timestamp.
•	Updated during stock purchases and sales.

"bank_transaction_history.txt":
•	Documents all bank transactions, including deposits and withdrawals, with details such as the transaction type, amount, new balance, and timestamp.
•	Updated during bank deposits and withdrawals.
•	These text files serve as essential components for maintaining and recording the state and history of both the stock portfolio and bank account. They provide users with a transparent record of their financial transactions and portfolio changes.

Conclusion:

The Account Management System integrates essential functionalities for managing both stock and bank accounts, providing users with a comprehensive tool for financial portfolio management. The main function provides user interactions and ensures a seamless experience. The project's modular design allows for future expansions and improvements. Ongoing development may focus on refining existing features, introducing new sorting algorithms, and implementing the graph display for a more interactive user experience.

Compilation and Execution:

To compile and run the code, follow these steps:

1.	Compile the code by executing the following command :

        g++ -w Account_VishwasGM.cpp BankAccount_VishwasGM.cpp StockAccount_VishwasGM.cpp Main_VishwasGM.cpp -o main
        
2.	Run the program by executing the resulting executable:

        ./main
