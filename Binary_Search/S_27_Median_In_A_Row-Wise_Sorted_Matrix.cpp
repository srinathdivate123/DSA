// https://leetcode.com/problems/median-of-a-row-wise-sorted-matrix/description/
// The above is leetcode premium :(

// Given a row-wise sorted matrix of size m x n, where m is no. of rows and n is no. of columns, find the median in the given matrix. Both n and m are odd.
// The first element of a particular row may not necessarily be smaller then the last element of the previous row.

#include <bits/stdc++.h>
using namespace std;

// The upperbound will always point to the first element greater than x
// TC = log(m)
int upperBound(vector<int> &arr, int x, int n)
{
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] > x)
        {
            ans = mid;
            // look for smaller index on the left
            high = mid - 1;
        }
        else
        {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

// TC = n
int countSmallEqual(vector<vector<int>> &matrix, int m, int n, int x)
{
    int cnt = 0;
    // Iterate through all the rows
    for (int i = 0; i < m; i++)
    {
        cnt += upperBound(matrix[i], x, n);
    }
    return cnt;
}

// Total TC = log(10^9) * n * log(m)
// The smallest number in the matrix can be as small as 1
// The largest number in the matrix can be as large as 10^9
int median(vector<vector<int>> &matrix, int m, int n)
{
    int low = INT_MAX, high = INT_MIN;

    // point low and high to right elements:
    for (int i = 0; i < m; i++)
    {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][n - 1]);
    }

    int req = (n * m) / 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int smallEqual = countSmallEqual(matrix, m, n, mid);
        if (smallEqual <= req)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3, 4, 5},
        {8, 9, 11, 12, 13},
        {21, 23, 25, 27, 29}};
    int m = matrix.size(), n = matrix[0].size();
    cout << "The median element is: " << median(matrix, m, n);
}