//  Given an array that contains only 1 and 0 return the count of maximum consecutive ones in the array.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max = 0, count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
            count++;
        else if (arr[i] == 0)
            count = 0;
        if (count > max)
            max = count;
    }
    cout << max;
    return 0;
}