// We are given a target sum of target and N distinct numbers denoting the coin denominations. We need to tell the minimum number of coins required to reach the target sum. We can pick a coin denomination for any number of times we want.

// Greedy cannot be followed here.
#include <bits/stdc++.h>
using namespace std;

// targetC = N*target, SC N*target + N
int memoization(vector<int> &arr, int ind, int target, vector<vector<int>> &dp)
{
    if (ind == 0)
        // Check if the target sum is divisible by the first element
        if (target % arr[0] == 0)
            return target / arr[0]; // If target is divisible return quotient
        else
            return 1e9; // Else, return a very large value to indicate it's not possible

    if (dp[ind][target] != -1)
        return dp[ind][target];

    int nottargetaken = 0 + memoization(arr, ind - 1, target, dp);
    int taken = 1e9;
    if (arr[ind] <= target)
        taken = 1 + memoization(arr, ind, target - arr[ind], dp);

    return dp[ind][target] = min(nottargetaken, taken);
}

int tabulation(vector<int> &arr, int n, int target)
{
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    for (int T = 0; T <= target; T++)
        if (T % arr[0] == 0)
            dp[0][T] = T / arr[0];
        else
            dp[0][T] = 1e9;

    for (int ind = 1; ind < n; ind++)
    {
        for (int T = 0; T <= target; T++)
        {
            int take = 0 + dp[ind - 1][T];
            int notTake = 1e9;
            if (arr[ind] <= T)
                take = 1 + dp[ind][T - arr[ind]];
            dp[ind][T] = min(take, notTake);
        }
    }
    int ans = dp[n - 1][target];
    if (ans >= 1e9)
        return -1;
    else
        return ans;
}

int spaceOptimised(vector<int> &arr, int n, int target)
{
    vector<int> prev(target + 1, 0), curr(target + 1, 0);
    for (int T = 0; T <= target; T++)
        if (T % arr[0] == 0)
            prev[T] = T / arr[0];
        else
            prev[T] = 1e9;

    for (int ind = 1; ind < n; ind++)
    {
        for (int T = 0; T <= target; T++)
        {
            int take = 0 + prev[T];
            int notTake = 1e9;
            if (arr[ind] <= T)
                take = 1 + curr[T - arr[ind]];
            curr[T] = min(take, notTake);
        }
        prev = curr;
    }
    int ans = prev[target];
    if (ans >= 1e9)
        return -1;
    else
        return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3};
    int target = 7;
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    int ans = memoization(arr, n - 1, target, dp);
    if (ans >= 1e9) // If ans is still very large, it means it's not possible to form the target sum
        cout << -1 << endl;
    else
        cout << ans << endl;
    cout << tabulation(arr, n, target) << endl;
    cout << spaceOptimised(arr, n, target) << endl;
    return 0;
}
