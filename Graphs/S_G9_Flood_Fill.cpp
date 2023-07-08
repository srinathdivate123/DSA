// Problem Statement: An image is represented by a 2-D array of integers, each integer representing the pixel value of the image. Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, “flood fill” the image.

// To perform a “flood fill”, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same colour as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same colour as the starting pixel), and so on. Replace the colour of all of the aforementioned pixels with the newColor.

// TC = P*4 where P is he total number of nodes that end up being new-colored. 4 because we travel for 4 neighbour nodes for each node.
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