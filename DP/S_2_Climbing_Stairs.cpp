// Given a number of stairs. Starting from the 0th stair we need to climb to the “Nth” stair. At a time we can climb either one or two steps. We need to return the total number of distinct ways to reach from 0th to Nth stair.
#include <bits/stdc++.h>
using namespace std;

// TC = 2^N, SC = N
int func_memoization(int index)
{
    if (index == 0 || index == 1)
        return 1;
    return func_memoization(index - 1) + func_memoization(index - 2);
}

// TC = N, SC = N
int func_tabulation(int n)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}

// TC = N, SC = 1
int func_space_optimised(int n)
{
    int prev2 = 1;
    int prev = 1;
    for (int i = 2; i <= n; i++)
    {
        int cur_i = prev2 + prev;
        prev2 = prev;
        prev = cur_i;
    }
    return prev;
}

int main()
{
    cout << func_memoization(3) << endl;
    cout << func_tabulation(3) << endl;
    cout << func_space_optimised(3) << endl;
    return 0;
}