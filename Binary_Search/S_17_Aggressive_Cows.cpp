// You are given an array arr of size n which denotes the position of stalls.
// You are also given an integer k which denotes the number of aggressive cows.
// You are given the task of assigning stalls to k cows such that the minimum distance between any two of them is the maximum possible.
// Find the maximum possible minimum distance.

// --> Basically here we check if it is possible to arrange k cows with a gap ranging from [ 1 , max(stalls)-min(stalls) ]. max(stalls)-min(stalls) is the largest possible gap (from starting to ending stall).

#include <bits/stdc++.h>
using namespace std;

// Checks the possibility if we can place
bool canWePlace(vector<int> stalls, int dist, int cows)
{
    int n = stalls.size();
    int cntCows = 1;
    int last = stalls[0]; // position of last placed cow.
    for (int i = 1; i < n; i++)
    {
        if (stalls[i] - last >= dist) // if the distance bw the last-cow-placed-stall and stalls[i] is greater than dist, then place a cow at stalls[i]
        {
            cntCows++;        // place next cow.
            last = stalls[i]; // update the last location.
        }
        if (cntCows >= cows)
            return true;
    }
    return false;
}

// Binary search from 1 to max(stalls)-min(stalls)
int aggressiveCows(vector<int> stalls, int cows)
{
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());
    int low = 1, high = stalls[n - 1] - stalls[0];

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (canWePlace(stalls, mid, cows) == true)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return high;
}

int main()
{
    vector<int> stalls = {0, 3, 4, 7, 10, 9};
    int cows = 4;
    int ans = aggressiveCows(stalls, cows);
    cout << "The maximum possible minimum distance is: " << ans << "\n";
    return 0;
}