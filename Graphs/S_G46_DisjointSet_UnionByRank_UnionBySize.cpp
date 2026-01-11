// https://takeuforward.org/data-structure/disjoint-set-union-by-rank-union-by-size-path-compression-g-46

#include <bits/stdc++.h>
using namespace std;
class DisJointSet
{
    vector<int> rank, parent;

public:
    DisJointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUltimateParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findUltimateParent(parent[node]);
        // In the above, the 'parent[node] = ' does the path compression and makes sure that in the future whenever we call it for another node that we've already traversed, then we can just find it by a lookup
        // No need to call the findUltimateParent() for that node again
    }
    void unionByRank(int u, int v)
    {
        int ultimateParent_u = findUltimateParent(u);
        int ultimateParent_v = findUltimateParent(v);
        if (ultimateParent_u == ultimateParent_v)
        {
            return;
        }
        if (rank[ultimateParent_u] < rank[ultimateParent_v])
        {
            parent[ultimateParent_u] = ultimateParent_v;
        }
        else if (rank[ultimateParent_u] > rank[ultimateParent_v])
        {
            parent[ultimateParent_v] = ultimateParent_u;
        }
        else
        {
            // You can either attach u to v or v to u
            // Here we've chosen to attaach v to u
            parent[ultimateParent_v] = ultimateParent_u;
            rank[ultimateParent_u]++;
        }
    }
};
int main()
{
    DisJointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);

    if (ds.findUltimateParent(3) == ds.findUltimateParent(7))
        cout << "Same\n";
    else
        cout << "Not same\n";

    ds.unionByRank(3, 7);

    if (ds.findUltimateParent(3) == ds.findUltimateParent(7))
        cout << "Same\n";
    else
        cout << "Not same\n";

    return 0;
}