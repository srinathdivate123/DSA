// The array given to you is sorted and you cannot use any extra array to solve.
// You should return the same array as the answer
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {3, 4, 5, 5, 6, 7, 7, 8, 9, 10}; // Must be sorted
    int n = arr.size();
    int i = 0;
    for (int j = 1; j < n; j++)
        if (arr[j] != arr[i])
            arr[++i] = arr[j];
    cout << "Number of unique elements in array - " << i + 1 << endl;
    cout << "The unique array is - " << endl;
    for (int k = 0; k <= i; k++)
        cout << arr[k] << " ";
    return 0;
}