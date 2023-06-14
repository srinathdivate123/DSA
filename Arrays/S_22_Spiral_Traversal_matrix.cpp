#include <bits/stdc++.h>
using namespace std;
// Given a Matrix, print the given matrix in spiral order.
// This soln has only one soln and that is the optimal soln
// Traverse in right -> bottom -> left -> top direction

// TC = N*N
// SC = N*N
void best(vector<vector<int>> arr)
{
    int n = arr.size();    // no. of nows
    int m = arr[0].size(); // no. of columns
    int left = 0, right = m - 1;
    int top = 0, bottom = n - 1;
    vector<int> ans;

    while (top <= bottom && left <= right)
    {
        // From left to right keping top constant
        for (int i = left; i <= right; i++)
            ans.push_back(arr[top][i]);
        top++;

        // From top till bottom keeping right constant
        for (int i = top; i <= bottom; i++)
            ans.push_back(arr[i][right]);
        right--;

        // From right to left keeping bottm constant
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
                ans.push_back(arr[bottom][i]);
            bottom--;
        }

        // From bottom to top keping left constant
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
                ans.push_back(arr[i][left]);
            left++;
        }
    }

    for (auto element : ans)
        cout << element << " ";
}

int main()
{
    vector<vector<int>> arr =
        {
            {1, 2, 3, 4, 5, 6},
            {20, 21, 22, 23, 24, 7},
            {19, 32, 33, 34, 25, 8},
            {18, 31, 36, 35, 26, 9},
            {17, 30, 29, 28, 27, 10},
            {16, 15, 14, 13, 12, 11},
        };

    best(arr);
    return 0;
}