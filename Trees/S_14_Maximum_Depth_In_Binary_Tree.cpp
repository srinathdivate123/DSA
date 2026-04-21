// https://takeuforward.org/data-structure/maximum-depth-of-a-binary-tree
// https://leetcode.com/problems/maximum-depth-of-binary-tree

// Given the root of a binary tree, return its maximum depth. A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

// Time Complexity: O(N), each node is processed once in Level Order Traversal.
// Space Complexity: O(N), in worst case, a maximum of N/2 nodes can be present in queue.

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
    int maxDepth(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        return 1 + max(lh, rh);
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
    cout << solution.maxDepth(root);

    return 0;
}
