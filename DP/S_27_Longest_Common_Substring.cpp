// A substring of a string is a subsequence in which all the characters are consecutive. Given two strings, we need to find the longest common substring. We need to print the length of the longest common substring.

// We're not writing the memoization approach as it needs 3 dp states and a 3D matrix

#include <bits/stdc++.h>
using namespace std;

// TC = SC = n*m
int tabulation(string &s1, string &s2)
{
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int ans = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (s1[i - 1] == s2[j - 1])
            {
                int val = 1 + dp[i - 1][j - 1]; // Characters match, increment substring length
                dp[i][j] = val;
                ans = max(ans, val);
            }
            else
                dp[i][j] = 0; // Characters don't match, substring length becomes 0
    return ans;
}

// TC = n*m, SC = m
int spaceOptimised(string &s1, string &s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<int> prev(m + 1, 0), cur(m + 1, 0);

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                int val = 1 + prev[j - 1]; // Characters match, increment substring length
                cur[j] = val;
                ans = max(ans, val);
            }
            else
                cur[j] = 0; // Characters don't match, substring length becomes 0
        }
        prev = cur;
    }

    return ans;
}
int main()
{
    string s1 = "abcjklp";
    string s2 = "acjkp";
    cout << tabulation(s1, s2) << endl;
    cout << spaceOptimised(s1, s2) << endl;
    return 0;
}
