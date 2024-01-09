// We are given an array arr with N positive integers. We need to find if we can partition the array into two subsets such that the sum of elements of each subset is equal to the other. If we can partition, return true else return false.

// Basically the question boils down to - Can we find a subset with sum TotalSum/2 because, if we find one then the remaining part of the array which is the second subset will also have the sum TotalSum/2.

#include <bits/stdc++.h>
using namespace std;

bool memoizationUtil(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    // Base case: If the target sum is 0, we found a valid partition
    if (target == 0)
        return true;

    // Base case: If we have considered all elements and the target is still not 0, return false
    if (ind == 0)
        return arr[0] == target;

    if (dp[ind][target] != -1)
        return dp[ind][target];

    bool notTaken = memoizationUtil(ind - 1, target, arr, dp);

    bool taken = false;
    if (arr[ind] <= target)
        taken = memoizationUtil(ind - 1, target - arr[ind], arr, dp);

    return dp[ind][target] = notTaken || taken;
}

// TC = n*k + n, SC = n*k + n
bool memoization(int n, vector<int> &arr)
{
    int totSum = 0;
    for (int i = 0; i < n; i++)
        totSum += arr[i];

    // If the total sum is odd, it cannot be partitioned into two equal subsets
    if (totSum % 2 == 1)
        return false;
    int target = totSum / 2;
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return memoizationUtil(n - 1, target, arr, dp);
}

// TC = n*k + n, SC = n*k
bool tabulation(int n, vector<int> &arr)
{
    int totSum = 0;
    for (int i = 0; i < n; i++)
        totSum += arr[i];

    // If the total sum is odd, it cannot be partitioned into two equal subsets
    if (totSum % 2 == 1)
        return false;

    int k = totSum / 2;
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    // Base case: If the target sum is 0, it can be achieved by not selecting any elements
    for (int i = 0; i < n; i++)
        dp[i][0] = true;

    // Initialize the first row based on the first element of the array
    if (arr[0] <= k)
        dp[0][arr[0]] = true;

    for (int ind = 1; ind < n; ind++)
        for (int target = 1; target <= k; target++)
        {
            // Exclude the current element
            bool notTaken = dp[ind - 1][target];

            // Include the current element if it doesn't exceed the target
            bool taken = false;
            if (arr[ind] <= target)
                taken = dp[ind - 1][target - arr[ind]];

            // Update the DP table
            dp[ind][target] = notTaken || taken;
        }
    return dp[n - 1][k];
}

// TC = n*k + n, SC = k
bool spaceOptimised(int n, vector<int> &arr)
{
    int totSum = 0;

    for (int i = 0; i < n; i++)
        totSum += arr[i];

    // If the total sum is odd, it cannot be partitioned into two equal subsets
    if (totSum % 2 == 1)
        return false;

    int k = totSum / 2;
    vector<bool> prev(k + 1, false);
    // Base case: If the target sum is 0, it can be achieved by not selecting any elements
    prev[0] = true;
    // Initialize the first row based on the first element of the array
    if (arr[0] <= k)
        prev[arr[0]] = true;

    for (int ind = 1; ind < n; ind++)
    {
        vector<bool> cur(k + 1, false);
        cur[0] = true;

        for (int target = 1; target <= k; target++)
        {
            bool notTaken = prev[target];
            bool taken = false;
            if (arr[ind] <= target)
                taken = prev[target - arr[ind]];
            cur[target] = notTaken || taken;
        }
        prev = cur;
    }
    return prev[k];
}

int main()
{
    vector<int> arr = {2, 3, 3, 3, 4, 5};
    int n = arr.size();
    cout << memoization(n, arr) << endl;
    cout << tabulation(n, arr) << endl;
    cout << spaceOptimised(n, arr) << endl;
    return 0;
}
