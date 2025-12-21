// This code is not there on TUF
// https://leetcode.com/problems/course-schedule/description/

// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses. Otherwise, return false

// The idea is to find the parent/root/origin dependency using DFS
// Traverse deeper and deeper until you find it, then backtrack and add all the other dependencies in reverse way
// This will give you the order of courses you can take
// If you find any circular dependency, then you won't be able to start any course at all because each course in the circe depends on any one of the others'

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfs(int u, vector<vector<int>> &adj, vector<bool> &vis, vector<bool> &pathVis)
    {
        vis[u] = true;
        pathVis[u] = true;

        for (int v : adj[u])
        {
            if (!vis[v])
            {
                if (dfs(v, adj, vis, pathVis))
                {
                    // If anytime you find that there is cyclic dependency, then you return true
                    // Because each course depends on each other so you cannot start any of the courses
                    return true;
                }
            }
            else if (pathVis[v])
            {
                // If anytime you find that there is cyclic dependency, then you return true
                // Because each course depends on each other so you cannot start any of the courses
                return true;
            }
        }

        pathVis[u] = false;
        return false;
    }

    bool findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        for (auto &p : prerequisites)
        {
            adj[p[0]].push_back(p[1]);
        }

        vector<bool> vis(numCourses, false);
        vector<bool> pathVis(numCourses, false);

        for (int i = 0; i < numCourses; i++)
        {
            if (!vis[i])
            {
                // If anytime you find that there is cyclic dependency, then you return true
                // Because each course depends on each other so you cannot start any of the courses
                if (dfs(i, adj, vis, pathVis))
                {
                    return false;
                }
            }
        }
    }
};

int main()
{
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    Solution obj;
    cout << obj.findOrder(numCourses, prerequisites);

    return 0;
}