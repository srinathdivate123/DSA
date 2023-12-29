/* Given an array of ‘N’ positive integers, we need to return the maximum sum of the subsequence such that no two elements of the subsequence are adjacent elements in the array.
Note: A subsequence of an array is a list with elements of the array where some elements are deleted (or not deleted at all) and the elements should be in the same order in the subsequence as in the array. */

#include <bits/stdc++.h>
using namespace std;
// Brute is to try out all subsequences with the given condition. This will take TC = 2^N.

// TC = N, SC = N
int memoization(int ind, vector<int> &arr, vector<int> &dp)
{
    if (ind == 0)
        return arr[ind];
    if (ind < 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    int pick = arr[ind] + memoization(ind - 2, arr, dp);
    int nonPick = 0 + memoization(ind - 1, arr, dp);
    return dp[ind] = max(pick, nonPick);
}

// TC = N, SC = N
int tabulation(int n, vector<int> &arr, vector<int> &dp)
{
    dp[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        int pick = arr[i];
        if (i > 1) // This is so that we do not go to negative indexes
            pick += dp[i - 2];
        int nonPick = dp[i - 1];
        dp[i] = max(pick, nonPick);
    }
    return dp[n - 1];
}

// TC = N, SC = 1
int space_optimised(int n, vector<int>& arr) {
    int prev = arr[0];   // Initialize the maximum sum ending at the previous element
    int prev2 = 0;       // Initialize the maximum sum ending two elements ago
    for (int i = 1; i < n; i++) {
        int pick = arr[i];  // Maximum sum if we pick the current element
        if (i > 1)
            pick += prev2;  // Add the maximum sum two elements ago
        
        int nonPick = 0 + prev;  // Maximum sum if we don't pick the current element
        
        int cur_i = max(pick, nonPick);  // Maximum sum ending at the current element
        prev2 = prev;   // Update the maximum sum two elements ago
        prev = cur_i;   // Update the maximum sum ending at the previous element
    }
    return prev;
}

int main()
{
    vector<int> arr{2, 1, 4, 9};
    int n = arr.size();
    vector<int> dp(n, -1);
    cout << memoization(n - 1, arr, dp) << endl;
    cout << tabulation(n, arr, dp) << endl;
    cout << space_optimised(n, arr) << endl;
    return 0;
}
