// https://takeuforward.org/data-structure/check-if-the-binary-tree-is-balanced-binary-tree
// https://leetcode.com/problems/balanced-binary-tree/description

// Given a binary tree, determine if it is "height-balanced". A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution
{

public:
    bool isBalanced(Node *root)
    {
        return dfsHeight(root) != -1;
    }

    int dfsHeight(Node *root)
    {
        if (root == NULL)
            return 0;

        int leftHeight = dfsHeight(root->left);
        int rightHeight = dfsHeight(root->right);

        // If the left or right subtree is unbalanced, propagate the unbalance status
        if (leftHeight == -1 || rightHeight == -1)
            return -1;

        // Check if the difference in height between left and right subtrees is greater than 1
        // If it's greater, the tree is unbalanced, return -1 to propagate the unbalance status
        if (abs(leftHeight - rightHeight) > 1)
            return -1;

        // Return the maximum height of left and right subtrees, adding 1 for the current node
        return max(leftHeight, rightHeight) + 1;
    }
};

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);

    Solution solution;

    if (solution.isBalanced(root))
    {
        cout << "The tree is balanced." << endl;
    }
    else
    {
        cout << "The tree is not balanced." << endl;
    }

    return 0;
}
