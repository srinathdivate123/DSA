// https://leetcode.com/problems/number-of-provinces/
// Problem Statement: Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v or v to u. Your task is to find the number of provinces.

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
            for (int j = 0; j < V; j++)
                if (isConnected[i][j] == 1 && i != j) // We put i!=j so that there are no self-nodes in our adjacency list. Self nodes are those nodes that are connected with themselves
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
        vector<int> vis(V, 0);
        int cnt = 0;
        for (int i = 0; i < V; i++)
            if (!vis[i])
            {
                cnt++;
                dfs(i, adj, vis);
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