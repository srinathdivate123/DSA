// https://takeuforward.org/data-structure/find-eventual-safe-states-dfs-g-20
// https://leetcode.com/problems/find-eventual-safe-states/description/

// A directed graph of V vertices and E edges is given in the form of an adjacency list adj. Each node of the graph is labeled with a distinct integer in the range 0 to V - 1.
// A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node.
// You have to return an array containing all the safe nodes of the graph. The safeNodes should be sorted in ascending order.

// If any path starting from a node leads to a cycle, that node is considered unsafe. Nodes directly in a cycle or leading into a cycle cannot be safe.

// Two types of nodes cannot be a cycle:
// 1) Any node which is a part of a cycle
// 2) Any node which is not directly in a cycle but leads to a cycle

// Apart from these, every node is a safe node

// This code requires very little modifications from G19. Our end goal is to find all nodes that are in a cycle or that lead to a cycle. All other nodes are safeNodes!

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfsCheck(int node, vector<vector<int>> &graph, vector<int> &vis, vector<int> &pathVis, vector<int> &checkSafeNodes)
    {
        vis[node] = 1;
        pathVis[node] = 1;
        checkSafeNodes[node] = 0;

        for (auto neighbour : graph[node])
        {
            if (!vis[neighbour])
            {
                if (dfsCheck(neighbour, graph, vis, pathVis, checkSafeNodes))
                {
                    // If there is a cycle, it will always break out over here
                    // So this node cannot be a safe node
                    checkSafeNodes[node] = 0;
                    return true;
                }
            }
            else if (pathVis[neighbour])
            {
                // If there is a cycle, it will always break out over here
                // So this node cannot be a safe node
                checkSafeNodes[node] = 0;
                return true;
            }
        }

        // If the DFS is successfully completed for a node then there is no cycle and it will come here. So we mark it safe
        checkSafeNodes[node] = 1;
        pathVis[node] = 0; // backtrack
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> vis(n, 0);             // To know if the node has ever been visited
        vector<int> pathVis(n, 0);         // To know if the node has been visited in this current traversal path
        vector<int> checkSafeNodes(n, 0);  // To know if the node is safe
        vector<int> safeNodesAnswer;       // To store the answer

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfsCheck(i, graph, vis, pathVis, checkSafeNodes);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (checkSafeNodes[i])
            {
                safeNodesAnswer.push_back(i);
            }
        }
        return safeNodesAnswer;
    }
};
int main()
{
    vector<vector<int>> adj = {
        {1}, {2}, {3}, {4, 5}, {6}, {6}, {7}, {}, {1, 9}, {10}, {8}, {9}};
    Solution obj;
    vector<int> safe = obj.eventualSafeNodes(adj);
    for (int node : safe)
        cout << node << " ";
    return 0;
}