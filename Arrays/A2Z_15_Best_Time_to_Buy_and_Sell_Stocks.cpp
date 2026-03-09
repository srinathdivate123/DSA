// https://takeuforward.org/data-structure/stock-buy-and-sell
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

#include <bits/stdc++.h>
using namespace std;

// Brute would be an TC with N square
void brute()
{
}

// TC = N
// SC = 1
void best(int arr[], int n)
{
    int maxProfit = 0, minPrice = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        minPrice = min(minPrice, arr[i]);
        maxProfit = max(maxProfit, arr[i] - minPrice);
    }
    cout << "Maximum Profit that can be made is: " << maxProfit;
}

int main()
{
    // The below array represents the prices of the stock as the time passes
    int arr[] = {7, 1, 5, 3, 6, 4};
    best(arr, sizeof(arr) / sizeof(arr[0]));
    return 0;
}