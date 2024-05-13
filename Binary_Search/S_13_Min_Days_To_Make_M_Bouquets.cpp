/*
You are given an array bloomDay, an integer m and an integer k.

You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

The garden consists of n flowers, the ith flower will bloom on the bloomDay[i] and then can be used in exactly one bouquet.

Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.
*/

#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int> &bloomDay, int day, int m, int k, int n)
{
    int sequenceCount = 0, boquetCount = 0;
    for (int i = 0; i < n; i++)
        if (bloomDay[i] <= day) // If the flower is bloomed
            sequenceCount++;
        else
        {
            boquetCount += (sequenceCount / k); // The number of bouquets with k flowers that can be made with sequenceCount flowers.
            sequenceCount = 0;
        }
    boquetCount += (sequenceCount / k);
    return boquetCount >= m; // Have m boquets been made?
}

int roseGarden(vector<int> bloomDay, int k, int m)
{
    long long val = (long long)m * (long long)k;
    int n = bloomDay.size();
    if (val > n)
        return -1; // Impossible case if the number of bouquets * no of flowers per bouquet is less than the total number of flowers available.
    int low = INT_MAX, high = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        low = min(low, bloomDay[i]);
        high = max(high, bloomDay[i]);
    }
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (possible(bloomDay, mid, m, k, n))
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

int main()
{
    vector<int> bloomDay = {7, 7, 7, 7, 13, 11, 12, 7};
    int k = 3;
    int m = 2;
    cout << roseGarden(bloomDay, k, m);
    return 0;
}