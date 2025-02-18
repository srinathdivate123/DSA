// Given an m*n 2D matrix and an integer, write a program to find if the given integer exists in the matrix.
// Integers in each row are sorted from left to right
// The first integer of each row is greater than the last integer of the previous row

#include <bits/stdc++.h>
using namespace std;

// TC = O(N + log(M))
// First search in which row the target may lie. Then perform binary search on that row
bool brute(vector<vector<int>> matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int low = 0, high = n - 1;

    // Outer for loop is to search for which row we should apply the binary search
    for (int i = 0; i < n; i++)
        if (matrix[i][0] <= target && target <= matrix[i][m - 1])
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
    return false;
}

// Perform binary search on that 2D array by hypothetically-flattening it to 1D array
// TC = O(log(n*m))
// SC = O(1)
bool best(vector<vector<int>> matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int low = 0;
    int high = m * n - 1;

    if (matrix.size() == 0)
        return false;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int row = mid / n;
        int col = mid % n;

        if (matrix[row][col] == target)
            return true;
        else if (matrix[row][col] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

int main()
{
    vector<vector<int>> arr = {
        {3, 4, 7, 9},
        {12, 13, 16, 18},
        {20, 21, 23, 29}};
    cout << brute(arr, 23) << endl;
    cout << best(arr, 23) << endl;
    return 0;
}