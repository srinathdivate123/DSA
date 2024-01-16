/* We are given an array arr of length n. It represents the price of a stock on n days.

- We can buy and sell the stock any number of times.
- In order to sell the stock, we need to first buy it on the same or any previous day.
- We can’t buy a stock again after buying it once. In other words, we first buy a stock and then sell it. After selling we can buy and sell another stock. But we can’t sell before buying and can’t buy before selling any previously bought stock.
- Means, at any given time, you can have only 1 or 0 stock with you. */

#include <bits/stdc++.h>
using namespace std;
// Starting on 0th day with 'buy', what max profit can you give me?
// TC = n*2, SC = n*2 + n
long memoization(long *Arr, int n, int ind, int buy, vector<vector<long>> &dp)
{
    // Base case: When we reach the end of the array, there are no more decisions to make.
    if (ind == n)
        return 0;

    if (dp[ind][buy] != -1)
        return dp[ind][buy];

    long profit = 0;

    if (buy == 1) // You are allowed to buy. You cannot sell.
    {
        // If you buy, you'll have a profit of -Arr[ind]
        long buyStock = -Arr[ind] + memoization(Arr, n, ind + 1, 0, dp);
        long dontBuyStock = 0 + memoization(Arr, n, ind + 1, 1, dp);
        profit = max(buyStock, dontBuyStock);
    }

    if (buy == 0) // You cannot buy. You are allowed to sell
    {
        // If you sell, you'll have a profit of +Arr[ind]
        long SellStock = +Arr[ind] + memoization(Arr, n, ind + 1, 1, dp);
        long dontSellStock = 0 + memoization(Arr, n, ind + 1, 0, dp);
        profit = max(SellStock, dontSellStock);
    }

    return dp[ind][buy] = profit;
}

// TC = n*2, SC = n*2
long tabulation(long *Arr, int n)
{
    long profit = 0;
    vector<vector<long>> dp(n + 1, vector<long>(2, 0));
    dp[n][0] = dp[n][1] = 0;
    for (int ind = n - 1; ind >= 0; ind--)
        for (int buy = 0; buy <= 1; buy++)
        {
            if (buy == 1) // You are allowed to buy. You cannot sell.
            {
                // If you buy, you'll have a profit of -Arr[ind]
                long buyStock = -Arr[ind] + dp[ind + 1][0];
                long dontBuyStock = 0 + dp[ind + 1][1];
                profit = max(buyStock, dontBuyStock);
            }

            if (buy == 0) // You cannot buy. You are allowed to sell
            {
                // If you sell, you'll have a profit of +Arr[ind]
                long SellStock = +Arr[ind] + dp[ind + 1][1];
                long dontSellStock = 0 + dp[ind + 1][0];
                profit = max(SellStock, dontSellStock);
            }
            dp[ind][buy] = profit;
        }
    return dp[0][1];
}

// TC = n*2, SC = 1
long spaceOptimised(long *Arr, int n)
{
    vector<long> ahead(2, 0), curr(2, 0);
    ahead[0] = ahead[1] = 0;
    for (int ind = n - 1; ind >= 0; ind--)
    {
        long profit = 0;
        for (int buy = 0; buy <= 1; buy++)
        {
            if (buy == 1) // You are allowed to buy. You cannot sell.
            {
                // If you buy, you'll have a profit of -Arr[ind]
                long buyStock = -Arr[ind] + ahead[0];
                long dontBuyStock = 0 + ahead[1];
                profit = max(buyStock, dontBuyStock);
            }

            if (buy == 0) // You cannot buy. You are allowed to sell
            {
                // If you sell, you'll have a profit of +Arr[ind]
                long SellStock = +Arr[ind] + ahead[1];
                long dontSellStock = 0 + ahead[0];
                profit = max(SellStock, dontSellStock);
            }
            curr[buy] = profit;
        }
        ahead = curr;
    }
    return ahead[1];
}

// TC = n*2, SC = 1
long spaceOptimised_DifferentVariation(long *Arr, int n)
{
    long aheadNotBuy = 0, aheadBuy = 0, curNotBuy, curBuy;
    for (int ind = n - 1; ind >= 0; ind--)
    {
        // If you sell, you'll have a profit of +Arr[ind]
        long SellStock = +Arr[ind] + aheadBuy;
        long dontSellStock = 0 + aheadNotBuy;
        curNotBuy = max(SellStock, dontSellStock);

        // If you buy, you'll have a profit of -Arr[ind]
        long buyStock = -Arr[ind] + aheadNotBuy;
        long dontBuyStock = 0 + aheadBuy;
        curBuy = max(buyStock, dontBuyStock);

        aheadNotBuy = curNotBuy;
        aheadBuy = curBuy;
    }
    return aheadBuy;
}
int main()
{
    int n = 6;
    long Arr[n] = {7, 1, 5, 3, 6, 4};
    vector<vector<long>> dp(n, vector<long>(2, -1));
    if (n == 0)
        cout << 0 << endl;
    else
        cout << memoization(Arr, n, 0, 1, dp) << endl;
    cout << tabulation(Arr, n) << endl;
    cout << spaceOptimised(Arr, n) << endl;
    cout << spaceOptimised_DifferentVariation(Arr, n) << endl;
    return 0;
}
