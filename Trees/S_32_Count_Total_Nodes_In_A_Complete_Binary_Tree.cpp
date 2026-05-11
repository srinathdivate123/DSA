// https://takeuforward.org/binary-tree/count-number-of-nodes-in-a-binary-tree
// https://leetcode.com/problems/count-complete-tree-nodes/description

// Given the root of a complete binary tree, return the number of the nodes in the tree.
// According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h. Design an algorithm that runs in less than O(n) time complexity.

// Brute force is to traverse the tree using inorder traversal and count the number of nodes as we are traversing the tree. But we will need to visit every node in the tree leading to O(n) time complexity.

// ---------------------------------------------------------------------------------

// We can exploit its properties of a complete binary tree to optimise the algorithm and achieve a better time complexity.
// In a complete binary tree, the last level may not be completely filled, but the nodes are positioned from left to right. This property allows us to determine the number of nodes using just the height.
// The relationship between the height of the binary tree (h) and the maximum number of nodes it can have, denoted by the formula:
// Maximum Number of Nodes: 2^h-1
// If the last level of a binary tree is perfectly filled, known as a perfect binary tree, the count of nodes can be determined by the formula: 2^h-1, where h is the height. To check if the last level of the Binary Tree is filled or not we can compare the left and right heights of the tree.
// If the left height equals right height, it indicates that the last level is completely filled. Or else the last level is not completely filled.
// When left and right height differ, we can employ a recursive approach. We recursively calculate the number of nodes in the left subtree and in the right subtree, and then return the total count as 1 + leftNodes + rightNodes.

// TC: O(log N * log N) The calculation of leftHeight and rightHeight takes O(log N) time.In the worst case, when encountering the second case (leftHeight != rightHeight), the recursive calls are made at most log N times (the height of the tree) Therefore, the total time complexity is O(log N * log N).

// Space Complexity : O(H). Since the given tree is a complete binary tree, the height will always be log N. Therefore, the space complexity is O(log N).

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
    int countNodes(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int lh = findHeightLeft(root);
        int rh = findHeightRight(root);

        // If heights are equal, it's a perfect binary tree
        if (lh == rh)
        {
            // Use formula: 2^h - 1
            return (1 << lh) - 1;
        }
        // Otherwise, recursively count left and right subtrees
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    int findHeightLeft(TreeNode *node)
    {
        int height = 0;
        while (node)
        {
            height++;
            node = node->left;
        }
        return height;
    }

    int findHeightRight(TreeNode *node)
    {
        int height = 0;
        while (node)
        {
            height++;
            node = node->right;
        }
        return height;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    Solution sol;
    int totalNodes = sol.countNodes(root);
    cout << "Total number of nodes in the Complete Binary Tree: " << totalNodes << endl;
    return 0;
}
