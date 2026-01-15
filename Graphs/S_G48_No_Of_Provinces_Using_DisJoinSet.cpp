// https://leetcode.com/problems/number-of-provinces/

// This problem was earlier solved in (S_G7) using DFS. Here we'll solve it using DisJointSet. Unfortunately there is no TUF blog for this.

// The intuition is that there wil be as many provinces as many unique ultimateParents are there. Hence you need to find the number of unique ultimateParents

#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
public:
    vector<int> rank, parent, size;
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    // Function to find ultimate parent
    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    // Function to implement union by rank
    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    // Function to implement union by size
    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{
public:
    int numProvinces(vector<vector<int>> adj, int V)
    {
        DisjointSet ds(V);
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (adj[i][j] == 1)
                {
                    ds.unionBySize(i, j);
                }
            }
        }

        int cnt = 0;
        // Find the nodes who are themselves their parents (these are ultimateParents)
        for (int i = 0; i < V; i++)
        {
            if (ds.parent[i] == i)
            {
                cnt++;
            }
        }
        return cnt;
    }
};
int main()
{

    return 0;
}