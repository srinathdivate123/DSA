#include <bits/stdc++.h>
using namespace std;
// This optimal approach of N TC is a based on a modification of Kadane's algorithm. But it is not a very intuiive approach. It is only a algo that can be told if you remember it. So don't tell the below algo in interviews as it seems pre-planned!

int kadane_algo_based_optimal_approach(vector<int> nums)
{
    int prod1 = nums[0],prod2 = nums[0],result = nums[0];
    for(int i=1;i<nums.size();i++) {
        int temp = max({nums[i],prod1*nums[i],prod2*nums[i]});
        prod2 = min({nums[i],prod1*nums[i],prod2*nums[i]});
        prod1 = temp;
        
        result = max(result,prod1);
    }
    return result;
}

// Tell below in interviews
// TC = N
int observation_based_optimal_approach(vector<int> &arr)
{
    int ans = INT_MIN;
    int prefix = 1, suffix = 1;
    for(int i = 0; i < arr.size(); i++)
    {
        if(prefix == 0)
            prefix = 1;
        if(suffix == 0)
            suffix = 1;
        prefix *= arr[i];
        suffix *= arr[arr.size() - i - 1];
        ans = max(ans, max(prefix, suffix));
    }
    return ans;
}


int main()
{
    vector<int> arr = {2, 3, -2, 4};
    observation_based_optimal_approach(arr);
    return 0;
}