// https://takeuforward.org/data-structure/rotten-oranges-min-time-to-rot-all-oranges-bfs/
// https://leetcode.com/problems/rotting-oranges/description/

// You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

// TC: O(n × n × 4) In the worst case, every cell in the grid may contain an orange, and for each rotten orange we explore 4 directions (up, down, left, right). So we iterate through all cells (n × n) and perform 4 operations per orange. Hence, the complexity becomes O(n × n × 4), which simplifies to O(n²).

// SC: O(n × n) In the worst case, all the oranges might be rotten and will be stored in the queue simultaneously. The maximum size of the queue can be equal to the total number of oranges in the grid, i.e., n × n. Therefore, the space complexity is O(n²).

#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{
    if (grid.empty())
        return 0;

    int m = grid.size();
    int n = grid[0].size();

    int minutesPassed = 0;

    // fresh + rotten
    int totalOranges = 0;

    // Variable to count how many oranges became rotten during the process
    int cnt = 0;
    queue<pair<int, int>> rotten;

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (grid[i][j] != 0)
                totalOranges++; // Count it as a valid orange

            if (grid[i][j] == 2)
                rotten.push({i, j});
        }
    }

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    while (!rotten.empty())
    {
        // Number of rotten oranges to process at this minute
        int k = rotten.size();

        // Add these many oranges to the count of rotted oranges
        cnt += k;

        // Process ALL the current rotten oranges at this time step
        while (k--)
        {
            // Get the front orange from the queue
            int x = rotten.front().first;
            int y = rotten.front().second;
            rotten.pop();

            // Check all 4 directions
            for (int i = 0; i < 4; ++i)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1)
                    continue;

                grid[nx][ny] = 2;
                rotten.push({nx, ny});
            }
        }
        // If new oranges were added to the queue, increase the time
        if (!rotten.empty())
        {
            minutesPassed++;
        }
    }
    return totalOranges == cnt ? minutesPassed : -1;
}

int main()
{
    vector<vector<int>> v{{2, 1, 1},
                          {1, 1, 0},
                          {0, 1, 1}};

    cout << orangesRotting(v);
    return 0;
}