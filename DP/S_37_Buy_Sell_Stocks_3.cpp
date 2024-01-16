/* We are given an array Arr[] of length n. It represents the price of a stock on ‘n’ days. The following guidelines need to be followed:

- We can do at most 2 transactions.
- We can buy and sell the stock any number of times.
- In order to sell the stock, we need to first buy it on the same or any previous day.
- We can’t buy a stock again after buying it once. In other words, we first buy a stock and then sell it. After selling we can buy and sell again. But we can’t sell before buying and can’t buy before selling any previously bought stock. */

#include <bits/stdc++.h>
using namespace std;

// TC = n*2*3, SC = n*2*3 + n
int memoization(vector<int> &Arr, int n, int ind, int buy, int cap, vector<vector<vector<int>>> &dp)
{
    // If we reach the end of the array or run out of allowed transactions, return 0.
    if (ind == n || cap == 0)
        return 0;

    if (dp[ind][buy][cap] != -1)
        return dp[ind][buy][cap];

    if (buy == 1) // We can buy the stock
        dp[ind][buy][cap] = max(0 + memoization(Arr, n, ind + 1, 1, cap, dp),
                                -Arr[ind] + memoization(Arr, n, ind + 1, 0, cap, dp));

    if (buy == 0) // We can sell the stock
        dp[ind][buy][cap] = max(0 + memoization(Arr, n, ind + 1, 0, cap, dp),
                                Arr[ind] + memoization(Arr, n, ind + 1, 1, cap - 1, dp));

    return dp[ind][buy][cap];
}

// TC = n*2*3, SC = n*2*3
int tabulation(vector<int> &Arr, int n)
{
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

    // Base case: dp array is already initialized to 0, covering the base case. So writing for loops and conditions to initialize the array with base cases is of no sense because in the base case also the array elements are initialized to 0.

    for (int ind = n - 1; ind >= 0; ind--)
        for (int buy = 0; buy <= 1; buy++)
            for (int cap = 1; cap <= 2; cap++) // For every cap=0 tha array dp value will be 0, as per base case. So we start from cap=1.
            {
                if (buy == 1) // We can buy the stock, but not sell it.
                    dp[ind][buy][cap] = max(-Arr[ind] + dp[ind + 1][0][cap], 0 + dp[ind + 1][1][cap]);

                if (buy == 0) // We can sell the stock, but not buy it.
                    dp[ind][buy][cap] = max(Arr[ind] + dp[ind + 1][1][cap - 1], 0 + dp[ind + 1][0][cap]);
            }
    return dp[0][1][2];
}

// TC = n*2*3, SC = Constant
int spaceOptimised(vector<int> &Arr, int n)
{
    vector<vector<int>> after(2, vector<int>(3, 0));
    vector<vector<int>> curr(2, vector<int>(3, 0));

    // Base case: dp array is already initialized to 0, covering the base case. So writing for loops and conditions to initialize the array with base cases is of no sense because in the base case also the array elements are initialized to 0.

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
            for (int cap = 1; cap <= 2; cap++) // For every cap=0 tha array dp value will be 0, as per base case. So we start from cap=1.
            {
                if (buy == 1) // We can buy the stock, but not sell it.
                    curr[buy][cap] = max(-Arr[ind] + after[0][cap], 0 + after[1][cap]);

                if (buy == 0) // We can sell the stock, but not buy it.
                    curr[buy][cap] = max(Arr[ind] + after[1][cap - 1], 0 + after[0][cap]);
            }
        after = curr;
    }
    return after[1][2];
}

/* We can also solve this in a TC of n*4. We do not use buy and cur variables here. We use a transaction_id here, which can take 4 values.
0 - First Buy
1 - First Sell
2 - Second Buy
3 - Second Sell
So when transaction_id id even, we buy. When it is odd, we sell. And whenever we're performing a transaction, we increase the value of transaction_id.

*/
int main()
{
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = prices.size();
    // [n][2][3] for storing states of prices, buy (0, 1), cap (2, 1, 0)
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    cout << memoization(prices, n, 0, 1, 2, dp) << endl;
    cout << tabulation(prices, n) << endl;
    cout << spaceOptimised(prices, n) << endl;
    return 0;
}
