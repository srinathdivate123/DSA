// https://takeuforward.org/data-structure/area-of-largest-rectangle-in-histogram
// https://leetcode.com/problems/largest-rectangle-in-histogram/description

// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

// The intuition behind the approach is the same as finding the smaller element on both sides but in an optimized way using the concept of the previous smaller element and the next smaller element.
// Pre-req for this approach is Next Smaller Element and Previous Smaller Element

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        stack<int> st;
        vector<int> PSE(n), NSE(n);

        // PSE
        for (int i = 0; i < n; i++)
        {
            // Pop until a smaller element is found or stack is empty
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }

            // If stack is empty, no smaller element on the left
            // +1 because we want the next element after the previous smaller element
            // Else we will not be able to make a rectangle with it
            PSE[i] = st.empty() ? 0 : st.top() + 1;

            // Push current index to stack
            st.push(i);
        }

        // Clear stack to reuse for NSE
        while (!st.empty())
            st.pop();

        // NSE
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }

            // If stack is empty, no smaller to the right
            // -1 because we want one index before the next smaller element
            // Else we will not be able to make a rectange with it
            NSE[i] = st.empty() ? n - 1 : st.top() - 1;

            st.push(i);
        }

        // Calculate max area using PSE & NSE
        int maxA = 0;
        for (int i = 0; i < n; i++)
        {
            int width = NSE[i] - PSE[i] + 1;
            maxA = max(maxA, heights[i] * width);
        }

        return maxA;
    }
};

int main()
{
    vector<int> heights = {2, 1, 5, 6, 2, 3, 1};
    Solution obj;
    cout << obj.largestRectangleArea(heights) << endl;
    return 0;
}
