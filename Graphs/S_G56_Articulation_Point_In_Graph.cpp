// https://takeuforward.org/data-structure/articulation-point-in-graph-g-56

// articulation points are nodes whose removal splits the graph into more components

// Here the definition of timeOfInsertion is same but the definition of lowestTimeOfInsertion is a bit different

// Time of insertion: Also called as step of insertion or discovery time. It is the DFS step at which the node is in visited. Like in step 1, the parent is visited. In step 2, one of parent's neighbour is visited. In step 3, one of the neighbour's neighbour is visited.

// Lowest time of insertion: Minimum time of insertion of all the adjacent nodes apart from the parent & visited nodes

// Watch video for more explanation

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int globalTimer = 1;

    // DFS to find articulation points
    void dfs(int node, int parent, vector<int> &vis, vector<int> &timeOfInsertion, vector<int> &lowestTimeOfInsertion, vector<int> &mark, vector<vector<int>> adj)
    {
        vis[node] = 1;
        timeOfInsertion[node] = lowestTimeOfInsertion[node] = globalTimer++;
        int child = 0;

        for (auto it : adj[node])
        {
            if (it == parent)
                continue; // skip the edge to parent

            if (!vis[it])
            {
                dfs(it, node, vis, timeOfInsertion, lowestTimeOfInsertion, mark, adj);                     // recursive DFS
                lowestTimeOfInsertion[node] = min(lowestTimeOfInsertion[node], lowestTimeOfInsertion[it]); // update lowestTimeOfInsertion

                // Check articulation condition (excluding root)
                if (lowestTimeOfInsertion[it] >= timeOfInsertion[node] && parent != -1)
                {
                    mark[node] = 1;
                }
                // Note that child++ is done only if the node is unvisited
                child++;
            }
            else
            {
                // back edge case
                lowestTimeOfInsertion[node] = min(lowestTimeOfInsertion[node], timeOfInsertion[it]);
            }
        }

        // If root node has more than one child
        if (parent == -1 && child > 1)
        {
            mark[node] = 1;
        }
    }

public:
    vector<int> articulationPoints(int n, vector<vector<int>> adj)
    {
        vector<int> vis(n, 0), mark(n, 0);
        vector<int> timeOfInsertion(n), lowestTimeOfInsertion(n);

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i, -1, vis, timeOfInsertion, lowestTimeOfInsertion, mark, adj);
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (mark[i])
            {
                ans.push_back(i);
            }
        }
        return ans.empty() ? vector<int>{-1} : ans;
    }
};

int main()
{
    int n = 5;
    vector<vector<int>> edges = {
        {0, 1}, {1, 4}, {2, 4}, {2, 3}, {3, 4}};

    vector<vector<int>> adj(n);
    for (auto e : edges)
    {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    Solution sol;
    vector<int> res = sol.articulationPoints(n, adj);
    for (int v : res)
        cout << v << " ";
    cout << endl;
    return 0;
}
