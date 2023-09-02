#include <bits/stdc++.h>
using namespace std;
// For this, elements have to be in sorted order!
// Dividing array into half and then searching!

int binarySearchIterative(int *arr, int n, int key)
{
    int low = 0, high = n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2; // We do this because we can get INT_MAX + INT_MAX, which may overflow.
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int binarySearchRecursive(int *arr, int key, int low, int high)
{
    if (low > high)
        return -1;
    int mid = low + (high - low) / 2; // We do this because we can get INT_MAX + INT_MAX, which may overflow.
    if (arr[mid] == key)
        return mid;
    else if (arr[mid] > key)
        return binarySearchRecursive(arr, key, low, mid - 1);
    return binarySearchRecursive(arr, key, mid + 1, high);
}

int main()
{
    int arr[] = {3, 4, 6, 7, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 10;
    cout << "Element found at index : " << binarySearchIterative(arr, n - 1, key) << endl;
    cout << "Element found at index : " << binarySearchRecursive(arr, key, 0, n - 1) << endl;
    return 0;
}