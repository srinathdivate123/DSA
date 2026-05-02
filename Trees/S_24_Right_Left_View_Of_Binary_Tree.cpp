// https://takeuforward.org/data-structure/right-left-view-of-binary-tree
// https://leetcode.com/problems/binary-tree-right-side-view/description

// Given the root of a binary tree, imagine yourself standing on the right or left side of it, return the values of the nodes you can see ordered from top to bottom.

// Brute is iterative solution to do a level order traversal and then the first nodes at each level is left view and the last nodes at each level is right view. But this takes TC=O(N) and SC=O(N) where N=nodes
// But recursive solutions at the worst can take TC=(N) and SC=O(H) where H=height of tree
// Hence, recursive solution might be better in most cases

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v) : val(v), left(NULL), right(NULL) {}
};

// Time Complexity: O(N) In the worst case, we may visit every node in the binary tree exactly once. This happens when the tree is skewed.

// Space Complexity: O(H), the space complexity depends on the height (H) of the binary tree due to the recursion stack in depth-first traversal (like preorder, inorder, postorder). In a balanced binary tree, the height is log₂N, leading to O(log N) space. However, in the worst case (a skewed tree), the height is N, resulting in O(N) space. So the space complexity is O(H), where H is the height of the tree.

class Solution
{
public:
    // Recursive function to get left view
    // Root, Left, Right
    void leftDFS(TreeNode *node, int level, vector<int> &res)
    {
        // Base case: null node
        if (!node)
            return;

        // If this is the first time you came at this level
        // Initially res.size = 0, hence the first node gets pushed
        // Then after pushing, res.size = 1 and then when we come to level 1 for the first time, the first node (as left as possible) gets pushed
        if (res.size() == level)
            res.push_back(node->val);

        // Explore left subtree first
        leftDFS(node->left, level + 1, res);

        // Then explore right subtree
        leftDFS(node->right, level + 1, res);
    }

    // Recursive function to get right view
    // Root, Right, Left
    void rightDFS(TreeNode *node, int level, vector<int> &res)
    {
        if (!node)
            return;

        // If this is the first time you came at this level
        // Initially res.size = 0, hence the first node gets pushed
        // Then after pushing, res.size = 1 and then when we come to level 1 for the first time, the first node (as right as possible) gets pushed
        if (res.size() == level)
            res.push_back(node->val);

        // Explore right subtree first
        rightDFS(node->right, level + 1, res);

        // Then explore left subtree
        rightDFS(node->left, level + 1, res);
    }

    vector<int> leftView(TreeNode *root)
    {
        vector<int> res;
        leftDFS(root, 0, res);
        return res;
    }

    vector<int> rightView(TreeNode *root)
    {
        vector<int> res;
        rightDFS(root, 0, res);
        return res;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->left->right->right = new TreeNode(5);
    root->left->right->right->right = new TreeNode(6);

    Solution sol;
    vector<int> left = sol.leftView(root);
    vector<int> right = sol.rightView(root);

    cout << "Left View: ";
    for (int val : left)
        cout << val << " ";
    cout << "\nRight View: ";
    for (int val : right)
        cout << val << " ";
    return 0;
}
