// We are given an array arr with N positive integers. We need to find if there is a subset in arr with a sum equal to K. If there is, return true else return false.

// Brute is to generate all subsequences by using Power-Set or by recursion.
#include <bits/stdc++.h>
using namespace std;

// TC = n*k, SC = n*k + n
bool memoization(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;
    if (ind == 0)
        return arr[0] == target;
    if (dp[ind][target] != -1)
        return dp[ind][target];

    bool notTaken = memoization(ind - 1, target, arr, dp);
    bool taken = false;
    if (arr[ind] <= target)
        taken = memoization(ind - 1, target - arr[ind], arr, dp);
    return dp[ind][target] = notTaken || taken;
}

// TC = n*k, SC = n*k
bool tabulation(int n, int k, vector<int> &arr)
{
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
    // If the target sum is 0, we can always achieve it by taking no elements.
    for (int i = 0; i < n; i++)
        dp[i][0] = true;
    
    // The first row dp[0][] indicates that only the first element of the array is considered, therefore for the target value equal to arr[0], only cell with that target will be true, so explicitly set dp[0][arr[0]] = true, (dp[0][arr[0]] means that we are considering the first element of the array with the target equal to the first element itself). Please note that it can happen that arr[0]>target, so we first check it: if(arr[0]<=target) then set dp[0][arr[0]] = true.
    if (arr[0] <= k)
        dp[0][arr[0]] = true;

    for (int ind = 1; ind < n; ind++)
        for (int target = 1; target <= k; target++)
        {
            bool notTaken = dp[ind - 1][target];
            bool taken = false;
            if (arr[ind] <= target)
                taken = dp[ind - 1][target - arr[ind]];
            dp[ind][target] = notTaken || taken;
        }
    return dp[n - 1][k];
}

// TC = n*k, SC = K
bool spaceOptimised(int n, int k, vector<int> &arr)
{
    vector<bool> prev(k + 1, false);

    // Base case: If the target sum is 0, we can always achieve it by taking no elements
    prev[0] = true;

    // Base case: If the first element of 'arr' is less than or equal to 'k', set prev[arr[0]] to true
    if (arr[0] <= k)
        prev[arr[0]] = true;

    // Iterate through the elements of 'arr' and update the DP table
    for (int ind = 1; ind < n; ind++)
    {
        vector<bool> cur(k + 1, false);

        // Base case: If the target sum is 0, we can achieve it by taking no elements
        cur[0] = true;

        for (int target = 1; target <= k; target++)
        {
            // If we don't take the current element, the result is the same as the previous row
            bool notTaken = prev[target];

            // If we take the current element, subtract its value from the target and check the previous row
            bool taken = false;
            if (arr[ind] <= target)
                taken = prev[target - arr[ind]];

            // Store the result in the current DP table row for the current subproblem
            cur[target] = notTaken || taken;
        }
        prev = cur;
    }
    return prev[k];
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int k = 4;
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    cout << memoization(n - 1, k, arr, dp) << endl;
    cout << tabulation(n, k, arr) << endl;
    cout << spaceOptimised(n, k, arr) << endl;
    return 0;
}