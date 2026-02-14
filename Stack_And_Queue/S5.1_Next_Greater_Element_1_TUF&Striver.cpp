// https://takeuforward.org/data-structure/next-greater-element-using-stack
// https://leetcode.com/problems/next-greater-element-i/description/
// The LC question is bit different than taught by Striver, so refer the next file

// Given an integer array A, return the next greater element for every element in A. The next greater element for an element x is the first element greater than x that we come across while traversing the array in a clockwise manner. If it doesn't exist, return -1 for this element.

// ---------------------------------------------------------------------------

// To find the next greater element (not the greatest) towards the right of each element in an array, we can use a stack to efficiently track potential candidates. As we traverse the array from right to left, we maintain a stack that always stores elements in decreasing order from top to bottom. This way, when we process an element, we can simply pop off all smaller or equal elements (which can't be the next greater element), and then, the top of the stack, if it exists, it will be the next greater element. If the stack is empty, there is no greater element to the right, so we assign -1.

// ALGORITHM
// Initialize an empty stack and a result array of the same length as input.
// Traverse the array from the last element to the first (right to left).
// For each element, pop elements from the stack while the stack top is less than or equal to the current element.
// If the stack becomes empty, no greater element exists, assign -1 in the result.
// Otherwise, the top of the stack is the next greater element for the current element.
// Push the current element onto the stack for use in future comparisons.

// Time Complexity: O(N), we traverse the entire array once and find next greater element in linear time.
// Space Complexity: O(N), additional space used for resultant array and stack.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextGreater(vector<int> &nums)
    {
        // We basically need to maintain the stack such that the next greater element is there on the top

        stack<int> st;
        int n = nums.size();
        vector<int> res(n);

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--)
        {
            // Pop all smaller or equal elements
            while (!st.empty() && nums[i] >= st.top())
            {
                st.pop();
            }

            // If stack is empty, no greater element
            if (st.empty())
                res[i] = -1;

            // Else stack.top() is the answer
            else
                res[i] = st.top();

            // Push current element
            st.push(nums[i]);
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {4, 5, 2, 10};
    Solution sol;
    vector<int> ans = sol.nextGreater(nums);

    for (int x : ans)
        cout << x << " ";
    return 0;
}