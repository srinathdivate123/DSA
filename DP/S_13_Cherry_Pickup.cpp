/* We are given an ‘N*M’ matrix. Every cell of the matrix has some chocolates on it, mat[i][j] gives us the number of chocolates. We have two friends ‘Alice’ and ‘Bob’. initially, Alice is standing on the cell(0,0) and Bob is standing on the cell(0, M-1). Both of them can move only to the cells below them in these three directions: to the bottom cell (↓), to the bottom-right cell(↘), or to the bottom-left cell(↙).

When Alica and Bob visit a cell, they take all the chocolates from that cell with them. It can happen that they visit the same cell, in that case, the chocolates need to be considered only once.

They cannot go out of the boundary of the given matrix, we need to return the maximum number of chocolates that Bob and Alice can together collect. */

// Here we have to write recursion for Alice & Bob. We cannot do their recursion one after the other because Bob can pass through a cell which Alice has already passed through. So we will have to do their recursion paralelly.

// Both Alice & Bob will reach the last row at the same time because they both either move down, left diagonal or right diagonal. So they will move one steo down always. So we can represent Alice and Bob position by (i, j1) and (i, j2). Note that i (row number) is same.

#include <bits/stdc++.h>
using namespace std;

// Only Recursive: TC = 3^n * 3^n (because Alice & bob have 3 options), SC = n
// Memoised: TC = n*m*m*9 (because for every state you have 9 options, corresponding to the no of times the for loop runs), SC = n + n*m*m
int memoization(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{
    if (j1 < 0 || j2 < 0 || j1 >= c || j2 >= c)
        return -1e8;

    if (i == r - 1)
        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];

    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];
    int maxi = -1e8;
    // Explore all paths of Alice & Boob simultaneously
    for (int dj_Alice = -1; dj_Alice <= +1; dj_Alice++)
        for (int dj_Bob = -1; dj_Bob <= +1; dj_Bob++)
        {
            int value = 0;
            if (j1 == j2)
                value = grid[i][j1];
            else
                value = grid[i][j1] + grid[i][j2];
            value += memoization(i + 1, j1 + dj_Alice, j2 + dj_Bob, r, c, grid, dp);
            maxi = max(maxi, value);
        }
    return dp[i][j1][j2] = maxi;
}

// TC = n*m*m*9, SC = n*m*m
int tabulation(int r, int c, vector<vector<int>> &grid)
{
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, 0)));

    for (int j1 = 0; j1 < c; j1++)
        for (int j2 = 0; j2 < c; j2++)
            if (j1 == j2)
                dp[r - 1][j1][j2] = grid[r - 1][j1];
            else
                dp[r - 1][j1][j2] = grid[r - 1][j1] + grid[r - 1][j2];

    for (int i = r - 2; i >= 0; i--)
        for (int j1 = 0; j1 < c; j1++)
            for (int j2 = 0; j2 < c; j2++)
            {
                int maxi = INT_MIN;
                // Inner nested loops to try out 9 options (diagonal moves)
                for (int dj_Alice = -1; dj_Alice <= 1; dj_Alice++)
                    for (int dj_Bob = -1; dj_Bob <= 1; dj_Bob++)
                    {
                        int ans;
                        if (j1 == j2)
                            ans = grid[i][j1];
                        else
                            ans = grid[i][j1] + grid[i][j2];

                        // Check if the move is valid (within the grid boundaries)
                        if (j1 + dj_Alice >= 0 && j1 + dj_Alice < c && j2 + dj_Bob >= 0 && j2 + dj_Bob < c)
                            ans += dp[i + 1][j1 + dj_Alice][j2 + dj_Bob];
                        else
                            ans += -1e9;

                        maxi = max(ans, maxi);
                    }
                dp[i][j1][j2] = maxi;
            }
    // The maximum chocolates that can be collected is stored at the top-left corner of the DP array
    return dp[0][0][c - 1];
}

// TC = n*m*m*9, SC = 2*m*m
int spaceOptimised(int r, int c, vector<vector<int>> &grid)
{
    vector<vector<int>> front(c, vector<int>(c, 0)), curr(c, vector<int>(c, 0));

    for (int j1 = 0; j1 < c; j1++)
        for (int j2 = 0; j2 < c; j2++)
            if (j1 == j2)
                front[j1][j2] = grid[r - 1][j1];
            else
                front[j1][j2] = grid[r - 1][j1] + grid[r - 1][j2];

    for (int i = r - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < c; j1++)
            for (int j2 = 0; j2 < c; j2++)
            {
                int maxi = INT_MIN;
                // Inner nested loops to try out 9 options (diagonal moves)
                for (int dj_Alice = -1; dj_Alice <= 1; dj_Alice++)
                    for (int dj_Bob = -1; dj_Bob <= 1; dj_Bob++)
                    {
                        int ans;
                        if (j1 == j2)
                            ans = grid[i][j1];
                        else
                            ans = grid[i][j1] + grid[i][j2];

                        // Check if the move is valid (within the grid boundaries)
                        if (j1 + dj_Alice >= 0 && j1 + dj_Alice < c && j2 + dj_Bob >= 0 && j2 + dj_Bob < c)
                            ans += front[j1 + dj_Alice][j2 + dj_Bob];
                        else
                            ans += -1e9;

                        maxi = max(ans, maxi);
                    }
                curr[j1][j2] = maxi;
            }
        front = curr;
    }
    // The maximum chocolates that can be collected is stored at the top-left corner of the DP array
    return front[0][c - 1];
}

int main()
{
    vector<vector<int>> grid{
        {2, 3, 1, 2},
        {3, 4, 2, 2},
        {5, 6, 3, 5},
    };

    int r = grid.size();
    int c = grid[0].size();
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    cout << memoization(0, 0, c - 1, r, c, grid, dp) << endl;
    cout << tabulation(r, c, grid) << endl;
    cout << spaceOptimised(r, c, grid) << endl;

    return 0;
}