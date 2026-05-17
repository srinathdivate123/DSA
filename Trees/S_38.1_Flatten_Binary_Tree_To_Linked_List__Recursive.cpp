// https://takeuforward.org/data-structure/flatten-binary-tree-to-linked-list
// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description

// Given the root of a binary tree, flatten the tree into a "linked list":

// --> The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
// --> The "linked list" should be in the same order as a pre-order traversal of the binary tree.

// NOTE: You should not create a new linked list. You should re-arrange the same nodes of the tree to form a linked list.

// This is a recursive solution

// Time Complexity: O(N) nodes
// Space Complexity: O(H) height

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
    TreeNode *prev = nullptr;

    // Flatten tree to right-skewed linked list (preorder sequence)
    void flatten(TreeNode *root)
    {
        if (root == nullptr)
            return;
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = nullptr;
        prev = root;
    }
};

void printPreorder(TreeNode *root)
{
    if (!root)
        return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printFlattenTree(TreeNode *root)
{
    if (!root)
        return;
    cout << root->val << " ";
    printFlattenTree(root->right);
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->left = new TreeNode(8);

    Solution sol;

    cout << "Binary Tree Preorder: ";
    printPreorder(root);
    cout << endl;

    sol.flatten(root);

    cout << "Binary Tree After Flatten: ";
    printFlattenTree(root);
    cout << endl;
    return 0;
}