/* We are given an array Arr[] of length n. It represents the price of a stock on ‘n’ days. The following guidelines need to be followed:

- We can buy and sell a stock only once.
- We can buy and sell the stock on any day but to sell the stock, we need to first buy it on the same or any previous day.
We need to tell the maximum profit one can get by buying and selling this stock.*/

// If you are selling on the i-th day then you buy on the minimum proces from the 1st to the (i - 1)th day.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> Arr = {7, 1, 5, 3, 6, 4};
    int maxProfit = 0;
    int minBuyingPrice = Arr[0];
    for (int i = 1; i < Arr.size(); i++)
    {
        int curProfit = Arr[i] - minBuyingPrice;
        maxProfit = max(maxProfit, curProfit);
        minBuyingPrice = min(minBuyingPrice, Arr[i]);
    }
    cout << maxProfit;
}