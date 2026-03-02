// https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/description/

// Given an n x n binary grid, in one step you can choose two adjacent rows of the grid and swap them.

// A grid is said to be valid if all the cells above the main diagonal are zeros.

// Return the minimum number of steps needed to make the grid valid, or -1 if the grid cannot be valid.

// The main diagonal of a grid is the diagonal that starts at cell (1, 1) and ends at cell (n, n).
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSwaps(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<int> endZeroes(n, 0);
        for (int i = 0; i < n; i++)
        {
            int j = n - 1;
            int count = 0;
            while (j >= 0 && grid[i][j] == 0)
            {
                count++;
                j--;
            }
            endZeroes[i] = count;
        }
        int steps = 0;
        for (int i = 0; i < n; i++)
        {
            int need = n - i - 1;
            int j = i;
            while (j < n && endZeroes[j] < need)
            {
                j++;
            }
            if (j == n)
            {
                return -1;
            }
            steps += j - i;
            while (j > i)
            {
                swap(endZeroes[j], endZeroes[j - 1]);
                j--;
            }
        }
        return steps;
    }
};