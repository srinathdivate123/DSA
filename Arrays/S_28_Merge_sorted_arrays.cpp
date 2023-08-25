#include <bits/stdc++.h>
using namespace std;

void swapIfGreater(vector<int> &arr1, vector<int> &arr2, int index1, int index2)
{
    if (arr1[index1] > arr2[index2])
        swap(arr1[index1], arr2[index2]);
}

// This uses GAP method which uses the 'Shell Sort' algorithm
// TC = log2(n) for outer while loop + (n+m) for inner while loop
// SC = (1)
void optimal_2_gap_method(vector<int> &arr1, vector<int> &arr2, int n, int m)
{
    int len = n + m;
    int gap = (len / 2) + (len % 2); // We're doing len%2 so that we can take the ceiling of len/2.
    while (gap > 0)
    {
        int left = 0;
        int right = left + gap;
        while (right < len)
        {
            // We're in arr1 & arr2
            if (left < n && right >= n)
                swapIfGreater(arr1, arr2, left, right - n);

            // If left is >=n then right obv >=n so no need to write condition for right. Both are in arr2
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
    for (int element : arr1)
        cout << element << " ";
    for (int element : arr2)
        cout << element << " ";
}

void optimal_1(vector<int> arr1, int m, vector<int> arr2, int n)
{
    int left = m - 1;
    int right = 0;
    // Below takes TC of min(n, m)
    while (left >= 0 && right < n)
        if (arr1[left] > arr2[right])
        {
            swap(arr1[left], arr2[right]);
            left--;
            right++;
        }
        else
            break;
    sort(arr1.begin(), arr1.end() - n); // TC = n*log(n)
    sort(arr2.begin(), arr2.end());     // TC = m*log(m)
    for (int i = m; i < m + n; i++)
        arr1[i] = arr2[i - n];

    for (int element : arr1)
        cout << element << " ";
    cout << endl;
    for (int element : arr2)
        cout << element << " ";
}

int main()
{
    vector<int> arr1 = {0};
    vector<int> arr2 = {1};
    optimal_1(arr1, arr1.size() - arr2.size(), arr2, arr2.size());
    // optimal_2_gap_method(arr1, arr2, arr1.size(), arr2.size());
    return 0;
}