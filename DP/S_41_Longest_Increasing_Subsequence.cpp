/*
The longest increasing subsequence is described as a subsequence of an array where:
All elements of the subsequence are in increasing order.
This subsequence itself is of the longest length possible.
*/

#include <bits/stdc++.h>
using namespace std;

// f(ind, prevIndex) means gimme the length of the LIS starting from ind whose previous index is prevIndex.
// TC = n*n, SC = n*n + n
int memoizaion(vector<int> arr, int n, int ind, int prev_index, vector<vector<int>> &dp)
{
    if (ind == n)
        return 0;

    if (dp[ind][prev_index + 1] != -1)
        return dp[ind][prev_index + 1];

    int notTake = 0 + memoizaion(arr, n, ind + 1, prev_index, dp);

    int take = 0;

    if (prev_index == -1 || arr[ind] > arr[prev_index])
        take = 1 + memoizaion(arr, n, ind + 1, ind, dp);

    return dp[ind][prev_index + 1] = max(notTake, take);
}

// Tabulation and spaceOptimised are in the next code.

int main()
{
    vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = arr.size();
    // We use a n*(n+1) dp
    // n is for ind, n+1 is for prev_index -> Because prev_index can have values ranging from -1 to n-1. So we represent it as changing from 0 to n. For that we need a size of n+1. So we always write prev_index + 1 in the memoizaion function.
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    cout << memoizaion(arr, n, 0, -1, dp) << endl;
    return 0;
}