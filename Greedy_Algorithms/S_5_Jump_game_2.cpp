/*
You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

    -> 0 <= j <= nums[i]
    -> i + j < n

Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

Eg: {2,3,1,4,1,1,1,2} ::> Start from 2 and go to 1. Then go to 4. Then to the last element. The min no of jumps taken is 3.
*/

#include <bits/stdc++.h>
using namespace std;

// Try all possible ways using recursion
// TC: Can go exponential. SC: Auxiliary stack space O(N)
int brute(int ind, int jumps, vector<int> &nums)
{
    if (ind >= nums.size() - 1) // If it reaches the last index, return.
        return jumps;

    int mini = INT_MAX;

    // Iterate through the number of jumps that you can take (from 1 jump to nums[ind] jumps). You should take atleast 1 jump or there is no use, so start loop from 1
    for (int i = 1; i <= nums[ind]; i++)
    {
        mini = min(mini, brute(ind + i, jumps + 1, nums));
    }
    return mini;
}

// TC: O(N*N). SC = O(N*N)
int dp_solution(int ind, int jumps, vector<int> &nums, vector<vector<int>> &dp)
{
    if (dp[ind][jumps] != -1)
        return dp[ind][jumps];

    int mini = INT_MAX;

    // Iterate through the number of jumps that you can take (from 1 jump to nums[ind] jumps). You should take atleast 1 jump or there is no use.
    for (int i = 1; i <= nums[ind]; i++)
    {
        mini = min(mini, brute(ind + i, jumps + 1, nums));
    }
    return dp[ind][jumps] = mini;
}

int dp_solution_space_optmized(int ind, int jumps, vector<int> &nums)
{
    // To do!
}

// This is similar to 'valid paranthesis string'
// Convert the recursive solution into a range based solution
// TC = (N) you traverse each element only once. SC = O(N)
int best(vector<int> &nums)
{
    int jumps = 0, leftRange = 0, rightRange = 0, n = nums.size();
    // leftRange will go to the next index after i, because that is the minimum distance you can travel from i
    // rightRange will go to the the farthest distance that you can go from i

    while (rightRange < nums.size() - 1)
    {
        int farthest = 0;
        // Traverse for all elements in the range, to find out that from all the elements in the range what is the farthest you can go
        for (int i = leftRange; i <= rightRange; i++)
        {
            farthest = max(farthest, i + nums[i]);
        }
        leftRange = rightRange + 1;
        rightRange = farthest;
        jumps++;
    }
    return jumps;
}

int main()
{
    // vector<int> nums = {2, 3, 1, 1, 4};
    vector<int> nums = {2, 3, 0, 1, 4};
    int n = nums.size();

    cout << brute(0, 0, nums) << endl;

    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << dp_solution(0, 0, nums, dp) << endl;

    cout << best(nums) << endl;
}