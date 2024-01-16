/* We are given an array Arr[] of length n. It represents the price of a stock on n days. The following guidelines need to be followed:

- We can buy and sell the stock any number of times.
- In order to sell the stock, we need to first buy it on the same or any previous day.
- We can’t buy a stock again after buying it once. In other words, we first buy a stock and then sell it. After selling we can buy and sell again. But we can’t sell before buying and can’t buy before selling any previously bought stock.
- We can do at-most K transactions. */

#include <bits/stdc++.h>
using namespace std;

// memoization, tabulation & spaceOptimised are same as previous one, but instead of stopping cap at 2, we have to stop cap at k.

// Below is another way of solving it, which can be applicable to previous problem also. But it is not implemented for previous one. I have only implemented it for this one.

int memoization(int ind, int tranNo, vector<int> &prices, int n, int k, vector<vector<int>> &dp)
{
    if (ind == n || tranNo == 2 * k)
        return 0;
    if (dp[ind][tranNo] != -1)
        dp[ind][tranNo];
    if (tranNo % 2 == 0) // You can buy. You cannot sell.
    {
        int buy = -prices[ind] + memoization(ind + 1, tranNo + 1, prices, n, k, dp);
        int dontBuy = 0 + memoization(ind + 1, tranNo, prices, n, k, dp);
        return dp[ind][tranNo] = max(buy, dontBuy);
    }
    else // You can sell. You cannot buy.
    {
        int sell = prices[ind] + memoization(ind + 1, tranNo + 1, prices, n, k, dp);
        int notSell = 0 + memoization(ind + 1, tranNo, prices, n, k, dp);
        return dp[ind][tranNo] = max(sell, notSell);
    }
}

int tabulation(vector<int> &prices, int n, int k)
{
    vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));
    // Base case: dp array is already initialized to 0, covering the base case. So writing for loops and conditions to initialize the array with base cases is of no sense because in the base case also the array elements are initialized to 0.

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int tranNo = 2 * k - 1; tranNo >= 0; tranNo--)
        {
            if (tranNo % 2 == 0) // You can buy. You cannot sell.
            {
                int buy = -prices[ind] + dp[ind + 1][tranNo + 1];
                int dontBuy = 0 + dp[ind + 1][tranNo];
                dp[ind][tranNo] = max(buy, dontBuy);
            }
            else // You can sell. You cannot buy.
            {
                int sell = prices[ind] + dp[ind + 1][tranNo + 1];
                int notSell = 0 + dp[ind + 1][tranNo];
                dp[ind][tranNo] = max(sell, notSell);
            }
        }
    }
    return dp[0][0];
}

// TC = n*2k, SC = 2k + 1
int spaceOptimised(vector<int> &prices, int n, int k)
{
    vector<int> after(2 * k + 1, 0);
    vector<int> curr(2 * k + 1, 0);
    // Base case: dp array is already initialized to 0, covering the base case. So writing for loops and conditions to initialize the array with base cases is of no sense because in the base case also the array elements are initialized to 0.

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int tranNo = 2 * k - 1; tranNo >= 0; tranNo--)
        {
            if (tranNo % 2 == 0) // You can buy. You cannot sell.
            {
                int buy = -prices[ind] + after[tranNo + 1];
                int dontBuy = 0 + after[tranNo];
                curr[tranNo] = max(buy, dontBuy);
            }
            else // You can sell. You cannot buy.
            {
                int sell = prices[ind] + after[tranNo + 1];
                int notSell = 0 + after[tranNo];
                curr[tranNo] = max(sell, notSell);
            }
        }
        after = curr;
    }
    return curr[0];
}
int main()
{
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = prices.size();
    int k = 2;
    vector<vector<int>> dp(n, vector<int>(2 * k, -1));
    cout << memoization(0, 0, prices, n, k, dp) << endl;
    cout << tabulation(prices, n, k) << endl;
    cout << spaceOptimised(prices, n, k) << endl;
    return 0;
}
