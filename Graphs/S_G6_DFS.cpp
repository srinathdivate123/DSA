// This code will work for unidirected, bidirected graphs also
// SC = N for visited array + N for storing the answer + N for the recursion stack space at the worst case when the nodes are connected together like train coaches are connected. So it's 3N in worst case!
// TC = The dfs function is called for every node so it is N
// The dfs function is also called for every neighbour node which is equal to 2*Edges.
// So TC = N + 2*E
// TC is not N*2*E

#include <bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int> &visited, vector<int> &ans, vector<vector<int>> &adj);

vector<int> dfsParentFunction(int numberOfNodes, vector<vector<int>> &adj, int startDFSFrom)
{
    vector<int> visited(numberOfNodes, 0);
    vector<int> ans;
    dfs(startDFSFrom, visited, ans, adj);
    return ans;
}

// Using recursion to trace back the way to the parent node
// This makes sure that all the children node are iterated first and then the neighbour nodes are iterated
// The below DFS only works for connected components. If there are disconnected components, then we have to run a for loop from 0 to N (all nodes) and call the dfs function for every unvisited node: https://www.geeksforgeeks.org/dsa/depth-first-search-or-dfs-for-a-graph/

void dfs(int node, vector<int> &visited, vector<int> &ans, vector<vector<int>> &adj)
{
    visited[node] = 1;
    ans.push_back(node);
    for (auto it : adj[node]) // Traverse all its degrees (neighbours)
        if (!visited[it])
            dfs(it, visited, ans, adj);
    return; // Writing this return isn't necessary
}

void addEdge(vector<vector<int>> &adj, int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector<int> &ans)
{
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}

int main()
{
    int n = 11;
    vector<vector<int>> adj(n);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 5);
    addEdge(adj, 2, 6);
    addEdge(adj, 3, 4);
    addEdge(adj, 3, 7);
    addEdge(adj, 4, 8);
    addEdge(adj, 7, 8);

    vector<int> ans = dfsParentFunction(n, adj, 1);
    printAns(ans);
    return 0;
}