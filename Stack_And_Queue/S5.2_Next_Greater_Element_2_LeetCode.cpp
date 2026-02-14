// https://takeuforward.org/data-structure/next-greater-element-using-stack
// https://leetcode.com/problems/next-greater-element-i/description/
// Striver's & TUF's is a bit different from LC question
// This file has the solution to LC question

#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &arr)
{
    stack<int> st;
    unordered_map<int, int> mpp;
    int n = arr.size();

    // So basically you apply the same Striver's logic on arr and store the ans in a mpp instead of another array
    // Then you just do a lookup of elements of nums1 in mpp and store the ans in ans

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
    // Do a lookup kind of thing of elements of nums1 in mpp and store the ans in ans 
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