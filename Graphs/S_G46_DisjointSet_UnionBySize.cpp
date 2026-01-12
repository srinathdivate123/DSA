// https://takeuforward.org/data-structure/disjoint-set-union-by-rank-union-by-size-path-compression-g-46

#include <bits/stdc++.h>
using namespace std;
class DisJointSet
{
    vector<int> size, parent;

public:
    DisJointSet(int n)
    {
        size.resize(n + 1, 1); // NOTE: size is initially 1
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

    void unionBySize(int u, int v)
    {
        int ultimateParent_u = findUltimateParent(u);
        int ultimateParent_v = findUltimateParent(v);

        if (ultimateParent_u == ultimateParent_v)
        {
            return;
        }

        if (size[ultimateParent_u] < size[ultimateParent_v])
        {
            parent[ultimateParent_u] = ultimateParent_v;
            size[ultimateParent_v] += size[ultimateParent_u]; // It's like you're attaching all the nodes of u to v, hence need to increment size[v] by size[u]
        }
        // If size[ultimateParent_u] > size[ultimateParent_v] then you attach v to u
        // If size[ultimateParent_u] == size[ultimateParent_v] then it doesn't matter whom you attach to. Here we choose to attach v to u
        else
        {
            parent[ultimateParent_v] = ultimateParent_u;
            size[ultimateParent_u] += size[ultimateParent_v]; // It's like you're attaching all the nodes of v to u, hence need to increment size[u] by size[v]
        }
    }
};
int main()
{
    DisJointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);

    if (ds.findUltimateParent(3) == ds.findUltimateParent(7))
        cout << "Same\n";
    else
        cout << "Not same\n";

    ds.unionBySize(3, 7);

    if (ds.findUltimateParent(3) == ds.findUltimateParent(7))
        cout << "Same\n";
    else
        cout << "Not same\n";

    return 0;
}