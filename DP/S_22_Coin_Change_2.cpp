// We are given an array Arr with N distinct coins and a target. We have an infinite supply of each coin denomination. We need to find the number of ways we sum up the coin values to give us the target. Each coin can be used any number of times.

#include <bits/stdc++.h>
using namespace std;

// Till index in, in how many ways can you form target?
// TC = n*target, SC = n*target + n
long memoization(vector<int> &arr, int ind, int target, vector<vector<long>> &dp)
{
    if (ind == 0)
        return (target % arr[ind] == 0); // Check if the target sum is divisible by the first element

    if (dp[ind][target] != -1)
        return dp[ind][target];

    long ifYouDontTakeThis = memoization(arr, ind - 1, target, dp);
    long ifYouTakeThis = 0;
    if (arr[ind] <= target)
        ifYouTakeThis = memoization(arr, ind, target - arr[ind], dp);
    return dp[ind][target] = ifYouDontTakeThis + ifYouTakeThis;
}

// TC = n*target, SC = n*target
long tabulation(vector<int> &arr, int n, int target)
{
    vector<vector<long>> dp(n, vector<long>(target + 1, 0));
    for (int i = 0; i <= target; i++)
        dp[0][i] = i % arr[0] == 0;

    for (int ind = 1; ind < n; ind++)
        for (int target = 0; target <= target; target++)
        {
            long ifYouDontTakeThis = dp[ind - 1][target];
            long ifYouTakeThis = 0;
            if (arr[ind] <= target)
                ifYouTakeThis = dp[ind][target - arr[ind]];

            dp[ind][target] = ifYouDontTakeThis + ifYouTakeThis;
        }
    return dp[n - 1][target];
}

long spaceOptimied(vector<int> &arr, int n, int target)
{
    vector<long> prev(target + 1, 0);
    for (int i = 0; i <= target; i++)
            prev[i] = i % arr[0] == 0;

    for (int ind = 1; ind < n; ind++)
    {
        vector<long> cur(target + 1, 0);
        for (int target = 0; target <= target; target++)
        {
            long ifYouDontTakeThis = prev[target];

            long ifYouTakeThis = 0;
            if (arr[ind] <= target)
                ifYouTakeThis = cur[target - arr[ind]];

            cur[target] = ifYouDontTakeThis + ifYouTakeThis;
        }
        prev = cur;
    }
    return prev[target];
}
int main()
{
    vector<int> arr = {1, 2, 3};
    int target = 4;
    int n = arr.size();
    vector<vector<long>> dp(n, vector<long>(target + 1, -1));
    cout << memoization(arr, n - 1, target, dp) << endl;
    cout << tabulation(arr, n, target) << endl;
    cout << spaceOptimied(arr, n, target) << endl;
    return 0;
}
