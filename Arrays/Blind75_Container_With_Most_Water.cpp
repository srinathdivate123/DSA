// https://leetcode.com/problems/container-with-most-water/description/

// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
// Find two lines that together with the x-axis form a container, such that the container contains the most water.
// Return the maximum amount of water a container can store.
// Notice that you may not slant the container.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &arr)
    {
        int left = 0, right = arr.size() - 1;
        int res = 0;
        while (left < right)
        {
            // Find the water stored in the container between
            // arr[left] and arr[right]
            int water = min(arr[left], arr[right]) * (right - left);
            res = max(res, water);

            if (arr[left] < arr[right])
                left += 1;
            else
                right -= 1;
        }

        return res;
    }
};