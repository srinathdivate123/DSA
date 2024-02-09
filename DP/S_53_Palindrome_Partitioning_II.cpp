// Given a string s, partition s such that every substring of the partition is a palindrome. Return the minimum cuts needed for a palindrome partitioning of s.

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int i, int j, string &s)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

// TC = n*n, SC = n + n
int memoization(int i, int n, string &str, vector<int> &dp)
{
    // Base case: If we've reached the end of the string.
    if (i == n)
        return 0;

    if (dp[i] != -1)
        return dp[i];

    int minCost = INT_MAX;
    // Consider all possible substrings starting from the current index.
    for (int j = i; j < n; j++)
        if (isPalindrome(i, j, str))
        {
            // If the substring is a palindrome, calculate the cost and minimize it.
            int cost = 1 + memoization(j + 1, n, str, dp);
            minCost = min(minCost, cost);
        }
    return dp[i] = minCost;
}

// TC = n*n, SC = n
int tabulation(string str)
{
    int n = str.size();
    vector<int> dp(n + 1, 0);
    dp[n] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        int minCost = INT_MAX;
        // Consider all possible substrings starting from the current index.
        for (int j = i; j < n; j++)
            if (isPalindrome(i, j, str))
            {
                // If the substring is a palindrome, calculate the cost and minimize it.
                int cost = 1 + dp[j + 1];
                minCost = min(minCost, cost);
            }
        dp[i] = minCost;
    }
    return dp[0] - 1;
}

int main()
{
    string str = "BABABCBADCEDE";
    int n = str.size();
    vector<int> dp(n, -1);
    // We do a -1 in the answer because our code considers the last character in itself also a palindrome, so we have to minus that.
    cout << memoization(0, n, str, dp) - 1 << endl;
    cout << tabulation(str)<< endl;
    return 0;
}