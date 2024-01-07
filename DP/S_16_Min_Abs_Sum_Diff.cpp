// We are given an array arr with N positive integers. We need to partition the array into two subsets such that the absolute difference of the sum of elements of the subsets is minimum. We need to return only the minimum absolute difference of the sum of elements of the two partitions.

#include <bits/stdc++.h>
using namespace std;

bool memoizationUtil(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return dp[ind][target] = true;

    // Base case: If we have considered all elements and the target is still not 0, return false
    if (ind == 0)
        return dp[ind][target] = (arr[0] == target);

    if (dp[ind][target] != -1)
        return dp[ind][target];

    bool notTaken = memoizationUtil(ind - 1, target, arr, dp);
    bool taken = false;
    if (arr[ind] <= target)
        taken = memoizationUtil(ind - 1, target - arr[ind], arr, dp);
    return dp[ind][target] = notTaken || taken;
}

// TC = n*totalSum + n + n, SC = n*totalSum + n
int memoization(vector<int> &arr, int n)
{
    int totSum = 0;
    for (int i = 0; i < n; i++)
        totSum += arr[i];
    vector<vector<int>> dp(n, vector<int>(totSum + 1, -1));

    // Calculate the subset sum for each possible sum from 0 to the total sum
    for (int i = 0; i <= totSum; i++)
        bool dummy = memoizationUtil(n - 1, i, arr, dp);

    int mini = 1e9;
    for (int i = 0; i <= totSum; i++)
        if (dp[n - 1][i] == true)
        {
            int diff = abs(i - (totSum - i));
            mini = min(mini, diff);
        }
    return mini;
}

// TC = n*totalSum + n + n, SC = n*totalSum
int tabulation(vector<int> &arr, int n)
{
    int totSum = 0;
    for (int i = 0; i < n; i++)
        totSum += arr[i];
    vector<vector<bool>> dp(n, vector<bool>(totSum + 1, false));

    // Base case: If no elements are selected (sum is 0), it's a valid subset
    for (int i = 0; i < n; i++)
        dp[i][0] = true;

    // Initialize the first row based on the first element of the array
    if (arr[0] <= totSum)
        dp[0][totSum] = true;

    // Fill in the DP table using a bottom-up approach
    for (int ind = 1; ind < n; ind++)
        for (int target = 1; target <= totSum; target++)
        {
            bool notTaken = dp[ind - 1][target];
            bool taken = false;
            if (arr[ind] <= target)
                taken = dp[ind - 1][target - arr[ind]];
            dp[ind][target] = notTaken || taken;
        }

    int mini = 1e9;
    // dp[n-1][col->0...totSum]
    for (int s1 = 0; s1 <= totSum / 2; s1++)
        if (dp[n - 1][s1] == true)
            mini = min(mini, abs(s1 - (totSum - s1)));
    return mini;
}

// TC = n*totalSum + n + n, SC = totalSum
int spaceOptimised(vector<int> &arr, int n)
{
    int totSum = 0;
    for (int i = 0; i < n; i++)
        totSum += arr[i];
    vector<bool> prev(totSum + 1, false);

    // Base case: If no elements are selected (sum is 0), it's a valid subset
    prev[0] = true;

    // Initialize the first row based on the first element of the array
    if (arr[0] <= totSum)
        prev[arr[0]] = true;

    for (int ind = 1; ind < n; ind++)
    {
        vector<bool> cur(totSum + 1, false);
        cur[0] = true;

        for (int target = 1; target <= totSum; target++)
        {
            bool notTaken = prev[target];
            bool taken = false;
            if (arr[ind] <= target)
                taken = prev[target - arr[ind]];
            cur[target] = notTaken || taken;
        }
        prev = cur;
    }

    int mini = 1e9;
    for (int s1 = 0; s1 <= totSum; s1++)
        if (prev[s1] == true)
            mini = min(mini, abs(s1 - (totSum - s1)));
    return mini;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int n = arr.size();
    cout << memoization(arr, n) << endl;
    cout << tabulation(arr, n) << endl;
    cout << spaceOptimised(arr, n) << endl;

    return 0;
}
