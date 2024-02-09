// Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has its values changed to become the maximum value of that subarray.Return the largest sum of the entire given array after partitioning.

#include <bits/stdc++.h>
using namespace std;

// Gimme the maximum sum if you have the array starting from ind onwards till the end.
// TC = n*k, SC = n + n
int memoization(int ind, vector<int> &num, int k, vector<int> &dp)
{
    int n = num.size();

    // Base case: If the current index is equal to the size of the array, return 0.
    if (ind == n)
        return 0;

    if (dp[ind] != -1)
        return dp[ind];

    int len = 0;
    int maxi = INT_MIN;
    int maxAns = INT_MIN;

    // Loop through the array starting from the current index.
    for (int j = ind; j < min(ind + k, n); j++)
    {
        len++;
        maxi = max(maxi, num[j]);
        int sum = len * maxi + memoization(j + 1, num, k, dp);
        maxAns = max(maxAns, sum);
    }

    return dp[ind] = maxAns;
}

// TC = n*k, SC = n
int tabulation(vector<int> &num, int k)
{
    int n = num.size();
    vector<int> dp(n + 1, 0);

    // Iterate through the array from right to left.
    for (int ind = n - 1; ind >= 0; ind--)
    {
        int len = 0;
        int maxi = INT_MIN;
        int maxAns = INT_MIN;

        // Loop through the next k elements (or remaining elements if k is smaller).
        for (int j = ind; j < min(ind + k, n); j++)
        {
            len++;
            maxi = max(maxi, num[j]);
            int sum = len * maxi + dp[j + 1];
            maxAns = max(maxAns, sum);
        }
        dp[ind] = maxAns;
    }
    return dp[0];
}

int main()
{
    vector<int> num = {1, 15, 7, 9, 2, 5, 10};
    int k = 3;
    int n = num.size();
    vector<int> dp(n, -1);
    cout << memoization(0, num, k, dp) << endl;
    cout << tabulation(num, k) << endl;
    return 0;
}
