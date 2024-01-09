// We are given an array arr with N positive integers and an integer K. We need to find the number of subsets whose sum is equal to K.

// If there are 0's in the array, see the notes you have made to solve it.
#include <bits/stdc++.h>
using namespace std;

// This func works well for both when there are zeroes present and when zeroes are not present
int memoization_if_zeroes_in_array(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (target == 0 && arr[ind] == 0)
            return 2; // Because there are 2 possible ways in which you can form the subsequence - By taking the 0 or by not taking the 0. Your sum will be same in either case.
        if(target == 0 && arr[ind] != 0)
            return 1; // If we are at ind=0 and we need 0 as target and arr[ind] != 0, then there is only way (by not taking it) so that the target does not go in -ve.
        if(target == arr[ind])
            return 1; // If we don't take it then the target will stay as arr[ind] and will not reduce. So there is no question of not taking it. We have to take it, which coresponds to 1 choice.
        return 0;
    }
    if (dp[ind][target] != -1)
        return dp[ind][target];

    int notTaken = memoization(ind - 1, target, arr, dp);
    int taken = 0;
    if (arr[ind] <= target)
        taken = memoization(ind - 1, target - arr[ind], arr, dp);

    return dp[ind][target] = notTaken + taken;
}

// This means, till 'index' how many subsequences are there which will give you the sum 'target'.
// TC = n*target, SC = n*target + n
int memoization(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return 1;
    if (ind == 0)
        return arr[0] == target;
    if (dp[ind][target] != -1)
        return dp[ind][target];

    int notTaken = memoization(ind - 1, target, arr, dp);
    int taken = 0;
    if (arr[ind] <= target)
        taken = memoization(ind - 1, target - arr[ind], arr, dp);

    return dp[ind][target] = notTaken + taken;
}

// TC = n*target, SC = n*target
int tabulation(vector<int> &num, int n, int target)
{
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    // Base case: If the target sum is 0, there is one valid subset (the empty subset)
    for (int i = 0; i < n; i++)
        dp[i][0] = 1;
    if (num[0] <= target)
        dp[0][num[0]] = 1;

    for (int ind = 1; ind < n; ind++)
        for (int target = 1; target <= target; target++)
        {
            int notTaken = dp[ind - 1][target];
            int taken = 0;
            if (num[ind] <= target)
                taken = dp[ind - 1][target - num[ind]];
            dp[ind][target] = notTaken + taken;
        }
    return dp[n - 1][target];
}

// TC = n*target, SC = target
int spaceOptimsied(vector<int> &num, int n, int target)
{
    vector<int> prev(target + 1, 0);

    // Base case: If the target sum is 0, there is one valid subset (the empty subset)
    prev[0] = 1;

    if (num[0] <= target)
        prev[num[0]] = 1;

    for (int ind = 1; ind < n; ind++)
    {
        vector<int> cur(target + 1, 0);
        cur[0] = 1;
        for (int target = 1; target <= target; target++)
        {
            int notTaken = prev[target];
            int taken = 0;
            if (num[ind] <= target)
                taken = prev[target - num[ind]];
            cur[target] = notTaken + taken;
        }
        prev = cur;
    }
    return prev[target];
}

int main()
{
    vector<int> arr = {1, 2, 2, 3};
    int target = 3;
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    cout << memoization(n - 1, target, arr, dp) << endl;
    cout << tabulation(arr, n, target) << endl;
    cout << spaceOptimsied(arr, n, target) << endl;

    return 0;
}
