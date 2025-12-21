// Here we have to use topological sort for which we need to have atlease one node whose indegree is 0.
// We have to find the safeNodes (i.e. nodes which have an outdegree of 0)
// So we actually reverse the graph connections and startoff with the node which no has indegree of 0 after reversing it

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find all eventual safe nodes in a directed graph
    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        vector<vector<int>> adjRev(V, vector<int>(V, 0)); // Reverse adjacency list
        vector<int> indegree(V, 0);                       // Indegree array to track nodes with no outgoing edges

        // Build the reverse graph and calculate indegrees
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                adjRev[it].push_back(i); // Reverse the direction of edges
                indegree[i]++;           // Increment indegree for the current node
            }
        }

        queue<int> q; // Queue to store nodes with no outgoing edges (safe nodes)
        vector<int> safeNodes;

        // Add all nodes with 0 indegree to the queue
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        // Process the queue to find all safe nodes
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node); // This node is safe as it has indegree of 0 (originally, it had outdegree of 0 before reversing)
            for (auto it : adjRev[node])
            {
                indegree[it]--; // Decrease indegree of the parent nodes
                if (indegree[it] == 0)
                {
                    q.push(it); // If indegree becomes 0, it is a safe node
                }
            }
        }

        sort(safeNodes.begin(), safeNodes.end()); // Sort the safe nodes
        return safeNodes;
    }
};

int main()
{
    // Adjacency list representation of the graph
    vector<int> adj[12] = {{1}, {2}, {3, 4}, {4, 5}, {6}, {6}, {7}, {}, {1, 9}, {10}, {8}, {9}};
    int V = 12; // Number of nodes in the graph

    Solution obj;
    vector<int> safeNodes = obj.eventualSafeNodes(V, adj);

    for (auto node : safeNodes)
    {
        cout << node << " "; // Print the safe nodes
    }
    cout << endl;

    return 0;
}
