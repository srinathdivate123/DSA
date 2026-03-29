// This question is not there on LC and TUF blog.
// It is there from TUF video ONLY

// Given two sorted arrays nums1 and nums2 of sizes n and m in ascending order. Merge them in sorted order. Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.

// SPOILER ALERT: You cannot use extra space here
#include <bits/stdc++.h>
using namespace std;

void optimal_1(vector<int> arr1, int n, vector<int> arr2, int m)
{
    // Basically you need to make sure that the correct set of elements are in the correct array
    // These "correct set" of elements need not necessarily be in the sorted order in the "correct array"
    // They just have to be in their "correct array" in any order
    // Because we'll be sorting these two arrays later

    int left = n - 1; // last index of the arr1
    int right = 0;    // first index of the arr2
    // Below takes TC of min(n, m)
    while (left >= 0 && right < m)
    {
        if (arr1[left] > arr2[right])
        {
            // The arr1[left] is greater that arr2[right] so it should actually go to the second array
            // Hence, swap the elements
            swap(arr1[left], arr2[right]);
            left--;
            right++;
        }
        else
        {
            // If you find that the above condition is false
            // Then it means all the elements are in their respective arrays, but they may be in unsorted order
            // Hence, you need to sort the individual halves below
            break;
        }
    }
    sort(arr2.begin(), arr2.end()); // TC = m*log(m)
    sort(arr1.begin(), arr1.end()); // TC = n*log(n)

    for (int element : arr1)
        cout << element << " ";
    for (int element : arr2)
        cout << element << " ";
}

void swapIfGreater(vector<int> &arr1, vector<int> &arr2, int index1, int index2)
{
    if (arr1[index1] > arr2[index2])
    {
        swap(arr1[index1], arr2[index2]);
    }
}

// This uses GAP method which uses the 'Shell Sort' algorithm
// TC = log2(n) for outer while loop and (n + m) for inner while loop. The log2() comes here because we're dividing by 2 in the loop
// SC = (1)

void optimal_2_gap_method(vector<int> &arr1, vector<int> &arr2, int n, int m)
{
    int len = n + m;
    // You need to compute something that is called as the 'gap'
    // Initial gap = ceil((n + m) / 2)
    int gap = (len / 2) + (len % 2); // We're adding this len%2 term which is equivalent to taking the ceil of len/2

    // You need to iteratively divide gap by 2 with a ceil until gap becomes 1
    while (gap > 0)
    {
        int left = 0;
        int right = left + gap;

        // As soon as right exceeds the len, stop
        while (right < len)
        {
            // Left is in arr1 & right is in arr2
            if (left < n && right >= n)
                swapIfGreater(arr1, arr2, left, right - n); 

            // If left is >=n then obv right >= n so no need to write condition for right. Both are in arr2
            else if (left >= n)
                swapIfGreater(arr2, arr2, left - n, right - n);

            else // Both pointers are in arr1
                swapIfGreater(arr1, arr1, left, right);
            left++, right++;
        }
        if (gap == 1)
            break;
        gap = (gap / 2) + (gap % 2);
    }
    for (auto element : arr1)
        cout << element << " ";
    for (auto element : arr2)
        cout << element << " ";
}

int main()
{
    vector<int> arr1 = {1, 4, 8, 10};
    vector<int> arr2 = {2, 3, 9};
    // optimal_1(arr1, arr1.size(), arr2, arr2.size());
    optimal_2_gap_method(arr1, arr2, arr1.size(), arr2.size());
    return 0;
}