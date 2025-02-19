// Given two sorted arrays of size m and n respectively, you are tasked with finding the element that would be at the kth position of the final sorted array.

// This problem involves extension of the logic used to solve the previous question. Basically we need to divide the array such that it has k elements on left and the remaining n-k elements on the right

#include <bits/stdc++.h>
using namespace std;

int brute(vector<int> &a, vector<int> &b, int m, int n, int k)
{
    // Merge the two arrays and form a third array. Then return the kth element from it
}

int better(vector<int> &a, vector<int> &b, int m, int n, int k)
{
    // Instead of storing elements in a separate array, we will use a counter called 'cnt' to represent the imaginary third array's index. As we traverse through the arrays, when 'cnt' reaches the index (k-1), we will store that particular element and break. This way, we can achieve the same goal without using any extra space.
}

int best(vector<int> &a, vector<int> &b, int m, int n, int k)
{
    // if m is bigger then swap the arrays, because we want to do BS on the smaller array to reduce time
    if (m > n)
        return best(b, a, n, m, k);

    // Apply binary search. The length of the left half should be k

    int low = max(0, k - n); // If array 'b' has 5 elements and you need to find the 7th element of the merged array, then you need atleast 2 {max(0, 7-5)} elements form the 'a' array as well to get the 7th index of the merged array

    int high = min(k, m); // If array 'a' has 6 elements and we need to find the 2nd element after merging a&b, then at max from array 'a', we will be taking 2 elements i.e. min(2, 6). If we take more than 2 elements from array a, it does not make sense as we need to only find the 2nd element in the sorted array


    while (low <= high)
    {
        int mid1 = (low + high) >> 1;
        int mid2 = k - mid1;
        // calculate l1, l2, r1 and r2;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if (mid1 < m)
            r1 = a[mid1];
        if (mid2 < n)
            r2 = b[mid2];
        if (mid1 - 1 >= 0)
            l1 = a[mid1 - 1];
        if (mid2 - 1 >= 0)
            l2 = b[mid2 - 1];

        if (l1 <= r2 && l2 <= r1)
        {
            return max(l1, l2);
        }

        // eliminate the halves:
        else if (l1 > r2)
            high = mid1 - 1;
        else
            low = mid1 + 1;
    }
    return 0; // dummy statement
}

int main()
{
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    cout << best(a, b, a.size(), b.size(), 5) << endl;
    return 0;
}