// Given an array of integers and an integer k, return the total number of subarrays whose sum equals k.

// A subarray is a contiguous non-empty sequence of elements within an array.
#include <bits/stdc++.h>
using namespace std;

// Brute is to find all sub-arrays and find their sums
// Better is to calculate the sums of sub-arrays by adding the next element to the sum of the previous sub-array

// TC = N (assuming there are no colisions in unordered_map and the TC of map is 1)
// SC = N in worst case for map
int bestUsingHashMap(vector<int> arr, int target)
{
    unordered_map<int, int> mpp; // < Sum, number of times it occoured >
    mpp[0] = 1; // This is very important to mark that the sum of 0 appears once
    int preSum = 0, cnt = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        preSum += arr[i];
        int remove = preSum - target;
        cnt += mpp[remove];
        mpp[preSum] += 1;
    }
    return cnt;
}

int main()
{
    vector<int> arr = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
    int target = 3;
    cout << bestUsingHashMap(arr, 3);

    return 0;
}