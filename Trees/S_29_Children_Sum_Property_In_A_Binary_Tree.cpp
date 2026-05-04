// https://takeuforward.org/data-structure/check-for-children-sum-property-in-a-binary-tree
// This is not available on LeetCode or on LintCode

// Problem Statement: Given a Binary Tree, convert the value of its nodes to follow the Children Sum Property. The Children Sum Property in a binary tree states that for every node, the sum of its children's values (if they exist) should be equal to the node's value. If a child is missing, it is considered as having a value of 0.

// Note:
// --> The node values can be increased by any positive integer any number of times, but decrementing any node value is not allowed.
// --> A value for a NULL node can be assumed as 0.
// --> We cannot change the structure of the given binary tree.

// --------------------------------------------------------------------------

// Node values can only be increased; decreasing is not allowed. Tree structure stays fixed.
// Bottom-up adjustment fails when child sum is less than the parent, since we can't reduce parent.
// Hence,
// During top-bottom traversal, If children sum is less than the node, we increase children's values recursively to match.
// Use recursion to visit every node and check the Children Sum Property at each level.
// Compare this sum with the parent value and adjust accordingly.
// If children ≥ node, update node to match child sum.
// If children < node, update one child to match parent (since we can't decrease).
// After processing both children, update node value to final left + right sum.

// Time Complexity: O(N) nodes
// Space Complexity: O(H) height

#include <iostream>
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
    void changeTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }

        // Calculate the sum of the values of the left and right children, if they exist.
        int childSum = 0;
        if (root->left)
        {
            childSum += root->left->val;
        }
        if (root->right)
        {
            childSum += root->right->val;
        }

        // Compare the sum of children with the current node's value and update
        if (childSum >= root->val)
        {
            root->val = childSum;
        }
        else
        {
            // If the sum is smaller, update the child with the current node's value.
            if (root->left)
            {
                root->left->val = root->val;
            }
            else if (root->right)
            {
                root->right->val = root->val;
            }
        }

        // Recursively call the function on the left and right children.
        changeTree(root->left);
        changeTree(root->right);

        // Calculate the total sum of the values of the left and right children, if they exist.
        int tot = 0;
        if (root->left)
        {
            tot += root->left->val;
        }
        if (root->right)
        {
            tot += root->right->val;
        }

        // If either left or right child exists, update the current node's value with the total sum.
        if (root->left || root->right)
        {
            root->val = tot;
        }
    }
};

void inorderTraversal(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution sol;

    cout << "Binary Tree before modification: ";
    inorderTraversal(root);
    cout << endl;

    sol.changeTree(root);

    cout << "Binary Tree after Children Sum Property: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
