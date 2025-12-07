// https://takeuforward.org/data-structure/rotten-oranges-min-time-to-rot-all-oranges-bfs/
// https://leetcode.com/problems/rotting-oranges/description/

// You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        if (grid.empty())
            return 0;

        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>> q; // {{row, col}, time} --> Storing the row, col, time of the rotting oranges
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int cntFresh = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // Iterate once through the entire matrix and push all the rotten oranges into the queue!
                if (grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
                // Count number of fresh oranges
                if (grid[i][j] == 1)
                    cntFresh++;
            }
        }

        int time = 0;
        int delRow[] = {-1, 0, 1, 0}; // This is the difference of row for 4 neighbours
        int delCol[] = {0, 1, 0, -1}; // This is the difference of col for 4 neighbours
        int cnt = 0;

        while (!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            time = max(time, t);
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nrow = r + delRow[i];
                int ncol = c + delCol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1)
                {
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 2;
                    cnt++;
                }
            }
        }
        if (cnt != cntFresh)
        // If we did not push all the fresh oranges into the queue, we will not end up rotting all the oranges, hence return -1
        {
            return -1;
        }
        return time;
    }
};

int main()
{
    vector<vector<int>> v = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}};
    Solution obj;
    cout << obj.orangesRotting(v);

    return 0;
}