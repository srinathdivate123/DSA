/* We are given an n*m matrix of integers. We need to find a path from the top-left corner to the bottom-right corner of the matrix, such that there is a minimum cost past that we select.

At every cell, we can move in only two directions: right and bottom. The cost of a path is given as the sum of values of cells of the given matrix. */

#include <bits/stdc++.h>
using namespace std;

int memoization(int i, int j, vector<vector<int>> matrix, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return matrix[0][0];
    if (i < 0 || j < 0)
        return 1e9;
    if (dp[i][j] != -1)
        return dp[i][j];

    int up = matrix[i][j] + memoization(i - 1, j, matrix, dp);
    int left = matrix[i][j] + memoization(i, j - 1, matrix, dp);
    return dp[i][j] = min(up, left);
}

int tabulation(int n, int m, vector<vector<int>> &matrix)
{
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = matrix[i][j];
            else
            {
                int up = matrix[i][j];
                if (i > 0)
                    up += dp[i - 1][j];
                else
                    up += 1e9; // A large value if moving up is not possible (out of bounds)

                int left = matrix[i][j];
                if (j > 0)
                    left += dp[i][j - 1];
                else
                    left += 1e9;
                dp[i][j] = min(up, left);
            }
        }
    return dp[n - 1][m - 1];
}

int spaceOptimised(int n, int m, vector<vector<int>> &matrix)
{
    vector<int> prev(m, 0);
    for (int i = 0; i < n; i++)
    {
        vector<int> temp(m, 0);
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                temp[j] = matrix[i][j];
            else
            {
                int up = matrix[i][j];
                if (i > 0)
                    up += prev[j];
                else
                    up += 1e9; // A large value if moving up is not possible (out of bounds)

                int left = matrix[i][j];
                if (j > 0)
                    left += temp[j - 1];
                else
                    left += 1e9;
                temp[j] = min(up, left);
            }
        }
        prev = temp;
    }
    return prev[m - 1];
}

int main()
{
    vector<vector<int>> matrix{
        {5, 9, 6},
        {11, 5, 2}};

    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << memoization(n - 1, m - 1, matrix, dp) << endl;
    cout << tabulation(n, m, matrix) << endl;
    cout << spaceOptimised(n, m, matrix) << endl;
    return 0;
}