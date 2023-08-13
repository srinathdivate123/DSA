#include <bits/stdc++.h>
using namespace std;

// Given an array of N + 1 size, where each element is between 1 and N. Assuming there is only one duplicate number, your task is to find the duplicate number.

int findDuplicate(vector<int> &nums)
{
    int slow = nums[0];
    int fast = nums[0];
    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    fast = nums[0];
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}
// Brute is to sort and check for duplicates
int main()
{
    vector<int> arr = {1, 3, 4, 2, 3};
    cout << findDuplicate(arr);
    return 0;
}