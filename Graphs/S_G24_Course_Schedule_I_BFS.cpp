// If anytime you find that there is a cyclic dependency in the nodes, then you will not be able to complete the courses.
// This cyclic dependency can be inferred when the count of nodes you've processed is less than the nodes in the graph (numCourses)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);

        // Fill adjacency and in-degree
        for (auto &pre : prerequisites)
        {
            int a = pre[0], b = pre[1];
            adj[b].push_back(a);
            inDegree[a]++;
        }

        // Initialize queue with zero in-degree nodes
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        // Count processed nodes
        int count = 0;

        // Process queue
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;

            // Reduce in-degree of neighbors
            for (int it : adj[node])
            {
                inDegree[it]--;
                if (inDegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }

        // Return true if all nodes processed
        return count == numCourses;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};
    int numCourses = 2;
    cout << sol.canFinish(numCourses, prerequisites);
    return 0;
}
