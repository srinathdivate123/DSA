// Say you have an array for which the ith element is the price of a given stock on day i.
// If you were only permitted to complete at most one transaction (i.e buy one and sell one share of stock), design an algo to find maximum profit
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
        if (arr[i] < minPrice)
            minPrice = arr[i];
            
        if (maxProfit < arr[i] - minPrice)
            maxProfit = arr[i] - minPrice;
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