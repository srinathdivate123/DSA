// https://takeuforward.org/data-structure/next_permutation-find-next-lexicographically-greater-permutation
// https://leetcode.com/problems/next-permutation/description/

// A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

// For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
// The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

// For example, the next permutation of arr = [1,2,3] is [1,3,2].
// Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
// While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
// Given an array of integers nums, find the next permutation of nums.

// The replacement must be in place and use only constant extra memory.

#include <bits/stdc++.h>
using namespace std;
void printArray(vector<int> &arr, int n)
{
    cout << "Printing array:\n";
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << "\n\n";
}

// Generate all the permutations of array which would take N!*N time complexity and then search the given array in it and the next array will be the "next permutation"
void brute() {}

// STL has inbuilt function next_permutation(arr.begin(), arr.end());
// Tell this solution to the interviewer because it tells that you have knowledge of STL
void better() {}

// To find this next permutation with minimal change, we need to find a digit that can be increased slightly to make the number bigger and then rearrange the remaining part to be the smallest possible.
// --> Traverse from the end and find the first index where the current digit is smaller than the next one (i.e. where there is a dip as seen from the right) (this is the "breaking point").
// --> Note that all digits to the right of breakpoint are bound to be in a descending order
// --> Then again traverse from the end to find the first smallest digit that is greater than the breaking point and then swap them.
// --> Finally, reverse the part of the array to the right of the breaking point to get the smallest next permutation.
// --> If no such breaking point exists (entire array is descending), just reverse the whole array.
// [2, 1, 5, 4, 3, 0, 0]
// Breaking point = 1
// First smallest digit from the end that is greater than the breaking point = 3
// Swap {1, 3}
// [2, 3, 5, 4, 1, 0, 0]
// After sorting ==> [2, 3, 0, 0, 1, 4, 5]

void best(vector<int> &arr, int n)
{
    int breakPoint = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            breakPoint = i;
            break;
        }
    }

    if (breakPoint == -1) // Means all elements are in sorted order
    {
        reverse(arr.begin(), arr.end());
        printArray(arr, n);
        return;
    }

    for (int i = n - 1; i > breakPoint; i--)
    {
        if (arr[i] > arr[breakPoint])
        {
            swap(arr[i], arr[breakPoint]);
            break;
        }
    }
    sort(arr.begin() + breakPoint + 1, arr.end());
    printArray(arr, n);
    return;
}

int main()
{
    vector<int> arr = {2, 1, 5, 4, 3, 0, 0};
    best(arr, arr.size());
    return 0;
}