#include <bits/stdc++.h>
using namespace std;
// Find the minimum element in the unsorted array and swap it with the element at the beginning of the unsorted part of array.
void printArray(int arr[], int n)
{
    cout << "Printing array:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++) // Note the n-1 here. We run upto <n-1 because in next loop we wouldn't have any j=i+1 if we run upto <n. The last element would be naturally sorted by the time control reaches there.
    {
        // Finding the minumum element
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (arr[min] > arr[j])
                min = j;
                
        // Swap min element with i-th element
        arr[i] = arr[i] + arr[min];
        arr[min] = arr[i] - arr[min];
        arr[i] = arr[i] - arr[min];
    }
}

int main()
{
    int n;
    cout << "Enter array size - ";
    cin >> n;
    int arr[n];
    cout << "Enter array - ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    printArray(arr, n);
    selectionSort(arr, n);
    printArray(arr, n);
    return 0;
}