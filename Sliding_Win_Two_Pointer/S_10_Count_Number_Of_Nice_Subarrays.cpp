// https://leetcode.com/problems/count-number-of-nice-subarrays/
// https://takeuforward.org/data-structure/count-number-of-nice-subarrays

// Given an array nums and an integer k. An array is called nice if and only if it contains k odd numbers. Find the number of nice subarrays in the given array nums. A subarray is continuous part of the array.

// Consider all the odd numbers as 1 and even numbers as 0. Then this problem will be reduced to the same as the previous problem ==> find the number of subarrays where the sum is k

#include <bits/stdc++.h>
using namespace std;

int brute()
{
    // Same as prev
}

int better()
{
    // Same as prev
}

int atMost(vector<int> &nums, int k)
{
    // If k is negative, no such subarrays exist
    if (k < 0)
        return 0;

    int left = 0;
    int right = 0;
    int sum = 0;
    int count = 0;
    int n = nums.size();

    // Traverse the array using right pointer
    while (right < n)
    {
        sum += (nums[right] % 2); // % 2 will make odd numbers to 1

        // Shrink the window from the left if sum exceeds k
        // Combine the conditional check with a whilw loop
        while (sum > k)
        {
            sum -= (nums[left] % 2);
            left++;
        }

        // Add the number of valid subarrays ending at right
        // The number of valid subarrays ending at right is (right - left + 1)
        // Because here the question is "sum less than or equal to k"
        // So if the sum between left & right is "less than or equal to k", then all the possible subarrays between left & right have a "sum less than or equal to k"
        // The number of possible subarrays is (right - left + 1)
        count += (right - left + 1);
        right++;
    }

    return count;
}

int best(vector<int> &nums, int k)
{
    // Return difference between subarrays with sum at most k and at most (k - 1)
    // This will work for all values of k including k == 0
    return atMost(nums, k) - atMost(nums, k - 1);
}

int main()
{
    vector<int> nums = {2, 2, 2, 1, 2, 2, 1, 2, 2, 2};
    int k = 2;
    cout << best(nums, k) << endl;
    return 0;
}