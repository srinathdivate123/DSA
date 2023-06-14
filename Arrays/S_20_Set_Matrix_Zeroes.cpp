#include <bits/stdc++.h>
using namespace std;
void printArray(int (*arr)[4]);
void printArray(int (*arr)[4])
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            cout << arr[i][j] << " ";
        }
        cout << std::endl;
    }
}
// Given a 2D binary matrix of 0's and 1's, if an element in the matrix is 0 then you will have to set its entire column and row to 0 and then return the matrix.
// Only for the originally present zeroes in the matrix you hv to mark the rows & columns as 0's and not for rows & columns of the newly marked zeroes!

// While iterating through array if you find 0, then mark the 1's in its rows and columns as -1. Then while iterating through seond time, change all the -1's into 0's.
void brute() {}

// Create a 1D array of m-size named col and a 1D array of n-size named row and initialize them to 0's.
// While iterating in the 2D matrix if you come across a 0 in the (i, j) position then mark the i-th index in the m-size matrix and the j-th index in the n-size matrix as 1.
// Then re-iterate through 2D array and check that if in the col or row array it is marked as 1. If yes, then mark that element in the 2D array as 0.

// TC = n*m + n*m
// SC = n + m for declaring arrays
void better(int (*arr)[4], int m, int n) // Here 4 is the cols
{
    int col[m] = {0}, row[n] = {0};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (arr[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (row[i] || col[j] == 1)
                arr[i][j] = 0;
}

// See video or website for explanation
// SC = 1 variable i.e. col0
void best(int (*arr)[4], int n, int m) // Here 4 is the cols
{
    // int col[m] = {0}; -> here it is arr[0][..]
    // int row[n] = {0}; -> here it is arr[..][0]
    int col0 = 1;

    // TC = N*M
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (arr[i][j] == 0)
            {
                arr[i][0] = 0; // Mark the i-th row
                if (j != 0)
                    arr[0][j] = 0; // Mark the j-th row
                else
                    col0 = 0;
            }

    // TC of all below code summed up is N*M
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
        {
            if (arr[i][j] != 0)
            {
                // check for column and row
                if (arr[0][j] || arr[i][0] == 0)
                    arr[i][j] = 0;
            }
        }

    if (arr[0][0] == 0)
        for (int j = 0; j < m; j++)
            arr[0][j] = 0;

    if (col0 == 0)
        for (int i = 0; i < n; i++)
            arr[i][0] = 0;
    printArray(arr);
}



int main()
{
    int arr[4][4] = {
        {1, 1, 1, 1},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {0, 1, 1, 1}};
    best(arr, 4, 4);
    return 0;
}