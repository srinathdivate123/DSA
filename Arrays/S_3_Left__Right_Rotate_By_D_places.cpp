// Bruteforce approach would be to do d%=n and take a temp array, store elements from 0 to d in it, And pre-shift the remaining elements in the arr by d places. Add the temp elements in the end after pre-shifting. TC = n+d and SC = d

// For below optimal approach TC = 2n and SC = 1
#include <bits/stdc++.h>
using namespace std;
void printArray(int arr[], int n)
{
    cout << "Printing array:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n\n";
}
void reverseArray(int arr[], int left, int right)
{
    while (left < right)
    {
        arr[left] = arr[left] + arr[right];
        arr[right] = arr[left] - arr[right];
        arr[left] = arr[left] - arr[right];
        left++;
        right--;
    }
}

void leftrotate(int arr[], int n, int d)
{
    d %= n; // Because if we have to rotate the array by d (>n) times it is equivalent to rotating it by d%n times because if you rotate an array by n places, then you get the original array back.
    reverseArray(arr, 0, d - 1); // Reverse from 0th to d-1 th index
    reverseArray(arr, d, n - 1); // Reverse from dth to n-1 th index
    reverseArray(arr, 0, n - 1); // Reverse entire array
}

void rightRotate(int arr[], int n, int d)
{
    d %= n;
    reverseArray(arr, 0, n - d - 1);
    reverseArray(arr, n - d, n - 1);
    reverseArray(arr, 0, n - 1);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; // Needn't be in sorted order!
    int n = sizeof(arr) / sizeof(arr[0]);
    int d = 4;
    cout << "After left rotating - " << endl;
    leftrotate(arr, n, d);
    printArray(arr, n);

    cout << "After right rotating - \n"
         << endl;
    rightRotate(arr, n, d);
    rightRotate(arr, n, d); // Doing it twice to cancel the left rotation
    printArray(arr, n);
    return 0;
}