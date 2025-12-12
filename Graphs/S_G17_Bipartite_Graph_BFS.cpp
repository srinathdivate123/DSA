// https://leetcode.com/problems/is-graph-bipartite/description/
// Also refer: 
// - https://www.geeksforgeeks.org/dsa/m-coloring-problem/
// - https://leetcode.com/problems/painting-a-grid-with-three-different-colors/description/

// TC = N + 2E
// SC = 2N : Queue, colour array

// Start BFS from any uncolored vertex and assign it color 0.
// For each vertex, color its uncolored neighbors with the opposite color (1 if current is 0, and vice versa)
// Check if a neighbor already has the same color as the current vertex, return false (graph is not bipartite).
// If BFS completes without any conflicts, return true (graph is bipartite).

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool colorGraph(int start, int edges, vector<vector<int>> graph, vector<int> colour)
    {
        queue<int> q;
        q.push(start);
        colour[start] = 0;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (int neighbour : graph[node])
            {
                // If the adjacent node is not yet coloured
                // You will give the opposite colour of the current node to it
                if (colour[neighbour] == -1)
                {
                    colour[neighbour] = !colour[node];
                    q.push(neighbour);
                }
                // If the adjacent node has the same colour as the current node
                // Then someone else had coloured it previously
                else if (colour[neighbour] == colour[node])
                {
                    return false;
                }
            }
        }
        return true;
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
                if (!colorGraph(i, m, graph, colour))
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