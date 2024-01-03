/* We are given an ‘N*M’ matrix. We need to find the maximum path sum from any cell of the first row to any cell of the last row.

At every cell we can move in three directions: to the bottom cell (↓), to the bottom-right cell(↘), or to the bottom-left cell(↙). */
#include <bits/stdc++.h>
using namespace std;

// TC = n*m, SC = n + n*m
int memoization(int i, int j, int m, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    if (j < 0 || j >= m)
        return -1e9;
    if (i == 0)
        return matrix[0][j];
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = matrix[i][j] + memoization(i - 1, j, m, matrix, dp);
    int leftDiagonal = matrix[i][j] + memoization(i - 1, j - 1, m, matrix, dp);
    int rightDiagonal = matrix[i][j] + memoization(i - 1, j + 1, m, matrix, dp);
    return dp[i][j] = max(up, max(leftDiagonal, rightDiagonal));
}

// TC = n*m + n, SC = n*m
int tabulation(vector<vector<int>> &matrix, int n, int m)
{
    vector<vector<int>> dp(n, vector<int>(m, 0));

    // Initialize the first row of dp with values from the matrix (base condition)
    for (int j = 0; j < m; j++)
        dp[0][j] = matrix[0][j];

    for (int i = 1; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            int up = matrix[i][j] + dp[i - 1][j];

            int leftDiagonal = matrix[i][j];
            if (j - 1 >= 0)
                leftDiagonal += dp[i - 1][j - 1];
            else
                leftDiagonal += -1e9;

            int rightDiagonal = matrix[i][j];
            if (j + 1 < m)
                rightDiagonal += dp[i - 1][j + 1];
            else
                rightDiagonal += -1e9;
            dp[i][j] = max(up, max(leftDiagonal, rightDiagonal));
        }

    // Find the maximum value in the last row of dp, which represents the maximum path sums ending at each cell
    int maxi = INT_MIN;
    for (int j = 0; j < m; j++)
        maxi = max(maxi, dp[n - 1][j]);
    return maxi;
}

// TC = n*m, SC = m
int spaceOptimised(vector<vector<int>> &matrix, int n, int m)
{
    vector<int> prev(m, 0), cur(m, 0); // Prev & current row's max path sums

    for (int j = 0; j < m; j++)
        prev[j] = matrix[0][j];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int up = matrix[i][j] + prev[j];

            int leftDiagonal = matrix[i][j];
            if (j - 1 >= 0)
                leftDiagonal += prev[j - 1];
            else
                leftDiagonal += -1e9;

            int rightDiagonal = matrix[i][j];
            if (j + 1 < m)
                rightDiagonal += prev[j + 1];
            else
                rightDiagonal += -1e9;

            cur[j] = max(up, max(leftDiagonal, rightDiagonal));
        }
        prev = cur;
    }

    // Find the maximum value in the last row of 'prev', which represents the maximum path sums ending at each cell
    int maxi = INT_MIN;
    for (int j = 0; j < m; j++)
        maxi = max(maxi, prev[j]);
    return maxi;
}
int main()
{
    vector<vector<int>> matrix{{1, 2, 10, 4},
                               {100, 3, 2, 1},
                               {1, 1, 20, 2},
                               {1, 2, 2, 1}};
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int maxi = INT_MIN;
    for (int j = 0; j < m; j++)
    {
        int ans = memoization(n - 1, j, m, matrix, dp);
        maxi = max(maxi, ans);
    }
    cout << maxi << endl;
    cout << tabulation(matrix, n, m) << endl;
    cout << spaceOptimised(matrix, n, m) << endl;
    return 0;
}