// Given a string, we need to find the minimum insertions that we can make in that string to make it a palindrome. You are allowed to insert any number characters anywhere.

// Maximum way is to attach the reverse of the string to the end of thr string like str + rev(str). But you will need str.size() number of operations to do so.
#include <bits/stdc++.h>
using namespace std;

// TC = SC = n*n
// The minimum insertions required is the difference between the string length and its longest palindromic subsequence length
int tabulationUtil(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    // Initialize the first row and first column to 0
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= m; i++)
        dp[0][i] = 0;

    for (int ind1 = 1; ind1 <= n; ind1++)
        for (int ind2 = 1; ind2 <= m; ind2++)
            if (s1[ind1 - 1] == s2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
            else
                dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);

    return dp[n][m];
}


int tabulation(string s)
{
    int n = s.size();
    string t = s;
    reverse(s.begin(), s.end());
    int k = tabulationUtil(s, t);

    // The minimum insertions required is the difference between the string length and its longest palindromic subsequence length
    return n - k;
}

// Space optimised is also similar
int main()
{
    string s = "abcaa";
    cout << tabulation(s);
    return 0;
}
