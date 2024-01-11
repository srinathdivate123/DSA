// We are given an array Arr with N distinct coins and a target. We have an infinite supply of each coin denomination. We need to find the number of ways we sum up the coin values to give us the target. Each coin can be used any number of times.

#include <bits/stdc++.h>
using namespace std;

// Till index in, in how many ways can you form target?
// TC = n*T, SC = n*T + n
long memoization(vector<int> &arr, int ind, int T, vector<vector<long>> &dp)
{
    if (ind == 0)
        return (T % arr[ind] == 0); // Check if the target sum is divisible by the first element

    if (dp[ind][T] != -1)
        return dp[ind][T];

    long notTaken = memoization(arr, ind - 1, T, dp);
    long taken = 0;
    if (arr[ind] <= T)
        taken = memoization(arr, ind, T - arr[ind], dp);
    return dp[ind][T] = notTaken + taken;
}

// TC = n*T, SC = n*T
long tabulation(vector<int> &arr, int n, int T)
{
    vector<vector<long>> dp(n, vector<long>(T + 1, 0));
    for (int i = 0; i <= T; i++)
        if (i % arr[0] == 0)
            dp[0][i] = 1;

    for (int ind = 1; ind < n; ind++)
        for (int target = 0; target <= T; target++)
        {
            long notTaken = dp[ind - 1][target];
            long taken = 0;
            if (arr[ind] <= target)
                taken = dp[ind][target - arr[ind]];

            dp[ind][target] = notTaken + taken;
        }
    return dp[n - 1][T];
}

long spaceOptimied(vector<int> &arr, int n, int T)
{
    vector<long> prev(T + 1, 0);
    for (int i = 0; i <= T; i++)
        if (i % arr[0] == 0)
            prev[i] = 1;

    for (int ind = 1; ind < n; ind++)
    {
        vector<long> cur(T + 1, 0);
        for (int target = 0; target <= T; target++)
        {
            long notTaken = prev[target];

            long taken = 0;
            if (arr[ind] <= target)
                taken = cur[target - arr[ind]];

            cur[target] = notTaken + taken;
        }
        prev = cur;
    }
    return prev[T];
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
