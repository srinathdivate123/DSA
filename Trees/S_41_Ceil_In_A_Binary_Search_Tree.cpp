// https://takeuforward.org/binary-search-tree/ceil-in-a-binary-search-tree
// No question on LeetCode

// Given a BST and a key, return the ceiling of the given key in BST
// Ceiling of a value refers to the value of the smallest node in BST that is greater than or equal to the given key. If the ceiling node does not exist, return nullptr.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    int findCeil(TreeNode *root, int key)
    {
        int ceil = -1;
        while (root)
        {
            if (root->val == key)
            {
                return root->val;
            }
            if (key > root->val)
            {
                root = root->right;
            }
            else
            {
                ceil = root->val;
                root = root->left;
            }
        }
        return ceil;
    }
};

void printInOrder(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(13);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(2);
    root->left->left->right = new TreeNode(4);
    root->left->right = new TreeNode(6);
    root->left->right->right = new TreeNode(9);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(14);

    cout << "Binary Search Tree: " << endl;
    printInOrder(root);
    cout << endl;

    Solution solution;

    int target = 8;
    int ceil = solution.findCeil(root, target);

    if (ceil != -1)
    {
        cout << "Ceiling of " << target << " is: " << ceil << endl;
    }
    else
    {
        cout << "No ceiling found!";
    }

    return 0;
}