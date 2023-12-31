#include <bits/stdc++.h>
using namespace std;
void printArray(vector<int> &arr, int n)
{
    cout << "Printing array:\n";
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << "\n\n";
}
// The different permutations of [1, 2, 3] are 1,2,3  1,3,2  2,1,3  2,3,1  3,1,2  3,2,1
// The "next permutation" of [3,1,2] is [3,2,1] as in the ascending order
// If there is no next permutation for the array, then return the first permutation.
// Eg for [3,2,1] next permutation is [1,2,3]

// Generate all the permutations of array which would take N!*N time complexity and then search the given array in it and the next array will be the "next permutation"
void brute() {}

// STL has inbuilt function next_permutation(arr.begin(), arr.end());
// Tell this solution to the interviewer because it tells that you have knowledge of STL
void better() {}

// Find the breakpoint in the array.  Break-point means the first index i from the back of the given array where arr[i] becomes smaller than arr[i+1].
// Then the find the element in the right side of the breakpoint that is just larger than it
// Swap the breakpoint & that element
// Place the remaining elements of the array in a sorted order
void best(vector<int> &arr, int n)
{
    int breakPoint = -1;
    for (int i = n - 2; i >= 0; i--)
        if (arr[i] < arr[i+1])
        {
            breakPoint = i;
            break;
        }
    if (breakPoint == -1) // Means all elements are in sorted order
    {
        reverse(arr.begin(), arr.end());
        printArray(arr, n);
        return;
    }

    for (int i = n - 1; i > breakPoint; i--)
        if (arr[i] > arr[breakPoint])
        {
            swap(arr[i], arr[breakPoint]);
            break;
        }
    sort(arr.begin() + breakPoint + 1, arr.end());
    printArray(arr, n);
    return;
}

int main()
{
    vector<int> arr = {2,1,5,4,3,0,0};
    best(arr, arr.size());
    return 0;
}