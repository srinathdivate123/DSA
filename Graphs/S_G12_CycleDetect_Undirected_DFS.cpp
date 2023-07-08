#include <bits/stdc++.h>
using namespace std;
// SC = N (for recursion stack space at worst case if all nodes are connected like coaches of train) + N (for visited array)
// TC = N + 2E (for DFS) + N (the for loop in the isCycle function)
class Solution
{
private:
    bool dfs(int node, int parent, vector<int> vis, vector<int> adj[])
    {
        vis[node] = 1;
        for (auto adjacentNode : adj[node])
        {
            if (vis[adjacentNode] == 0)
            {
                if (dfs(adjacentNode, node, vis, adj) == true) // If this returns a false then it's fine. We do DFS for the next neighbours
                    return true;
            }
            if (vis[adjacentNode] == 1 && adjacentNode != parent)
                return true;
        }
        return false;
    }

public:
    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++)
            if (!vis[i])
                if (dfs(i, -1, vis, adj) == true)
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