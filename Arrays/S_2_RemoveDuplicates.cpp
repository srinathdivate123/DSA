// The array given to you is sorted and you cannot use any extra array to solve.
// You should return the same array as the answer
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of elements in array - ";
    cin >> n;
    vector<int> arr;
    cout << "Enter array in sorted order - ";
    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        arr.push_back(a);
    }
    int i = 0;
    for (int j = 1; j < n; j++)
        if (arr[j] != arr[i])
            arr[++i] = arr[j];

    cout << "Number of unique elements in array - " << i + 1 <<endl;
    cout << "The unique array is - " <<endl;
    for(int k=0; k<=i;k++)
    cout<< arr[k] <<" ";
    return 0;
}