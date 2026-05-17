// https://takeuforward.org/data-structure/flatten-binary-tree-to-linked-list
// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description

// Given the root of a binary tree, flatten the tree into a "linked list":

// --> The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
// --> The "linked list" should be in the same order as a pre-order traversal of the binary tree.

// NOTE: You should not create a new linked list. You should re-arrange the same nodes of the tree to form a linked list.

// This is an iterative solution. No need to tell this in an interview. Recursive solution will suffice

// Time Complexity: O(N) nodes
// Space Complexity: O(1)

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
    void flatten(TreeNode *root)
    {
        TreeNode *curr = root;
        while (curr)
        {
            if (curr->left)
            {
                TreeNode *pre = curr->left;
                // Find the rightmost node in the left subtree
                while (pre->right)
                {
                    pre = pre->right;
                }

                // Connect the rightmost node in the left subtree to the current node's right child
                pre->right = curr->right;

                // Move the entire left subtree to the right child of the current node
                curr->right = curr->left;

                // Set the left child of the current node to NULL
                curr->left = NULL;
            }
            // Move to the next node on the right side
            curr = curr->right;
        }
    }
};

void printPreorder(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printFlattenTree(TreeNode *root)
{
    if (!root)
    {
        return;
    }
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