/* We are given an array Arr[] of length n. It represents the price of a stock on ‘n’ days. The following guidelines need to be followed:

- We can buy and sell the stock any number of times.
- In order to sell the stock, we need to first buy it on the same or any previous day.
- We can’t buy a stock again after buying it once. In other words, we first buy a stock and then sell it. After selling we can buy and sell again. But we can’t sell before buying and can’t buy before selling any previously bought stock.
- We can’t buy a stock on the very next day of selling it. This is the cooldown clause. */

#include <bits/stdc++.h>
using namespace std;

// TC = n*2, SC = n*2 + n
int memoization(vector<int> Arr, int ind, int buy, int n, vector<vector<int>> &dp)
{
    if (ind >= n)
        return 0;

    if (dp[ind][buy] != -1)
        return dp[ind][buy];

    int profit;

    if (buy == 1) // We can buy, we can't sell.
        profit = max(0 + memoization(Arr, ind + 1, 1, n, dp), -Arr[ind] + memoization(Arr, ind + 1, 0, n, dp));

    if (buy == 0) // We can sell. We can't buy.
        profit = max(0 + memoization(Arr, ind + 1, 0, n, dp), Arr[ind] + memoization(Arr, ind + 2, 1, n, dp));

    return dp[ind][buy] = profit;
}

// TC = SC = n*2
int tabulation(vector<int> &Arr)
{
    int n = Arr.size();
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit;

            if (buy == 1) // We can buy. But not sell.
                profit = max(0 + dp[ind + 1][1], -Arr[ind] + dp[ind + 1][0]);

            if (buy == 0) // We can sell. But not buy.
                profit = max(0 + dp[ind + 1][0], Arr[ind] + dp[ind + 2][1]);

            dp[ind][buy] = profit;
        }
    }
    return dp[0][1];
}

// We removed the inner for loop. Btw this can be done in the prev problem also!
// TC = n, SC = 1
int spaceOptimised(vector<int> &Arr)
{
    int n = Arr.size();
    vector<int> cur(2, 0);
    vector<int> front1(2, 0);
    vector<int> front2(2, 0);

    for (int ind = n - 1; ind >= 0; ind--)
    {
        // We can buy. But not sell.
        cur[1] = max(0 + front1[1], -Arr[ind] + front1[0]);

        // We can sell. But not buy.
        cur[0] = max(0 + front1[0], Arr[ind] + front2[1]);

        front2 = front1;
        front1 = cur;
    }
    return cur[1];
}

int main()
{
    vector<int> prices{4, 9, 0, 4, 10};
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    cout << memoization(prices, 0, 1, n, dp) << endl;
    cout << tabulation(prices) << endl;
    cout << spaceOptimised(prices) << endl;
    return 0;
}
