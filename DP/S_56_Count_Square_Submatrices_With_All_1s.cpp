// Given an n * m matrix of ones and zeros, return how many square submatrices have all ones.

#include <bits/stdc++.h>
using namespace std;

int countSquares(int n, int m, vector<vector<int>> &arr)
{
    vector<vector<int>> dp(n, vector<int>(m, 0));

    int sum = 0;
    // Copy the first row & column as it is
    for (int j = 0; j < m; j++)
    {
        dp[0][j] = arr[0][j];
        sum += arr[0][j];
    }
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = arr[i][0];
        sum += arr[i][0];
    }
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            if (arr[i][j] == 0)
                dp[i][j] = 0;
            else
            {
                dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1]));
                sum += dp[i][j];
            }
    return sum;
}

int main()
{

    vector<vector<int>> arr = {
        {0, 1, 1, 1}, {1, 1, 1, 1}, {0, 1, 1, 1}};
    int n = arr.size(), m = arr[0].size();
    cout << countSquares(n, m, arr);
    return 0;
}