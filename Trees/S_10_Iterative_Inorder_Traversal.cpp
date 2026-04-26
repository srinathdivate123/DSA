// https://takeuforward.org/data-structure/inorder-traversal-of-binary-tree
// https://leetcode.com/problems/binary-tree-inorder-traversal

// Time Complexity: O(n), where n is the number of nodes in the binary tree. Each node is visited exactly once.
// Space Complexity: O(h), where h is the height of the binary tree. This is the space required for the stack to store the nodes during traversal.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    vector<int> inorder(TreeNode *root)
    {
        stack<TreeNode *> st;
        TreeNode *node = root;
        vector<int> inorder;

        // Start an infinite loop for traversal
        while (true)
        {
            if (node != NULL)
            {
                // Push the current node to the stack
                st.push(node);
                // Move to the left child of the current node
                node = node->left;
                // Continue this process until a node with no left child is reached.
            }
            else
            {
                // If the stack is empty, break the loop
                if (st.empty())
                {
                    break;
                }
                node = st.top();
                st.pop();
                inorder.push_back(node->data);
                node = node->right;
            }
        }
        return inorder;
    }
};

int main()
{
    // Creating a binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Initializing the Solution class
    Solution sol;

    // Getting the inorder traversal
    vector<int> result = sol.inorder(root);

    // Displaying the inorder traversal result
    cout << "Inorder Traversal: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
