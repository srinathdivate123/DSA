// You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

// Return true if you can reach the last index, or false otherwise.

// Observation: The only thing that can stop you from reaching the end is a 0. If there are no 0's in the array then you can always reach the end.

#include <bits/stdc++.h>
using namespace std;

bool best(vector<int> &nums)
{
    // Initialize the maximum index that can be reached
    int maxIndex = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        // If the current index is greater than the maximum reachable index computed so far, it means the we cannot actually reach here by taking "jumps". Hence, we cannot move forward and should return false
        if (i > maxIndex)
            return false;

        // Update the maximum index that can be reached by comparing the current maxIndex with the sum of the current index and the maximum jump from that index
        maxIndex = max(maxIndex, i + nums[i]);
    }
    return true;
}

int main()
{
    vector<int> nums = {4, 3, 7, 1, 2};
    cout << best(nums) << endl;
    return 0;
}