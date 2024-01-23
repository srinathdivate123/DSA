// We are given two strings S1 and S2. We need to return their shortest common supersequence. A supersequence is defined as the string which contains both the strings S1 and S2 as subsequences.
// S1 = bleed, S2 = blue. Shortest supersequence = bleued

#include <bits/stdc++.h>
using namespace std;

// TC = SC = n*m
// Common chars should be taken once
// Length of ans = n + m - len(Longest Common Subsequence)
string shortestSupersequence(string s1, string s2)
{

    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= m; i++)
        dp[0][i] = 0;

    for (int ind1 = 1; ind1 <= n; ind1++)
        for (int ind2 = 1; ind2 <= m; ind2++)
            if (s1[ind1 - 1] == s2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
            else
                dp[ind1][ind2] = 0 + max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
    // Upto now we were finding LCS.
    int len = dp[n][m];
    int i = n;
    int j = m;

    int index = len - 1;
    string ans = "";

    while (i > 0 && j > 0)
        if (s1[i - 1] == s2[j - 1])
        {
            ans += s1[i - 1];
            index--;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            ans += s1[i - 1];
            i--;
        }
        else
        {
            ans += s2[j - 1];
            j--;
        }

    // Adding Remaing Characters - Only one of the below two while loops will run
    while (i > 0)
    {
        ans += s1[i - 1];
        i--;
    }
    while (j > 0)
    {
        ans += s2[j - 1];
        j--;
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{

    string s1 = "bleed";
    string s2 = "blue";

    cout << "The Longest Common Supersequence is " << shortestSupersequence(s1, s2);
}