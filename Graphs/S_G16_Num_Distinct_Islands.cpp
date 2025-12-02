// https://takeuforward.org/data-structure/number-of-distinct-islands/
// https://leetcode.com/problems/number-of-distinct-islands-ii/

// Given a boolean 2D matrix grid of size N x M. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is equal to another (not rotated or reflected).

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid)
    {
        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = 1;

        // Define all 8 directions
        int deltaRow[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int deltaCol[] = {-1, 0, 1, 1, 1, 0, -1, -1};

        while (!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            // Traverse all 8 directions
            for (int i = 0; i < 8; i++)
            {
                int nrow = r + deltaRow[i];
                int ncol = c + deltaCol[i];

                // Check bounds and unvisited land
                if (nrow >= 0 && nrow < grid.size() &&
                    ncol >= 0 && ncol < grid[0].size() &&
                    !vis[nrow][ncol] && grid[nrow][ncol] == '1')
                {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int count = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == '1')
                {
                    count++;
                    bfs(i, j, vis, grid);
                }
            }
        }
        return count;
    }
};

int main()
{
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}};

    Solution obj;
    cout << obj.numIslands(grid) << endl;
    return 0;
}