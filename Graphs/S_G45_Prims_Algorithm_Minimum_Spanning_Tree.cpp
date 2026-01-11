// https://takeuforward.org/data-structure/prims-algorithm-minimum-spanning-tree-c-and-java-g-45

// Refer above for notes

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSpanningTree(int V, vector<vector<vector<int>>> &adj, vector<pair<int, int>> &mstEdges)
    {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        vector<int> vis(V, 0);
        // {wt, {node, parentNode}}
        pq.push({0, {0, -1}}); // Start from node 0

        int sum = 0;
        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int wt = it.first;
            int node = it.second.first;
            int parent = it.second.second;

            // If it is already a part of the MST, then continue
            if (vis[node] == 1)
            {
                continue;
            }
            
            // add it to the MST
            vis[node] = 1;
            sum += wt;

            if (parent != -1)
            {
                mstEdges.push_back({parent, node});
            }

            for (auto it : adj[node])
            {
                int adjNode = it[0];
                int edW = it[1];
                if (!vis[adjNode])
                {
                    pq.push({edW, {adjNode, node}});
                }
            }
        }
        return sum;
    }
};

int main()
{
    int V = 5;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
    vector<vector<vector<int>>> adj(V);
    vector<pair<int, int>> mstEdges;
    for (auto it : edges)
    {
        vector<int> tmp(2);
        tmp[0] = it[1];
        tmp[1] = it[2];
        adj[it[0]].push_back(tmp);

        tmp[0] = it[0];
        tmp[1] = it[2];
        adj[it[1]].push_back(tmp);
    }

    Solution obj;
    cout << obj.minSpanningTree(V, adj, mstEdges) << endl;
    for (auto it : mstEdges)
    {
        cout << it.first << " --> " << it.second << endl;
    }
    return 0;
}
