// https://takeuforward.org/data-structure/maximum-width-of-a-binary-tree
// https://leetcode.com/problems/maximum-width-of-binary-tree/description

// Given the root of a binary tree, return the maximum width of the given tree. The maximum width of a tree is the maximum width among all levels.

// The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

// It is guaranteed that the answer will in the range of a 32-bit signed integer.

// ---------------------------------------------------------------

// To determine the maximum width of a tree, an effective strategy would be to assign and identify indexes for the leftmost and rightmost nodes at each level. Using these indexes, we can calculate the width for each level by subtracting the index of the leftmost node from that of the rightmost node.
// Start by assigning an index to the root node as 0. For each level, the left child gets an index equal to (2*parent + 1), and the right child gets an index equal to (2*parent + 2). Using a level order traversal, we use the leftmost and rightmost nodes at each level to get the width at that level. Keep track of the maximum width encountered during the traversal. Whenever a wider level is found, update the maximum width.

// --> Use level-order traversal (BFS) and track each node’s position as if the tree were a complete binary tree.
// --> For each level in the tree, note the position of the first and last node and compute the width as the difference between these two positions.
// --> For the next level, assign positions to children. After processing all levels, return the maximum width recorded.

#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;

        int maxWidth = 0;

        // <Node, Index>
        queue<pair<TreeNode *, int>> q;

        // Push the root with 0
        q.push({root, 0});

        // Note the the indexes can overflow int32 range if the tree is very large
        // Hence, we subtract the index with the leftmost minimum index of the tree so that the subsequent indices start with 0
        while (!q.empty())
        {
            int size = q.size();

            // Store the index of the first node at this level
            int minIndex = q.front().second;

            int first = 0;
            int last = 0;

            for (int i = 0; i < size; i++)
            {
                // Get the current node and its relative index (by subtracting the minIndex from it's index)
                int currIndex = q.front().second - minIndex;
                TreeNode *node = q.front().first;

                q.pop();

                if (i == 0)
                    first = currIndex;

                if (i == size - 1)
                    last = currIndex;

                // In below, you need to use LL because:
                // Even though you’re doing this trick: int currIndex = q.front().second - minIndex;
                // (which normalizes indices per level and keeps them small), the problem is what happens when you generate children indices:
                // 2 * currIndex + 1
                // 2 * currIndex + 2
                // Suppose, currIndex is already near INT_MAX/2, then 2*currIndex exceeds INT_MAX
                // Even if:
                // curr itself fits in int
                // last - first fits in int
                // The intermediate multiplication 2 * curr can overflow before being stored.
                if (node->left)
                    q.push({node->left, 2LL * currIndex + 1});

                if (node->right)
                    q.push({node->right, 2LL * currIndex + 2});
            }
            maxWidth = max(maxWidth, last - first + 1);
        }
        return maxWidth;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);

    Solution sol;

    cout << "Maximum width: " << sol.widthOfBinaryTree(root) << endl;

    return 0;
}
