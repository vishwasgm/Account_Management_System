//Name: Vishwas Gowdihalli Mahalingappa
//Netid: vg421

// Header guards to prevent multiple inclusion of the same file
#ifndef SORTING_IMPLEMENTATION_VISHWASGM_H
#define SORTING_IMPLEMENTATION_VISHWASGM_H


#include <iostream>
#include <string>

using namespace std;

// Declaration of the SortImpl class
class SortImpl {
public:
    // Pure virtual function for sorting a linked list of Nodes
    virtual Node* sort(Node*) = 0;
};

// Declaration of the SortSelection class, inheriting from SortImpl
class SortSelection : public SortImpl {
public:
    // Implementation of the sort function using selection sort algorithm
    virtual Node* sort(Node* Start)
    {
        Node* current_ptr = Start;
        Node* largest_ptr = Start;
        string temp_ss;
        int temp_sh;
        double temp_pps;

        // Outer loop to traverse the list
        do
        {
            current_ptr = largest_ptr->next;

            // Inner loop to compare and find the largest node
            while (current_ptr != NULL)
            {
                // Compare the product of num_of_shares and price_per_share for sorting
                if ((current_ptr->num_of_shares * current_ptr->price_per_share) > (largest_ptr->num_of_shares * largest_ptr->price_per_share))
                {
                    // Swap data of largest_ptr and current_ptr
                    temp_ss = largest_ptr->stock_symbol;
                    temp_sh = largest_ptr->num_of_shares;
                    temp_pps = largest_ptr->price_per_share;

                    largest_ptr->stock_symbol = current_ptr->stock_symbol;
                    largest_ptr->num_of_shares = current_ptr->num_of_shares;
                    largest_ptr->price_per_share = current_ptr->price_per_share;

                    current_ptr->stock_symbol = temp_ss;
                    current_ptr->num_of_shares = temp_sh;
                    current_ptr->price_per_share = temp_pps;
                }
                current_ptr = current_ptr->next;
            }

            // Move the largest_ptr to the next node
            largest_ptr = largest_ptr->next;
        } while (largest_ptr != NULL);

        return Start;
    }
};

// Declaration of the SortBubble class, inheriting from SortImpl
class SortBubble : public SortImpl {
public:
    // Implementation of the sort function using bubble sort algorithm
    virtual Node* sort(Node* Start)
    {
        bool flag;
        Node* current_ptr = Start;
        Node* lastPtr = NULL;
        string temp_ss;
        int temp_sh;
        double temp_pps;

        // Outer loop for each pass
        do
        {
            flag = false;
            current_ptr = Start;

            // Inner loop to compare and swap adjacent nodes
            while (current_ptr->next != lastPtr)
            {
                // Compare the product of num_of_shares and price_per_share for sorting
                if ((current_ptr->num_of_shares * current_ptr->price_per_share) < (current_ptr->next->num_of_shares * current_ptr->next->price_per_share))
                {
                    // Swap data of current_ptr and current_ptr->next
                    temp_ss = current_ptr->stock_symbol;
                    temp_sh = current_ptr->num_of_shares;
                    temp_pps = current_ptr->price_per_share;

                    current_ptr->stock_symbol = current_ptr->next->stock_symbol;
                    current_ptr->num_of_shares = current_ptr->next->num_of_shares;
                    current_ptr->price_per_share = current_ptr->next->price_per_share;

                    current_ptr->next->stock_symbol = temp_ss;
                    current_ptr->next->num_of_shares = temp_sh;
                    current_ptr->next->price_per_share = temp_pps;

                    flag = true;
                }
                current_ptr = current_ptr->next;
            }

            // Move the lastPtr to the current_ptr
            lastPtr = current_ptr;

        } while (flag == true);

        return Start;
    }
};

// End of header guard
#endif
