// We are given an array arr with N positive integers and an integer D. We need to count the number of ways we can partition the given array into two subsets, S1 and S2 such that S1 – S2 = D and S1 is always greater than or equal to S2.
/*
S1 = Total - S2
S1 - S2 = D
Total - S2 - S2 = D
Total - D = 2*S2
S2 = (Total - D) / 2
Target = (Total - D) / 2
This is similar to DP-17 with modified target.
S2 >= 0 which means Total-D >= 0
There are no fractions in arrays so Total-D must be even.
*/

#include <bits/stdc++.h>
using namespace std;
int mod = (int)1e9 + 7;

int memoizationUtil(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (ind == 0) // Conditions are same as DP-17
        if (target == 0 && arr[0] == 0)
            return 2;
        else if (target == 0 && arr[ind] != 0)
            return 1;
        else if (target == arr[0])
            return 1;
        else
            return 0;

    if (dp[ind][target] != -1)
        return dp[ind][target];

    int notTaken = memoizationUtil(ind - 1, target, arr, dp);

    int taken = 0;
    if (arr[ind] <= target)
        taken = memoizationUtil(ind - 1, target - arr[ind], arr, dp);

    return dp[ind][target] = (notTaken + taken) % mod;
}

// TC = n*k, SC = n*k + n
int memoization(int n, int d, vector<int> &arr)
{
    int totSum = 0;
    for (int i = 0; i < arr.size(); i++)
        totSum += arr[i];

    if (totSum - d < 0 || (totSum - d) % 2)
        return 0;

    int s2 = (totSum - d) / 2;
    vector<vector<int>> dp(n, vector<int>(s2 + 1, -1));
    return memoizationUtil(n - 1, s2, arr, dp);
}

// TC = n*k, SC = n*k
int tabulationUtil(vector<int> &num, int target)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    if (num[0] == 0)
        dp[0][0] = 2; // 2 cases - pick and not pick
    else
        dp[0][0] = 1; // 1 case - not pick

    if (num[0] != 0 && num[0] <= target)
        dp[0][num[0]] = 1; // 1 case -pick

    for (int ind = 1; ind < n; ind++)
        for (int sum = 0; sum <= target; sum++)
        {

            int notTaken = dp[ind - 1][sum];

            int taken = 0;
            if (num[ind] <= sum)
                taken = dp[ind - 1][sum - num[ind]];

            dp[ind][sum] = (notTaken + taken) % mod;
        }
    return dp[n - 1][target];
}

int tabulation(int n, int d, vector<int> &arr)
{
    int totSum = 0;
    for (int i = 0; i < n; i++)
        totSum += arr[i];

    if (totSum - d < 0 || (totSum - d) % 2)
        return 0;

    return tabulationUtil(arr, (totSum - d) / 2);
}

// TC = n*k, SC = k
int spaceOptimisedUtil(vector<int> &num, int target)
{
    int n = num.size();
    vector<int> prev(target + 1, 0), curr(target + 1, 0);

    if (num[0] == 0)
        prev[0] = 2; // 2 cases - pick and not pick
    else
        prev[0] = 1; // 1 case - not pick

    if (num[0] != 0 && num[0] <= target)
        prev[num[0]] = 1; // 1 case -pick

    for (int ind = 1; ind < n; ind++)
    {
        for (int sum = 0; sum <= target; sum++)
        {

            int notTaken = prev[sum];

            int taken = 0;
            if (num[ind] <= sum)
                taken = prev[sum - num[ind]];

            curr[sum] = (notTaken + taken) % mod;
        }
        prev = curr;
    }
    return prev[target];
}

int spaceOptimised(int n, int d, vector<int> &arr)
{
    int totSum = 0;
    for (int i = 0; i < n; i++)
        totSum += arr[i];

    if (totSum - d < 0 || (totSum - d) % 2)
        return 0;

    return spaceOptimisedUtil(arr, (totSum - d) / 2);
}

int main()
{
    vector<int> arr = {5, 2, 6, 4};
    int n = arr.size();
    int d = 3;
    cout << memoization(n, d, arr) << endl;
    cout << tabulation(n, d, arr) << endl;
    cout << spaceOptimised(n, d, arr) << endl;
}