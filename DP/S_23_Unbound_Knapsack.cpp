// A thief wants to rob a store. He is carrying a bag of capacity W. The store has n items of infinite supply. Its weight is given by the wt array and its value by the val array. He can either include an item in its knapsack or exclude it but can’t partially have it as a fraction. We need to find the maximum value of items that the thief can steal. He can take a single item any number of times he wants and put it in his knapsack.

#include <bits/stdc++.h>
using namespace std;

// TC = n*w, SC = n*w + n
int memoization(vector<int> &wt, vector<int> &val, int ind, int W, vector<vector<int>> &dp)
{
    if (ind == 0)
        return (W / wt[0]) * val[0];
    if (dp[ind][W] != -1)
        return dp[ind][W];

    int notTaken = 0 + memoization(wt, val, ind - 1, W, dp);
    int taken = INT_MIN;
    if (wt[ind] <= W)
        taken = val[ind] + memoization(wt, val, ind, W - wt[ind], dp);
    return dp[ind][W] = max(notTaken, taken);
}

// TC= n*w, SC = n*w
int tabulation(int n, int W, vector<int> &val, vector<int> &wt)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));
    for (int i = wt[0]; i <= W; i++)
        dp[0][i] = (i / wt[0]) * val[0];

    for (int ind = 1; ind < n; ind++)
        for (int cap = 0; cap <= W; cap++)
        {
            int notTaken = 0 + dp[ind - 1][cap];
            int taken = INT_MIN;
            if (wt[ind] <= cap)
                taken = val[ind] + dp[ind][cap - wt[ind]];
            dp[ind][cap] = max(notTaken, taken);
        }
    return dp[n - 1][W];
}

// TC = n*w, SC = 2w
int spaceOpotimsied(int n, int W, vector<int> &val, vector<int> &wt)
{
    vector<int> prev(W + 1, 0), cur(W + 1, 0);
    for (int i = 0; i <= W; i++)
        prev[i] = (i / wt[0]) * val[0];

    for (int ind = 1; ind < n; ind++)
    {
        for (int cap = 0; cap <= W; cap++)
        {
            int notTaken = prev[cap];
            int taken = INT_MIN;
            if (wt[ind] <= cap)
                taken = val[ind] + cur[cap - wt[ind]];

            cur[cap] = max(notTaken, taken);
        }
        prev = cur;
    }
    return cur[W];
}

// TC = n*w, SC = w
int mostSpaceOpotimsied(int n, int W, vector<int> &val, vector<int> &wt)
{
    vector<int> prev(W + 1, 0);
    for (int i = 0; i <= W; i++)
        prev[i] = (i / wt[0]) * val[0];

    for (int ind = 1; ind < n; ind++)
        for (int cap = 0; cap <= W; cap++)
        {
            int notTaken = prev[cap];
            int taken = INT_MIN;
            if (wt[ind] <= cap)
                taken = val[ind] + prev[cap - wt[ind]];
            prev[cap] = max(notTaken, taken);
        }
    return prev[W];
}
int main()
{
    vector<int> wt = {2, 4, 6};
    vector<int> val = {5, 11, 13};
    int W = 10;
    int n = wt.size();
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    cout << memoization(wt, val, n - 1, W, dp) << endl;
    cout << tabulation(n, W, val, wt) << endl;
    cout << spaceOpotimsied(n, W, val, wt) << endl;
    cout << mostSpaceOpotimsied(n, W, val, wt) << endl;
    return 0;
}