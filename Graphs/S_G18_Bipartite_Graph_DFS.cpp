// https://leetcode.com/problems/is-graph-bipartite/description/
// Also refer: 
// - https://www.geeksforgeeks.org/dsa/m-coloring-problem/
// - https://leetcode.com/problems/painting-a-grid-with-three-different-colors/description/

// • Bi-Partite Graph: A graph is said to be bi-partite if you can colour the graph with 2 colours, such that no adjacent nodes have the same colour
// • Linear Graphs with no cycles are always bipartite
// • Any graph with an even cycle length can also be bipartite
// Any graph with odd cycle length can never be bipartite

// TC and SC same as DFS

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool dfs(int node, int col, vector<int> colour, vector<vector<int>> adj)
    {
        colour[node] = col;
        for (auto neighbour : adj[node])
        {
            if (colour[neighbour] == -1)
            {
                if (!dfs(neighbour, !col, colour, adj))
                {
                    return false;
                }
                else if (colour[neighbour] == col)
                {
                    return false;
                }
            }
        }
    }

public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int m = graph.size();
        vector<int> colour(m, -1);
        for (int i = 0; i < m; i++)
        {
            if (colour[i] == -1)
            {
                if (!dfs(i, 0, colour, graph))
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{

    return 0;
}