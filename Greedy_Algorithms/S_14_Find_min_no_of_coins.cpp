// Given a value V, if we want to make a change for V Rs, and we have an infinite supply of each of the denominations in Indian currency, i.e., we have an infinite supply of { 1, 2, 5, 10, 20, 50, 100, 500, 1000} valued coins/notes, what is the minimum number of coins and/or notes needed to make the change.

#include <bits/stdc++.h>
using namespace std;

// TC
int main()
{
    int V = 87;
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int denominationIndex = coins.size() - 1; // We start by spending the 1000rs
    int coinsUsed = 0;
    while(V != 0)
    {
        if(coins[denominationIndex] <=  V)
        {
            coinsUsed++;
            V -= coins[denominationIndex];
        }
        else
            denominationIndex--;
    }
    cout << coinsUsed;
}