#include <bits/stdc++.h>
using namespace std;
// Leader is defined as an element towards the right of which only smaller elements are present
// The last element will always be a leader because there are no elements on the right to it
// Return the leaders array in which they occour in the array


// TC - N
// SC - N in worst case if all elements are leaders
void best(vector<int> arr, int n)
{
    int lastLargest = arr[n-1];
    vector<int> leaders;
    for (int i = n - 1; i >= 0; i--)
    {
        lastLargest = max(arr[i], lastLargest);
        if (arr[i] >= lastLargest)
            leaders.insert( leaders.begin(),arr[i]); // Note that we're inserting in the beginning of the vector because we are iterating from back and we want the elements to be in the leaders array in the same order that they were in the arr array
    }
    for (int it : leaders)
        cout << it << " ";
}

int main()
{
    vector<int> arr = {10, 22, 12, 3, 0, 6};
    best(arr, arr.size());
    return 0;
}