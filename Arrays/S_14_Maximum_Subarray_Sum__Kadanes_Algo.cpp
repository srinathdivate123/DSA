#include <bits/stdc++.h>
using namespace std;
// Return the maximum sum formed from any subarray
// The intuition of the algorithm is not to consider the subarray as a part of the answer if its sum is less than 0
// A subarray with a sum less than 0 will always reduce our answer and so this type of subarray cannot be a part of the subarray with maximum sum.
// TC = N
// SC = 1
void Kadnes_Algo(int arr[], int n)
{
    long long sum = 0, maxi = LONG_MIN;
    int ansStart = 0, ansEnd = 0, start = 0;
    for (int i = 0; i < n; i++)
    {

        if (sum == 0)
            start = i; // starting index

        sum += arr[i];

        if (sum > maxi)
        {
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0)
            sum = 0;
    }


    cout << "The maximum subarray sum is " << maxi << " and the subarray indices are (" << ansStart << ", " <<ansEnd << ")" ;
}

int main()
{
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
Kadnes_Algo(arr, sizeof(arr) / sizeof(arr[0]));
    return 0;
}