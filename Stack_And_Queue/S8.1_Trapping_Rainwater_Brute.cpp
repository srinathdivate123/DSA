// https://takeuforward.org/data-structure/trapping-rainwater
// https://leetcode.com/problems/trapping-rain-water/description/

// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

// --------------------------------------------------------------

// We need to sum the water that is trapped on top of each bar. You need to know the highest bar on the left and the highest bar on the right of that position. The water trapped on top of a bar depends on the smaller of these two heights minus the height of the current bar. If the current bar is taller than both sides, no water can be trapped there.
// For each bar in the array, find the maximum height bar on its left and right.
// Calculate the trapped water on the current bar as min(maxLeft, maxRight) - current height.
// Sum all trapped water from each bar to get the total amount of trapped water.

// TC: 2N for precompute and N for actual iteration
// SC: 2N for the precomputed arrays

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int totalWater = 0;

        vector<int> maxLeft(n, -1);
        vector<int> maxRight(n, -1);
        maxLeft[0] = height[0];
        maxRight[n - 1] = height[n - 1];

        // Pre compute maxLeft and maxRight
        for (int i = 0; i < n - 1; i++)
            maxLeft[i] = max(maxLeft[i - 1], height[i]);

        for (int i = n - 2; i > 0; i--)
            maxRight[i] = max(maxRight[i + 1], height[i]);

        // Iterate over each bar in the elevation map
        for (int i = 0; i < n; i++)
        {
            totalWater += min(maxLeft[i], maxRight[i]) - height[i];
        }
        return totalWater;
    }
};

int main()
{
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    Solution sol;
    int result = sol.trap(height);
    cout << "Trapped Rainwater: " << result << endl;
    return 0;
}