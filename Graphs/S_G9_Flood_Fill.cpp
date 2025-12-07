// https://takeuforward.org/graph/flood-fill-algorithm-graphs/
// https://leetcode.com/problems/flood-fill/description/

// You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

// To perform a flood fill:

// Begin with the starting pixel and change its color to 'color'.
// Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
// Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
// The process stops when there are no more adjacent pixels of the original color to update.
// Return the modified image after performing the flood fill.

// TC = P*4 where P is the total number of nodes that end up being new-colored. 4 because we travel for 4 neighbour nodes for each node.
// Sc = N*M external matrix for storing answer + N*M for recursion stack space in worst case where are the elements are of the initial given color



#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>> &image, int newColor, int delRow[], int delCol[], int initialColor)
    {
        ans[row][col] = newColor;
        int n = image.size();
        int m = image[0].size();
        // Checks for neighbour
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == initialColor && ans[nrow][ncol] != newColor)
                dfs(nrow, ncol, ans, image, newColor, delRow, delCol, initialColor);
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int initialColor = image[sr][sc];
        vector<vector<int>> ans = image; // We do not flood fill the original image. We make a copy and then do because in industry it is a good practice to not tamper with the original data.
        int delRow[] = {-1, 0, +1, 0};   // This is the difference of row for 4 neighbours
        int delCol[] = {0, +1, 0, -1};   // This is the difference of col for 4 neighbours
        dfs(sr, sc, ans, image, newColor, delRow, delCol, initialColor);
        return ans;
    }
};

int main()
{
    vector<vector<int>> image{
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}};

    int sr = 1, sc = 1, newColor = 9;
    Solution obj;
    vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);

    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << " ";
        cout << "\n";
    }

    return 0;
}