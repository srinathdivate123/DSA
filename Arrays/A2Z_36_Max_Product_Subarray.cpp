// https://takeuforward.org/data-structure/maximum-product-subarray-in-an-array
// https://leetcode.com/problems/maximum-product-subarray/

// Given an integer array nums which has both +ves and -ves, find a subarray that has the largest product, and return the product.
// Note that the product of an array with a single element is the value of that element.

#include <bits/stdc++.h>
using namespace std;
// This optimal approach of N TC is a based on a modification of Kadane's algorithm. But it is not a very intutive approach. It is only a algo that can be told if you remember it. So don't tell the below algo in interviews as it seems pre-planned!

int kadane_algo_based_optimal_approach(vector<int> nums)
{
    int res = nums[0];
    int maxProd = nums[0];
    int minProd = nums[0];

    // Traverse from second element
    for (int i = 1; i < nums.size(); i++)
    {
        // Store current number
        int curr = nums[i];

        // If current number is negative, swap max and min
        if (curr < 0)
            swap(maxProd, minProd);

        // Update max and min product ending at current index
        maxProd = max(curr, maxProd * curr);
        minProd = min(curr, minProd * curr);

        // Update global result
        res = max(res, maxProd);
    }
    return res;
}

// Tell below in interviews
// TC = N
// CASE 1: All positives in array -> Multiply all elements
// CASE 2: Even number of negatives in array, rest positives -> Multiply all elements
// CASE 3: Odd number of negatives in array, rest positives -> You need to choose only even number of negatives amongst all the negatives present in the array and leave out one negative element. Which negative element will you leave out? You need below code logic to do that. You only have choice to ignore one -ve from either the right or left. If you're ignoring from the right, then you need prefix mul and if you're ignoring from the left, then you need suffix mul. So your answer will either be in the max of prefix multiplication or in the max of suffix multiplication along the way.
// CASE 4: Any number of zeroes present in the array. You should not consider the zeroes.

// Traverse the array from left to right (prefix) to build cumulative prefix product.
// Traverse the array from right to left (suffix) to catch subarrays ending at the back (helpful when max product is at the end or due to even negatives).
// Reset the product to 1 whenever a zero is found, as it breaks the subarray continuity.
// By comparing products in both directions at each step, we ensure we don’t miss any possible maximum.

int observation_based_optimal_approach(vector<int> &arr)
{
    int n = arr.size();
    int ans = INT_MIN;
    int prefix = 1, suffix = 1;
    for (int i = 0; i < n; i++)
    {
        if (prefix == 0)
            prefix = 1;
        if (suffix == 0)
            suffix = 1;
        prefix *= arr[i];
        suffix *= arr[n - i - 1];
        ans = max(ans, max(prefix, suffix));
    }
    return ans;
}

int main()
{
    vector<int> arr = {2, 3, -2, 4};
    observation_based_optimal_approach(arr);
    return 0;
}