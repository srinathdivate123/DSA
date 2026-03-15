// https://takeuforward.org/data-structure/set-matrix-zero
// https://leetcode.com/problems/set-matrix-zeroes/description/

// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
// You must do it in place.
// Only for the originally present zeroes in the matrix you have to mark the rows & columns as 0's and not for rows & columns of the newly marked zeroes!

#include <bits/stdc++.h>
using namespace std;
void printArray(int (*arr)[4]);
void printArray(int (*arr)[4])
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
            cout << arr[i][j] << " ";
        cout << std::endl;
    }
}

// While iterating through array if you find 0, then mark the 1's in its rows and columns as -1. Then while iterating through seond time, change all the -1's into 0's.
void brute() {}

// Create a 1D array of m-size named row and a 1D array of n-size named col and initialize them to 0's.
// While iterating in the 2D matrix if you come across a '0' in the (i, j) position then mark the i-th index in the m-size matrix and the j-th index in the n-size matrix as 1.
// Then re-iterate through 2D array and check that if in the col or row array it is marked as 1, then mark that element in the 2D array as 0.

// TC = n*m + n*m
// SC = n + m for declaring arrays
void better(int (*arr)[4], int m, int n) // Here 4 is the cols
{
    vector<int> rowSetZero(m, 0);
    vector<int> colSetZero(n, 0);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 0)
            {
                rowSetZero[i] = 1;
                colSetZero[j] = 1;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (rowSetZero[i] || colSetZero[j] == 1)
            {
                arr[i][j] = 0;
            }
        }
    }
}

// Instead of using separate arrays, we use the first row and first column of the matrix itself to store whether a row or column needs to be zeroed. We also store two flags:
// --> firstRowZero:Was the first row supposed to be all zero?
// --> firstColZero:Was the first column supposed to be all zero?
// Then:
// --> First pass: Mark zeros in the first row and column for any zero found in the rest of the matrix.
// --> Second pass: Use those markers to set rows and columns to zero.
// Finally, handle the first row and column separately based on the flags. This is super space-efficient because we’re reusing the input matrix itself to store markers.
// --> Check if the first row has any zero and store in a boolean flag.
// --> Check if the first column has any zero and store in a boolean flag.
// --> Traverse the rest of the matrix:
// -----> If a cell is zero, mark its row in the first column and its column in the first row as zero.
// --> Traverse again (excluding first row and column), setting cells to zero if their row marker or column marker is zero.
// --> Finally, update the first row and first column based on the stored flags.
// SC = 1 variable i.e. col0
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int m, int n)
{
    // int col[m] = {0}; here it is --> matrix[0][..]
    // int row[n] = {0}; here it is --> matrix[..][0]

    int col0 = 1;
    // step 1: Traverse the matrix and mark 1st row & col accordingly
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                // mark i-th row:
                matrix[i][0] = 0;

                // mark j-th column:
                if (j != 0)
                    matrix[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }

    // Step 2: Mark with 0 from (1, 1) to (n-1, m-1):
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (matrix[i][j] != 0)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                    // check for col & row:
                }
            }
        }
    }

    // step 3: Finally mark the 1st col & then 1st row:
    if (matrix[0][0] == 0)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[0][j] = 0;
        }
    }

    if (col0 == 0)
    {
        for (int i = 0; i < m; i++)
        {
            matrix[i][0] = 0;
        }
    }
    return matrix;
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> ans = zeroMatrix(matrix, m, n);

    cout << "The Final matrix is: \n";
    for (auto it : ans)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << "\n";
    }
    return 0;
}