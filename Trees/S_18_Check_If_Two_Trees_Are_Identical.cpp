// https://takeuforward.org/data-structure/check-if-two-trees-are-identical
// https://leetcode.com/problems/same-tree/description

// Given the roots of two binary trees p and q, write a function to check if they are the same or not. Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

// Time Complexity: O(N + M) where N is the number of nodes in the first Binary Tree and M is the number of nodes in the second Binary Tree.

// Space Complexity: O(1)

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
    bool isIdentical(Node *node1, Node *node2)
    {
        // Case 1: If both nodes are NULL, they are identical
        if (node1 == NULL && node2 == NULL)
        {
            return true;
        }

        // Case 2: If only one of the nodes is NULL, they are not identical
        if (node1 == NULL || node2 == NULL)
        {
            return false;
        }

        bool sameVal = node1->data == node2->data;
        bool sameLeft = isIdentical(node1->left, node2->left);
        bool sameRight = isIdentical(node1->right, node2->right);

        // Check if the current nodes have the same data value and recursively check their left and right subtrees
        return sameVal && sameLeft && sameRight;
    }
};

int main()
{
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);

    Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);

    Solution solution;

    cout << solution.isIdentical(root1, root2) << endl;

    return 0;
}
