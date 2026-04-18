// SDE sheet - Arrays Part 3.
// Given a matrix m X n, count unique paths from left-top to the right bottom of a matrix with the constraints that from each cell you can either only move to the rightward direction or the downward direction.

#include <bits/stdc++.h>
using namespace std;

int recursive(int i, int j, int n, int m)
{
    if (i == (n - 1) && j == (m - 1))
        return 1;
    if (i >= n || j >= m)
        return 0;
    else
        return recursive(i + 1, j, n, m) + recursive(i, j + 1, n, m);
}

// TC = It will be exponential in nature as it is recursive.
// SC = It will also be exponential as we're are using stack space!
int unique_paths_recursive(int m, int n)
{
    return recursive(0, 0, m, n);
}

int DP(int i, int j, int n, int m, vector<vector<int>> &dp)
{
    if (i == (n - 1) && j == (m - 1))
        return 1;
    if (i >= n || j >= m)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    else
        return dp[i][j] = DP(i + 1, j, n, m, dp) + DP(i, j + 1, n, m, dp);
}

// TC = m*n
// SC = m*n for 'dp'.
int unique_paths_DP(int m, int n)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    int num = DP(0, 0, m, n, dp);
    if (m == 1 && n == 1)
        return num;
    return dp[0][0];
}

// We see that if we want to reach the end, we will have to take m-1 steps downwards.
// We will also have to take n-1 steps rightwards.
// Where m is no of rows and n is no of cols.
// So total number of steps is m+n-2
int unique_paths_combination(int m, int n)
{
    int N = m + n - 2; // We're computing N to find NCr
    int r = m - 1;     // We're computing r to find NCr
    double NCr = 1;
    for (int i = 1; i <= r; i++)
        NCr = NCr * (N - r + i) / i;
    return (int)NCr;
}

int main()
{
    cout << unique_paths_recursive(3, 7) << endl;
    cout << unique_paths_DP(3, 7) << endl;
    cout << unique_paths_combination(3 ,7) << endl;
    return 0;
}