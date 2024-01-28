// We are given two strings S1 and S2, we want to know how many distinct subsequences of S2 are present in S1.

#include <bits/stdc++.h>
using namespace std;

const int prime = 1e9 + 7;

// TC = n*m, SC = n*m + n + m
// Here we used 0 based indexing although we could have used 1 based indexing as well
int memoization(string s1, string s2, int ind1, int ind2, vector<vector<int>> &dp)
{
    // If s2 has been completely matched, return 1 (found a valid subsequence)
    if (ind2 < 0)
        return 1;

    // If s1 has been completely traversed but s2 hasn't (meaning we exhausted s1 but found no occourence of s2 in it), return 0
    if (ind1 < 0)
        return 0;

    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];

    int result = 0;

    // If the characters match, consider two options: either leave one character in both s1 and s2 or leave one character in s1 and continue matching s2.
    if (s1[ind1] == s2[ind2])
    {
        int leaveOne = memoization(s1, s2, ind1 - 1, ind2 - 1, dp);
        int stay = memoization(s1, s2, ind1 - 1, ind2, dp);
        result = (leaveOne + stay) % prime;
    }
    // If characters don't match, just leave one character in s1 and continue matching s2 with s1
    else
        result = memoization(s1, s2, ind1 - 1, ind2, dp);

    dp[ind1][ind2] = result;
    return result;
}

// TC = SC = n*m
int tabulation(string &s1, string &s2, int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // We'll be doing 1 based indexing because in memoization, we see that we wrote conditions for ind1 & ind2 < 0. So calls for -ve indexes are being made. To avoid this, we're using 1-based indexing in tabulation.
    // Initialize the first row: empty string s2 can be matched with any non-empty s1 in one way. For every j=0, put 1.
    for (int i = 0; i <= n; i++) // i starts from 0
        dp[i][0] = 1;

    // Initialize the first column: s1 can't match any non-empty s2. For every i=0, put 0. We can omit this step also, as we're initialising everything with 0.
    for (int j = 1; j <= m; j++) // j starts from 1
        dp[0][j] = 0;

    // 1 based indexing
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (s1[i - 1] == s2[j - 1])
                // If the characters match, we have two options:
                // 1. Match the current characters and move diagonally (dp[i-1][j-1])
                // 2. Leave the current character in s1 and match s2 with the previous characters (dp[i-1][j])
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % prime;
            else
                // If the characters don't match, we can only leave the current character in s1
                dp[i][j] = dp[i - 1][j];

    return dp[n][m];
}

int spaceOptimised(string &s1, string &s2, int n, int m)
{
    vector<int> prev(m + 1, 0), cur(m + 1, 0);

    // Initialize the count for an empty string (base case)
    prev[0] = cur[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                // If the characters match, we have two options:
                // 1. Match the current characters and add to the previous count (prev[j-1])
                // 2. Leave the current character in s1 and match s2 with the previous characters (prev[j])
                cur[j] = (prev[j - 1] + prev[j]) % prime;
            }
            else
                cur[j] = prev[j];
        }
        prev = cur;
    }
    return prev[m];
}

// TC = n*m, SC = m
int spaceOptimised_Further(string &s1, string &s2, int n, int m)
{
    vector<int> prev(m + 1, 0);

    // Initialize the count for an empty string (base case)
    prev[0] = 1;

    // Iterate through s1 and s2 to calculate the counts
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 1; j--)
        { // Iterate in reverse direction to avoid overwriting values prematurely
            if (s1[i - 1] == s2[j - 1])
            {
                // If the characters match, we have two options:
                // 1. Match the current characters and add to the previous count (prev[j-1])
                // 2. Leave the current character in s1 and match s2 with the previous characters (prev[j])
                prev[j] = (prev[j - 1] + prev[j]) % prime;
            }
            // No need for an else statement since we can simply leave the previous count as is. Like we had put cur[j] = prev[j]. Here prev is same as cur.
        }
    }
    return prev[m];
}

int main()
{
    string s1 = "babgbag";
    string s2 = "bag";
    vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), -1));
    cout << memoization(s1, s2, s1.size() - 1, s2.size() - 1, dp) << endl;
    cout << tabulation(s1, s2, s1.size(), s2.size()) << endl;
    cout << spaceOptimised(s1, s2, s1.size(), s2.size()) << endl;
    cout << spaceOptimised_Further(s1, s2, s1.size(), s2.size()) << endl;
    return 0;
}
