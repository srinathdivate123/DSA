// https://takeuforward.org/data-structure/detect-cycle-in-an-undirected-graph-using-bfs

// The cycle in a graph starts from a node and ends at the same node.
// We say that the graph has a cycle if any of the components (may be connected or not connected) have a cycle.

// TC = N + 2E (for BFS) + N (for the for loop in isCycle())
// SC = N (for visited array) + N (for queue in worst case)
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool detect_the_BFS_way(int start, vector<int> adj[], vector<int> vis)
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
                if (!vis[adjacentNode])
                {
                    vis[adjacentNode] = 1;
                    q.push({adjacentNode, node});
                }
                // IMP CONDITION: If adjacent node is visited and it's not your own parent node
                // Let's say you have a graph like 5-6-7
                // And the cycle is at 7. So when you come to 6 then you check that you have 2 neighbours (5 & 7). Now 5 has been visited because it is your parent and you yourself have come from 5. Let's say 7 has been visited by someone else.
                // When you check that 7 has already been visited AND it is not your parent (5 here) then you can conclude that there is a cycle
                // Can't write more understanding here. Refer video at https://youtu.be/BPlrALf1LDU?t=212
                else if (adjacentNode != parent)
                {
                    // yes it is a cycle
                    return true;
                }
            }
        }
        return false;
    }

public:
    bool isCycle(int V, vector<int> adj[]) // V is number of nodes
    {
        vector<int> vis(V, 0);
        // For multi-source BFS
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (detect_the_BFS_way(i, adj, vis))
                {
                    return true;
                }
            }
        }
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