// https://takeuforward.org/data-structure/post-order-traversal-of-binary-tree
// https://leetcode.com/problems/binary-tree-postorder-traversal/

// Time Complexity: O(N), we process each node once in traversal.
// Space Complexity: O(N), extra space used for storing post order traversal and recursion stack space.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    void postorderTraversal(TreeNode *root, vector<int> &result)
    {
        if (!root)
            return;

        postorderTraversal(root->left, result);
        postorderTraversal(root->right, result);
        result.push_back(root->val);
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    Solution sol;
    vector<int> result;

    sol.postorderTraversal(root, result);

    for (int val : result)
        cout << val << " ";
    return 0;
}
