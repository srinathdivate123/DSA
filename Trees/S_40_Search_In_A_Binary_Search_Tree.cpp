// https://takeuforward.org/data-structure/search-in-a-binary-search-tree-2
// https://leetcode.com/problems/search-in-a-binary-search-tree/description

// You are given the root of a binary search tree (BST) and an integer val.

// Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(log N), each step eliminates half of the tree, just like binary search. However, in the worst case (unbalanced tree), it could be O(N).
// Space Complexity:O(1)

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        val = data;
        left = right = nullptr;
    }
};

class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int target)
    {
        // Traverse until we reach a null node or the target is found
        while (root != nullptr && root->val != target)
        {
            if (target < root->val)
            {
                root = root->left;
            }
            else
            {
                root = root->right;
            }
        }
        // Return node if found, else nullptr
        return root;
    }
};

int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution obj;
    TreeNode *result = obj.searchBST(root, 2);

    if (result)
        cout << "Node found: " << result->val << endl;
    else
        cout << "Node not found" << endl;

    return 0;
}