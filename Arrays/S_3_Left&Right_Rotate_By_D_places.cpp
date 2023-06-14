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

void leftrotate(int arr[], int n, int d)
{
    d%=n; // Because if we have to rotate the array by d (>n) times it is equivalent to rotating it by d%n times because if you rotate an array by n places, then you get the original array back.
    reverse(arr, arr + d);     // Reverse from 0th to d-1 th index
    reverse(arr + d, arr + n); // Reverse from dth to n-1 th index
    reverse(arr, arr + n);     // Reverse entire array
}


void rightRotate(int arr[], int n , int d)
{
    d%=n;
    reverse(arr+n-d,arr+n);
    reverse(arr,arr+n-d);
    reverse(arr,arr+n);

}


int main()
{
    int n, d;
    cout << "Enter no of elements in array - ";
    cin >> n;
    int arr[n];
    cout << "Enter array - ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter number of places you want to left & right rotate - ";
    cin >> d;



    cout << "After left rotating - " << endl;
    leftrotate(arr, n, d);
    printArray(arr, n);

    cout << "After rightrotating - \n" << endl;
    rightRotate(arr, n, d);
    rightRotate(arr, n, d); // Doing it twice to cancel the left rotation
    printArray(arr, n);
    return 0;
}