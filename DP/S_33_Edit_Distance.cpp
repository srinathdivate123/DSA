/* We are given two strings S1 and S2. We need to convert S1 to S2. The following three operations are allowed:

- Deletion of a character.
- Replacement of a character with another one.
- Insertion of a character.

We have to return the minimum number of operations required to convert S1 to S2 as our answer. */

// This is similar to DP-30, but here we're allowed to insert any character also!

// It is always possible to convert S1 to S2 because we can delete all characters of S1 by taking time n, and insert all characters of S2 in S1 by taking time m.

using namespace std;
#include <bits/stdc++.h>
// Find the min operations to convert S1[0...i] to S2[0...j].
// TC = n*m, SC = n*m + n + m
int memoization(string &S1, string &S2, int i, int j, vector<vector<int>> &dp)
{
    // S1 exhausted: You return the no of unmatched chars in S2.
    if (i < 0)
        return j + 1;
    // S2 exhausted: S2 is now an empty string. The number of delete operations to turn S1 into an empty string like S2 is (i + 1).
    if (j < 0)
        return i + 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    // If the characters at the current positions match, no operation is needed, so we add 0.
    if (S1[i] == S2[j])
        return dp[i][j] = 0 + memoization(S1, S2, i - 1, j - 1, dp);

    // 1. Replace the character at S1[i] with the character at S2[j].
    // 2. Delete the character at S1[i].
    // 3. Insert the character at S2[j] into S1.
    int replace = memoization(S1, S2, i - 1, j - 1, dp);
    int Delete = memoization(S1, S2, i - 1, j, dp);
    int insert = memoization(S1, S2, i, j - 1, dp);
    return dp[i][j] = 1 + min(replace, min(Delete, insert));
}

// TC = SC = n*m
int tabulation(string &S1, string &S2)
{
    int n = S1.size();
    int m = S2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // 1 based indexiing
    for (int i = 0; i <= n; i++)
        dp[i][0] = i;
    for (int j = 0; j <= m; j++)
        dp[0][j] = j;

    // Fill in the DP table
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (S1[i - 1] == S2[j - 1])
                dp[i][j] = dp[i - 1][j - 1]; // If the characters match, no additional cost
            else
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));

    return dp[n][m];
}

// TC = n*m, SC = m
int spaceOptimised(string &S1, string &S2)
{
    int n = S1.size();
    int m = S2.size();
    vector<int> prev(m + 1, 0);
    vector<int> cur(m + 1, 0);

    for (int j = 0; j <= m; j++)
        prev[j] = j;

    for (int i = 1; i <= n; i++)
    {
        cur[0] = i; // Initialize the first column of the current row
        for (int j = 1; j <= m; j++)
            if (S1[i - 1] == S2[j - 1])
                cur[j] = prev[j - 1];
            else
                // Minimum of three choices:
                // 1. Replace the character at S1[i-1] with S2[j-1]
                // 2. Delete the character at S1[i-1]
                // 3. Insert the character at S2[j-1] into S1
                cur[j] = 1 + min(prev[j - 1], min(prev[j], cur[j - 1]));
        prev = cur; // Update the previous row with the current row
    }
    return cur[m];
}
int main()
{
    string S1 = "horse";
    string S2 = "ros";
    int n = S1.size();
    int m = S2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << memoization(S1, S2, n - 1, m - 1, dp) << endl;
    cout << tabulation(S1, S2) << endl;
    cout << spaceOptimised(S1, S2) << endl;
    return 0;
}
