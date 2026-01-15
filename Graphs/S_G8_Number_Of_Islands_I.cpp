// https://takeuforward.org/data-structure/number-of-islands/
// https://leetcode.com/problems/number-of-islands/description/

// Given a grid of size NxM (N is the number of rows and M is the number of columns) consisting of ‘0’s (Water) and ‘1’s (Land). Find the number of islands.

// Note: An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

// SC = N*N for visited array + N*N for queue at worst case when all are 1 i.e. only one island is there and no water is there

// SC = O(N² + NxMx9), N² for the nested loops, and NxMx9 for the overall BFS of the matrix.
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
        int delRow[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int delCol[] = {-1, 0, 1, 1, 1, 0, -1, -1};

        while (!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            // Pop it from the queue
            q.pop();

            for (int i = 0; i < 8; i++)
            {
                int nrow = r + delRow[i];
                int ncol = c + delCol[i];

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