#include <iostream>
using namespace std;
// For this, elements have to be in sorted order!
// Dividing array into half and then searching!

int binarySearch(int arr[], int n, int key)
{
    int start = 0, end = n;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            end = mid - 1;
        else if (arr[mid] < key)
            start = mid + 1;
    }
    return -1;
}

int main()
{
    int n, key;
    cout << "The array must be sorted - ";
    cout << "Enter array size - ";
    cin >> n;
    int arr[n];
    cout << "Enter array - ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter key - ";
    cin >> key;
    cout << "Element found at index - " << binarySearch(arr, n, key);
    return 0;
}