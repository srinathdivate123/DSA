// https://takeuforward.org/data-structure/lowest-common-ancestor-for-two-given-nodes
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description

// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

// --------------------------------------------------------------------------------------

// Start by checking if the current root node is null or matches one of the target nodes (x or y). If the root is null or matches either target node, return the root, as it could be the LCA or simply indicate the end of the search path.
// Perform a recursive search in the left subtree to find nodes x and y by calling the LCA function on the left child of the current root.
// Similarly, perform a recursive search in the right subtree by calling the LCA function on the right child of the current root.
// After completing the recursive searches, analyze the results of both subtree searches:
// --> If both recursive calls return non-null values, it means one target node was found in each subtree. In this case, the current root node must be the LCA, as it is the common ancestor of both nodes.
// --> If only one of the subtree searches returns a non-null result, it implies both target nodes are located within the same subtree. Return the non-null result, which represents the LCA found in that subtree.

// Time Complexity: O(N) nodes
// Space Complexity: O(H) height

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL || root == p || root == q)
        {
            return root;
        }

        // Search in left and right subtrees
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        // Result
        if (left == NULL)
        {
            // No matter what, return the right. If it is NULL, then it will get returned
            return right;
        }
        else if (right == NULL)
        {
            // No matter what, return the left. If it is NULL, then it will get returned
            return left;
        }
        else
        { // Both left and right are not null, we found our result
            return root;
        }
    }
};

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    Solution solution;
    TreeNode *p = root->left;
    TreeNode *q = root->right;

    TreeNode *lca = solution.lowestCommonAncestor(root, p, q);
    cout << "Lowest Common Ancestor: " << lca->data << endl;

    return 0;
}