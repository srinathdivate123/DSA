// The cycle in a graph starts from a node and ends at the same node.
// We say that the graph has a cycle if any of the components (may be connected or not connected) have a cycle.

// TC =
#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    bool detect(int source, vector<int> adj[], int vis[])
    {
        vis[source] = 1;
        queue<pair<int, int>> q;
        q.push({source, -1});
        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for (auto adjacentNode : adj[node])
            {
                if (!vis[adjacentNode])
                {
                    vis[adjacentNode] = 1;
                    q.push({adjacentNode, node});
                }
                else if (parent != adjacentNode)
                    return true;
            }
        }
        return false;
    }

public:
    bool isCycle(int V, vector<int> adj[]) // V is number of nodes
    {
        int vis[V] = {0};
        for (int i = 0; i < V; i++)
            if (!vis[i])
                if (detect(i, adj, vis) == true)
                    return true;
        return false;
    }
};
int main()
{
    vector<int> adj[8] = {
        {},
        {2, 3},
        {1, 5},
        {1, 4, 6},
        {3},
        {2, 7},
        {3, 7},
        {5, 6},
    };
    Solution obj;
    cout << obj.isCycle(7, adj); // 7 is number of nodes!
    return 0;
}