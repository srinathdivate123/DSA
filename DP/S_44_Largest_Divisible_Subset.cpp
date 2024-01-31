// A divisible subset is the one in which if we pick two elements i and j from the subset, then either arr[i]%arr[j] == 0 "OR" arr[j] % arr[i] == 0. For example, [16,8,4] is a divisible subset.

// Given an array with distinct elements, we need to print its longest divisible subset. We can print any subset (means in any order).

#include <bits/stdc++.h>
using namespace std;

// This is same as the LIS code in 42nd question with minor changes
vector<int> divisibleSet(vector<int> &arr)
{
    int n = arr.size();

    sort(arr.begin(), arr.end());

    vector<int> dp(n, 1);   // dp[i] stores the length of the divisible subset ending at arr[i]
    vector<int> hash(n, 1); // hash[i] stores the previous index in the divisible subset ending at arr[i]

    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int prev_index = 0; prev_index < i; prev_index++)
            if (arr[i] % arr[prev_index] == 0 && 1 + dp[prev_index] > dp[i])
            {
                dp[i] = 1 + dp[prev_index];
                hash[i] = prev_index;
            }
    }

    int ans = -1;
    int lastIndex = -1;

    for (int i = 0; i < n; i++)
        if (dp[i] > ans)
        {
            ans = dp[i];
            lastIndex = i;
        }

    vector<int> temp;
    temp.push_back(arr[lastIndex]);

    // Reconstruct the divisible subset using the hash table
    while (hash[lastIndex] != lastIndex)
    {
        lastIndex = hash[lastIndex];
        temp.push_back(arr[lastIndex]);
    }

    // Here we don't need to reverse the answer because subsets can be in any order!

    return temp;
}

int main()
{
    vector<int> arr = {1, 16, 7, 8, 4};
    vector<int> ans = divisibleSet(arr);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}