// https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/
// https://takeuforward.org/data-structure/number-of-operations-to-make-network-connected-dsu-g-49

// There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

// You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

// Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

// There are no repeated connections. No two computers are connected by more than one cable.

// Note that you cannot add random cables to connect computers. You must use only those cables which are already used to connect existing computers.

// INTUITION: Find the number of extra edges availble in the graph, if you are going to do a UnionByRank and find that the ultimateParents of 2 nodes are same then it means that there is an extra edge available. Count these extra edges & also count the number of components

// If the number of edges are more or equal to the number of components, then the number of components is the answer. If not, then -1

// Time Complexity: O(N + M × α(N)), we visit every node and edge once to find number of components.
// Space Complexity: O(N), for storing parent and rank/size vector for DSU.

#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

class DSU
{
public:
    vector<int> parent, rank;

    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);

        // Initially, every node is its own parent
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    // Find with path compression
    int findUltimateParent(int x)
    {
        if (parent[x] == x)
        {
            return x;
        }
        return parent[x] = findUltimateParent(parent[x]);
    }

    // Union by rank
    void unionByRank(int x, int y)
    {
        int px = findUltimateParent(x);
        int py = findUltimateParent(y);

        if (px == py)
            return;

        if (rank[px] < rank[py])
            parent[px] = py;
        else if (rank[px] > rank[py])
            parent[py] = px;
        else
        {
            parent[py] = px;
            rank[px]++;
        }
    }
};

class Solution
{
public:
    // Function to find minimum operations to make the graph connected
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        DSU dsu(n);
        int extraAvailableEdges = 0;
        for (auto it : connections)
        {
            int u = it[0];
            int v = it[1];
            if (dsu.findUltimateParent(u) == dsu.findUltimateParent(v))
            {
                extraAvailableEdges++;
            }
            else
            {
                dsu.unionByRank(u, v);
            }
        }

        int components = 0;
        for (int i = 0; i < n; i++)
        {
            if (dsu.parent[i] == i)
            {
                components++;
            }
        }

        int ans = components - 1;

        if (extraAvailableEdges >= ans)
        {
            return ans;
        }
        return -1;
    }
};

// Driver code
int main()
{
    int n = 6;
    vector<vector<int>> connections = {{0, 1}, {0, 2}, {0, 3}, {2, 3}, {1, 4}};
    Solution sol;
    cout << sol.makeConnected(n, connections) << endl;
    return 0;
}
