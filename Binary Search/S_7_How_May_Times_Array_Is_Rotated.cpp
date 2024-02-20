// This is similar to previous code.

#include <bits/stdc++.h>
using namespace std;

int findKRotation(vector<int> &arr)
{
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    int index = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        // If search space is already sorted then arr[low] of that search space will always be the minimum in that search space. So no need to check further at all.
        if (arr[low] <= arr[high])
        {
            if (arr[low] < ans) // Instead of calling the min() func, we are manually finding the min.
            {
                ans = arr[low];
                index = low;
            }
            break;
        }

        if (arr[low] <= arr[mid]) // if left part is sorted
        {
            if (arr[low] < ans) // Instead of calling the min() func, we are manually finding the min.
            {
                ans = arr[low];
                index = low;
            }
            low = mid + 1; // Eliminate left half
        }
        else // if right part is sorted
        {
            if (arr[mid] < ans) // Instead of calling the min() func, we are manually finding the min.
            {
                ans = arr[mid];
                index = mid;
            }
            high = mid - 1; // Eliminate right half
        }
    }
    return index;
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int ans = findKRotation(arr);
    cout << "The array is rotated " << ans << " times.\n";
    return 0;
}
