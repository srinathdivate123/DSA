/* We are given two strings S1 and S2. S1 can have the following two special characters:

-> ? can be matched to a single character of S2.
-> * can be matched to any sequence of characters of S2. (sequence can be of length zero or more).
We need to check whether strings S1 and S2 match or not.*/

#include <bits/stdc++.h>
using namespace std;

bool isAllStars(string &S1, int i, int startFrom)
{
    for (int j = startFrom; j <= i; j++)
        if (S1[j - startFrom] != '*')
            return false;
    return true;
}

// f(i, j) means that is the string S1[0...i] matching with S2[0...j] ?
// TC = n*m, SC = n*m + n + m
bool memoization(string &S1, string &S2, int i, int j, vector<vector<bool>> &dp)
{
    if (i < 0 && j < 0)
        return true;
    if (i < 0 && j >= 0)
        return false;
    if (j < 0 && i >= 0)
        return isAllStars(S1, i, 0);

    if (dp[i][j] != -1)
        return dp[i][j];

    // If the characters at the current positions match or S1 has a '?'
    if (S1[i] == S2[j] || S1[i] == '?')
        return dp[i][j] = memoization(S1, S2, i - 1, j - 1, dp);

    if (S1[i] == '*')
        // Two options: either '*' represents an empty string or it matches a character in S2
        return dp[i][j] = memoization(S1, S2, i - 1, j, dp) || memoization(S1, S2, i, j - 1, dp);

    return dp[i][j] = false;
}

// TC = SC = n*m
bool tabulation(string &S1, string &S2)
{
    int n = S1.size();
    int m = S2.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m, false));

    // 1 based indexing
    dp[0][0] = true;
    for (int j = 1; j <= m; j++)
        dp[0][j] = false;
    for (int i = 1; i <= n; i++)
        dp[i][0] = isAllStars(S1, i, 1);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (S1[i - 1] == S2[j - 1] || S1[i - 1] == '?')
                dp[i][j] = dp[i - 1][j - 1];
            else if (S1[i - 1] == '*')
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            else
                dp[i][j] = false;

    return dp[n][m];
}

// TC = n*m, SC = m
bool spaceOptimised(string &S1, string &S2)
{
    int n = S1.size();
    int m = S2.size();

    vector<bool> prev(m + 1, false);
    vector<bool> cur(m + 1, false);

    prev[0] = true;

    for (int i = 1; i <= n; i++)
    {
        cur[0] = isAllStars(S1, i, 1); // Initialize the first element of the current row
        for (int j = 1; j <= m; j++)
            if (S1[i - 1] == S2[j - 1] || S1[i - 1] == '?')
                cur[j] = prev[j - 1]; // Characters match or S1 has '?'
            else if (S1[i - 1] == '*')
                cur[j] = prev[j] || cur[j - 1]; // '*' represents empty or a character
            else
                cur[j] = false; // Characters don't match and S1[i-1] is not '*'
        prev = cur;
    }
    return prev[m];
}

int main()
{
    string S1 = "ab*cd";
    string S2 = "abdefcd";

    int n = S1.size();
    int m = S2.size();
    vector<vector<bool>> dp(n, vector<bool>(m, -1));
    cout << memoization(S1, S2, n - 1, m - 1, dp) << endl;
    cout << tabulation(S1, S2) << endl;
    cout << spaceOptimised(S1, S2) << endl;

    return 0;
}
