// https://takeuforward.org/data-structure/most-stones-removed-with-same-row-or-column-dsu-g-53
// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

// On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

// A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

// Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.

// The below code is present on the TUF website and it is also the most optimal solution in the LeetCode Editorial
// Striver, however, presents a different approach which is there in the other file
// Read the LeetCode Editorial for further clarification

// The answer is going to be number of stones minus number of components. Because from each component you can take out all but one stone (refer LC Editorial)

// You can find the number of components by doing DFS also

#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

class DSU
{
public:
    unordered_map<int, int> parent;

    int find(int x)
    {
        if (parent.find(x) == parent.end())
            parent[x] = x;

        if (x != parent[x])
            parent[x] = find(parent[x]);

        return parent[x];
    }

    void unite(int x, int y)
    {
        parent[find(x)] = find(y);
    }
};

class Solution
{
public:
    int removeStones(vector<vector<int>> &stones)
    {
        DSU dsu;

        // Connect each stone's row and column (offset to avoid collision)
        for (auto &stone : stones)
        {
            dsu.unite(stone[0], stone[1] + 10001);
        }

        unordered_set<int> components;

        // Count unique connected components
        for (auto &stone : stones)
        {
            components.insert(dsu.find(stone[0]));
        }

        // Max stones removed = total stones - number of components
        return stones.size() - components.size();
    }
};

int main()
{
    vector<vector<int>> stones = {
        {0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}};

    Solution obj;
    cout << obj.removeStones(stones) << endl;
    return 0;
}
