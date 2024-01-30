#include <bits/stdc++.h>
using namespace std;

// TC = SC = n*n
int tabulation(vector<int> arr, int n)
{
    // No need of base case as we're anyways assigining everything to 0.
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int ind = n - 1; ind >= 0; ind--)
        for (int prev_index = ind - 1; prev_index >= -1; prev_index--)
        {
            int notTake = 0 + dp[ind + 1][prev_index + 1];
            int take = 0;

            if (prev_index == -1 || arr[ind] > arr[prev_index])
                take = 1 + dp[ind + 1][ind + 1];

            dp[ind][prev_index + 1] = max(notTake, take);
        }
    return dp[0][0];
}

// TC = n*n, SC = 2n
int spaceOptimised(vector<int> arr, int n)
{

    vector<int> next(n + 1, 0), cur(n + 1, 0);

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev_index = ind - 1; prev_index >= -1; prev_index--)
        {
            int notTake = 0 + next[prev_index + 1];

            int take = 0;

            if (prev_index == -1 || arr[ind] > arr[prev_index])
                take = 1 + next[ind + 1];

            cur[prev_index + 1] = max(notTake, take);
        }
        next = cur;
    }
    return cur[0];
}

// In below dp[i] signifies the longest increasing subsequence "ending" at i. The final ans LIS will be the max of dp[0...n].
// TC = n*n, SC = n
// This solution will be required if you want to trace back the LIS.
int Different_Tabulation(vector<int> arr, int n)
{
    // We initialize all of them to 1 because the LIS upto that element will atleast be 1 (i.e. if only the element is counted in the LIS)
    vector<int> dp(n, 1);
    int maxi = 1;
    for (int ind = 0; ind < n; ind++)
    {
        for (int prev = 0; prev < ind; prev++)
            if (arr[prev] < arr[ind])
                dp[ind] = max(dp[ind], 1 + dp[prev]);
        maxi = max(maxi, dp[ind]);
    }
    return maxi;
}

// TC = n*n, SC = n
int Different_Tabulation_For_Printing(vector<int> arr, int n)
{
    vector<int> dp(n, 1), hash(n, 1);
    int maxi = 1;
    int lastIndex = 0;

    for (int ind = 0; ind < n; ind++)
    {
        hash[ind] = ind;
        for (int prev = 0; prev < ind; prev++)
        {
            if (arr[prev] < arr[ind] && 1 + dp[prev] > dp[ind])
            {
                dp[ind] = 1 + dp[prev];
                hash[ind] = prev;
            }
        }

        if (dp[ind] > maxi)
        {
            maxi = dp[ind];
            lastIndex = ind;
        }
    }
    vector<int> temp;
    temp.push_back(arr[lastIndex]);
    while (hash[lastIndex] != lastIndex)
    {
        lastIndex = hash[lastIndex];
        temp.push_back(arr[lastIndex]);
    }
    reverse(temp.begin(), temp.end());
    for (auto it : temp)
        cout << it << " ";
}

int main()
{
    vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = arr.size();

    cout << tabulation(arr, n) << endl;
    cout << spaceOptimised(arr, n) << endl;
    cout << Different_Tabulation(arr, n) << endl;
    cout << Different_Tabulation_For_Printing(arr, n) << endl;

    return 0;
}