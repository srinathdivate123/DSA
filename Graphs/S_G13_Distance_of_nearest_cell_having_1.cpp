// https://takeuforward.org/graph/distance-of-nearest-cell-having-1/
// https://leetcode.com/problems/01-matrix/description/
// https://leetcode.com/problems/map-of-highest-peak/description/

// Problem Statement: Given a binary grid of N*M. Find the distance of the nearest 1 in the grid for each cell.

// The distance is calculated as |i1  – i2| + |j1 – j2|, where i1, j1 are the row number and column number of the current cell, and i2, j2 are the row number and column number of the nearest cell having value 1

// If the element itself is 1, then the distance=0
// There are no diagonal distances calculated

// TC = N*M + N*M*4
// SC = N*M for vis and NxM for dist and NxM for queue because all elements are put into the queue

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> nearest(vector<vector<int>> grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> dist(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;

        // TC = NxM
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }

        int delRow[] = {-1, 0, +1, 0}; // This is the difference of row for 4 neighbours
        int delCol[] = {0, +1, 0, -1}; // This is the difference of col for 4 neighbours
        // TC = NxMx4
        while (!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            dist[row][col] = steps;
            for (int i = 0; i < 4; i++)
            {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0)
                {
                    vis[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, steps + 1});
                }
            }
        }
        return dist;
    }
};

int main()
{
    vector<vector<int>> grid = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 0, 1}};
    Solution obj;
    vector<vector<int>> dist = obj.nearest(grid);
    for (auto row : dist)
    {
        for (auto element : row)
        {
            cout << element << " ";
        }
        cout << endl;
    }
}