// Given a sorted array of N integers and an integer x, write a program to find the lower bound of x.

// The lower bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than or equal to a given target i.e. x.

// The lower bound is the smallest index, ind, where arr[ind] >= x. But if any such index is not found, the lower bound algorithm returns n i.e. size of the given array.

#include <bits/stdc++.h>
using namespace std;

// In C++ we have a in-built function for this.
// int lb = lower_bound(arr.begin(), arr.end(), target);
// This will return an iterator pointing at the lower boind.
// If you want the index number then do index = lb - arr.begin();
int lowerBound(vector<int> arr, int n, int target)
{
    int low = 0, high = n - 1, ans = n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= target)
            ans = mid, high = mid - 1; // Look for more smaller index on left
        else
            low = mid + 1; // Look for right
    }
    return ans;
}
int upperBound(vector<int> arr, int n, int target)
{
    
}
int main()
{
    int target = 19;
    vector<int> arr = {3, 5, 8, 15, 19, 19, 19};
    cout << lowerBound(arr, arr.size(), target);
    return 0;
}