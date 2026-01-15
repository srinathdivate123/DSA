// https://www.lintcode.com/problem/434/
// https://leetcode.com/problems/number-of-islands-ii/description/ (PREMIUM)
// https://takeuforward.org/graph/number-of-islands-ii-online-queries-dsu-g-51

// Given a n,m which means the row and column of the 2D matrix and an array of pair A( size k). Originally, the 2D matrix is all 0 which means there is only sea in the matrix. The list pair has k operator and each operator has two integer A[i].x, A[i].y means that you can change the grid matrix[A[i].x][A[i].y] from sea to island. Return how many island are there in the matrix after each operator.You need to return an array of size K.

// This does not involve Disjoint Set
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> numIslands2(int n, int m, vector<pair<int, int>> &operators)
    {
        if (operators.size() == 0)
        {
            return {};
        }

        int count;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<int> ans;
        ans.push_back(1);
        vis[operators[0].first][operators[0].second] = 1;

        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};
        for (int j = 1; j < operators.size(); j++)
        {
            int x = operators[j].first;
            int y = operators[j].second;
            int minIslandID = INT_MAX;

            for (int i = 0; i < 4; i++)
            {
                int row = x + delRow[i];
                int col = y + delCol[i];
                if (row >= 0 && row < n && col >= 0 && col < m && vis[row][col] != 0)
                {
                    minIslandID = min(minIslandID, vis[row][col]);
                }
            }
            for (int i = 0; i < 4; i++)
            {
                int row = x + delRow[i];
                int col = y + delCol[i];
                if (row >= 0 && row < n && col >= 0 && col < m && vis[row][col] != 0)
                {
                    vis[row][col] = minIslandID;
                }
            }

            if (minIslandID)
            {
                ans.push_back(ans.back());
            }
            else
            {
                ans.push_back(ans.back() + 1);
            }
        }
        return ans;
    }
};
int main()
{
    int n = 2, m = 2;
    vector<pair<int, int>> A = {{0, 0}, {1, 1}, {1, 0}, {0, 1}};
    Solution obj;
    vector<int> ans = obj.numIslands2(n, m, A);

    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}