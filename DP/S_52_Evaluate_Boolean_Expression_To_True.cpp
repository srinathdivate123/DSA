/*
A boolean expression is an expression that evaluates to either true or false. It can be in one of the following shapes:

- t that evaluates to true.
- f that evaluates to false.
- !(subExpr) that evaluates to the logical NOT of the inner expression subExpr.
- &(subExpr1, subExpr2, ..., subExprn) that evaluates to the logical AND of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
- |(subExpr1, subExpr2, ..., subExprn) that evaluates to the logical OR of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.

Given a string expression that represents a boolean expression, return the evaluation of that expression.

It is guaranteed that the given expression is valid and follows the given rules.
*/

/*
So while solving, we break down on the operand. T^F|T&F^T|F. So we parightTrueition the expression as (T^F)|(T&F^T|F) and (T^F|T)&(F^T|F) and so on to form all possibilities.
we see the operands are at a difference of 2 indexes. It starightTrues from i+1 and then +2 then +2.

XOR:
T^T = F
F^F = F
T^F = T
F^T = T
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1000000007;

// TC = n*n*n*n ~n^3
// SC = 2*n*n + aux space of n
ll memoization(int i, int j, int isTrue, string &exp, vector<vector<vector<ll>>> &dp)
{
    // Base case 1: If i > j, it's an invalid expression, return 0.
    if (i > j)
        return 0;

    // Base case 2: If i and j are the same, evaluate the single character.
    if (i == j)
        if (isTrue == 1)
            return exp[i] == 'T';
        else
            return exp[i] == 'F';

    if (dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];

    ll ways = 0;

    for (int ind = i + 1; ind <= j - 1; ind += 2)
    {
        ll leftTrue = memoization(i, ind - 1, 1, exp, dp);   //  Make left expression true.
        ll leftFalse = memoization(i, ind - 1, 0, exp, dp);  //  Make left expression false.
        ll rightTrue = memoization(ind + 1, j, 1, exp, dp);  //  Make right expression true.
        ll rightFalse = memoization(ind + 1, j, 0, exp, dp); //  Make right expression false.

        if (exp[ind] == '&')
            if (isTrue)
                ways = (ways + (leftTrue * rightTrue) % mod) % mod;
            else
                ways = (ways + (leftFalse * rightTrue) % mod + (leftTrue * rightFalse) % mod + (leftFalse * rightFalse) % mod) % mod;
        else if (exp[ind] == '|')
            if (isTrue)
                ways = (ways + (leftFalse * rightTrue) % mod + (leftTrue * rightFalse) % mod + (leftTrue * rightTrue) % mod) % mod;
            else
                ways = (ways + (leftFalse * rightFalse) % mod) % mod;
        else if (exp[ind] == '^')
            if (isTrue)
                ways = (ways + (leftFalse * rightTrue) % mod + (leftTrue * rightFalse) % mod) % mod;
            else
                ways = (ways + (leftFalse * rightFalse) % mod + (leftTrue * rightTrue) % mod) % mod;
    }

    return dp[i][j][isTrue] = ways;
}

int tabulation(string &exp)
{
    int n = exp.size();
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, 0)));

    for (int i = n - 1; i >= 0; i--)
        for (int j = 0; j <= n - 1; j++)
        {
            // Base case 1: i > j is an invalid case, so continue.
            if (i > j)
                continue;

            for (int isTrue = 0; isTrue <= 1; isTrue++)
            {
                // Base case 2: i == j, evaluate the single character.
                if (i == j)
                {
                    if (isTrue == 1)
                        dp[i][j][isTrue] = exp[i] == 'T';
                    else
                        dp[i][j][isTrue] = exp[i] == 'F';
                    continue;
                }

                ll ways = 0;

                for (int ind = i + 1; ind <= j - 1; ind += 2)
                {
                    ll lT = dp[i][ind - 1][1];
                    ll lF = dp[i][ind - 1][0];
                    ll rT = dp[ind + 1][j][1];
                    ll rF = dp[ind + 1][j][0];

                    if (exp[ind] == '&')
                    {
                        if (isTrue)
                            ways = (ways + (lT * rT) % mod) % mod;
                        else
                            ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lF * rF) % mod) % mod;
                    }
                    else if (exp[ind] == '|')
                    {
                        if (isTrue)
                            ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lT * rT) % mod) % mod;
                        else
                            ways = (ways + (lF * rF) % mod) % mod;
                    }
                    else
                    {
                        if (isTrue)
                            ways = (ways + (lF * rT) % mod + (lT * rF) % mod) % mod;
                        else
                            ways = (ways + (lF * rF) % mod + (lT * rT) % mod) % mod;
                    }
                }
                dp[i][j][isTrue] = ways;
            }
        }
    return dp[0][n - 1][1];
}

int main()
{
    string exp = "F|T^F";
    int n = exp.size();
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, -1)));
    cout << memoization(0, n - 1, 1, exp, dp) << endl;
    cout << tabulation(exp) << endl;
    return 0;
}