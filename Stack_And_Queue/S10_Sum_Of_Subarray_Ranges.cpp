// https://takeuforward.org/data-structure/sum-of-subarray-ranges
// https://leetcode.com/problems/sum-of-subarray-ranges/description/

// You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.
// Return the sum of all subarray ranges of nums.
// A subarray is a contiguous non-empty sequence of elements within an array.

// Brute is to find all subarrays

// In previous question, you've solved "Sum Of Subarray Minimum". Similarly, you can also solve "Sum Of Subarray Maximum". And then find the difference between the two to find the range.

// NSE - Next Smaller Element
// PSEE - Previous Smaller or Equal Element
// NGE - Next Greater Element
// PGEE - Previous Smaller or Greater Element

// Use NSE and PSEE to calculate the total contribution of each element as the minimum in subarrays
// Use NGE and PGEE to calculate the total contribution of each element as the maximum in subarrays
// Subtract the total of subarray minimums from the total of subarray maximums

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

    vector<int> findNGE(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] <= arr[i])
                st.pop();

            ans[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }

        // Return the answer
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
            // If there is an equal element, we don't pop the stack
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

    /* Function to find the indices of
    previous greater or equal elements */
    vector<int> findPGEE(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] < arr[i])
                st.pop();
            ans[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }
        return ans;
    }

    // Same as previous question
    long long sumSubarrayMins(vector<int> &arr)
    {
        vector<int> nse = findNSE(arr);
        vector<int> psee = findPSEE(arr);
        int n = arr.size();
        long long sum = 0;

        for (int i = 0; i < n; i++)
        {
            int left = i - psee[i];
            int right = nse[i] - i;
            long long freq = left * right * 1LL;
            long long val = (freq * arr[i] * 1LL);
            sum += val;
        }
        return sum;
    }

    // Similar to the previous question. Here we just find max
    long long sumSubarrayMaxs(vector<int> &arr)
    {
        vector<int> nge = findNGE(arr);
        vector<int> pgee = findPGEE(arr);
        int n = arr.size();
        long long sum = 0;

        for (int i = 0; i < n; i++)
        {
            int left = i - pgee[i];
            int right = nge[i] - i;
            long long freq = left * right * 1LL;
            long long val = (freq * arr[i] * 1LL);
            sum += val;
        }
        return sum;
    }

public:
    long long subArrayRanges(vector<int> &arr)
    {
        return (sumSubarrayMaxs(arr) - sumSubarrayMins(arr));
    }
};

int main()
{
    vector<int> arr = {1, 2, 3};
    Solution sol;
    cout << sol.subArrayRanges(arr);
    return 0;
}