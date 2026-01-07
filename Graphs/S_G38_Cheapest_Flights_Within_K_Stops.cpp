// There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

// You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        // Create the adjacency list to represent airports and flights as a graph
        vector<vector<pair<int, int>>> adj(n);

        for (auto it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]}); // Add an edge from source to destination with the weight (cost)
        }

        // Create a queue to store the node, its distance from the source, and the number of stops
        queue<pair<int, pair<int, int>>> q;

        q.push({0, {src, 0}}); // source node with 0 stops and 0 cost

        vector<int> dist(n, 1e9);
        dist[src] = 0;

        // BFS traversal with a queue to process the nodes
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int stops = it.first;        // Number of stops so far
            int node = it.second.first;  // Current node
            int cost = it.second.second; // Cost to reach the current node

            // If the number of stops exceeds K, continue to the next iteration
            if (stops > k)
                continue;

            // Iterate over all the adjacent nodes (next destinations)
            for (auto iter : adj[node])
            {
                int adjNode = iter.first; // Next destination node
                int edW = iter.second;    // Cost of the flight to the next destination

                // If a shorter path to the adjacent node is found, update the distance
                if (cost + edW < dist[adjNode] && stops <= k)
                {
                    dist[adjNode] = cost + edW;                 // Update the distance
                    q.push({stops + 1, {adjNode, cost + edW}}); // Push the new node with updated stops and cost
                }
            }
        }

        // If destination node is unreachable, return -1
        if (dist[dst] == 1e9)
            return -1;

        return dist[dst]; // Return the minimum cost to reach the destination
    }
};

int main()
{

    return 0;
}