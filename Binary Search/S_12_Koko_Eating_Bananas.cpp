/*
A monkey is given 'n' piles of bananas, whereas the ‘ith’ pile has ‘a[i]’ bananas. An integer 'h' is also given, which denotes the time (in hours) for all the bananas to be eaten.

Each hour, the monkey chooses a non-empty pile of bananas and eats 'k' bananas. If the pile contains less than 'k' bananas, then the monkey consumes all the bananas and won’t eat any more bananas in that hour.

Find the minimum number of bananas 'k' to eat per hour so that the monkey can eat all the bananas within 'h' hours.
*/

#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &piles, int h, int k)
{
    long long ans = 0;
    for (int i = 0; i < piles.size(); i++)
    {
        ans += ceil((double)piles[i] / (double)k);
        if (ans > h)
            return false;
    }
    return true;
}

int minimumRateToEatBananas(vector<int> v, int h)
{
    int low = 1;
    int high = *max_element(v.begin(), v.end()); // Find max element in v
    // Let's say the max element in the array is M, koko can have a maximum eating speed of M bananas per hour. Koko cannot exceed that because it would not make sense to do so. Lets say some pile has m bananas (m<M), then the time m will only be used for eating bananas, the time M-m will go unutilised. So Koko can have a max eating speed of only M bananas per hour.

    while (low <= high)
    {
        int mid = ((high - low) / 2) + low;
        if (check(v, h, mid))
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

int main()
{
    vector<int> v = {7, 15, 6, 3};
    int h = 8;
    cout << minimumRateToEatBananas(v, h);
    return 0;
}