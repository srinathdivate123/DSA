// https://takeuforward.org/graph/bridges-in-graph-using-tarjans-algorithm-of-time-in-and-low-time-g-55
// https://leetcode.com/problems/critical-connections-in-a-network/description/

// There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

// A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

// Return all critical connections in the network in any order.

// Time of insertion: Also called as step of insertion or discovery time. It is the DFS step at which the node is in visited. Like in step 1, the parent is visited. In step 2, one of parent's neighbour is visited. In step 3, one of the neighbour's neighbour is visited.

// Lowest time of insertion: Minimum time of insertion of all the adjacent nodes apart from the parent

// Time Complexity: O(V+2E), where V = no. of vertices, E = no. of edges. It is because the algorithm is just a simple DFS traversal.

// Space Complexity: O(V+2E) + O(3V), where V = no. of vertices, E = no. of edges. O(V+2E) to store the graph in an adjacency list and O(3V) for the three arrays i.e. timeOfInsertion, lowestTimeOfInsertion, and vis, each of size V.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int globalTimer = 1; // Global timer to assign discovery times

    void dfs(int node, int parent, vector<int> &vis, vector<vector<int>> &adj, vector<int> &timeOfInsertion, vector<int> &lowestTimeOfInsertion, vector<vector<int>> &bridges)
    {
        vis[node] = 1;                                                     // Mark current node as visited
        timeOfInsertion[node] = lowestTimeOfInsertion[node] = globalTimer; // Set discovery time and low-link value
        globalTimer++;

        for (auto it : adj[node])
        {
            if (it == parent)
                continue; // Skip the edge to parent

            if (!vis[it])
            {
                // If neighbor is unvisited, recurse it
                dfs(it, node, vis, adj, timeOfInsertion, lowestTimeOfInsertion, bridges);

                // Update lowestTimeOfInsertion of min of current node (it) and parent node (node)
                lowestTimeOfInsertion[node] = min(lowestTimeOfInsertion[node], lowestTimeOfInsertion[it]);

                // Check if the edge is a bridge
                // Can this node---it be a bridge ?
                if (lowestTimeOfInsertion[it] > timeOfInsertion[node])
                {
                    bridges.push_back({it, node});
                }
            }
            else
            {
                // Bridge is not possible because you had already visited it and now you are visiting it again
                // Back edge: update lowestTimeOfInsertion value
                lowestTimeOfInsertion[node] = min(lowestTimeOfInsertion[node], lowestTimeOfInsertion[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<vector<int>> adj(n);
        for (auto it : connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(n, 0);
        vector<int> timeOfInsertion(n, 0);       // Discovery time
        vector<int> lowestTimeOfInsertion(n, 0); // Lowest reachable time
        vector<vector<int>> bridges;

        // Run DFS (assuming graph is connected)
        dfs(0, -1, vis, adj, timeOfInsertion, lowestTimeOfInsertion, bridges);

        return bridges;
    }
};

int main()
{
    int n = 4;
    vector<vector<int>> connections = {
        {0, 1}, {1, 2}, {2, 0}, {1, 3}};

    Solution obj;
    vector<vector<int>> bridges = obj.criticalConnections(n, connections);

    cout << "Critical Connections (Bridges): " << endl;
    for (auto it : bridges)
    {
        cout << it[0] << " -> " << it[1] << endl;
    }
    return 0;
}
