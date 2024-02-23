// Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

// Return the kth positive integer that is missing from this array.

#include <bits/stdc++.h>
using namespace std;

int missingK(vector<int> vec, int n, int k)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int missing = vec[mid] - mid - 1;
        if (missing < k)
            low = mid + 1;
        else
            high = mid - 1;
    }
    /*
    ans = vec[high] + moreNeeded
    moreNeeded = k - missing
    missing = vec[high] - high - 1
    so ans = vec[high] + moreNeeded
    ans = vec[high] + (k - missing)
    ans = vec[high] + k - (vec[high] - high - 1)
    ans = vec[high] + k - vec[high] + high + 1
    ans = k + high + 1;
    ans = k + low (Because low = high + 1)
    */
    return k + low;
}

int main()
{
    vector<int> vec = {4, 7, 9, 10};
    int n = vec.size(), k = 4;
    cout << missingK(vec, n, k);
    return 0;
}
