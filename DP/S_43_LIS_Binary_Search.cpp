#include <bits/stdc++.h>
using namespace std;

// TC = n * log(n). n for outer loop and log(n) for Binary Search.
int longestIncreasingSubsequence(vector<int> &arr, int n)
{
    // Store the LIS
    vector<int> temp;
    temp.push_back(arr[0]);

    int len = 1;

    for (int i = 1; i < n; i++)
        if (arr[i] > temp.back())
        {
            // If arr[i] is greater than the last element of temp, extend the subsequence by adding it to the array.
            temp.push_back(arr[i]);
            len++;
        }
        else
        {
            // If arr[i] is not greater, replace the element in temp with arr[i]
            int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            // Lower bound returns the index of arr[i] if it exists. If it does not exist, is returns the index of the element just  greater that arr[i];
            temp[ind] = arr[i];
        }
    return len;
}

int main()
{
    vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = arr.size();
    cout << longestIncreasingSubsequence(arr, n);
    return 0;
}