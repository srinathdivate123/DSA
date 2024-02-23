// Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

// Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

#include <bits/stdc++.h>
using namespace std;

bool sumByD(vector<int> &arr, int divisor, int limit)
{
    int n = arr.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += ceil((double)(arr[i]) / (double)(divisor));
        if (sum > limit)
            return false;
    }
    return true;
}

int smallestDivisor(vector<int> &arr, int limit)
{
    int n = arr.size();
    if (n > limit)
        return -1;
    int low = 1, high = *max_element(arr.begin(), arr.end());

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (sumByD(arr, mid, limit))
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int limit = 8;
    cout << smallestDivisor(arr, limit);
    return 0;
}
