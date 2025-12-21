// After using the Kahn's algorithm, if you find that the toposort gives less than V vertices then it means that there was a cycle somewhere in the graph!

// This happens if the queue has no more elements to process and it's size becomes zero, but more unprocessed elements are actually remaining in the graph.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isCyclic(int V, vector<vector<int>> &adj)
    {
        vector<int> indegree(V, 0);

        // Calculate indegree of each node
        for (int i = 0; i < V; i++)
        {
            for (auto &nbr : adj[i])
            {
                indegree[nbr]++;
            }
        }

        // Initialize queue with all nodes having 0 indegree
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        // Counter to track number of processed nodes
        int count = 0;

        // Perform BFS using Kahn's algorithm
        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            // Increment processed node count
            count++;

            // Reduce indegree of neighbors
            for (auto &nbr : adj[node])
            {
                indegree[nbr]--;

                // If indegree becomes 0, push it to the queue
                if (indegree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }

        // If processed node count is not equal to total nodes, a cycle exists
        return count != V;
    }
};

int main()
{
    int V = 4;

    vector<vector<int>> adj = {
        {1}, {2}, {3}, {1}};

    Solution sol;

    cout << (sol.isCyclic(V, adj) ? "Graph contains a cycle" : "No cycle") << endl;

    return 0;
}
