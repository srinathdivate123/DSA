// https://takeuforward.org/data-structure/maximum-sum-path-in-binary-tree
// https://leetcode.com/problems/binary-tree-maximum-path-sum

// A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.
// The path sum of a path is the sum of the node's values in the path. Given the root of a binary tree, return the maximum path sum of any non-empty path.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    int maxPathSum(TreeNode *root)
    {
        int maxSum = INT_MIN;
        dfs(root, maxSum);
        return maxSum;
    }

    // To find the maximum sum path in a binary tree, we treat every node as a possible turning point. At each node, we calculate the maximum path sum by adding the node’s value to the maximum path sums from its left and right subtrees.
    int dfs(TreeNode *node, int &maxSum)
    {
        if (!node)
            return 0;

        // If you get a negative sum, do not take it as we ant to maximize the sum. Hence, do a max with 0.
        int left = max(0, dfs(node->left, maxSum));
        int right = max(0, dfs(node->right, maxSum));

        // Update global max sum considering node as turning point
        maxSum = max(maxSum, left + right + node->val);

        // Return the best one-sided path sum
        return max(left, right) + node->val;
    }
};

int main()
{
    TreeNode *root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution obj;
    cout << obj.maxPathSum(root) << endl;

    return 0;
}
