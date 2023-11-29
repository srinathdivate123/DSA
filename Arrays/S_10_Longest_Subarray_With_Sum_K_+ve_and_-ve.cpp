// In case the array has only positive integers then the 'optimised' function is the optimal solution.
// But if the array has positive and negative integers, the 'betterHashing' function is only the optimal solution.

#include <bits/stdc++.h>
using namespace std;
void brute(int arr[], int target, int n)
{
    int len = 0;
    // Find all the sub arrays and find their individual sum
    for (int i = 0; i < n; i++)
    {
        int s = 0;
        for (int j = i; j < n; j++)
        {
            s += arr[j];
            if (s == target)
                len = max(len, j - i + 1);
        }
    }
    cout << len;
}

// This will work for +ves & -ves also in array
void betterHashing(int arr[], int target, int n)
{
    // arr[] = {a, b, c, d, e, f, g}
    // Let the sum of all elements upto e be SUM.
    // If sum of c+d+e=K then sum of a+b = SUM-K
    // Let's say we are standing at e and we get sum upto there as SUM. If anywhere previously we got a sum of SUM-K, which we got from a & b, then the sum of next element after b upto e will be K i.e. sum of c+d+e=K

    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == target)
            maxLen = max(maxLen, i + 1);
        long long rem = sum - target;
        // map::find function is used to search for a specific key in a std::map container. It returns an iterator that points to the element with the specified key if it is found, or it returns the end iterator of the map if the key is not found. So if it returns the end iterator, then the key is not found.
        if (preSumMap.find(rem) != preSumMap.end())
        {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }
        // if array = {2, 0, 0, 3};
        // Here if the target=3, then it should give us the longest subarray as {0, 0, 3} and not just {3}, that's why we are checking below condition that if even after going to next element (i.e. 0), the sum remains same, we shouldn't update the index at which the sum was found!
        // If sum is not found then the first condition would return the end iterator, which matches with the second condition, so then only we've to insert in the map.
        if (preSumMap.find(sum) == preSumMap.end()) // Checking if the sum was previously not there. If it was previously not there, then enter into map. If it was previously there, then don't enter into map. We do so because we want the longest subarray.
            preSumMap[sum] = i;
    }
    cout << maxLen;
}

// Only for +ves
// This is the optimal solution for +ves
// TC = 2N (N for the outer while loop and N for the inner while loop)
void optimised(int arr[], int target, int n)
{
    int left = 0, right = 0, maxLen = 0;
    long long sum = arr[0]; // Because both left and right are at 0, so the sum is the first element.
    while (right < n)
    {
        while (left <= right && sum > target)
        {
            sum = sum - arr[left];
            left++;
        }
        if (sum == target)
            maxLen = max(maxLen, right - left + 1);
        right++;
        if (right < n)
            sum += arr[right];
    }
    cout << maxLen;
}

int main()
{
    int arr[] = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3}, target = 3;
    // brute(arr, target, sizeof(arr) / sizeof(arr[0]));
    // betterHashing(arr, target, sizeof(arr) / sizeof(arr[0]));
    optimised(arr, target, sizeof(arr) / sizeof(arr[0]));

    return 0;
}