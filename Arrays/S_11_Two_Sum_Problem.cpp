// Problem Statement: Given an array of integers arr[] and an integer target.
// 1st variant: Return YES if there exist two numbers such that their sum is equal to the target. Otherwise, return NO
// 2nd variant: Return indices of the two numbers such that their sum is equal to the target. Otherwise, we will return {-1, -1}.

// Brute is to loop over every element and to check with every other element in a nested for loop.

#include <bits/stdc++.h>
using namespace std;

// TC = N x log(N)
// SC = N (Space taken by map in worst case)
array <int, 2> better(int arr[], int n, int target)
{
    map<int, int> mpp; // Map will store the element-key.
    for (int i = 0; i < n; i++)
    {
        int a = arr[i];
        int more_needed = target - a; // more is the no that is required in order to get a sum up to the target
        if (mpp.find(more_needed) != mpp.end())
            return {mpp[more_needed], i};
        mpp[a] = i; // Add the element and it's index to the map
    }
    return {-1, -1};
}

// Greedy two pointer approach
// After sorting array, if sum < target means you should increment the left pointer so that you get the next element which is larger and the hence the sum would be larger.
// Likewise, if sum > target, then you should decrement the right pointer so that you get smaller element and hence the sum will be smaller.
// This function can't be used to return the indices of the array elements as indices will change after sorting.
// TC = N + N*log(N)   (For iterating the array and for sorting)
string best(int arr[], int n, int target)
{
    int left = 0, right = n - 1;
    sort(arr, arr+n);
    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (sum == target)
            return "YES";
        if (sum < target)
            left++;
        else
            right--;
    }
    return "NO";
}

int main()
{
    int arr[] = {2, 6, 5, 8, 11};
    int target = 14;
    array<int, 2> answer = better(arr, sizeof(arr) / sizeof(arr[0]), target);
    cout << answer[0] << " , " << answer[1] << endl;

    cout << best(arr, sizeof(arr) / sizeof(arr[0]), target);
    return 0;
}