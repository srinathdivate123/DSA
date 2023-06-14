// In case the array has only positive integers then the 'optimised' function is only the optimal solution.
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

void betterHashing(int arr[], int target, int n)
{
    // arr[] = {a,b,c,d,e,f,g}
    // If there exists a subarray having summation K with e as the last element.
    // The sum of c,d,e=k and a,b=x-k; Thus sum of a to e = k.
    // So if anywhere we get a su of x-k then it means that we will get a sum of k ahead.

    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == target)
            maxLen = max(maxLen, i + 1);
        long long rem = sum - target;
        if (preSumMap.find(rem) != preSumMap.end())
        {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }
        // if array = {2, 0, 0, 3};
        // Here if the target=3, then it should give us the longest subarray as {0, 0, 3} and not just {3}, that's why we are checking below condition that if even after going to next element (i.e. 0), the sum remains same, we shouldn't update the index at which the sum was found!
        if (preSumMap.find(sum) == preSumMap.end())
            preSumMap[sum] = i;
    }

    cout << maxLen;
}

void optimised(int arr[], int target, int n)
{
    int left = 0, right = 0, maxLen = 0;
    long long sum = arr[0];
    while (right < n)
    {
        while (left <= right && sum > target)
        {
            sum -= arr[left];
            left++;
        }
        if (sum==target)
        {
            maxLen = max(maxLen, right-left+1);
        }
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