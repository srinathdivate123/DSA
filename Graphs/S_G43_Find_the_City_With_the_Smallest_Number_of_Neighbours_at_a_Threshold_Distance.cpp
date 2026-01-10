// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/
// https://takeuforward.org/data-structure/find-the-city-with-the-smallest-number-of-neighbours-at-a-threshold-distance-g-43

// There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.

// Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.

// Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<int>> distAdjMatrix(n, vector<int>(n, INT_MAX));

        // Adjacency matrix of the distances
        for (auto it : edges)
        {
            distAdjMatrix[it[0]][it[1]] = it[2];
            distAdjMatrix[it[1]][it[0]] = it[2];
        }

        // Set the diagonal to 0, as the distance from a city to itself is 0
        for (int i = 0; i < n; i++)
        {
            distAdjMatrix[i][i] = 0;
        }

        // Apply Floyd-Warshall Algorithm to find the shortest paths between all pairs of cities
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    // If it is already INT_MAX and if you add any number to it, then it will overflow the signed integer limit
                    // So it is better to continue to the next iteration
                    if (distAdjMatrix[i][k] == INT_MAX || distAdjMatrix[k][j] == INT_MAX)
                    {
                        continue;
                    }
                    distAdjMatrix[i][j] = min(distAdjMatrix[i][j], distAdjMatrix[i][k] + distAdjMatrix[k][j]);
                }
            }
        }

        // Initialize variables to track the city with the least reachable cities
        int maxReachableCount = n;
        int ansCity = -1;

        // Check each city and count the number of cities within the threshold distance
        for (int city = 0; city < n; city++)
        {
            int cnt = 0;
            // Count the number of adjCity that are reachable from city and are within distanceThreshold
            for (int adjCity = 0; adjCity < n; adjCity++)
            {
                if (distAdjMatrix[city][adjCity] <= distanceThreshold)
                    cnt++;
            }

            // Update the city with the least number of reachable cities
            if (cnt <= maxReachableCount)
            {
                maxReachableCount = cnt;
                ansCity = city;
            }
        }
        return ansCity;
    }
};

int main()
{
    int n = 4;
    vector<vector<int>> edges = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
    int distanceThreshold = 4;

    Solution obj;
    int ansCity = obj.findCity(n, edges, distanceThreshold);

    cout << "The answer is node: " << ansCity << endl;
    return 0;
}