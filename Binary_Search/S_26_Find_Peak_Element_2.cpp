/*
A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.

Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].

You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell. In other words, an element is always considered to be strictly greater than a neighbor that lies outside the array.

You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.
*/

#include <bits/stdc++.h>
using namespace std;

int indexOfMaxElementInColumn(vector<vector<int>> &mat, int n, int m, int col)
{
    int maxValue = -1;
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        if (mat[i][col] > maxValue)
        {
            maxValue = mat[i][col];
            index = i;
        }
    }
    return index;
}

// TC = log(m) * n
void best(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    int low = 0;      // Place at the first column
    int high = m - 1; // Place at the last column

    while (low <= high)
    {
        int mid = low - (low - high) / 2;
        int maxRowIndex = indexOfMaxElementInColumn(mat, n, m, mid);

        int left = mid - 1 >= 0 ? mat[maxRowIndex][mid - 1] : -1;
        int right = mid + 1 < m ? mat[maxRowIndex][mid + 1] : -1;

        if (mat[maxRowIndex][mid] > left && mat[maxRowIndex][mid] > right)
        {
            cout << maxRowIndex << " " << mid;
            break;
        }
        else if (mat[maxRowIndex][mid] < left)
            high = mid - 1;
        else
            low = mid + 1;
    }
}

int main()
{
    vector<vector<int>> mat = {
        {4, 2, 5, 1, 4, 5},
        {2, 9, 3, 2, 3, 2},
        {1, 7, 6, 0, 1, 3},
        {3, 6, 2, 3, 7, 2},
    };
    best(mat);
}