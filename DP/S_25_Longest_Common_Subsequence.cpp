// Return the length of the longest common sub-sequence between the two strings. The longest Common Subsequence is defined for two strings. It is the common subsequence that has the greatest length.

// One of the ways is to generate all subsequences and compare on the way.

#include <bits/stdc++.h>
using namespace std;
// TC = n*m, SC = n*m + n + m
// Give me the LCS of the s1 upto ind1 and s2 upto ind2.
int memoization(string &s1, string &s2, int ind1, int ind2, vector<vector<int>> &dp)
{
    if (ind1 < 0 || ind2 < 0)
        return 0;

    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];

    // If the characters at the current indices match, increment the LCS length
    if (s1[ind1] == s2[ind2])
        return dp[ind1][ind2] = 1 + memoization(s1, s2, ind1 - 1, ind2 - 1, dp);
    else
        // If the characters don't match, consider two options: moving either left or up in the strings
        return dp[ind1][ind2] = max(memoization(s1, s2, ind1, ind2 - 1, dp), memoization(s1, s2, ind1 - 1, ind2, dp));
}

// TC = n*m, SC = n*m
int tabulation(string s1, string s2, int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    // Here we've done shifting of index (https://youtu.be/NPZn9jBrX8U?t=210)
    // We do a right shift of index. i-1 = i, i = i+1. Every i you're given, you should treat it as i-1.
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;

    for (int ind1 = 1; ind1 <= n; ind1++)
        for (int ind2 = 1; ind2 <= m; ind2++)
            if (s1[ind1 - 1] == s2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1]; // Characters match, increment LCS length
            else
                dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]); // Characters don't match, consider the maximum from left or above

    return dp[n][m];
}

// TC = n*m, SC = m
int spaceOptimised(string s1, string s2, int n, int m)
{
    vector<int> prev(m + 1, 0), cur(m + 1, 0);

    // Base case is covered as we have initialized the prev and cur vectors to 0.

    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                cur[ind2] = 1 + prev[ind2 - 1]; // Characters match, increment LCS length
            else
                cur[ind2] = max(prev[ind2], cur[ind2 - 1]); // Characters don't match, consider the maximum from above or left
        }
        prev = cur;
    }
    return prev[m];
}

int main()
{
    string s1 = "acd";
    string s2 = "ced";
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << memoization(s1, s2, n - 1, m - 1, dp) << endl;
    cout << tabulation(s1, s2, n, m) << endl;
    cout << spaceOptimised(s1, s2, n, m) << endl;
    return 0;
}