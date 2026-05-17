// https://takeuforward.org/binary-search-tree/delete-a-node-in-binary-search-tree
// https://leetcode.com/problems/delete-node-in-a-bst/description

// Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.
// Basically, the deletion can be divided into two stages:
// --> Search for a node to remove.
// --> If the node is found, delete the node.

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
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        if (root->val == key)
        {
            return helper(root);
        }
        TreeNode *dummy = root;
        while (root != nullptr)
        {
            if (root->val > key)
            {
                if (root->left != nullptr && root->left->val == key)
                {
                    root->left = helper(root->left);
                    break;
                }
                else
                {
                    root = root->left;
                }
            }
            else
            {
                if (root->right != nullptr && root->right->val == key)
                {
                    root->right = helper(root->right);
                    break;
                }
                else
                {
                    root = root->right;
                }
            }
        }
        return dummy;
    }

    TreeNode *helper(TreeNode *root)
    {
        if (root->left == nullptr)
        {
            return root->right;
        }
        else if (root->right == nullptr)
        {
            return root->left;
        }

        // If a root has both left and right childs
        TreeNode *rightChild = root->right;
        TreeNode *lastRight = findLastRight(root->left);
        lastRight->right = rightChild;
        return root->left;
    }

    TreeNode *findLastRight(TreeNode *root)
    {
        if (root->right == nullptr)
        {
            return root;
        }
        return findLastRight(root->right);
    }
};

int main()
{
    Solution sol;
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    sol.deleteNode(root, 10);
    return 0;
}
