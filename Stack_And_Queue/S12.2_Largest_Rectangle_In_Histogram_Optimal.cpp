// https://takeuforward.org/data-structure/area-of-largest-rectangle-in-histogram
// https://leetcode.com/problems/largest-rectangle-in-histogram/description

// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

// This approach is a single pass approach instead of a two-pass approach. When we traverse the array by finding the next greater element, we found that some elements were inserted into the stack which signifies that after them the smallest element is themselves
// So we can find the area of the rectangle by using arr[i] * (right smaller - left smaller -1)

// Time Complexity: O(N) + O(N). For loop used along with a while loop
// Space Complexity: O(N). Used for stack

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &histo)
    {
        stack<int> st;
        int maxA = 0;
        int n = histo.size();

        // Loop through each bar including an imaginary bar at the end
        for (int i = 0; i <= n; i++)
        {
            // While current bar is smaller than the top of the stack or we reached the end
            while (!st.empty() && (i == n || histo[st.top()] >= histo[i]))
            {
                int height = histo[st.top()]; // Get the height of the bar at top of the stack
                st.pop();                     // Remove that bar

                int width;
                if (st.empty())
                {
                    width = i; // All bars before were higher
                }
                else
                {
                    width = i - st.top() - 1; // Width between current index and index at top of stack
                }

                // Calculate area and update maximum area
                maxA = max(maxA, width * height);
            }
            // Push current index into stack, not the value
            st.push(i);
        }
        return maxA;
    }
};

int main()
{
    vector<int> histo = {2, 1, 5, 6, 2, 3, 1};
    Solution obj;
    cout << obj.largestRectangleArea(histo) << endl;
    return 0;
}
