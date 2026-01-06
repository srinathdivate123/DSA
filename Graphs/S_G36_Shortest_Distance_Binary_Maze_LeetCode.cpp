// https://leetcode.com/problems/shortest-path-in-binary-matrix/description/

// Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

// A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

// --> All the visited cells of the path are 0.
// --> All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner)
// The length of a clear path is the number of visited cells of this path.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        if (grid[0][0] == 1)
            return -1;
        int n = grid.size();

        if (n == 1 && grid[0][0] == 0)
            return 1;

        queue<pair<int, pair<int, int>>> q;

        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        dist[0][0] = 0;

        q.push({0, {0, 0}});

        int dr[] = {-1, -1, 0, +1, +1, +1, 0, -1};
        int dc[] = {0, +1, +1, +1, 0, -1, -1, -1};

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;

            // Check all 8 adjacent directions
            for (int i = 0; i < 8; i++)
            {
                int newr = r + dr[i];
                int newc = c + dc[i];

                if (newr >= 0 && newr < n && newc >= 0 && newc < n && grid[newr][newc] == 0 && dis + 1 < dist[newr][newc])
                {
                    dist[newr][newc] = 1 + dis; // Update the distance

                    // If destination is reached, return the distance
                    if (newr == n - 1 && newc == n - 1)
                        return dis + 2; // Need to do +2 instead of +1 because we need to consider the starting cell also

                    // Add the new cell to the queue for further processing
                    q.push({1 + dis, {newr, newc}});
                }
            }
        }
        return -1;
    }
};

int main()
{
    vector<vector<int>> grid = {{0, 0, 1, 1},
                                {1, 1, 0, 1},
                                {1, 1, 0, 1},
                                {1, 1, 0, 0}};

    Solution obj;

    int res = obj.shortestPathBinaryMatrix(grid);

    cout << res << endl;

    return 0;
}