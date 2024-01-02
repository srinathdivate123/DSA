/* Given two values M and N, which represent a matrix[M][N]. We need to find the total unique paths from the top-left cell (matrix[0][0]) to the rightmost cell (matrix[M-1][N-1]). We are allowed to move bottom and right. */
#include <bits/stdc++.h>
using namespace std;

// TC = m*n (it will visit only unique states. It will not visit the same index twice because we memoised it)
// SC = (n-1 + m-1) stack space + (m*n) dp array>f
int memoization(int i, int j, vector<vector<int>> &dp)
{
    // Base case: If we reach the top-left corner (0, 0), there is one way.
    if (i == 0 && j == 0)
        return 1;

    // If we go out of bounds or reach a blocked cell, there are no ways.
    if (i < 0 || j < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    // Calculate the number of ways by moving up and left recursively.
    int up = memoization(i - 1, j, dp);
    int left = memoization(i, j - 1, dp);
    return dp[i][j] = up + left;
}

// TC = m*n, SC = m*n
int tabulation(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            // Base condition: If we are at the top-left cell (0, 0), there is one way.
            if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
                continue;
            }
            int up = 0;
            int left = 0;

            // If we are not at the first row (i > 0), update 'up' with the value from the cell above.
            if (i > 0)
                up = dp[i - 1][j];

            // If we are not at the first column (j > 0), update 'left' with the value from the cell to the left.
            if (j > 0)
                left = dp[i][j - 1];

            // Calculate the number of ways to reach the current cell by adding 'up' and 'left'.
            dp[i][j] = up + left;
        }
    return dp[m - 1][n - 1];
}

// TC = m*n, SC = 2n
int spaceOptimised(int m, int n)
{
    vector<int> prev(n, 0);
    for (int i = 0; i < m; i++)
    {
        vector<int> currentRow(n, 0);
        for (int j = 0; j < n; j++)
        {
            // Base case: If we are at the top-left cell (0, 0), there is one way.
            if (i == 0 && j == 0)
            {
                currentRow[j] = 1;
                continue;
            }
            int up = 0;
            int left = 0;

            // If we are not at the first row (i > 0), update 'up' with the value from the previous row.
            if (i > 0)
                up = prev[j];

            // If we are not at the first column (j > 0), update 'left' with the value from the current row.
            if (j > 0)
                left = currentRow[j - 1];

            // Calculate the number of ways to reach the current cell by adding 'up' and 'left'.
            currentRow[j] = up + left;
        }

        // Update the previous row with the values calculated for the current row.
        prev = currentRow;
    }
    // The result is stored in the last cell of the previous row (n-1).
    return prev[n - 1];
}

// This is using combinatorics. This is like finding NCr.
// https://youtu.be/t_f0nwwdg5o?t=803
int mostOptimised(int m, int n)
{
    int N = m + n - 2;
    int r = m - 1;
    double result = 1;
    for (int i = 1; i <= r; i++)
        result = result * (N - r + i) / i;
    return (int)result;
}
int main()
{
    int m = 3, n = 2;
    vector<vector<int>> dp(m, vector<int>(n, -1));
    cout << memoization(m - 1, n - 1, dp) << endl;
    cout << tabulation(m, n) << endl;
    cout << spaceOptimised(m, n) << endl;
    cout << mostOptimised(m, n) << endl;
    return 0;
}