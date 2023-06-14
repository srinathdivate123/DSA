// You're given an array arr = {1,1,2,3,3,4,4}
// The answer is 2, as it is the only element which appears once.
// For this you can use the XOR concept!

#include <bits/stdc++.h>
using namespace std;

int func(int arr[], int n)
{
    for (int i = 0; i < n - 1; i += 2)
    {
        int XOR = arr[i] ^ arr[i + 1];
        if (XOR != 0)
            return arr[i];
    }
    return arr[n - 1]; // This will only execute if the last element has occoured once.
}

int main()
{
    int arr[] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6};

    cout << func(arr, sizeof(arr) / sizeof(arr[0]));
    return 0;
}