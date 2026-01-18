// https://takeuforward.org/graph/strongly-connected-components-kosarajus-algorithm-g-54

// Time Complexity: O(V + E), since each node and edge is visited at most twice (once in the original graph, once in the transposed graph).

// Space Complexity: O(V + E), due to the adjacency list, visited array, and recursion stack.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Step 1: Perform dfs and store nodes in stack by finishing time
    void dfs_initial(int node, vector<int> &vis, vector<vector<int>> adj, stack<int> &st)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs_initial(it, vis, adj, st);
            }
        }
        // Push the node into stack after visiting all neighbors
        // The leaf node is the first to finish because it has no neighbours to call a DFS function for
        st.push(node);
    }

    // Step 3: Perform DFS on transposed graph
    void dfs_final(int node, vector<int> &vis, vector<vector<int>> adjT)
    {
        vis[node] = 1;
        for (auto it : adjT[node])
        {
            if (!vis[it])
            {
                dfs_final(it, vis, adjT);
            }
        }
    }

public:
    int kosaraju(int V, vector<vector<int>> adj)
    {
        vector<int> vis(V, 0);
        stack<int> st;

        // Step 1: Do DFS to fill stack with the nodes by their finishing times
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs_initial(i, vis, adj, st);
            }
        }

        // Step 2: Build the transpose graph
        vector<vector<int>> adjT(V);
        for (int i = 0; i < V; i++)
        {
            vis[i] = 0; // mark unvisited for further use
            for (auto it : adj[i])
            {
                adjT[it].push_back(i); // reverse edge
            }
        }

        // Step 3: Process stack to count SCCs
        int scc = 0;
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            if (!vis[node])
            {
                scc++;
                dfs_final(node, vis, adjT);
            }
        }
        return scc;
    }
};

int main()
{
    int n = 5;
    int edges[5][2] = {
        {1, 0}, {0, 2}, {2, 1}, {0, 3}, {3, 4}};

    vector<vector<int>> adj(n);
    for (int i = 0; i < 5; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
    }

    Solution obj;
    int ans = obj.kosaraju(n, adj);
    cout << "The number of strongly connected components is: " << ans << endl;
    return 0;
}
