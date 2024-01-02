/* We are given an “n*m” Maze. The maze contains some obstacles. A cell is ‘blockage’ in the maze if its value is -1. 0 represents non-blockage. There is no path possible through a blocked cell.

We need to count the total number of unique paths from the top-left corner of the maze to the bottom-right corner. At every cell, we can move either down or towards the right. */
#include <bits/stdc++.h>
using namespace std;
int mod = (int)(1e9 + 7);

// TC = n*m, SC = n-1 + m-1 + n*m
int memoization(int i, int j, vector<vector<int>> &maze, vector<vector<int>> &dp)
{
    if (i > 0 && j > 0 && maze[i][j] == -1)
        return 0;
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = memoization(i - 1, j, maze, dp);
    int left = memoization(i, j - 1, maze, dp);
    return dp[i][j] = (up + left) % mod;
}

// TC = n*m, SC = n*m
int tabulation(int n, int m, vector<vector<int>> &maze)
{
    vector<vector<int>> dp(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (i > 0 && j > 0 && maze[i][j] == -1)
            {
                dp[i][j] = 0;
                continue;
            }
            if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
                continue;
            }
            int up = 0;
            int left = 0;
            if (i > 0)
                up = dp[i - 1][j]; // Number of paths from above
            if (j > 0)
                left = dp[i][j - 1]; // Number of paths from the left
            dp[i][j] = (up + left) % mod;
        }
    return dp[n - 1][m - 1];
}

int spaceOptimised(int n, int m, vector<vector<int>> &maze)
{
    vector<int> prev(m, 0);
    for (int i = 0; i < n; i++)
    {
        vector<int> temp(m, 0);
        for (int j = 0; j < m; j++)
        {
            if (i > 0 && j > 0 && maze[i][j] == -1)
            {
                temp[j] = 0;
                continue;
            }
            if (i == 0 && j == 0)
            {
                temp[j] = 1;
                continue;
            }
            int up = 0;
            int left = 0;
            if (i > 0)
                up = prev[j];
            if (j > 0)
                left = temp[j - 1];
            temp[j] = up + left;
        }
        prev = temp;
    }
    return prev[m - 1];
}
int main()
{
    vector<vector<int>> maze{
        {0, 0, 0},
        {0, -1, 0},
        {0, 0, 0}};
    int n = maze.size();
    int m = maze[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << memoization(n - 1, m - 1, maze, dp) << endl;
    cout << tabulation(n, m, maze) << endl;
    cout << spaceOptimised(n, m, maze) << endl;
    return 0;
}