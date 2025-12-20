// https://takeuforward.org/graph/surrounded-regions-replace-os-with-xs/
// https://leetcode.com/problems/surrounded-regions/description/

// You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

// Connect: A cell is connected to adjacent cells horizontally or vertically.
// Region: To form a region connect every 'O' cell.
// Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
// To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.

// TC: O(N × M), since each cell is visited at most once during DFS and once during the final traversal.

// SC: O(N × M), due to the visited matrix and the recursion stack in the worst case.

// --------------------------------------------- //

// The intuition is that we start from boundary elements having ‘O’ and go through its neighboring Os in 4 directions and mark them as visited to avoid replacing them with ‘X’.
// Mark all 'O's that are connected to the boundary as safe.
// At the end, flip all other 'O's (unvisited ones) into 'X'.
// Approach
// Use DFS (or BFS) starting from boundary cells. Whenever we see an 'O' on the boundary, perform DFS/BFS to mark all connected 'O's as visited (safe).
// After this traversal, all boundary-connected 'O's remain as they are, because they cannot be surrounded.
// Traverse the entire matrix:
// If an 'O' is visited, leave it as 'O'.
// If an 'O' is not visited, convert it into 'X'.

#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &mat, int delRow[], int delCol[], int n, int m)
    {
        vis[row][col] = 1;
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && mat[nrow][ncol] == 'o')
            {
                dfs(nrow, ncol, vis, mat, delRow, delCol, n, m);
            }
        }
    }

public:
    vector<vector<char>> surroundedRegions(vector<vector<char>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};

        // Traverse all the boundaries of the graph
        // Traverse first row and last row
        for (int j = 0; j < m; j++)
        {
            // For first row
            if (!vis[0][j] && mat[0][j] == 'o')
            {
                dfs(0, j, vis, mat, delRow, delCol, n, m);
            }

            // For last row
            if (!vis[n - 1][j] && mat[n - 1][j] == 'o')
            {
                dfs(n - 1, j, vis, mat, delRow, delCol, n, m);
            }
        }

        // Traverse first and last column
        for (int i = 0; i < n; i++)
        {
            // For first col
            if (!vis[i][0] && mat[i][0] == 'o')
            {
                dfs(i, 0, vis, mat, delRow, delCol, n, m);
            }

            // For last col
            if (!vis[i][m - 1] && mat[i][m - 1] == 'o')
            {
                dfs(i, m - 1, vis, mat, delRow, delCol, n, m);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && mat[i][j] == 'o')
                {
                    mat[i][j] = 'x';
                }
            }
        }
        return mat;
    }
};

int main()
{
    vector<vector<char>> mat = {
        {'x', 'x', 'x', 'x', 'x'},
        {'x', 'o', 'o', 'x', 'o'},
        {'x', 'x', 'o', 'x', 'o'},
        {'x', 'o', 'x', 'o', 'x'},
        {'o', 'o', 'x', 'x', 'x'},
    };
    Solution obj;
    vector<vector<char>> dist = obj.surroundedRegions(mat);
    for (auto row : dist)
    {
        for (auto element : row)
            cout << element << " ";
        cout << endl;
    }
    return 0;
}