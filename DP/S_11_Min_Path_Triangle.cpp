/* We are given a Triangular matrix. We need to find the minimum path sum from the first row to the last row. At every cell we can move in only two directions: either to the bottom cell (↓) or to the bottom-right cell(↘) */

#include <bits/stdc++.h>
using namespace std;

// TC = n*n, SC = n + n*n
int memoization(int i, int j, vector<vector<int>> &triangle, int n,
                vector<vector<int>> &dp)
{
    if (dp[i][j] != -1)
        return dp[i][j];
    if (i == n - 1)
        return triangle[i][j];
    int down = triangle[i][j] + memoization(i + 1, j, triangle, n, dp);
    int diagonal = triangle[i][j] + memoization(i + 1, j + 1, triangle, n, dp);
    return dp[i][j] = min(down, diagonal);
}

// TC = n*n, SC = n*n
int tabulation(vector<vector<int>> &triangle, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int j = 0; j < n; j++)
        dp[n - 1][j] = triangle[n - 1][j];

    // Iterate through the triangle rows in reverse order
    for (int i = n - 2; i >= 0; i--)
        for (int j = i; j >= 0; j--)
        {
            int down = triangle[i][j] + dp[i + 1][j];
            int diagonal = triangle[i][j] + dp[i + 1][j + 1];
            dp[i][j] = min(down, diagonal);
        }
    return dp[0][0];
}

// TC = n*n, SC = n
int spaceOptimised(vector<vector<int>> &triangle, int n)
{
    vector<int> front(n, 0), cur(n, 0);
    for (int j = 0; j < n; j++)
        front[j] = triangle[n - 1][j];
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int down = triangle[i][j] + front[j];
            int diagonal = triangle[i][j] + front[j + 1];
            cur[j] = min(down, diagonal);
        }
        front = cur;
    }
    return front[0];
}

int main()
{
    vector<vector<int>> triangle{{1},
                                 {2, 3},
                                 {3, 6, 7},
                                 {8, 9, 6, 10}};
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << memoization(0, 0, triangle, n, dp) << endl;
    cout << tabulation(triangle, n) << endl;
    cout << spaceOptimised(triangle, n) << endl;
    return 0;
}