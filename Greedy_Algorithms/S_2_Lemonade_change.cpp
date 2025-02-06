/*
At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you and order one at a time (in the order specified by bills). Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. You must provide the correct change to each customer so that the net transaction is that the customer pays $5.

Note that you do not have any change in hand at first.

Given an integer array bills where bills[i] is the bill the ith customer pays, return true if you can provide every customer with the correct change, or false otherwise.
*/
#include <bits/stdc++.h>
using namespace std;

bool brute(vector<int> &bills)
{
    int fives = 0, tens = 0;
    for (int i = 0; i < bills.size(); i++)
    {
        if (bills[i] == 5)
        {
            fives++;
        }
        else if (bills[i] == 10)
        {
            if(fives>0)
            {
                tens++;
                fives--;
            }
            else
            {
                return false;
            }
        }
        else if (bills[i] == 20)
        {
            if(tens > 0 && fives > 0)
            {
                tens--;
                fives--;
            }
            else if(fives >=3)
            {
                fives -= 3;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    vector<int> bills = {5, 5, 5, 10, 20};
    cout << brute(bills) << endl;
}