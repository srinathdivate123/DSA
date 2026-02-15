// https://takeuforward.org/data-structure/trapping-rainwater
// https://leetcode.com/problems/trapping-rain-water/description/

// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

// In continuation to the intuition of the previous solution, to find the water above a certain bar, you will need min(leftMax , rigtMax). But if you see you actually only need either leftMax or rightMax (the smallest of the both); not both. So this is the intuition we'll be using

// The optimal approach uses two pointers to efficiently calculate the trapped water without extra space for arrays. The key insight is that the amount of water trapped at any position depends on the tallest bars to the left and right of that position. By maintaining two pointers starting from both ends of the array and tracking the maximum heights encountered so far from both sides, we can determine the trapped water at each step. If the left height is smaller or equal to the right height, the trapped water depends on the left side's maximum so far; otherwise, it depends on the right side's maximum, so far. This two-pointer technique lets us compute trapped water in one pass while using no extra space.
// --> Initialize two pointers: one at the left and one at the right of the array.
// --> Initialize two variables to track the maximum height encountered so far from the left (maxLeft) and so far from the right (maxRight).
// --> Initialize a variable to store the total trapped water (totalWater).
// --> While the left pointer is less than or equal to the right pointer:
// --> --> If the 'height' at the left pointer is less than or equal to the height at the right pointer:
// --> --> --> If the height at left is greater than maxLeft, then update maxLeft.
// --> --> --> ELSE, add the difference between maxLeft and the current height at left to totalWater.
// --> --> --> Move the left pointer one step right.
// --> --> Otherwise (height at right is smaller):
// --> --> --> If the height at right is greater than or equal to maxRight, update maxRight.
// --> --> --> ELSE, add the difference between maxRight and the current height at right to totalWater.
// --> --> --> Move the right pointer one step left.
// --> Return totalWater as the total trapped rainwater.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int left = 0;
        int right = n - 1;

        // Variables to track the maximum height to the left and right
        int maxLeft = 0;
        int maxRight = 0;

        int totalWater = 0;

        // Iterate until left pointer meets right pointer
        while (left <= right)
        {
            // If left bar is smaller or equal to right bar
            if (height[left] <= height[right])
            {
                // If current left bar is higher than maxLeft, update maxLeft
                if (height[left] >= maxLeft)
                {
                    maxLeft = height[left];
                }
                else
                {
                    // Water trapped on left is difference between maxLeft and current height
                    totalWater += maxLeft - height[left];
                }
                left++;
            }
            else
            {
                // If current right bar is higher than maxRight, update maxRight
                if (height[right] >= maxRight)
                {
                    maxRight = height[right];
                }
                else
                {
                    // Water trapped on right is difference between maxRight and current height
                    totalWater += maxRight - height[right];
                }
                right--;
            }
        }
        return totalWater;
    }
};

int main()
{
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    Solution sol;
    cout << sol.trap(height);
    return 0;
}