// https://takeuforward.org/data-structure/g-40-number-of-ways-to-arrive-at-destination
// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/

// You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

// You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

// Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 10^9 + 7.

// The crux here is that you define a "ways" array to store the number of shortest paths to each node, initialized to 0. This array will store for each node, the number of paths with shortest distance that reach it.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads, int src, int dst, int K)
    {
        // Note for LeetCode, you will need to take long long everywhere as the test cases are too large
        vector<vector<pair<int, int>>> adj(n);
        for (auto it : roads)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> dist(n, INT_MAX), ways(n, 0);

        dist[src] = 0; // Distance for the source node is 0

        ways[src] = 1; // There's 1 way to reach the source (itself)

        pq.push({0, src}); // Push the source node with distance 0

        int mod = (int)(1e9 + 7);

        while (!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int edW = it.second;

                // This is the first time you're arriving at this node
                // Then update the distance and number of ways
                if (dis + edW < dist[adjNode])
                {
                    // Update the distance
                    dist[adjNode] = dis + edW;

                    // Push the new node with updated distance
                    pq.push({dis + edW, adjNode});

                    // Copy the number of ways to the new node
                    ways[adjNode] = ways[node];
                }

                // If the same shortest path is already been found earlier
                // Then just update the number of ways
                // No need to update the dist and push it in queue because it will be a duplicate entry
                else if (dis + edW == dist[adjNode])
                {
                    // Increment the number of ways
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        // Return the number of ways to reach the last node modulo 10^9 + 7
        return ways[dst] % mod;
    }
};

int main()
{

    // Driver Code
    int n = 7;

    // Define the edges (source, destination, weight)
    vector<vector<int>> edges = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3}, {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};

    Solution obj;

    // Call the method to count the number of shortest paths
    int ans = obj.countPaths(n, edges, 0, 3, 1);

    // Output the result
    cout << ans << endl;

    return 0;
}