// https://takeuforward.org/data-structure/count-the-number-of-subarrays-with-given-xor-k

// Given an array of integers arr and an integer K. Find the total number of subarrays having bitwise XOR of all elements equal to k.
// Similar to "A2Z_23_Count_Subarrays_With_Sum_K"

#include <bits/stdc++.h>
using namespace std;

// Prefix XOR till index i = XR
// Let's say the XOR of first part is x
// The XOR of second part, that we're searching is K
// Thus
// x ^ K = XR
// x ^ K ^ K = XR ^ K
// x = XR ^ K
// Hence the XOR of first part must be x = XR ^ K

// Brute is to generate all the subarrays and take their XOR
int main()
{
    vector<int> arr = {4, 2, 2, 6, 4};
    int n = arr.size();
    int XR = 0;
    int cnt = 0;
    int K = 6;
    unordered_map<int, int> mpp;
    mpp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        XR = XR ^ arr[i];
        // Find remove
        int remove = XR ^ K;
        cnt += mpp[remove];
        mpp[XR]++;
    }
    cout << cnt;
    return 0;
}