#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfs(int u, vector<vector<int>> &adj, vector<bool> &vis, vector<bool> &pathVis, vector<int> &order)
    {
        vis[u] = true;
        pathVis[u] = true;

        for (int v : adj[u])
        {
            if (!vis[v])
            {
                if (dfs(v, adj, vis, pathVis, order))
                {
                    return true;
                }
            }
            else if (pathVis[v])
            {
                return true;
            }
        }

        // Once you iterate through all the dependencies and reach the parent dependency, then you add it in the 'order'
        // This is added after you reach the bottom of the dependency tree (the root/parent dependency) and you add it first
        order.push_back(u);
        pathVis[u] = false;
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        for (auto &p : prerequisites)
        {
            adj[p[0]].push_back(p[1]);
        }

        vector<bool> vis(numCourses, false);
        vector<bool> pathVis(numCourses, false);
        vector<int> order;

        for (int i = 0; i < numCourses; i++)
        {
            if (!vis[i])
            {
                // If anytime you find that there is cyclic dependency, then you return
                // Because each course depends on each other so you cannot start any of the courses
                if (dfs(i, adj, vis, pathVis, order))
                {
                    return {};
                }
            }
        }
        return order;
    }
};

int main()
{
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    Solution obj;
    vector<int> ans = obj.findOrder(numCourses, prerequisites);
    for (auto it : ans)
    {
        cout << it << endl;
    }
    return 0;
}