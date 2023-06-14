#include <bits/stdc++.h>
using namespace std;
void printArray(int arr[], int n)
{
    cout << "Printing array:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n\n";
}
// The Dutch National Flag Algorithm
// Use three pointers: low, mid & high and follow below rules.
// From 0 to low-1 we have only 0's
// From low to mid-1 we have only 1's
// From mid to high we have 0's, 1's and 2's in an unsorted order.
// From high+1 to n-1 we have only 2's
// Initially mid=0 and high=n-1 because the entire array is unsorted. Put low=0 as it is starting index
// When mid is iterating through the array: arr[mid] may be equal to 0, 1, 2.
// When arr[mid] == 0 -> swap(arr[low], arr[mid]); low++; mid++;
// When arr[mid] == 1 -> mid++;
// When arr[mid] == 2 -> swap(arr[mid], arr[high]); high--;
// TC = N because if arr[mid] == 0, 1, 2 we are sorting one element. Thus we're sorting one element every iteration and we need N iterations!
// SC = 1
void Dutch_National_Flag_Algorithm(int arr[], int n)
{
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
            mid++;
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main()
{
    int arr[] = {
        0,
        1,
        1,
        0,
        1,
        2,
        1,
        2,
        0,
        0,
        0,
    };
    int n = sizeof(arr) / sizeof(arr[0]);
    Dutch_National_Flag_Algorithm(arr, n);
    printArray(arr, n);

    return 0;
}