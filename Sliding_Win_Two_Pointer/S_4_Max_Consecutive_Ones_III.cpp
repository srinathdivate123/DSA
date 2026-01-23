// https://takeuforward.org/data-structure/max-consecutive-ones-iii
// https://leetcode.com/problemgyy  s/max-consecutive-ones-iii/description/

// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's

// Convert this problem into: Find the longest subarray of 1's and 0's with at most k 0's

#include <bits/stdc++.h>
using namespace std;

// TC: O(N^2), SC: O(1)
// Find out all subarrays
int brute(vector<int> &nums, int k)
{
    int maxi = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int zeros = 0;
        for (int j = i; j < nums.size(); j++)
        {
            if (nums[j] == 0)
                zeros++;
            if (zeros <= k)
                maxi = max(maxi, j - i + 1);
            else
                break;
        }
    }
    return maxi;
}

// TC: O(2N), SC: O(1)
int better(vector<int> &nums, int k)
{
    int l = 0, r = 0, maxi = 0, zeroes = 0;
    while (r < nums.size())
    {
        zeroes += !nums[r];
        /*
        Above is the same as writing:
        if (nums[r] == 0)
            zeroes++;
        */
        // If zeroes are greater than k, then you need to move the left pointer such that you get at max 2 zeroes
        while (zeroes > k)
        {
            if (nums[l] == 0)
                zeroes--;
            l++;
        }
        if (zeroes <= k)
            maxi = max(maxi, r - l + 1);
        r++;
    }
    return maxi;
}

// Why the below works, explained: https://youtu.be/3E4JBHSLpYk?t=1726
// All you did is replaced the while loop by an if condition
// TC: O(N), SC: O(1)
int best(vector<int> &nums, int k)
{
    int l = 0, r = 0, maxi = 0, zeroes = 0;
    while (r < nums.size())
    {
        zeroes += !nums[r];

        // Above you shrink the subarray by many places until the sum zeroes <= K
        // But once you have already found that (let's say) 3 is the maxi
        // The you wouldn't settle for 2 as the next maxi at all
        // So there is no use of shrinking the window to any size lesser than 3
        // Hence you shrink it only by 1 and hence replace while loop by if condition
        // i.e. you always keep the same max window size (3) throughout your further search
        // Because you will not settle for any answer less than 3
        if (zeroes > k)
        {
            if (nums[l] == 0)
                zeroes--;
            l++;
        }
        if (zeroes <= k)
            maxi = max(maxi, r - l + 1);
        r++;
    }
    return maxi;
}

int main()
{
    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;
    cout << brute(nums, k) << endl;
    cout << better(nums, k) << endl;
    cout << best(nums, k) << endl;
    return 0;
}