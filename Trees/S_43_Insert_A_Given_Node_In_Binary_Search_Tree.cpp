// https://takeuforward.org/binary-search-tree/insert-a-given-node-in-binary-search-tree
// https://leetcode.com/problems/insert-into-a-binary-search-tree/description

// You are given the root node of a BST and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

// Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

// Time Complexity: O(H)
// Space Complexity: O(1)

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
    TreeNode *insertNode(TreeNode *root, int key)
    {
        if (root = nullptr)
        {
            return new TreeNode(key);
        }
        TreeNode *cur = root;
        while (true)
        {
            if (cur->val <= key)
            {
                if (cur->right != nullptr)
                {
                    cur = cur->right;
                }
                else
                {
                    cur->right = new TreeNode(key);
                    break;
                }
            }
            else
            {
                if (cur->left != nullptr)
                {
                    cur = cur->left;
                }
                else
                {
                    cur->left = new TreeNode(key);
                    break;
                }
            }
        }
        return root;
    }
};

int main()
{
    Solution sol;
    TreeNode *root = new TreeNode(10);
    sol.insertNode(root, 5);
    sol.insertNode(root, 15);
    return 0;
}
