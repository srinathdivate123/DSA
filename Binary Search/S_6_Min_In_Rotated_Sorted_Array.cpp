// Given the sorted rotated array nums of unique elements, return the minimum element of this array.

// Pick the minimum from the sorted half because we're sure the the first element in the sorted half is indeed the minimum element of the sorted half. Then eliminate the sorted half because we have already picked the minimum element in the sorted half, so there is no further need of checking any of the remaining elements in the sorted half.

#include <bits/stdc++.h>
using namespace std;

int binarySearch_Unoptimised(vector<int> &arr)
{
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[low] <= arr[mid]) // left part is sorted
        {
            ans = min(ans, arr[low]); // keep the minimum.
            low = mid + 1;            // Eliminate left half
        }
        else // if right part is sorted
        {
            ans = min(ans, arr[mid]); // keep the minimum
            high = mid - 1;           // Eliminate right half
        }
    }
    return ans;
}

int binarySearch_Optimised(vector<int> &arr)
{
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        // If search space is already sorted then arr[low] of that search space will always be the minimum in that search space. So no need to check further at all.
        if (arr[low] <= arr[high])
        {
            ans = min(ans, arr[low]);
            break;
        }

        if (arr[low] <= arr[mid]) // left part is sorted
        {
            ans = min(ans, arr[low]); // keep the minimum.
            low = mid + 1;            // eliminate left half
        }
        else // if right part is sorted
        {
            ans = min(ans, arr[mid]); // keep the minimum
            high = mid - 1;           // eliminate right half
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    cout << binarySearch_Unoptimised(arr) << endl;
    cout << binarySearch_Optimised(arr) << endl;
    return 0;
}