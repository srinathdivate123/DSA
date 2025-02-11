/*
Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'

Any right parenthesis ')' must have a corresponding left parenthesis '('

Left parenthesis '(' must go before the corresponding right parenthesis ')'

'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

*/

#include <bits/stdc++.h>
using namespace std;

// TC = At the worst case we may have all '*'. If we have a * then we form three branches. Hence, TC = 3^N
// SC = O(s.size()) for auxiliary stack space
bool recursion(string s, int ind, int cnt)
{
    if (cnt < 0)
    {
        return false;
    }
    // If you reached the end, then you must have cnt=0
    if (ind == s.size() - 1)
    {
        return cnt == 0;
    }

    // If you encounter '(' then cnt++, if ')' then cnt--
    if (s[ind] == '(')
    {
        return recursion(s, ind + 1, cnt + 1);
    }
    else if (s[ind] == ')')
    {
        return recursion(s, ind + 1, cnt - 1);
    }
    else if (s[ind] == '*')
    {
        return recursion(s, ind + 1, cnt + 1) || recursion(s, ind + 1, cnt - 1) || recursion(s, ind + 1, cnt);
        // Replace * with ( || Replace * with ) || Replace * with empty character
    }
}

// TC = O(N*N)
// SC = O(N*N)
bool dp_solution(string s, int ind, int cnt, vector<vector<int>> &dp)
{
    if (dp[ind][cnt] != -1)
    {
        return dp[ind][cnt];
    }
    if (cnt < 0)
    {
        return false;
    }
    // If you reached the end, then you must have cnt=0
    if (ind == s.size() - 1)
    {
        return cnt == 0;
    }

    // If you encounter '(' then cnt++, if ')' then cnt--
    if (s[ind] == '(')
    {
        return dp[ind][cnt] = recursion(s, ind + 1, cnt + 1);
    }
    else if (s[ind] == ')')
    {
        return dp[ind][cnt] = recursion(s, ind + 1, cnt - 1);
    }
    else if (s[ind] == '*')
    {
        return dp[ind][cnt] = recursion(s, ind + 1, cnt + 1) || recursion(s, ind + 1, cnt - 1) || recursion(s, ind + 1, cnt);
        // Replace * with ( || Replace * with ) || Replace * with empty character
    }
}

// TC = O(N), SC = O(1)
bool best(string s)
{
    // So instead of maintaining a count, we maintain a range of possibilities where the count can lie in
    int minRange = 0, maxRange = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            minRange += 1;
            maxRange += 1;
        }
        else if (s[i] == ')')
        {
            minRange -= 1;
            maxRange -= 1;
        }
        else
        {
            minRange -= 1;
            maxRange += 1;
        }
        if (minRange < 0)
            minRange = 0;
        if (maxRange < 0)
            return false;
    }
    return minRange == 0;
}

int main()
{
    string s = "(*))";
    int n = s.size();

    // Note: // If you encounter '(' then cnt++, if ')' then cnt--

    cout << recursion(s, 0, 0) << endl;

    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << dp_solution(s, 0, 0, dp) << endl;

    cout << best(s) << endl;
}