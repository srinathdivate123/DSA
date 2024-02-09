// Pre-req: S_57_Largest_Rectangle_In_Histogram.cpp
// Given a row X cols binary matrix filled with 0’s and 1’s, find the largest rectangle containing only 1’s and return its area.

#include <bits/stdc++.h>
using namespace std;
// Total TC = N*(M+N). N for running a loop to check all rows. Now, inside that loop, M is for visiting all the columns, and another M is for the function we are using. The function takes linear time complexity. Here, the size of the height array is M, so it will take M.
// SC = M. We are using a height array and a stack of size M.
int largestRectangleArea(vector<int> &histo)
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
int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m)
{
    int maxArea = 0;
    vector<int> height(m, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            if (mat[i][j] == 1)
                height[j]++;
            else
                height[j] = 0;
        int area = largestRectangleArea(height);
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

int main()
{

    vector<vector<int>> mat = {
        {1, 0, 1, 0, 0}, {1, 0, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 0, 0, 1, 0}};
    int n = 4, m = 5;
    cout <<maximalAreaOfSubMatrixOfAll1(mat, n, m);
    return 0;
}