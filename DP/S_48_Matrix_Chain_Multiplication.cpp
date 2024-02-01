// Given a chain of matrices A1,…, An denoted by an array of size n+1, find out the minimum number of operations to multiply these n matrices.

// Matrix A1 has dimensions arr[0]xarr[1]. Matrix A2 has dimensions arr[1]xarr[2] and Ai has arr[i-1]xarr[i]
#include <bits/stdc++.h>
using namespace std;

// TC = n*n*n - There are N*N states and we explicitly run a loop inside the function which will run for N times, therefore at max ‘N*N*N’ new problems will be solved.
// SC = n*n + n
int f(vector<int> &arr, int i, int j, vector<vector<int>>& dp)
{
    if (i == j) // Multiplying a matrix with itself takes 0 operations. (We're not speaking about A1*A1 here. We're speaking about having only A1 here.)
        return 0;

    if(dp[i][j]!=-1)
        return dp[i][j];

    int mini = INT_MAX;

    // partioning loop
    for (int k = i; k <= j - 1; k++)
    {
        int steps = (arr[i - 1] * arr[k] * arr[j]) + f(arr, i, k, dp) + f(arr, k + 1, j, dp);
        mini = min(mini, steps);
    }

    return dp[i][j] =  mini;
}

int main()
{
    vector<int> arr = {10, 20, 30, 40, 50};
    int n = arr.size();
    int i = 1;
    int j = n - 1;
    vector<vector<int>> dp(n,vector<int>(n,-1));

    cout << f(arr, i, j, dp);
    return 0;
}