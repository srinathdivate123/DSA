// https://takeuforward.org/data-structure/kruskals-algorithm-minimum-spanning-tree-g-47ddd

// TC: O(N + E) + O(E log E) + O(E * 4α * 2), where N = number of nodes and E = number of edges. O(N + E) for extracting edge information from the adjacency list. O(E log E) for sorting the array consisting of the edge tuples. Finally, we are using disjoint set operations inside a loop. The loop will continue for E times. Inside that loop, there are two disjoint set operations like findUPar() and UnionBySize(), each taking 4, so it will result in 4 * 2. That is why the last term O(E * 4 * 2) is added.

// SC: O(N) + O(N) + O(E) , where E = number of edges and N = number of nodes. O(E) space is taken by the array that we are using to store the edge information. In the disjoint set data structure, we are using two N-sized arrays (i.e., a parent and a size array, as we are using unionBySize() function; otherwise, a rank array of the same size if unionByRank() is used), which result in the first two terms O(N).

#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    // Function to find ultimate parent
    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    // Function to implement union by rank
    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    // Function to implement union by size
    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{
public:
    int minSpanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int, pair<int, int>>> edges;

        // Getting all edges from adjacency list
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                int u = i;      // Node u
                int v = it[0];  // Node v
                int wt = it[1]; // Edge weight
                edges.push_back({wt, {u, v}});
            }
        }

        DisjointSet ds(V);

        // Sorting the edges based on their weights
        sort(edges.begin(), edges.end());

        // To store the sum of edges in MST
        int sum = 0;

        // Iterate on the edges (which are stored in ascending order of weights)
        for (auto it : edges)
        {
            int wt = it.first;        // Edge weight
            int u = it.second.first;  // First node
            int v = it.second.second; // Second node

            // Join the nodes if not in the same component
            if (ds.findUPar(u) != ds.findUPar(v))
            {
                // Update the sum of edges in MST
                sum += wt;

                // Unite the nodes
                ds.unionBySize(u, v);
            }
        }
        return sum;
    }
};

int main()
{
    int V = 4;
    vector<vector<int>> edges = {
        {0, 1, 1},
        {1, 2, 2},
        {2, 3, 3},
        {0, 3, 4}};

    // Forming the adjacency list from edges
    vector<vector<int>> adj[4];
    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    // Creating instance of Solution class
    Solution sol;

    /* Function call to get the sum
    of weights of edges in MST */
    int ans = sol.minSpanningTree(V, adj);

    cout << "The sum of weights of edges in MST is: " << ans;

    return 0;
}