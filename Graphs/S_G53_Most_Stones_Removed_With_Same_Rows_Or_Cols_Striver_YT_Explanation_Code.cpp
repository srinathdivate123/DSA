// https://takeuforward.org/data-structure/most-stones-removed-with-same-row-or-column-dsu-g-53
// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

// On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

// A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

// Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.

// The below code is as Striver explains in his YT video (https://youtu.be/OwMNX8SPavM)
// It is less optimal but more intuitive
// Read the LeetCode Editorial for further clarification

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

// The answer is going to be number of stones minus number of components. Because from each component you can take out all but one stone (refer LC Editorial)
class Solution
{
public:
    int removeStones(vector<vector<int>> &stones, int n)
    {
        // We don't have the input as a adjacency matrix, rather we have the [i, j] of all the stones. Hence we need to find the size of the matrix on which these stones are placed
        // In this way we can figure out the dimension of the grid on which the stones are placed

        int maxRow = 0;
        int maxCol = 0;
        for (auto it : stones)
        {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        // You are using ds to only to account for the number of rows & cols because every stone in that row & every stone in that col will be removed
        // We are considering the whole row as a node and also the whole column as a node
        // All stones on a particular row will be attached to that row node
        // Similarly all stones on a particular col will be attached to that col node
        // If we have a 5x4 matrix then the rows will be indexed [0, 1, 2, 3, 4] & cols will be indexed [5, 6, 7, 8]
        DisjointSet ds(maxRow + maxCol + 1); // +1 for 1-based indexing and for a backup

        // We use map to store the unique rows and unique cols on which the stones are placed
        // If in a row or col there are multiple stones, map will only store the unique rows & cols
        unordered_map<int, int> uniqueNodes;

        for (auto it : stones)
        {
            int stoneRow = it[0];
            int stoneCol = it[1] + maxRow + 1;
            // Combine stoneRow and stoneCol (equivalent to combining all stones on stoneRow and stoneCol)
            ds.unionBySize(stoneRow, stoneCol);
            uniqueNodes[stoneRow] = 1;
            uniqueNodes[stoneCol] = 1;
        }

        int numComponents = 0;
        for (auto it : uniqueNodes)
        {
            // Note that we are not using it.second at all as we're concerned only with the unique rows & cols (it.first) and not the '1' which indicates just the presence of the row & col
            if (ds.findUPar(it.first) == it.first)
            {
                numComponents++;
            }
        }
        return n - numComponents;
    }
};
int main()
{
    vector<vector<int>> stones = {
        {0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}};

    Solution obj;
    cout << obj.removeStones(stones, 6) << endl;
    return 0;
    return 0;
}