// https://takeuforward.org/data-structure/rotate-image-by-90-degree
// https://leetcode.com/problems/rotate-image/description/

// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

#include <bits/stdc++.h>
using namespace std;

void reverseArray(vector<vector<int>> &arr);
void printArray(vector<vector<int>> &arr);
void printArray(vector<vector<int>> &arr)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        for (int j = 0; j < arr.size(); ++j)
            cout << arr[i][j] << " ";
        cout << std::endl;
    }
}

// TC = N*N
// SC = N*N
void brute(int (*arr)[4])
{
    int ans[4][4];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            ans[j][4 - 1 - i] = arr[i][j];
        }
    }
}

// Step 1: Transpose the matrix
// Step 2: Reverse each row
void best(vector<vector<int>> &arr)
{
    // Transpose
    // TC = (N/2)*(N/2)  {N/2 for each of the loops}
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }

    // Reverse every row
    // TC = N*(N/2)  {N for traversing the first for loop and N/2 for reversing the array using two pointer approach}
    reverseArray(arr);
    printArray(arr);
}

void reverseArray(vector<vector<int>> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[i][n - j - 1];
            arr[i][n - j - 1] = temp;
        }
    }
}

int main()
{
    vector<vector<int>> arr = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};
    best(arr);
    return 0;
}