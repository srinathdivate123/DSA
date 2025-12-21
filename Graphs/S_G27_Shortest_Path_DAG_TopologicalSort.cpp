// https://takeuforward.org/data-structure/shortest-path-in-directed-acyclic-graph-topological-sort-g-27

// Given a Directed Acyclic Graph of N vertices from 0 to N-1 and M edges and a 2D Integer array edges, where there is a directed edge from vertex edge[i][0] to vertex edge[i][1] with a distance of edge[i][2] for all i.
// Find the shortest path from source vertex to all the vertices and if it is impossible to reach any vertex, then return -1 for that vertex. The source vertex is assumed to be 0.

// -------------------------------------------------

// Finding the shortest path to a vertex is easy if you already know the shortest paths to all the vertices that can precede it. Processing the vertices in topological order ensures that by the time you get to a vertex, you've already processed all the vertices that can precede it which reduces the computation time significantly. In this approach, we traverse the nodes sequentially according to their reachability from the source.

// Dijkstra's algorithm is necessary for graphs that can contain cycles because they can't be topologically sorted. In other cases, the topological sort would work fine as we start from the first node, and then move on to the others in a directed manner.

// We will calculate the shortest path in a directed acyclic graph by using topological sort. Topological sort can be implemented in two ways- BFS and DFS. Here, we will be implementing using the DFS technique. Depth First Search, DFS is a traversal technique where we visit a node and then continue visiting its adjacent nodes until we reach the end point, i.e., it keeps on moving in the depth of a particular node and then backtracks when no further adjacent nodes are available.

// -------------------------------------------------

// The shortest path in a directed acyclic graph can be calculated by the following steps:
// => Perform topological sort on the graph using BFS/DFS and store it in a stack.
// => Now, iterate on the topo sort. We can keep the generated topo sort in the stack only, and do an iteration on it, it reduces the extra space which would have been required to store it. Make sure for the source node, we will assign dist[src] = 0.
// => For every node that comes out of the stack, we can traverse for all its adjacent nodes, and relax them.
// => In order to relax them, we simply do a simple comparison of dist[node] + wt and dist[adjNode]. Here dist[node] means the distance taken to reach the current node, and it is the edge weight between the node and the adjNode.
// => If (dist[node] + wt < dist[adjNode]), then we will go ahead and update the distance of the dist[adjNode] to the new found better path.
// => Once all the nodes have been iterated, the dist[] array will store the shortest paths and we can then return it.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void topoSort(int node, vector<vector<pair<int, int>>> adj, vector<int> vis, stack<int> &st)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            int v = it.first;
            if (!vis[v])
            {
                topoSort(v, adj, vis, st);
            }
        }
        st.push(node);
    }

public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        vector<vector<pair<int, int>>> adj(N);
        for (int i = 0; i < M; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            // Store (target node, weight)
            adj[u].push_back({v, wt});
        }

        vector<int> vis(N, 0);
        stack<int> st;

        for (int i = 0; i < N; i++)
        {
            if (!vis[i])
            {
                topoSort(i, adj, vis, st);
            }
        }

        // Initialize the distance vector with infinity
        vector<int> dist(N, 1e9);

        dist[0] = 0;

        while (!st.empty())
        {
            int node = st.top();
            st.pop();

            // Relax all outgoing edges from the current node
            for (auto it : adj[node])
            {
                int v = it.first;
                int wt = it.second;

                // Update distance if a shorter path is found
                dist[v] = min(dist[v], dist[node] + wt);
            }
        }

        // Replace all unreachable nodes' distances with -1
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
    int N = 6, M = 7;
    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 4, 1},
        {4, 5, 4},
        {4, 2, 2},
        {1, 2, 3},
        {2, 3, 6},
        {5, 3, 1}};
    Solution obj;

    vector<int> ans = obj.shortestPath(N, M, edges);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
