// Repeatedly swap two adjacent elements if they are in the wrong order.
#include <iostream>
using namespace std;
void printArray(int arr[], int n)
{
    cout << "Printing array:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

void bubbleSort(int arr[], int n)
{
    // We're putting i=1 because in the below loop we're doing j<n-i. This would mean j<n when i=0. And we'd be accessing the j+1 th element which would be out of index.
    for (int i = 1; i < n; i++)
    {
        // At the end of all of the below loop, the largest element will be at the end of the array!
        int didSwap = 0; // If after iterating through entire array, we did no swaps (all elements in ascending order), means the array is sorted and so we can quit the loop by doing a break. This is use of didSwap variable.

        for (int j = 0; j < n - i; j++) // Note the n-i here! This is because the array from n-i th index onwards would be already sorted because bubble sort, sorts from back.
            if (arr[j] > arr[j + 1])
            {
                arr[j] = arr[j] + arr[j + 1];
                arr[j + 1] = arr[j] - arr[j + 1];
                arr[j] = arr[j] - arr[j + 1];
                didSwap = 1;
            }
        if (didSwap == 0)
            break;
    }
}

void recursive_Bubble_sort(int arr[], int n)
{
    // Base case
    if (n == 1)
        return;

    // One pass of bubble sort. After
    // this pass, the largest element
    // is moved (or bubbled) to end.
    for (int i = 0; i < n - 1; i++)
        if (arr[i] > arr[i + 1])
            swap(arr[i], arr[i + 1]);

    // Largest element is fixed,
    // recur for remaining array
    recursive_Bubble_sort(arr, n - 1);
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
    recursive_Bubble_sort(arr, n);
    cout << "Array after sorting - \n";
    printArray(arr, n);
    return 0;
}