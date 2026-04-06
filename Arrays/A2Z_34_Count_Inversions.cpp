// NEED TO STUDY THIS

// https://takeuforward.org/data-structure/count-inversions-in-an-array
// Need to search similar question on LC

// Given an array of N integers, count the inversion of the array (using merge-sort).
// An inversion in an array is defined as a pair of indices (i, j) such that i < j and a[i] > a[j]. This measures how far the array is from being sorted.

#include <bits/stdc++.h>
using namespace std;

// Brute force is to use two nested loops:
// --> Outer loop runs for each element a[i].
// --> Inner loop checks all elements a[j] where j > i.
// --> If a[i] > a[j], increment cnt.
// After traversing all pairs, return cnt as the number of inversions.

// ---------------------------------------------------------------------------------------------

// Brute force approach compares all pairs, but that takes O(N^2) time. We can optimize this using the merge sort algorithm. While merging two sorted halves, if an element in the left half is greater than an element in the right half, then all remaining elements in the left half will also be greater than that right element. This allows us to count multiple inversions in one step, instead of checking each pair individually.

// --> Apply merge sort recursively to divide the array into two halves.
// --> During the merge step:
// -----> If arr[left] <= arr[right], place arr[left] into the temp array and move left++.
// -----> Otherwise, place arr[right] into the temp array. Since arr[left] > arr[right], all elements from arr[left] to arr[mid] form inversions with arr[right]. So add (mid - left + 1) to the inversion count.
// --> Copy the merged elements back into the original array.
// --> The total inversion count is the sum of:
// -----> Inversions in the left half
// -----> Inversions in the right half
// -----> Inversions across the halves (counted during merge)

int merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;    // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1; // starting index of right half of arr

    // storing elements in the temporary array in a sorted manner//
    int cnt = 0;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else // right is smaller
        {
            temp.push_back(arr[right]);
            cnt += mid - left + 1;
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++)
        arr[i] = temp[i - low];
    return cnt;
}

int mergeSort(vector<int> &arr, int low, int high)
{
    int cnt = 0;
    if (low >= high)
        return cnt;
    int mid = (low + high) / 2;
    cnt += mergeSort(arr, low, mid);      // left half
    cnt += mergeSort(arr, mid + 1, high); // right half
    cnt += merge(arr, low, mid, high);    // merging sorted halves
    return cnt;
}

int numberOfInversions(vector<int> &arr, int n)
{
    return mergeSort(arr, 0, n - 1);
}
int main()
{
    vector<int> arr = {5, 3, 2, 4, 1};
    cout << numberOfInversions(arr, arr.size());
    return 0;
}