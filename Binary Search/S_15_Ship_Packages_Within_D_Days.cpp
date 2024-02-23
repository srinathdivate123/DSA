/*
A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights, do not change the order). The ship runs once per day. We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.
*/

// The range of answers is (max element in array, sum of all elements in array).
// The min range of ans is the max element in array because the max element also has to be loaded into the ship, so the capacity of ship must be atleast that much.
// The max range of ans is the sum of all elements assuming that we have d=1 and we have to load all items on same day.

#include <bits/stdc++.h>
using namespace std;

bool find_Possibility_With_Given_Capicity(vector<int> &weights, int cap, int d)
{
    int days = 1; // First day.
    int load = 0;
    int n = weights.size();
    for (int i = 0; i < n; i++)
        if (load + weights[i] > cap)
        {
            days += 1; // move to next day as it is beyond the capacity of the current day
            if (days > d)
                return false;
            load = weights[i]; // load the weight.
        }
        else // load the weight on the same day.
            load += weights[i];
    return true;
}

int leastWeightCapacity(vector<int> &weights, int d)
{
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (find_Possibility_With_Given_Capicity(weights, mid, d))
            // eliminate right half to find the minimum
            high = mid - 1;
        else
            // eliminate left half as capicity is it is not possible with given capicity or less than given capicity
            low = mid + 1;
    }
    return low;
}

int main()
{
    vector<int> weights = {5, 4, 5, 2, 3, 4, 5, 6};
    int d = 5;
    cout << leastWeightCapacity(weights, d);
    return 0;
}
