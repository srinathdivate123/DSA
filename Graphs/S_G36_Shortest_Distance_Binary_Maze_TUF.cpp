// https://takeuforward.org/data-structure/g-36-shortest-distance-in-a-binary-maze

// The below question is as per TUF. For LeetCode, refer the next cpp file

// Given an n * m matrix grid where each element can either be 0 or 1. You need to find the shortest distance between a given source cell to a destination cell. The path can only be created out of a cell if its value is 1.
// If the path is not possible between the source cell and the destination cell, then return -1.

// Note: You can move into an adjacent cell if that adjacent cell is filled with element 1. Two cells are adjacent if they share a side. In other words, you can move in one of four directions, Up, Down, Left, and Right.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination)
    {

        // Edge Case: if the source is the same as the destination
        if (source.first == destination.first && source.second == destination.second)
            return 0;

        queue<pair<int, pair<int, int>>> q; // Store nodes in format: {dist, {x, y}}
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[source.first][source.second] = 0;

        q.push({0, {source.first, source.second}});

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;

            // Check all 4 adjacent directions
            for (int i = 0; i < 4; i++)
            {
                int newr = r + dr[i];
                int newc = c + dc[i];

                if (newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] == 1 && dis + 1 < dist[newr][newc])
                {
                    dist[newr][newc] = 1 + dis; // Update the distance

                    // If destination is reached, return the distance
                    if (newr == destination.first && newc == destination.second)
                        return dis + 1;

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
    pair<int, int> source = {0, 1};
    pair<int, int> destination = {2, 2};

    vector<vector<int>> grid = {{1, 1, 1, 1},
                                {1, 1, 0, 1},
                                {1, 1, 1, 1},
                                {1, 1, 0, 0},
                                {1, 0, 0, 1}};

    Solution obj;

    int res = obj.shortestPath(grid, source, destination);

    cout << res << endl;

    return 0;
}