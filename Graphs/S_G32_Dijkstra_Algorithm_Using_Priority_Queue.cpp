// https://takeuforward.org/data-structure/dijkstras-algorithm-using-set-g-33

// Given a weighted, undirected, and connected graph of V vertices and E edges, find the shortest distance of all the vertex's from the source vertex S.

// Note: The Graph doesn't contain any negative weight cycle.

// TC: O((V+E)logV), each edge is relaxed at most once, and for each relaxation we may push into the priority queue, giving O(E) pushes with O(log V) heap operations.

// SC: O(V+E), additonal space is used to store adjacency list, distance array and priority queue.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<pair<int, int>>> &adj, int src)
    {
        vector<int> dist(V, 1e9);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Distance to source is 0
        dist[src] = 0;

        // Push source into heap
        pq.push({0, src}); // Format is {dist, node}

        // Process nodes until heap is empty
        while (!pq.empty())
        {
            // Extract node with minimum distance which is on top of the PQ
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // If the popped distance is greater than the stored distance, skip it (we have already processed this node in the past and had found a shorter distance, so there's no point in processing the neighbours of this node again)
            if (dis > dist[node])
            {
                continue;
            }

            // Traverse all adjacent neighbors
            for (auto neighbour : adj[node])
            {
                int adjNode = neighbour.first;
                int edgeWeight = neighbour.second;

                // Relaxation check
                if (dis + edgeWeight < dist[adjNode])
                {
                    // Update distance
                    dist[adjNode] = dis + edgeWeight;

                    // Push updated distance into heap
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};

int main()
{
    // Number of vertices
    int V = 5;
    int sourceNode = 0;

    // Adjacency list {neighbor, weight}
    vector<vector<pair<int, int>>> adj(V);

    adj[0].push_back({1, 2});
    adj[0].push_back({2, 4});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 7});
    adj[2].push_back({4, 3});
    adj[3].push_back({4, 2});

    Solution obj;
    vector<int> dist = obj.dijkstra(V, adj, sourceNode);

    for (int i = 0; i < V; i++)
    {
        cout << "Distance from 0 to " << i << " = " << dist[i] << endl;
    }
}
