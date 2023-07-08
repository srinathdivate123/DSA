// Problem Statement: Given a matrix mat of size N x M where every element is either ‘O’ or ‘X’. Replace all ‘O’ with ‘X’ that is surrounded by ‘X’. An ‘O’ (or a set of ‘O’) is considered to be surrounded by ‘X’ if there are ‘X’ at locations just below, just above just left, and just right of it.

// The boundary elements in the matrix cannot be replaced with ‘X’ as they are not surrounded by ‘X’ from all 4 directions. This means if ‘O’ (or a set of ‘O’) is connected to a boundary ‘O’ then it can’t be replaced with ‘X’.

// The intuition is that we start from boundary elements having ‘O’ and go through its neighboring Os in 4 directions and mark them as visited to avoid replacing them with ‘X’.

#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &mat, int delRow[], int delCol[])
    {
        vis[row][col] = 1;
        int n = mat.size();
        int m = mat[0].size();
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && mat[nrow][ncol] == 'o')
            {
                dfs(nrow, ncol, vis, mat, delRow, delCol);
            }
        }
    }

public:
    vector<vector<char>> surroundedRegions(vector<vector<char>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        // Traverse all the edges
        // Traverse first row and last row
        for (int j = 0; j < m; j++)
        {
            // For first row
            if (!vis[0][j] && mat[0][j] == 'o')
                dfs(0, j, vis, mat, delRow, delCol);

            // For last row
            if (!vis[n - 1][j] && mat[n - 1][j] == 'o')
                dfs(n - 1, j, vis, mat, delRow, delCol);
        }

        // Traverse first and last column
        for (int i = 0; i < n; i++)
        {
            // For first col
            if (!vis[i][0] && mat[i][0] == 'o')
                dfs(i, 0, vis, mat, delRow, delCol);

            // For last col
            if (!vis[i][m - 1] && mat[i][m - 1] == 'o')
                dfs(i, m - 1, vis, mat, delRow, delCol);
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (!vis[i][j] && mat[i][j] == 'o')
                    mat[i][j] = 'x';
        return mat;
    }
};
int main()
{
    vector<vector<char>> mat = {
        {'x', 'x', 'x', 'x', 'x'},
        {'x', 'o', 'o', 'x', 'o'},
        {'x', 'x', 'o', 'x', 'o'},
        {'x', 'o', 'x', 'o', 'x'},
        {'o', 'o', 'x', 'x', 'x'},
    };
    Solution obj;
    vector<vector<char>> dist = obj.surroundedRegions(mat);
    for (auto row : dist)
    {
        for (auto element : row)
            cout << element << " ";
        cout << endl;
    }
    return 0;
}