// Problem Statement: Given a grid of size NxM (N is the number of rows and M is the number of columns) consisting of ‘0’s (Water) and ‘1’s (Land). Find the number of islands.

// Note: An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

// SC = N*N for visited array + N*N for queue at worst case when all are 1 i.e. only one island is there and no water is there

// O (N² + NxMx9), N² for the nested loops, and NxMx9 for the overall BFS of the matrix.
#include <bits/stdc++.h>
using namespace std;
void bfs(vector<vector<int>> &matrix, vector<vector<int>> &visited, int row, int col, int n, int m);

void bfs(vector<vector<int>> &matrix, vector<vector<int>> &visited, int startRow, int startCol, int n, int m)
{
    visited[startRow][startCol] = 1;
    queue<pair<int, int>> q;
    q.push({startRow, startCol});
    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        // Traverse the neighbours
        // TC of below is 9 (3*3)
        for (int deltaRow = -1; deltaRow <= 1; deltaRow++)
            for (int deltaCol = -1; deltaCol <= 1; deltaCol++)
            {
                int neighbourRow = row + deltaRow; // Index of the neighbour row
                int neighbourCol = col + deltaCol; // Index of the neighbour col
                if (neighbourRow >= 0 && neighbourRow < n && neighbourCol >= 0 && neighbourCol < m && matrix[neighbourRow][neighbourCol] == 1 && !visited[neighbourRow][neighbourCol])
                {
                    visited[neighbourRow][neighbourCol] = 1;
                    q.push({neighbourRow, neighbourCol});
                }
            }
    }
}

int numberOfIslands(vector<vector<int>> &matrix)
{
    int answer = 0;
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    // TC of below is N*M
    for (int row = 0; row < n; row++)
        for (int col = 0; col < m; col++)
            if (!visited[row][col] && matrix[row][col] == 1)
            {
                ++answer;
                bfs(matrix, visited, row, col, n, m);
            }
    return answer;
}

int main()
{
    vector<vector<int>> matrix = {
        {0, 1, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0},
        {1, 1, 0, 1}};
    cout << numberOfIslands(matrix);

    return 0;
}