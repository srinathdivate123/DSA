// Given a sorted array arr of n integers and a target value k. Find the indices of the first and the last occurrences of the target value. If the target is not found then return -1 as indices.

// Here we are using a modified binary search!

#include <bits/stdc++.h>
using namespace std;

int firstOccurrence(vector<int> &arr, int n, int k)
{
    int low = 0, high = n - 1;
    int first = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == k)
            first = mid, high = mid - 1;
        else if (arr[mid] < k)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return first;
}

int lastOccurrence(vector<int> &arr, int n, int k)
{
    int low = 0, high = n - 1;
    int last = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == k)
            last = mid, low = mid + 1;
        else if (arr[mid] < k)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return last;
}

pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k)
{
    int first = firstOccurrence(arr, n, k);
    if (first == -1)
        return {-1, -1};
    int last = lastOccurrence(arr, n, k);
    return {first, last};
}

int main()
{
    vector<int> arr = {2, 4, 6, 8, 8, 8, 11, 13};
    int n = 8, k = 8;
    pair<int, int> ans = firstAndLastPosition(arr, n, k);
    cout << ans.first << " " << ans.second << "\n";
    return 0;
}
