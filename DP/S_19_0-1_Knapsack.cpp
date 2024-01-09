// A thief wants to rob a store. He is carrying a bag of capacity W. The store has n items. Its weight is given by the wt array and its value by the val array. He can either include an item in its knapsack or exclude it but can’t partially have it as a fraction. We need to find the maximum value of items that the thief can steal.

// https://takeuforward.org/data-structure/0-1-knapsack-dp-19

#include <bits/stdc++.h>
using namespace std;

// Meaning of function is : till index ind what is the maximum value that you can get with bag of weight W.
// TC = n*w, SC = n*w + N
int memoization(vector<int> &wt, vector<int> &val, int ind, int W, vector<vector<int>> &dp)
{
    // If there are no items left or the bag has no capacity
    if (ind == 0)
        if (wt[ind] <= W)
            return val[ind];
        else
            return 0;

    if (dp[ind][W] != -1)
        return dp[ind][W];

    int notTaken = memoization(wt, val, ind - 1, W, dp);
    int taken = INT_MIN;
    if (wt[ind] <= W)
        taken = val[ind] + memoization(wt, val, ind - 1, W - wt[ind], dp);
    return dp[ind][W] = max(notTaken, taken);
}

// TC = n*w, SC = n*w
int tabulation(vector<int> &wt, vector<int> &val, int n, int W)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));

    // Fill in the first row for the weight of the first item
    for (int i = wt[0]; i <= W; i++)
        dp[0][i] = val[0];

    for (int ind = 1; ind < n; ind++)
        for (int cap = 0; cap <= W; cap++)
        {
            int notTaken = dp[ind - 1][cap];
            int taken = INT_MIN;
            if (wt[ind] <= cap)
                taken = val[ind] + dp[ind - 1][cap - wt[ind]];
            dp[ind][cap] = max(notTaken, taken);
        }
    return dp[n - 1][W];
}

// TC = n*w, SC = 2*w
int spaceOptimised_2_arrays(vector<int> &wt, vector<int> &val, int n, int W)
{
    vector<int> prev(W + 1, 0), curr(W + 1, 0);

    // Fill in the first row for the weight of the first item
    for (int i = wt[0]; i <= W; i++)
        prev[i] = val[0];

    for (int ind = 1; ind < n; ind++)
    {
        for (int cap = 0; cap <= W; cap++)
        {
            int notTaken = prev[cap];
            int taken = INT_MIN;
            if (wt[ind] <= cap)
                taken = val[ind] + prev[cap - wt[ind]];
            curr[cap] = max(notTaken, taken);
        }
        prev = curr;
    }
    return prev[W];
}

// TC = n*w, SC = w
int spaceOptimised_1_array(vector<int> &wt, vector<int> &val, int n, int W)
{
    vector<int> prev(W + 1, 0);

    // Fill in the first row for the weight of the first item
    for (int i = wt[0]; i <= W; i++)
        prev[i] = val[0];

    for (int ind = 1; ind < n; ind++)
        // We have to fill from right to left
        for (int cap = W; cap >= 0; cap--)
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
    vector<int> wt = {1, 2, 4, 5};
    vector<int> val = {5, 4, 8, 6};
    int W = 5;
    int n = wt.size();
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    cout << memoization(wt, val, n - 1, W, dp) << endl;
    cout << tabulation(wt, val, n, W) << endl;
    cout << spaceOptimised_2_arrays(wt, val, n, W) << endl;
    return 0;
}
