// https://takeuforward.org/data-structure/disjoint-set-union-by-rank-union-by-size-path-compression-g-46

// Notes are long so refer TUF

// Time Complexity:  The actual time complexity is O(4*alpha) which is very small and close to 1. So, we can consider 4 as a constant.

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
        // Everyone is their initial parent
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
        // In the above, the 'parent[node] = ' does the so called path compression and makes sure that in the future whenever we call it for another node that we've already traversed, then we can just find it by a lookup on the parent array!
        // No need to call the findUltimateParent() for that node again
    }
    void unionByRank(int u, int v)
    {
        int ultimateParent_u = findUltimateParent(u);
        int ultimateParent_v = findUltimateParent(v);

        // The whole purpose of this function is to merge the two nodes or form a union of them
        // But if you find that they are already belonging to the same component, then there is no need to merge them at all because they are already a part of the same component
        if (ultimateParent_u == ultimateParent_v)
        {
            return;
        }

        // Merging happens by rank
        // In the below you're seeing that we're merging the smaller to larger
        // For explanation see: https://youtu.be/aBxjDBC4M1U?t=1949
        // OR: https://takeuforward.org/data-structure/disjoint-set-union-by-rank-union-by-size-path-compression-g-46#:~:text=as%20a%20constant.-,Follow%2Dup%20question%3A,-In%20the%20union

        // If u < v, attach u to v
        // We do not need to increase the rank of v by 1 because it is already the 'GREATER' one
        if (rank[ultimateParent_u] < rank[ultimateParent_v])
        {
            parent[ultimateParent_u] = ultimateParent_v;
        }
        // If v < u, attach v to u
        // We do not need to increase the rank of u by 1 because it is already the 'GREATER' one
        else if (rank[ultimateParent_v] < rank[ultimateParent_u])
        {
            parent[ultimateParent_v] = ultimateParent_u;
        }
        // If both are equal, then you can either attach u to v OR v to u
        // But you need to increase the rank of it, because you have attached a same ranked graph to it
        // In below, we've chosen to attach v to u, hence increase the rank of u by 1
        else
        {
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