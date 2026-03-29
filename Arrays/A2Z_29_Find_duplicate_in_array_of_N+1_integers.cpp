// https://leetcode.com/problems/find-the-duplicate-number/description/
// https://takeuforward.org/data-structure/find-the-duplicate-in-an-array-of-n1-integers
// Above TUF link is not included in the sheet
// https://www.youtube.com/watch?v=32Ll35mhWg0
// Video is not there in the Arrays playlist. It is there in the "Placement Series"

#include <bits/stdc++.h>
using namespace std;

// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
// There is only one repeated number in nums, return this repeated number.
// You must solve the problem without modifying the array nums and using only constant extra space.
// Note that you cannot sort the array 

// Intuition: Since there is a duplicate number in the list, a cycle will be formed
// Below is the most optimal method called as the "Linked List Cycle Method"
int findDuplicate(vector<int> &nums)
{
    int slow = nums[0];
    int fast = nums[0];

    // Initially move slow by one step and fast by two steps
    do
    {
        slow = nums[slow];
        fast = nums[fast];
        fast = nums[fast];
    } while (slow != fast);

    // Set fast at the beginning of the array
    fast = nums[0];

    // Move both slow and fast by one step. Where they collide will be the duplicate number. For proof, refer the video
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }
    // You can either return slow or fast
    return slow;
}
int main()
{
    vector<int> arr = {1, 3, 4, 2, 3};
    cout << findDuplicate(arr);
    return 0;
}