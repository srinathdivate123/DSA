/* A thief needs to rob money in a street. The houses in the street are arranged in a circular manner. Therefore the first and the last house are adjacent to each other. The security system in the street is such that if adjacent houses are robbed, the police will get notified.

Given an array of integers “Arr” which represents money at each house, we need to return the maximum amount of money that the thief can rob without alerting the police. */

// TC = N, SC = 1
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr)
{
    int n = arr.size();
    int prev = arr[0];
    int prev2 = 0;

    for (int i = 1; i < n; i++)
    {
        int pick = arr[i];
        if (i > 1)
            pick += prev2;
        int nonPick = 0 + prev;

        int cur_i = max(pick, nonPick);
        prev2 = prev;
        prev = cur_i;
    }
    return prev;
}

int robStreet(int n, vector<int> &arr)
{
    vector<int> arr1;
    vector<int> arr2;

    if (n == 1)
        return arr[0];

    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            arr1.push_back(arr[i]);
        if (i != n - 1)
            arr2.push_back(arr[i]);
    }

    int ans1 = solve(arr1);
    int ans2 = solve(arr2);
    return max(ans1, ans2);
}

int main()
{

    vector<int> arr{1, 5, 1, 2, 6};
    int n = arr.size();
    cout << robStreet(n, arr);
}