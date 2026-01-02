// https://takeuforward.org/data-structure/g-35-print-shortest-path-dijkstras-algorithm
// https://leetcode.com/discuss/post/6125318/shortest-path-in-weighted-undirected-gra-hpoa/

// You are given a weighted undirected graph having n+1 vertices numbered from 0 to n and m edges describing there are edges between a to b with some weight, find the shortest path between the vertex 1 and the vertex n, and if the path does not exist then return a list consisting of only -1.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        vector<vector<pair<int, int>>> adj(n + 1);
        // This is undirected graph
        for (auto it : edges)
        {
            adj[it[0]].push_back({it[1], it[2]}); // Edge from 1 to 2 with weight
            adj[it[1]].push_back({it[0], it[2]}); // Edge from 2 to 1 with weight
        }

        // Create a priority queue to store {distance, node} and retrieve the node with the minimum distance
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Distance array to store shortest distances from the source node and parent array to track the path
        vector<int> dist(n + 1, 1e9), parent(n + 1);

        // Initialize the parent array to track the path from the source
        // Each node is initialized as its own parent
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }

        dist[1] = 0; // The distance from the source node to itself is 0

        // Push the source node (node 1) with distance 0 into the priority queue
        pq.push({0, 1});

        while (!pq.empty())
        {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();

            // If the popped distance is greater than the stored distance, skip it (we have already processed this node in the past and had found a shorter distance, so there's no point in processing the neighbours of this node again)
            if (dis > dist[node])
            {
                continue;
            }

            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int edW = it.second;

                // If the new computed distance is smaller, update the distance and parent
                if (dis + edW < dist[adjNode])
                {
                    dist[adjNode] = dis + edW;
                    pq.push({dis + edW, adjNode});

                    // Now since you have got a minimum weight path, you need to store the parent node after coming from which you got this minimum weight path
                    // Basically you need to store that from which parent node you have come to this current node so that you got this minimum path
                    parent[adjNode] = node;
                }
            }
        }

        // If you have not reached the destination node at all, return {-1}
        if (dist[n] == 1e9)
        {
            return {-1};
        }

        // Store the final path in the 'path' array by backtracking from the destination node
        vector<int> path;
        int node = n;                // start from the last nonde
        while (parent[node] != node) // Run until you do not reach such a node that parent[node] == node
        {
            path.push_back(node); // Add node to path
            node = parent[node];  // Move to the parent node (move one step up in the chain to the parent)
        }

        path.push_back(1); // Add the source node to the path

        // Reverse the path to get the correct order from source to destination
        reverse(path.begin(), path.end());
        return path;
    }
};

int main()
{
    int V = 5, E = 6;
    vector<vector<int>> edges = {{1, 2, 2}, {2, 5, 5}, {2, 3, 4}, {1, 4, 1}, {4, 3, 3}, {3, 5, 1}};

    Solution obj;
    vector<int> path = obj.shortestPath(V, E, edges);

    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i] << " ";
    }
    cout << endl;
    return 0;
}