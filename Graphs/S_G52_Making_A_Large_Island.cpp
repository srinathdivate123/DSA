// https://takeuforward.org/data-structure/making-a-large-island-dsu-g-52
// https://leetcode.com/problems/making-a-large-island/description/

// You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.
// Return the size of the largest island in grid after applying this operation.
// An island is a 4-directionally connected group of 1s.

#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
public:
    vector<int> parent, size;

    DisjointSet(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

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
private:
    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, 1, 0, -1};

    bool isValid(int &i, int &j, int &n)
    {
        if (i < 0 || i >= n || j < 0 || j >= n)
            return false;
        return true;
    }

    // Function to add initial islands to the disjoint set data structure
    void addInitialIslands_ToDisjointSet(vector<vector<int>> grid, DisjointSet &ds, int n)
    {
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (grid[row][col] == 0)
                    continue;

                for (int ind = 0; ind < 4; ind++)
                {
                    int newRow = row + delRow[ind];
                    int newCol = col + delCol[ind];

                    if (isValid(newRow, newCol, n) && grid[newRow][newCol] == 1)
                    {
                        int nodeNo = row * n + col;
                        int adjNodeNo = newRow * n + newCol;

                        // Take union of both nodes as they are part of the same island
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }
    }

public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        DisjointSet ds(n * n);
        addInitialIslands_ToDisjointSet(grid, ds, n);

        int ans = 0;

        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (grid[row][col] == 1)
                    continue;

                // Set to store the ultimate parents of neighboring islands
                // To avoid double counting an island, we store the ultimate parents of neighboring islands in a set to ensure each island is counted once
                // Because a 0 could be surrounded by 1's on all sides that belong to teh same component. In that case we don't want to count them multiple times
                set<int> components;

                for (int ind = 0; ind < 4; ind++)
                {

                    int newRow = row + delRow[ind];
                    int newCol = col + delCol[ind];

                    if (isValid(newRow, newCol, n) && grid[newRow][newCol] == 1)
                    {
                        // Perform union and store ultimate parent in the set
                        int nodeNumber = newRow * n + newCol;
                        components.insert(ds.findUPar(nodeNumber));
                    }
                }

                // To store the size of current largest island formed by turning the current 0 to 1
                int sizeTotal = 0;

                // Iterate on all the neighbor's
                for (auto it : components)
                {
                    // Update the size
                    sizeTotal += ds.size[it];
                }
                ans = max(ans, sizeTotal + 1);
            }
        }

        // Edge case: If all the cells are only 1's
        for (int cellNo = 0; cellNo < n * n; cellNo++)
        {
            // Keep the answer updated
            int ultimateParent = ds.findUPar(cellNo);
            ans = max(ans, ds.size[ultimateParent]);
        }

        return ans;
    }
};

int main()
{
    vector<vector<int>> grid = {
        {1, 0},
        {0, 1}};

    Solution sol;

    cout << sol.largestIsland(grid);

    return 0;
}