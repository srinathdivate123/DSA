// The cycle in a graph starts from a node and ends at the same node.
// We say that the graph has a cycle if any of the components (may be connected or not connected) have a cycle.

// TC = N + 2E (for BFS) + N (for the for loop in isCycle())
// SC = N (for visited array) + N (for queue in worst case)
#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    bool detect_the_BFS_way(int start, vector<int> adj[], int vis[])
    {
        vis[start] = 1;
        queue<pair<int, int>> q; // To store node, source from where it came
        q.push({start, -1});     // Store -1 because start came from nowhere
        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for (auto adjacentNode : adj[node])
            {
                if (vis[adjacentNode] == 0)
                {
                    vis[adjacentNode] = 1;
                    q.push({adjacentNode, node});
                }
                if (vis[adjacentNode] == 1 && parent != adjacentNode)
                    return true;
            }
        }
        return false;
    }

public:
    bool isCycle(int V, vector<int> adj[]) // V is number of nodes
    {
        int vis[V] = {0};
        // We write like this if the graph has many non-connected components and one of them may be a cycle and some of them may not be a cycle
        for (int i = 0; i < V; i++)
            if (!vis[i])
                if (detect_the_BFS_way(i, adj, vis))
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