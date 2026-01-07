// You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

// A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

// Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; // Stores {effort, {x, y}}

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;       // Distance for the source cell (0, 0) is 0
        pq.push({0, {0, 0}}); // Push source cell to the priority queue

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int currEffort = it.first; // The current effort
            int row = it.second.first;
            int col = it.second.second;

            // If we reach the destination cell, return the current effort
            if (row == n - 1 && col == m - 1)
                return currEffort;

            // Check all 4 possible adjacent cells
            for (int i = 0; i < 4; i++)
            {
                int newr = row + dr[i];
                int newc = col + dc[i];

                if (newr >= 0 && newc >= 0 && newr < n && newc < m)
                {
                    // Calculate the effort required to move to the new cell
                    int newEffort = max(abs(heights[row][col] - heights[newr][newc]), currEffort);

                    // If the calculated effort is less, update and push to the queue
                    if (newEffort < dist[newr][newc])
                    {
                        dist[newr][newc] = newEffort;
                        pq.push({newEffort, {newr, newc}});
                    }
                }
            }
        }
        return 0;
    }
};

int main()
{
    vector<vector<int>> heights = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};
    Solution obj;
    int ans = obj.minimumEffortPath(heights);
    cout << ans << endl;
    return 0;
}