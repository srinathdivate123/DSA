// Given a number K, find the elments of the longest subarray whose sum is less than K

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

    int leftAns = 0;
    int rightAns = 0;

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
            if (maxLen <= right - left + 1)
            {
                maxLen = right - left + 1;
                leftAns = left;
                rightAns = right;
            }
        }
        right++;
    }
    cout << maxLen << endl;
    cout << leftAns << " " << rightAns << endl;
}

void best(vector<int> arr, int K)
{
    // The better is only the best solution. You cannot optimize it further by replacing the inner while loop by a if condition
    // Because here you need the left & right ends of the window
}

int main()
{
    int K = 14;
    vector<int> arr = {2, 5, 1, 7, 10};
    better(arr, K);
    return 0;
}