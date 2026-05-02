// https://takeuforward.org/data-structure/print-root-to-node-path-in-a-binary-tree
// https://leetcode.com/problems/binary-tree-paths
// The LeetCode is a bit diffrent but the most similar to this question

// Given a Binary Tree and a reference to a root belonging to it. Return the path from the root node to the given node.
// Note: No two nodes in the tree have the same data value and it is assured that the given node is present and a path always exists. The asked node could be a leaf node also

// Time Complexity: O(N) nodes
// Space Complexity: O(N) nodes in worst case

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
    bool getPath(TreeNode *root, vector<int> &arr, int value)
    {
        if (!root)
        {
            return false;
        }
        arr.push_back(root->val);

        // If current node's value is equal to value, return true
        if (root->val == value)
        {
            return true;
        }

        // Recursively search in left or right subtree
        if (getPath(root->left, arr, value) ||
            getPath(root->right, arr, value))
        {
            return true;
        }

        // If not found, backtrack and remove current nodes
        arr.pop_back();
        return false;
    }

    vector<int> solve(TreeNode *A, int value)
    {
        vector<int> arr;

        if (A == NULL)
        {
            return arr;
        }

        getPath(A, arr, value);
        return arr;
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
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution sol;

    int targetLeafValue = 7;

    vector<int> path = sol.solve(root, targetLeafValue);

    cout << "Path from root to node with value ";
    cout << targetLeafValue << ": ";

    for (int i = 0; i < path.size(); ++i)
    {
        cout << path[i];
        if (i < path.size() - 1)
        {
            cout << " -> ";
        }
    }

    return 0;
}
