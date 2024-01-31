#include <bits/stdc++.h>
using namespace std;

// TC = SC = n*n
int tabulation(vector<int> arr, int n)
{
    // No need of base case as we're anyways assigining everything to 0.
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int ind = n - 1; ind >= 0; ind--)
        for (int prev_index = ind - 1; prev_index >= -1; prev_index--)
        {
            int notTake = 0 + dp[ind + 1][prev_index + 1]; // We're writing prev_index + 1 because we've done coordinate shift.
            int take = 0;

            if (prev_index == -1 || arr[ind] > arr[prev_index]) // Here you've not done +1 while accessing the second parameter because you are accessing the arr and not the dp!
                take = 1 + dp[ind + 1][ind + 1]; // Here also we write the second parameter in the +1 state because we have done coordinate shift. So the second parameter always has to be written in the +1 state.

            dp[ind][prev_index + 1] = max(notTake, take);
        }
    return dp[0][0];
}

// TC = n*n, SC = 2n
int spaceOptimised(vector<int> arr, int n)
{
    vector<int> next(n + 1, 0), cur(n + 1, 0);

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev_index = ind - 1; prev_index >= -1; prev_index--)
        {
            int notTake = 0 + next[prev_index + 1];

            int take = 0;

            if (prev_index == -1 || arr[ind] > arr[prev_index]) // Here you've not done +1 while accessing the second parameter because you are accessing the arr and not the dp!
                take = 1 + next[ind + 1];

            cur[prev_index + 1] = max(notTake, take);
        }
        next = cur;
    }
    return cur[0];
}

// In below dp[i] signifies the longest increasing subsequence "ending" at i. The final ans LIS will be the max of dp[0...n].
// TC = n*n, SC = n
// This solution will be required if you want to trace back the LIS.
int Different_Tabulation(vector<int> arr, int n)
{
    // We initialize all of them to 1 because the LIS upto that element will atleast be 1 (i.e. if only the element is counted in the LIS)
    vector<int> dp(n, 1);
    int maxi = 1;
    for (int ind = 0; ind < n; ind++)
    {
        for (int prev = 0; prev < ind; prev++)
            if (arr[prev] < arr[ind])
                dp[ind] = max(dp[ind], 1 + dp[prev]); // If arr[prev] < arr[ind] then it can be a part of the LIS of arr[ind]. We are taking 1 + dp[prev] to include the no of LIS'es that end with arr[prev] and add 1 to it.
        maxi = max(maxi, dp[ind]);
    }
    return maxi;
}

// TC = n*n, SC = n
// If n = 10^5 this wil give s TLE.
int Different_Tabulation_For_Printing(vector<int> arr, int n)
{
    vector<int> dp(n, 1), hash(n, 1);
    int maxi = 1;
    int lastIndex = 0;

    for (int ind = 0; ind < n; ind++)
    {
        hash[ind] = ind;
        for (int prev = 0; prev < ind; prev++)
            if (arr[prev] < arr[ind] && dp[ind] < 1 + dp[prev]) // The second condition is like taking the max as in the prev function!
            {
                dp[ind] = 1 + dp[prev];
                hash[ind] = prev;
            }

        if (dp[ind] > maxi)
        {
            maxi = dp[ind];
            lastIndex = ind;
        }
        // lastIndex is the index at which the LSI ends.
    }

    vector<int> temp;
    temp.push_back(arr[lastIndex]); // This is the element at which the LSI ends.
    while (hash[lastIndex] != lastIndex) // This loop will stop when hash[lastIndex] = lastIndex. That will happen when they are = 1, which will be when we reach the first element.
    {
        lastIndex = hash[lastIndex];
        temp.push_back(arr[lastIndex]);
    }
    reverse(temp.begin(), temp.end());
    for (auto it : temp)
        cout << it << " ";
}

int main()
{
    vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = arr.size();

    cout << tabulation(arr, n) << endl;
    cout << spaceOptimised(arr, n) << endl;
    cout << Different_Tabulation(arr, n) << endl;
    cout << Different_Tabulation_For_Printing(arr, n) << endl;

    return 0;
}