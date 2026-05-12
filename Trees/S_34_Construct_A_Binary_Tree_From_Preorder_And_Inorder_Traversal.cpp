// https://takeuforward.org/data-structure/construct-a-binary-tree-from-inorder-and-preorder-traversal
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description

// Construct a binary tree from it's preorder and inorder traversals

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(N), as ach node is visited once.
// Space Complexity: O(N), for the hashmap and recursion stack (worst case when tree is skewed).

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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        // Map to store the index of each value in inorder
        map<int, int> inorderMap;

        // Fill the map with inorder values and their indices
        for (int i = 0; i < inorder.size(); i++)
        {
            inorderMap[inorder[i]] = i;
        }

        // Call the recursive helper function
        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inorderMap);
    }

private:
    // Recursive function to build tree using preorder and inorder segments
    TreeNode *build(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, map<int, int> &inorderMap)
    {
        if (preStart > preEnd || inStart > inEnd)
        {
            return nullptr;
        }

        // The first element in preorder is root
        TreeNode *root = new TreeNode(preorder[preStart]);

        // Find the root index in inorder
        int inRoot = inorderMap[root->val];

        // Number of elements in left subtree
        int numsLeft = inRoot - inStart;

        // Recursively build left and right subtrees
        root->left = build(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, inorderMap);
        root->right = build(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inorderMap);

        return root;
    }
};

// Inorder traversal to print tree
void printInorder(TreeNode *root)
{
    if (!root)
        return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main()
{
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> preorder = {3, 9, 20, 15, 7};

    Solution sol;
    TreeNode *root = sol.buildTree(preorder, inorder);

    cout << "Inorder of Unique Binary Tree Created:\n";
    printInorder(root);
    cout << endl;

    return 0;
}
