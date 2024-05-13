/*
A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.
*/

#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> &arr)
{
    int n = arr.size();

    if (n == 1)
        return 0;
    if (arr[0] > arr[1])
        return 0;
    if (arr[n - 1] > arr[n - 2])
        return n - 1;

    int low = 1, high = n - 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        // If arr[mid] is the peak
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
            return mid;

        // If we are in the left
        if (arr[mid] > arr[mid - 1])
            low = mid + 1;

        // If we are in the right:
        // Or, arr[mid] is a common point:
        else
            high = mid - 1;
    }
    // Dummy return statement
    return -1;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
    int ans = findPeakElement(arr);
    cout << "The peak is at index: " << ans << "\n";
    return 0;
}
