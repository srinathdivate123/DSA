#include <bits/stdc++.h>
using namespace std;
// Insert an element from the unsorted array to its correct position in the sorted array!
void merge(vector<int> &arr, int left, int mid, int r);

void printArray(vector<int> &arr, int n)
{
    cout << "Printing array:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n\n";
}

// In this function, we are only dividing the arrays. We're not sorting it.
void mergeSort(vector<int> &arr, int low, int high)
{
    if (low == high)
        return;
    // If low==high, then it means that we have only one element in the array and there's no need to sort it.

    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);      // mergeSort on left side.
    mergeSort(arr, mid + 1, high); // mergeSort on right side.
    merge(arr, low, mid, high);
}



void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;    // temporary array, This is the space complexity
    int left = low;      // starting index of left half of arr
    int right = mid + 1; // starting index of right half of arr

    // storing elements in the temporary array in a sorted manner

    while (left <= mid && right <= high) // While we still have elements on the left & we still have elements on the right!
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]); // Add the left pointer's element to temp if it is larger
            left++;
        }
        else
        {
            temp.push_back(arr[right]); // Add right pointer's element to temp if it is larger
            right++;
        }
    }

    // It doesn't matter if we push the arr[left] first or the arr[right] first because anyways only one of these blocks below is going to get executed.
    // The above while loop will cease to execute even if any one of the conditions are false, so if any one of the conditions are false then that corresponding while loop below will not execute!

    // if elements on the left half are still left
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    // if elements on the right half are still left
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    // transfering all elements from temporary to arr
    for (int i = low; i <= high; i++)
        arr[i] = temp[i - low];
}



int main()
{
    int n;
    cout << "Enter array size - ";
    cin >> n;
    vector<int> arr;
    cout << "Enter array - ";
    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        arr.push_back(a);
    }
    cout << "Before sorting - " << endl;
    printArray(arr, n);
    mergeSort(arr, 0, n - 1);
    cout << "After sorting - " << endl;
    printArray(arr, n);
    return 0;
}