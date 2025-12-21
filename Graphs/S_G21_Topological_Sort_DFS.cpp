// - Initialize a visited array to mark whether each vertex has been visited.
// - Create a stack to store vertices in their finishing order.
// - For each vertex, if it has not been visited, perform a DFS starting from it.
// - In DFS, mark the current vertex as visited.
// - For each neighbor of the current vertex, if unvisited, recursively call DFS on it.
// - After exploring all neighbors, push the current vertex onto the stack.
// - After DFS finishes for all vertices, pop all elements from the stack to get the topological ordering.

// The idea is that you reach the very end of the graph, get the last node and then put it into the stack, backtrack and put all the elements into the stack. Then pop the elements one by one!

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int node, vector<vector<int>> adj, vector<int> &vis, stack<int> &st)
    {
        vis[node] = 1;

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs(it, adj, vis, st);
            }
        }
        // When the node you're at, has no neighbours or has all of it's neighbours visited, then you push this node into the stack
        st.push(node);
    }

    vector<int> topoSort(int V, vector<vector<int>> adj)
    {
        vector<int> vis(V, 0);
        stack<int> st;

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, adj, vis, st);
            }
        }

        vector<int> ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};

int main()
{
    int V = 6, E = 6;

    vector<vector<int>> adj(V, vector<int>(E, 0));
    adj[5].push_back(0);
    adj[5].push_back(2);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    Solution obj;
    vector<int> res = obj.topoSort(V, adj);
    for (auto it : res)
    {
        cout << it << " ";
    }

    return 0;
}
