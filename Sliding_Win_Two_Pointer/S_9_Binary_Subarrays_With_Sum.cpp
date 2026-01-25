// https://takeuforward.org/data-structure/binary-subarray-with-sum
// https://leetcode.com/problems/binary-subarrays-with-sum/

// Refer the TUF blog

// Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal. A subarray is a contiguous part of the array.

// OPTIMAL Solution: To count the number of subarrays with sum exactly equal to goal, a clever strategy is to reframe the problem: We count the number of subarrays whose sum is at most goal, and subtract from it the number of subarrays whose sum is at most goal - 1
// At most means, <=, less than equal to.
// This works because: The subarrays with sum exactly goal are the ones included in atMost(goal) but not in atMost(goal - 1) and this is valid for positive elements only.
// This method only works when goal ≥ 1, because the atMost(goal - 1) calculation is invalid for goal = 0 (negative index/window not possible).

#include <bits/stdc++.h>
using namespace std;

int brute()
{
    // Find all subarrays
}

// Use prefix sum ==> Same as the problem: Count subarray sum eqals K from the Arrays playlist
// TC: O(n). Each element is visited exactly once during the single-pass traversal.
// SC: O(n). In the worst case, all cumulative sums are distinct, so the hash map can store up to n unique keys. Thus, the space required grows linearly with the input size.

int better(vector<int> &nums, int goal)
{
    // Hashmap to store prefix sum frequencies
    unordered_map<int, int> prefixSumCount;

    // Initialize count of valid subarrays and current sum
    int count = 0, prefixSum = 0;

    // Add base case: prefix sum 0 has frequency 1
    prefixSumCount[0] = 1;

    for (int num : nums)
    {
        prefixSum += num;

        // If (sum - goal) exists in map, add its frequency to count
        if (prefixSumCount.find(prefixSum - goal) != prefixSumCount.end())
        {
            count += prefixSumCount[prefixSum - goal];
        }

        // Increment frequency of current prefix sum
        prefixSumCount[prefixSum]++;
    }

    // Return total count of valid subarrays
    return count;
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
        sum += nums[right];

        // Shrink the window from the left if sum exceeds k
        // Combine the conditional check with a whilw loop
        while (sum > k)
        {
            sum -= nums[left];
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

int best(vector<int> &nums, int goal)
{
    // Return difference between subarrays with sum at most goal and at most (goal - 1)
    // This will work for all values of goal including goal == 0
    return atMost(nums, goal) - atMost(nums, goal - 1);
}

int main()
{
    vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;
    cout << better(nums, goal) << endl;
    cout << best(nums, goal) << endl;
    return 0;
}