// https://takeuforward.org/arrays/find-the-number-that-appears-once-and-the-other-numbers-twice
// https://leetcode.com/problems/single-number/description/

// Given a non-empty array of integers arr, every element appears twice except for one. Find that single one.
// You're given an array arr = {1,2,3,1,4,3,4}
// The answer is 2.

#include <bits/stdc++.h>
using namespace std;

int func(int arr[], int n)
{
    int XOR = 0;
    for (int i = 0; i < n; i++)
    {
        XOR ^= arr[i];
    }
    return XOR;
}

int main()
{
    int arr[] = {1, 2, 3, 1, 4, 3, 4};
    cout << func(arr, sizeof(arr) / sizeof(arr[0]));
    return 0;
}