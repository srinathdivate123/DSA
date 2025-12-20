// The cycle in a graph starts from a node and ends at the same node.
// We say that the graph has a cycle if any of the components (may be connected or not connected) have a cycle.

// SC = N (for recursion stack space at worst case if all nodes are connected like coaches of train) + N (for visited array)
// TC = N + 2E (for DFS) + N (the for loop in the isCycle function)

#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    bool dfs(int node, int parent, vector<int> vis, vector<int> adj[])
    {
        vis[node] = 1;
        for (auto adjacentNode : adj[node])
        {
            if (!vis[adjacentNode])
            {
                // If this returns a false then it's fine. We do DFS for the next neighbours
                if (dfs(adjacentNode, node, vis, adj))
                {
                    return true;
                }
            }
            // IMP CONDITION: If adjacent node is visited and it's not your own parent node
            // Let's say you have a graph like 5-6-7
            // And the cycle is at 7. So when you come to 6 then you check that you have 2 neighbours (5 & 7). Now 5 has been visited because it is your parent and you yourself have come from 5. Let's say 7 has been visited by someone else.
            // When you check that 7 has already been visited AND it is not your parent (5 here) then you can conclude that there is a cycle
            // Can't write more understanding here. Refer BFS video at https://youtu.be/BPlrALf1LDU?t=212
            else if (adjacentNode != parent)
            {
                // yes it is a cycle
                return true;
            }
        }
        return false;
    }

public:
    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, -1, vis, adj) == true)
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