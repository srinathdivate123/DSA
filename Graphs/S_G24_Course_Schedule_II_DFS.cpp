// This code is not there on TUF
// https://leetcode.com/problems/course-schedule-ii/description/

// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

// The idea is to find the parent/root/origin dependency using DFS
// Traverse deeper and deeper until you find it, then backtrack and add all the other dependencies in reverse way
// This will give you the order of courses you can take
// If you find any circular dependency, then you won't be able to start any course at all because each course in the circe depends on any one of the others'

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

        // If there is no cycle, then it will come here
        // Once you iterate through all the dependencies and reach the parent dependency (without any cycles), then you add it in the 'order'
        // This is added after you reach the bottom of the dependency tree (the root/parent dependency) and this root becomes the first in the answer because it is the first course you need to take!
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
                // If anytime you find that there is cyclic dependency, then you return true
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