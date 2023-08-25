// Given an m*n 2D matrix and an integer, write a program to find if the given integer exists in the matrix.
// Integers in each row are sorted from left to right
// The first integer of each row is greater than the last integer of the previous row
#include <bits/stdc++.h>
using namespace std;

bool func(vector<vector<int>> matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int low = 0;
    int high = m*n - 1;
    if(!matrix.size()) 
        return false;
    while(low <= high)
    {
        int mid = low + (low - high)/2;
        int row = mid / m;
        int col = mid % m;
        if(matrix[row][col] == target)
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
        {20, 21, 23, 29}
    };
    cout << func(arr, 23);
    return 0;
}