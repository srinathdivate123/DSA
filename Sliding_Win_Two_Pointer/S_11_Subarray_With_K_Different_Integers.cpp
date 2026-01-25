// https://leetcode.com/problems/subarrays-with-k-different-integers/
// https://takeuforward.org/data-structure/subarray-with-k-different-integers

// Given an integer array nums and an integer k, return the number of good subarrays of nums.

// A good array is an array where the number of different integers in that array is exactly k.

// For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.

// A subarray is a contiguous part of an array.

// Here, the typical approach of left & right pointer expanding & shrinking the window wil not work because you do not know whether you need to shrink or expand the window because you are not sure of the distribution of the elements in bw the left & right pointers. Watch more at: https://youtu.be/7wYGbV_LsX4?t=284

// So whenever you're not sure of whether you have to shrink or expand then you need to think about some other approach

// Change the problem statement to: Find the number of subarrays where the number of different integers <= k

// Then this problem becomes kinda similar to S_9

#include <bits/stdc++.h>
using namespace std;

// Generate all subarrays
int brute()
{
}

int atMostK(vector<int> &nums, int k)
{
    // If k is negative, no such subarrays exist
    if (k < 0)
        return 0;

    int left = 0;
    int right = 0;
    int count = 0;
    int n = nums.size();
    unordered_map<int, int> mpp;

    // Traverse the array using right pointer
    while (right < n)
    {
        mpp[nums[right]]++;
        while (mpp.size() > k)
        {
            mpp[nums[left]]--;
            if (mpp[nums[left]] == 0)
            {
                mpp.erase(nums[left]);
            }
            left++;
        }
        count += (right - left + 1);
        right++;
    }
    return count;
}

// Main function to return number of subarrays with exactly K distinct integers
int best(vector<int> &nums, int k)
{
    return atMostK(nums, k) - atMostK(nums, k - 1);
}

// Driver code
int main()
{
    vector<int> nums = {1, 2, 1, 2, 3};
    int k = 2;
    cout << best(nums, k) << endl;
    return 0;
}
