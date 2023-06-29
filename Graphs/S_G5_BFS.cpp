// This code will work for unidirected, bidirected graphs also
#include <bits/stdc++.h>
#include <typeinfo>
using namespace std;

// SC = Queue, visited array ~ 2N SC
// TC = A node goes once into the queue and the while loop runs for all it's degrees (for all the nodes connected to it)
// So it is N for queue because each node (total N) goes into it
// And it is 2E for running on all the degrees of all the nodes because the total num of degrees in a graph is 2E
// So TC = N + 2E
vector<int> bfs(int numberOfNodes, vector<int> adj[], int startBFSFrom)
{
    int visited[numberOfNodes] = {0};
    queue<int> q;
    vector<int> ans;
    visited[startBFSFrom] = 1; // Mark the starting node as visited
    q.push(startBFSFrom);      // push the initial starting node from where you want to start BFS
    while (!q.empty())
    {
        // get the topmost element in the queue
        int node = q.front();
        q.pop();
        ans.push_back(node);
        // traverse for all its neighbours
        for (auto it : adj[node])
            // if the neighbour has previously not been visited,
            // store in q and mark as visited
            if (!visited[it])
            {
                visited[it] = 1;
                q.push(it);
            }
    }
    return ans;
}

void addEdge(vector<int> adj[], int u, int v)
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
    vector<int> adj[10]; // declaring an array named adj consisting of 10 elements (because there are nodes upto number 9), where each element is a vector<int>.
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 6);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 6, 7);
    addEdge(adj, 6, 9);
    addEdge(adj, 4, 5);
    addEdge(adj, 7, 8);
    addEdge(adj, 5, 8);

    vector<int> ans = bfs(10, adj, 1);
    printAns(ans);
    return 0;
}