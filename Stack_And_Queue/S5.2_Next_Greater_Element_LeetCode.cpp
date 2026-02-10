// https://leetcode.com/problems/next-greater-element-i/description/

#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &arr)
{
    stack<int> st;
    unordered_map<int, int> mpp;
    int n = arr.size();
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() < arr[i])
        {
            st.pop();
        }
        if (st.empty())
            mpp[arr[i]] = -1;
        else
            mpp[arr[i]] = st.top();
        st.push(arr[i]);
    }
    vector<int> ans;
    for (int i = 0; i < nums1.size(); i++)
    {
        ans.push_back(mpp[nums1[i]]);
    }
    return ans;
}

int main()
{

    return 0;
}