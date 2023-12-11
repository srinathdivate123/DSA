#include <bits/stdc++.h>
using namespace std;
int temp;
int partition(vector<int> &arr, int low, int high);
void printArray(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (low > high)
        return;

    int partitionIndex = partition(arr, low, high); // Index of pivot after partition
    quickSort(arr, low, partitionIndex - 1);        // Sort left subarray, this can be done after sorting the right part also.
    quickSort(arr, partitionIndex + 1, high);       // Sort right subarray
                                                    // We don't need to include the pivot element in the above two function calls, because it is already at its correct position in the array!
    // We can sort left part first or right part first, doesn't matter
}

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        // Finding the firt largest element from the left side larger than pivot.
        // We're writing '<=' while comparing with the pivot because we want all elements less than equal to pivot to be placed to left.
        while (arr[i] <= pivot && i < high)
            i++;

        // Finding the first smaller element from the right side smaller than pivot.
        // Here we do only '>' for comparing with pivot because we have already done '<=' in prev while loop. Also we want that ony the larger (and not 'equal to') elements are placed on the right
        while (arr[j] > pivot && j > low)
            j--;

        if (i < j)
            swap(arr[i], arr[j]); // If i & j haven't crossed, then we swap them.
        // When j crosses i, do not swap because you're already at the left half of the array
    }
    swap(arr[low], arr[j]);
    return j;
}

int main()
{
    vector<int> arr = {3, 22, 5, 2, 4, 5, 6, 5, 5, 44, 35, 56};
    int n = arr.size();
    cout << "Before sorting - " << endl;
    printArray(arr, n);
    quickSort(arr, 0, n - 1);
    cout << "After sorting - " << endl;
    printArray(arr, n);
    return 0;
}