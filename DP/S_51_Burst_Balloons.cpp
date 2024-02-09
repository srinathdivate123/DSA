/*
You are given n balloons, indexed from 0 to n – 1. Each balloon is painted with a number on it represented by an array. You are asked to burst all the balloons in any order.

If you burst the ith balloon, you will get arr[i – 1] * arr[i] * arr[i + 1] coins. If i – 1 or i + 1 goes out of the array’s bounds, then treat it as if there is a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.
*/

/*
Consider array = [b1, b2, b3, b4, b5, b6]. We cannot burst b4 and then tell that [b1, b2, b3] and [b5, b6] are the next two individual subproblems that we have to solve. Because now if we burst b3, the coins are b2+b3+b5. So here we see that one subproblem is dependent on another subproblem. Because of this DP cannot work. DP works only when the subproblems are independent.
Now suppose we bursted b5 first then while bursting b3 cost = b3+b3+b6. Suppose we burst b6 first then while bursting b3 cost = b2+b3+b5. This is ambiguous. Thus we have two dependent subproblems.
https://youtu.be/Yz4LlDSlkns
*/

#include <bits/stdc++.h>
using namespace std;

// TC = n*n*n, SC = n*n + n
int memoization(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int maxCoins = INT_MIN;

    // Iterate through each possible balloon to burst last
    for (int k = i; k <= j; k++)
    {
        // Calculate the coins obtained by bursting the k-th balloon last
        int coins = nums[i - 1] * nums[k] * nums[j + 1];

        int remainingCoins = memoization(i, k - 1, nums, dp) + memoization(k + 1, j, nums, dp);

        maxCoins = max(maxCoins, coins + remainingCoins);
    }

    return dp[i][j] = maxCoins;
}

// TC = n*n*n, SC = n*n
int tabulation(vector<int> &nums, int n)
{
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    for (int i = n; i >= 1; i--)
        for (int j = 1; j <= n; j++)
        {
            if (i > j)
                continue;
            int maxi = INT_MIN;

            // Iterate through each possible balloon to burst at the last
            for (int ind = i; ind <= j; ind++)
            {
                // Calculate the coins obtained by bursting the ind-th balloon last
                int coins = nums[i - 1] * nums[ind] * nums[j + 1];

                // Calculate the maximum coins for the remaining balloons
                int remainingCoins = dp[i][ind - 1] + dp[ind + 1][j];

                maxi = max(maxi, coins + remainingCoins);
            }
            dp[i][j] = maxi;
        }
    return dp[1][n];
}

int main()
{
    vector<int> nums = {3, 1, 5, 8};
    int n = nums.size();
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
    cout << memoization(1, n, nums, dp) << endl;
    cout << tabulation(nums, n) << endl;
    return 0;
}