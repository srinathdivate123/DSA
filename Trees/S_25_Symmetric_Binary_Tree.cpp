// https://takeuforward.org/data-structure/check-for-symmetrical-binary-tree
// https://leetcode.com/problems/symmetric-tree/description

// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

// Symmetry conditions:
// The tree must visually mirror itself from left to right.
// This mirror pattern must be consistent at every level of the tree.

// Base check:
// If both parts are empty, it is symmetric. If only one is empty, it's not.

// Mirror checks:
// Both nodes should have the same value.
// Left of left side matches right of right side.
// Right of left side matches left of right side.

// Time Complexity: O(N) nodes
// Space Complexity: O(1)

#include <iostream>
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
private:
    bool isSymmetricUtil(Node *root1, Node *root2)
    {
        if (root1 == NULL || root2 == NULL)
        {
            // If one is null, then other must also be null
            return root1 == root2;
        }
        // Check if the data in the current nodes is equal
        if (root1->data != root2->data)
        {
            return false;
        }
        // Recursively check for symmetry in subtrees
        return isSymmetricUtil(root1->left, root2->right) &&
               isSymmetricUtil(root1->right, root2->left);
    }

public:
    bool isSymmetric(Node *root)
    {
        if (!root)
        {
            return true;
        }
        return isSymmetricUtil(root->left, root->right);
    }
};

void printInorder(Node *root)
{
    if (!root)
    {
        return;
    }
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->right->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);

    Solution solution;

    cout << "Binary Tree (Inorder): ";
    printInorder(root);
    cout << endl;

    bool res;
    res = solution.isSymmetric(root);

    if (res)
    {
        cout << "This Tree is Symmetrical" << endl;
    }
    else
    {
        cout << "This Tree is NOT Symmetrical" << endl;
    }

    return 0;
}