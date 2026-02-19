// https://takeuforward.org/data-structure/maximum-rectangle-area-with-all-1s-dp-on-rectangles-dp-55
// https://leetcode.com/problems/maximal-rectangle/description/

// Given a rows*cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

// You have to always connect questions to questions. This question is similar to the previous question.

// ANS

// INPUT:
// [1 0 1 0 0]
// [1 0 1 1 1]
// [1 1 1 1 1]
// [1 0 0 1 0]
// [1 0 0 1 0]

// Histogram of heights
// [1 0 1 0 0]
// [2 0 2 1 1]
// [3 1 3 2 2]
// [4 0 0 3 0]
// [5 0 0 4 0]

// Create an array to store heights of histogram bars, one for each column in the matrix.
// Traverse the matrix row by row and for each cell in the row:
// --> If the value is '1', increase the height at that column by 1.
// --> If the value is '0', reset the height at that column to 0.
// After updating the histogram for the current row, calculate the largest rectangle area in that histogram.
// Keep track of the maximum area seen so far across all rows. After processing all rows, the stored maximum will be the area of the largest rectangle consisting of only 1s.

#include <bits/stdc++.h>
using namespace std;

// Class containing the solution functions
class Solution
{
public:
    // This is same as the previosu question
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> st;
        int maxArea = 0;

        // Add a sentinel zero height at the end
        heights.push_back(0);

        // Iterate through all bars
        for (int i = 0; i < heights.size(); i++)
        {
            while (!st.empty() && heights[i] < heights[st.top()])
            {
                int height = heights[st.top()];
                st.pop();

                int width = st.empty() ? i : i - st.top() - 1;

                maxArea = max(maxArea, height * width);
            }

            st.push(i);
        }

        return maxArea;
    }

    // Function to find maximal rectangle in binary matrix
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if (matrix.empty())
            return 0;

        // Get number of columns
        int m = matrix[0].size();

        // Height array to build histogram row-wise
        vector<int> height(m, 0);

        // Variable to track max rectangle area
        int maxArea = 0;

        // Traverse each row of the matrix
        for (auto &row : matrix)
        {
            // Update histogram based on current row
            for (int i = 0; i < m; i++)
            {
                if (row[i] == '1')
                    height[i]++;
                else
                    height[i] = 0;
            }

            maxArea = max(maxArea, largestRectangleArea(height));
        }

        return maxArea;
    }
};

int main()
{
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}};

    Solution sol;
    cout << sol.maximalRectangle(matrix) << endl;
    return 0;
}