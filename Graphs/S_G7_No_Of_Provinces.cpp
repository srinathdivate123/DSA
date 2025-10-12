// https://leetcode.com/problems/number-of-provinces/
// https://takeuforward.org/data-structure/number-of-provinces/

// There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

// A province is a group of directly or indirectly connected cities and no other cities outside of the group.

// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

// Return the total number of provinces.

#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void dfs(int node, vector<vector<int>> adj, vector<int> &vis)
    {
        vis[node] = 1;
        for (auto it : adj[node])
            if (!vis[it])
                dfs(it, adj, vis);
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int V = isConnected.size();
        vector<vector<int>> adj;

        // Making adjacency list out of adjacency matrix.
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                // We put i!=j so that there are no self-nodes in our adjacency list. Self nodes are those nodes that are connected with themselves
                if (isConnected[i][j] == 1 && i != j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        // Basically count hwo many times the multi-source DFS/BFS runs
        vector<int> vis(V, 0);
        int cnt = 0;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                cnt++;
                dfs(i, adj, vis);
            }
        }
        return cnt;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> isConnected = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}};
    std::cout << obj.findCircleNum(isConnected);
}