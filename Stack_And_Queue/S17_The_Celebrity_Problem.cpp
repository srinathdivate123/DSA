// https://takeuforward.org/data-structure/celebrity-problem
// https://leetcode.com/problems/find-the-celebrity/description
// https://www.lintcode.com/problem/645

// A celebrity is a person who is known by everyone else at the party but does not know anyone in return. Given a square matrix M of size N x N where M[i][j] is 1 if person i knows person j, and 0 otherwise, determine if there is a celebrity at the party. Return the index of the celebrity or -1 if no such person exists.
// Note that M[i][i] is always 0.

// The minimum number of celebrities is 0 and the maximum number is 1. You cannot have more than 1 celebrity.

// ANSWER:::::

// Initialize two pointers, one at the top (start) and one at the bottom (end) of the matrix
// Compare the individuals at the top and bottom pointers
// If the person at the top pointer knows the person at the bottom pointer, move the top pointer down (the top person cannot be the celebrity)
// If the person at the bottom pointer knows the person at the top pointer, move the bottom pointer up (the bottom person cannot be the celebrity)
// If neither knows the other, increment both pointers (neither can be the celebrity)
// After the traversal, the remaining candidate at the top pointer is the potential celebrity
// Check if the candidate is a valid celebrity by ensuring that everyone knows this person and this person knows no one
// If the candidate is valid, return the index; otherwise, return -1 indicating no celebrity

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int celebrity(vector<vector<int>> &M)
    {
        int n = M.size();
        int top = 0, down = n - 1;

        // Traverse for all the people
        while (top < down)
        {

            // If top knows down, top can not be a celebrity
            if (M[top][down] == 1)
            {
                top = top + 1;
            }
            /// If down knowns top, it can not be a celebrity
            else if (M[down][top] == 1)
            {
                down = down - 1;
            }
            // If both do not know each other, both cannot be the celebrity
            // Because to be a celebrity, you should be known by everyone else. Even if one person does not know you, then you are not a celebrity
            else
            {
                top++;
                down--;
            }
        }

        // Return -1 if no celebrity is found
        if (top > down)
            return -1;

        // Check if the person pointed by top is celebrity
        for (int i = 0; i < n; i++)
        {
            if (i == top) // We should not check diagonal elements
                continue;

            // Check if it is not a celebrity
            if (M[top][i] == 1 || M[i][top] == 0) // Top should not know i and i should know top
            {
                return -1;
            }
        }
        return top;
    }
};

int main()
{
    vector<vector<int>> M = {
        {0, 1, 1, 0},
        {0, 0, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 1, 0}};
    Solution sol;
    cout << sol.celebrity(M);
    return 0;
}