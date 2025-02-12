// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's

// Convert this problem into: Find the longest subarray with at most k 0's

#include <bits/stdc++.h>
using namespace std;

// TC: O(N^2), SC: O(1)
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
// TC: O(N), SC: O(1)
int best(vector<int> &nums, int k)
{
    int l = 0, r = 0, maxi = 0, zeroes = 0;
    while (r < nums.size())
    {
        zeroes += !nums[r];
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