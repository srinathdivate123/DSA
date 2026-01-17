// https://www.lintcode.com/problem/434/
// https://leetcode.com/problems/number-of-islands-ii/description/ (PREMIUM)
// https://takeuforward.org/graph/number-of-islands-ii-online-queries-dsu-g-51

// You are given an n, m which means the row and column of the 2D matrix, and an array of size k denoting the number of operations. Matrix elements are 0 if there is water or 1 if there is land. Originally, the 2D matrix is all 0 which means there is no land in the matrix. The array has k operator(s) and each operator has two integers A[i][0], A[i][1] means that you can change the cell matrix[A[i][0]][A[i][1]] from sea to island. Return how many islands are there in the matrix after each operation. You need to return an array of size k.

// Note: An island means a group of 1s such that they share a common side.

// This problem is called an online queries problem where the graph changes after each query so we need to use DisjointSet. The graph is a dynamic graph

// The below solution by Striver used Disjoint Set

#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUltimatePar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUltimatePar(parent[node]); // Path compression
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUltimatePar(u);
        int ulp_v = findUltimatePar(v);
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

    void unionBySize(int u, int v)
    {
        int ulp_u = findUltimatePar(u);
        int ulp_v = findUltimatePar(v);
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
    bool isValid(int adjr, int adjc, int n, int m)
    {
        return adjr >= 0 && adjr < n && adjc >= 0 && adjc < m;
    }

public:
    // Main function to process all operators and count number of islands
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
    {
        DisjointSet ds(n * m); // Disjoint set to manage connected land cells
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        vector<int> ans;

        for (auto it : operators)
        {
            int row = it[0];
            int col = it[1];

            // Skip if the cell is already land, because it will not make a difference as it'd have already been computed earlier
            // This condition will happen true if you have duplicate queries
            if (vis[row][col] == 1)
            {
                ans.push_back(cnt);
                continue;
            }

            // Mark cell as land
            vis[row][col] = 1;
            // Initially count it as an individual island, then decrease the count if you find that it is a part of a larger island
            cnt++;

            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};
            for (int ind = 0; ind < 4; ind++)
            {
                int adjr = row + dr[ind];
                int adjc = col + dc[ind];
                if (isValid(adjr, adjc, n, m))
                {
                    if (vis[adjr][adjc] == 1)
                    {
                        int nodeNo = row * m + col;
                        int adjNodeNo = adjr * m + adjc;

                        if (ds.findUltimatePar(nodeNo) != ds.findUltimatePar(adjNodeNo))
                        {
                            // If you find that you & your neighbour have different ultimate parents then you need to connect with your neighbour
                            // Reduce count because you have merged this current node with it's neighbour
                            // So the current node is no longer a individual island
                            cnt--;
                            ds.unionBySize(nodeNo, adjNodeNo);
                        }
                        else
                        {
                            // Do nothing
                            // No need to connect because you are already connected (have the same ultimate parent)
                            // No need to reduce -1 because you have already reduced it in the above if (but with a different neighbour who has the same ultimate parent)
                            // You're coming here itself means that you had earlier come in contact with this graph but with a different neighbour and so you had connected yourself with this graph
                        }
                    }
                    else
                    {
                        // If it is not an island, then do not do anything
                    }
                }
            }

            ans.push_back(cnt);
        }
        return ans;
    }
};

int main()
{
    int n = 4, m = 5;
    vector<vector<int>> operators = {{0, 0}, {0, 0}, {1, 1}, {1, 0}, {0, 1}, {0, 3}, {1, 3}, {0, 4}, {3, 2}, {2, 2}, {1, 2}, {0, 2}};

    Solution obj;
    vector<int> ans = obj.numOfIslands(n, m, operators);
    for (auto res : ans)
    {
        cout << res << " ";
    }
    cout << endl;
    return 0;
}
