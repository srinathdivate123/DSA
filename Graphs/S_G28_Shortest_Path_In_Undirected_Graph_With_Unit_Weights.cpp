// Given an Undirected Graph having unit weight, find the shortest path from the source to all other nodes in this graph. In this problem statement, we have assumed the source vertex to be ‘0’. If a vertex is unreachable from the source node, then return -1 for that vertex.

// Perform BFS traversal starting from the source.
// For each node in the queue, check its neighbors.
// If the path to a neighbor through the current node is shorter (i.e., current distance + 1 < neighbor's recorded distance), update the neighbor's distance and push it to the queue

// Why BFS is used:
// -> All edges have unit weight. So as we explore adjacent nodes, they are at a fixed increment of distance (1, 2, 3…).
// -> This behavior naturally fits BFS because the queue automatically ensures we’re processing closer nodes first.
// -> BFS acts like a sorted queue for level-wise distances, so we don’t need extra data structures like a min-heap (unlike Dijkstra).

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
    {
        vector<vector<int>> adj(N);

        for (auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> dist(N, 1e9);

        dist[src] = 0;
        queue<int> q;
        q.push(src);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto it : adj[node])
            {

                if (dist[node] + 1 < dist[it])
                {
                    dist[it] = 1 + dist[node];
                    q.push(it);
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            if (dist[i] == 1e9)
            {
                dist[i] = -1;
            }
        }

        return dist;
    }
};

int main()
{
    int N = 9, M = 10;

    vector<vector<int>> edges = {
        {0, 1}, {0, 3}, {3, 4}, {4, 5}, {5, 6}, {1, 2}, {2, 6}, {6, 7}, {7, 8}, {6, 8}};

    Solution obj;

    vector<int> ans = obj.shortestPath(edges, N, M, 0);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
