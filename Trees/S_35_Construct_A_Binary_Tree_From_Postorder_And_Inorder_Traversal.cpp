// https://takeuforward.org/data-structure/construct-binary-tree-from-inorder-and-postorder-traversal
// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description

// Construct a binary tree from it's preorder and inorder traversals

// Time Complexity: O(N), Every node is visited once.
// Space Complexity: O(N), Due to hashmap and recursion stack (up to tree height).

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (inorder.size() != postorder.size())
        {
            return nullptr;
        }

        // Map each value in inorder to its index
        map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); i++)
        {
            inorderMap[inorder[i]] = i;
        }

        // Call recursive builder
        return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, inorderMap);
    }

private:
    TreeNode *build(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int postStart, int postEnd, map<int, int> &inorderMap)
    {
        if (postStart > postEnd || inStart > inEnd)
        {
            return nullptr;
        }

        // Last element in postorder is root
        TreeNode *root = new TreeNode(postorder[postEnd]);

        // Find root index in inorder
        int inRoot = inorderMap[postorder[postEnd]];

        // Number of elements in left subtree
        int numsLeft = inRoot - inStart;

        // Recursively build left and right subtrees
        root->left = build(inorder, inStart, inRoot - 1, postorder, postStart, postStart + numsLeft - 1, inorderMap);
        root->right = build(inorder, inRoot + 1, inEnd, postorder, postStart + numsLeft, postEnd - 1, inorderMap);

        return root;
    }
};

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
    vector<int> inorder = {40, 20, 50, 10, 60, 30};
    vector<int> postorder = {40, 50, 20, 60, 30, 10};

    Solution sol;
    TreeNode *root = sol.buildTree(inorder, postorder);

    cout << "Inorder of Unique Binary Tree Created:\n";
    printInorder(root);
    cout << endl;

    return 0;
}
