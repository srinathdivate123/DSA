#include <bits/stdc++.h>
using namespace std;

int matrixMultiplication(vector<int> &arr, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));

    // Initialize the diagonal elements of the DP table to 0. This is the minimum cost to multiply the matrix i with itself.
    for (int i = 1; i < n; i++)
        dp[i][i] = 0;

    // Loop for the length of the chain
    for (int i = n - 1; i >= 1; i--)
        for (int j = i + 1; j < n; j++)
        {
            int mini = 1e9;

            // Try different partition points to find the minimum
            for (int k = i; k < j; k++)
            {
                int cost = (arr[i - 1] * arr[k] * arr[j]) + dp[i][k] + dp[k + 1][j];
                mini = min(mini, cost);
            }
            dp[i][j] = mini;
        }

    return dp[1][n - 1];
}

int main()
{
    vector<int> arr = {10, 20, 30, 40, 50};
    int n = arr.size();
    cout << matrixMultiplication(arr, n) << endl;
    return 0;
}