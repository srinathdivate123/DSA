// Given an array of integers heights representing the histogram’s bar height where the width of each bar is 1  return the area of the largest rectangle in histogram.
// https://takeuforward.org/data-structure/area-of-largest-rectangle-in-histogram/
// approach_P1 - https://youtu.be/X0X6G-eWgQ8
// approach_P2 - https://youtu.be/jC_cWLy7jSI
#include <bits/stdc++.h>
using namespace std;

// TC = n*n, SC = 1
int brute(vector<int> arr, int n)
{
    int maxArea = 0;
    for (int i = 0; i < n; i++)
    {
        int minHeight = INT_MAX;
        for (int j = i; j < n; j++)
        {
            minHeight = min(minHeight, arr[j]);
            maxArea = max(maxArea, minHeight * (j - i + 1));
        }
    }
    return maxArea;
}

// TC = n, SC = 3n (for stack, left small array and right small array)
int approach_P1(vector<int> &heights)
{
    int n = heights.size();
    stack<int> st;
    int leftsmall[n], rightsmall[n];

    // Compute leftSmall
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
            st.pop();
        if (st.empty())
            leftsmall[i] = 0;
        else
            leftsmall[i] = st.top() + 1;
        st.push(i);
    }

    while (!st.empty()) // clear the stack to be re-used
        st.pop();

    int maxA = 0;
    // Compute rightSmall
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
            st.pop();
        if (st.empty())
            rightsmall[i] = n - 1;
        else
            rightsmall[i] = st.top() - 1;
        st.push(i);
        maxA = max(maxA, heights[i] * (rightsmall[i] - leftsmall[i] + 1));
    }
    return maxA;
}

// TSC = n + n, SC = n
int approach_P2(vector<int> &histo)
{
    stack<int> st;
    int maxA = 0;
    int n = histo.size();
    for (int i = 0; i <= n; i++)
    {
        while (!st.empty() && (i == n || histo[st.top()] >= histo[i]))
        {
            int height = histo[st.top()];
            st.pop();
            int width;
            if (st.empty())
                width = i;
            else
                width = i - st.top() - 1;
            maxA = max(maxA, width * height);
        }
        st.push(i);
    }
    return maxA;
}

int main()
{
    vector<int> heights = {2, 1, 5, 6, 2, 3, 1};
    cout << brute(heights, heights.size()) << endl;
    cout << approach_P1(heights) << endl;
    cout << approach_P2(heights) << endl;
    return 0;
}