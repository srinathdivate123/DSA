// https://takeuforward.org/data-structure/iterative-preorder-traversal-of-binary-tree
// https://leetcode.com/problems/binary-tree-preorder-traversal/description

// Time Complexity: O(N), where N is the number of nodes in the binary tree. Each node is visited once during the traversal.
// Space Complexity: O(H), where H is the height of the binary tree. The space is used by the stack to store nodes during traversal.

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
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> preorder;

        if (root == nullptr)
        {
            return preorder;
        }

        stack<TreeNode *> st; // Stack to store nodes during traversal
        st.push(root);        // Push the root node onto the stack

        // Perform iterative preorder traversal
        while (!st.empty())
        {
            root = st.top(); // Get the current node from the top of the stack
            st.pop();        // Remove the node from the stack

            preorder.push_back(root->val); // Add the node's value to the preorder result

            // Push the right child onto the stack if exists
            if (root->right != nullptr)
            {
                st.push(root->right);
            }

            // Push the left child onto the stack if exists
            if (root->left != nullptr)
            {
                st.push(root->left);
            }
        }

        // Return the preorder traversal result
        return preorder;
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

    // Getting the preorder traversal
    vector<int> result = sol.preorderTraversal(root);

    // Displaying the preorder traversal result
    cout << "Preorder Traversal: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}