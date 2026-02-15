// https://takeuforward.org/data-structure/sum-of-subarray-minimums
// https://leetcode.com/problems/sum-of-subarray-minimums/

// Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 10^9 + 7.

// Brute force is to generate all subarays and find the answer

// For every element, you need to compute, Next Smaller Element and Previous Smaller Element
// Use a stack to find the index of the next smaller element to the right for each position
// Use another stack to find the index of the previous smaller or equal element to the left for each position
// For each element, determine how many subarrays it appears in as the minimum using its NSE and PSEE indices
// Calculate the contribution of each element by multiplying its value with its frequency
// Add each contribution to a total sum
// Return the total sum modulo 10^9 + 7

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> findNSE(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st; // Remember, stack stores the indices

        // Start traversing from the back
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            if (st.empty())
                ans[i] = n;
            else
                ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> findPSEE(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        // Traverse on the array
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] > arr[i]) // Note that there is no '=' here because we don't want to count the same element in NSE and PSEE. That's why this is called PSEE instead of PSE
            {
                st.pop();
            }
            if (st.empty())
                ans[i] = -1;
            else
                ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

public:
    int sumSubarrayMins(vector<int> &arr)
    {
        vector<int> nse = findNSE(arr);   // This will give you the NSE index (not the element)
        vector<int> psee = findPSEE(arr); // This will give you the PSEE index (not the element)
        int n = arr.size();

        int mod = (int)1e9 + 7;
        int sum = 0;

        // First type of subarrays: The nearest previous index where the element is smaller than arr[i]
        // Second type of subarrays: The nearest next index where the element is smaller than arr[i]
        // Hence, arr[i] is the smallest element in the indices from psee[i] to nse[i]
        for (int i = 0; i < n; i++)
        {
            // Count of first type of subarrays
            // i.e. the extent towards the left
            int left = i - psee[i];

            // Count of second type of subarrays
            // i.e. the extent towards the right
            int right = nse[i] - i;

            // Count of subarrays where current element is minimum
            // Just need to multiply left & right to find out the number of combinations
            long long freq = left * right * 1LL;

            // Contribution due to current element
            int val = (freq * arr[i] * 1LL) % mod;

            // Updating the sum
            sum = (sum + val) % mod;
        }
        return sum;
    }
};

int main()
{
    vector<int> arr = {3, 1, 2, 5};
    Solution sol;
    cout << sol.sumSubarrayMins(arr);
    return 0;
}