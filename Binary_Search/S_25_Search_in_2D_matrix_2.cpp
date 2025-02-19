/*
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

    - Integers in each row are sorted in ascending from left to right.
    - Integers in each column are sorted in ascending from top to bottom.
    - But, the first element of a row is not necessarily greater than the last element of the previous row
*/

#include <bits/stdc++.h>
using namespace std;

// Perform binary search on each row of the array
// TC = O(N*log(M))
bool better(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < n; i++)
    {
        int low = 0, high = m - 1;

        // Perform binary search on the row
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (matrix[i][mid] == target)
                return true;
            else if (target > matrix[i][mid])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return false;
}

// TC = O(n + m)
bool best(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();

    // Currently standing at top right of matrix, as the elements towards left will be decreasing and the elements below will be increasing. So you can some to know which half to eliminate.
    // You can stand at bottom left also. Then elements on top will be decreasing & elements on right will be increasing.
    // You can't stand at top left or bottom right, as the elements will be either both increasing or both decreasing.
    int row = 0, col = m - 1;

    while (row < n && col >= 0)
    {
        if(matrix[row][col] == target)
            return true;
        else if( matrix[row][col] < target)
            row++;
        else
            col--;
    }
    return false;
}

// Brute is to search each element in the matrix
int main()
{
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15},
                                  {2, 5, 8, 12, 19},
                                  {3, 6, 9, 16, 22},
                                  {10, 13, 14, 17, 24},
                                  {18, 21, 23, 26, 30}};
    cout << better(matrix, 14) << endl;
}