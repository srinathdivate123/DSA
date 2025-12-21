#include <bits/stdc++.h>
using namespace std;

// - Prepare a list to store the topological order and create an array to track the in-degree (number of incoming edges) of each node.
// - Traverse each node and update the in-degree of its neighbors based on the adjacency list representation of the graph.
// - Initialize a queue and add all nodes with zero in-degree to it. These nodes have no dependencies and can be processed first.
// - Use a loop to process nodes from the queue until it is empty:
//      -> Remove a node from the front of the queue and add it to the topological order list.
//      -> For each neighbor of the removed node, reduce its in-degree by one.
//      -> If a neighbor's in-degree becomes zero, meaning all its parent nodes have been processed, add it to the queue.
// - After processing all nodes, the topological order list will contain a valid topological sorting of the graph.

class Solution
{
public:
    vector<int> topoSort(int V, vector<vector<int>> adj)
    {
        vector<int> ans;
        vector<int> inDegree(V, 0);

        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                inDegree[it]++;
            }
        }

        queue<int> q;

        // Add the nodes with no in-degree to queue
        for (int i = 0; i < V; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        // Start processing the nodes which have an indegree of 1
        while (!q.empty())
        {
            int node = q.front();

            // Nodes that have an inDegree==0 can be immediately put into the answer as they do not have any other nodes going into them!
            ans.push_back(node);
            q.pop();

            for (auto it : adj[node])
            {
                // 'node' is in your answer, so please remove it from indegree of 'it'
                inDegree[it]--;
                
                // Add the it to queue if its in-degree becomes zero
                if (inDegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        return ans;
    }
};

int main()
{

    int V = 6;
    vector<vector<int>> adj = {
        {},
        {},
        {3},
        {1},
        {0, 1},
        {0, 2}};

    /* Creating an instance of
    Solution class */
    Solution sol;

    /* Function call to return the
    topological sorting of given graph */
    vector<int> ans = sol.topoSort(V, adj);

    // Output
    cout << "The topological sorting of the given graph is: \n";
    for (int i = 0; i < V; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}