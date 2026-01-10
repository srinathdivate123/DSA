// https://takeuforward.org/data-structure/floyd-warshall-algorithm-g-42

// Given a graph of V vertices numbered from 0 to V-1. Find the shortest distances between every pair of vertices in a given edge-weighted directed graph. The graph is represented as an adjacency matrix of size n x n. Matrix[i][j] denotes the weight of the edge from i to j. If matrix[i][j]=-1, it means there is no edge from i to j.

// Refer to TUF for notes

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void shortest_distance(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        // Find path through each intermediate node k
        for (int viaNode = 0; viaNode < n; viaNode++)
        {
            // Check for every (i, j) pair of nodes
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    matrix[i][j] = min(matrix[i][j], matrix[i][viaNode] + matrix[viaNode][j]);
                }
            }
        }
    }
};

int main()
{

    vector<vector<int>> matrix = {
        {0, 2, -1, -1},
        {1, 0, 3, -1},
        {-1, -1, 0, -1},
        {3, 5, 4, 0}};

    Solution sol;
    sol.shortest_distance(matrix);

    int n = matrix.size();
    cout << "The shortest distance matrix is:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}