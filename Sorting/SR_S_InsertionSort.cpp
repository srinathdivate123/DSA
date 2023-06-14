#include <iostream>
using namespace std;
// Insert an element from the unsorted array to its correct position in the sorted array!
void printArray(int arr[], int n)
{
    cout << "Printing array:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

void insertionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    // Slowly slowly the size of the sorted array increases and the size of the unsorted array decreases.
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]) // We put j>0 because a 'j-1' th element (which would be -1th when j=0) wouldn't exist.
        // This while loop puts elements in their correct position in the array after comparing the jth element with the j-1 th element.
        // If the array is sorted, then this loop will never run.
        {
            arr[j] = arr[j] + arr[j - 1];
            arr[j - 1] = arr[j] - arr[j - 1];
            arr[j] = arr[j] - arr[j - 1];
            j--;
        }
    }
}


void recursiveInsertionSort(int arr[], int n)
{
    
}


int main()
{
    int n, start = 0;
    cout << "Enter array size - ";
    cin >> n;
    int arr[n];
    cout << "Enter array - ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    printArray(arr, n);
    recursiveInsertionSort(arr, n);
    cout << "After sorting - " << endl;
    printArray(arr, n);
    return 0;
}