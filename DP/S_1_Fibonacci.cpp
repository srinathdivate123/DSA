#include <bits/stdc++.h>
using namespace std;

int nth_fibonacciRecursion(int n)
{
    if (n <= 1)
        return n;
    return nth_fibonacciRecursion(n - 1) + nth_fibonacciRecursion(n - 2);
}

// TC = N, SC = N + N (stack space)
int nth_fibonacci_memoization(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = nth_fibonacci_memoization(n - 1, dp) + nth_fibonacci_memoization(n - 2, dp);
}

// TC = N, SC = N
int nth_fibonacci_tabulation(int n, vector<int> &dpp)
{
    for (int i = 2; i <= n; i++)
        dpp[i] = dpp[i - 1] + dpp[i - 2];
    return dpp[n];
}

//
int nth_fibonacci_optimal(int n)
{
    int prev = 1, prev2 = 0;
    for (int i = 2; i <= n; i++)
    {
        int current = prev + prev2;
        prev2 = prev;
        prev = current;
    }
    return prev;
}
int main()
{
    int find_fibonacci_for = 7;
    cout << nth_fibonacciRecursion(find_fibonacci_for) << endl;
    vector<int> dp(find_fibonacci_for + 1, -1);
    cout << nth_fibonacci_memoization(find_fibonacci_for, dp) << endl;
    vector<int> dpp(find_fibonacci_for + 1, -1);
    dpp[0] = 0;
    dpp[1] = 1;
    cout << nth_fibonacci_tabulation(find_fibonacci_for, dpp) << endl;
    cout << nth_fibonacci_optimal(find_fibonacci_for) << endl;
    return 0;
}