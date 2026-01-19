// Given a number K, find the length of the longest subarray whose sum is less than K

#include <bits/stdc++.h>
using namespace std;

// TC = O(N+N) because of two for loops
// SC = O(1)
void better(vector<int> arr, int K)
{
    int left = 0;
    int right = 0;
    int n = arr.size();
    int sum = 0;
    int maxLen = INT_MIN;

    while (right < n)
    {
        sum += arr[right];

        // Shrink window size if you find sum has become > K
        while (sum > K)
        {
            sum -= arr[left];
            left++;
        }
        if (sum <= K)
        {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
    }
    cout << maxLen << endl;
}

// TC = O(N)
// SC = O(1)
void best(vector<int> arr, int K)
{
    int left = 0;
    int right = 0;
    int n = arr.size();
    int sum = 0;
    int maxLen = INT_MIN;

    while (right < n)
    {
        sum += arr[right];
        // Here you shrink the subarray by many places until the sum becomes <= K
        // But once you have already found that (let's say) 3 is the maxLen
        // The you wouldn't settle for 2 as the next maxLen at all
        // So there is no use of shrinking the window to any size lesser than 3
        // Hence you shrink it only by 1 and hence replace while loop by if condition
        // i.e. you always keep the same max window size (3) throughout your further search
        if (sum > K)
        {
            sum -= arr[left];
            left++;
        }
        if (sum <= K)
        {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
    }
    cout << maxLen << endl;
}

int main()
{
    int K = 14;
    vector<int> arr = {2, 5, 1, 10, 10};
    better(arr, K);
    best(arr, K);
    return 0;
}