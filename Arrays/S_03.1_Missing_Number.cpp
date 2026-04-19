// TUF link redirects to: https://www.geeksforgeeks.org/dsa/find-the-missing-number/
// https://leetcode.com/problems/missing-number/description/

// Given an array arr[] of size n-1 with distinct integers in the range of [1, n]. This array represents a permutation of the integers from 1 to n with one element missing. Find the missing element in the array.

#include <bits/stdc++.h>
using namespace std;

// TC = N
// SC = 1
void sumApproach(int arr[], int N, int arraySize)
{
    int sum = N * (N + 1) / 2;
    int actualSum = 0;
    for (int i = 0; i < arraySize; i++)
        actualSum += arr[i];
    cout << "Missing element is: " << sum - actualSum << endl;
}
// If the array has numbers of order 10^5 then the sum will be 10^10 which you have to store in long datatype.

// But when we do XOR the value of 10^5 ordered numbers will never exceed 10^5. i.e. the XOR of all numbers will not be that big

// The XOR of two same numbers, taken even number of times, is always 0.
// 2^2 = 0
// 2^2^2^2 = 0
// 0^2 = 2
// 2^2^2^2^2 = 2

// XOR1 = 1^2^3^4^5^6^7  - The XOR of all numbers upto N
// XOR2 = 1^2^4^5^6^7 - The XOR of all numbers in array
// If we do XOR1^XOR2 we get 3!
void XOR_Approach(int arr[], int N)
{
    int XOR1 = 0, XOR2 = 0;
    // XOR1 = XOR of numbers from 1 to N
    // XOR2 = XOR of all elements in array

    for (int i = 0; i < N; i++)
    {
        XOR1 ^= (i + 1);
        XOR2 ^= arr[i];
    }
    cout << "Missing element is: " << (XOR1 ^ XOR2) << endl;
}

// Works only if sorted
void simple(int arr[], int N)
{
    for (int i = 1; i < N; i++) // start from 1 because the first number is 1
        if (arr[i] + 1 != arr[i + 1])
        {
            cout << arr[i] + 1;
            break;
        }
}

int main()
{
    int arr[6] = {1, 2, 4, 5, 6, 7}; // Array must start from 1
    // sumApproach(arr, 7, sizeof(arr) / sizeof(arr[0]));
    // XOR_Approach(arr, 7);
    simple(arr, 7);
    return 0;
}