// https://takeuforward.org/data-structure/morris-preorder-traversal-of-a-binary-tree

// Morris Preorder Traversal aims to achieve a space complexity of O(1) without recursion or an external data structure.

// Time Complexity: O(2N), the time complexity is linear, as each node is visited at most twice (once for establishing the temporary link and once for reverting it).
// Space Complexity: O(1)

// Refer TUF blog for explanation

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
    vector<int> getPreorder(TreeNode *root)
    {
        vector<int> preorder;
        TreeNode *cur = root;

        // Loop until the current node is not NULL
        while (cur != NULL)
        {
            // If the current node's left child is NULL
            // Means we are currently on the root
            if (cur->left == NULL)
            {
                // Add the value of the current node to the preorder vector
                preorder.push_back(cur->val);

                // Move to the right child
                cur = cur->right;
            }
            else
            {
                // If the current node has a left child, create a pointer to traverse to the rightmost node in the left subtree
                TreeNode *startPrev = cur->left;

                // Traverse to the rightmost node in the left subtree or until we find a node whose right child is not yet processed
                while (startPrev->right && startPrev->right != cur)
                {
                    startPrev = startPrev->right;
                }

                // If the predecessor's right child is NULL, establish a temporary link, add cur to the preorder traversal and move to the left child
                if (startPrev->right == NULL)
                {
                    startPrev->right = cur;
                    preorder.push_back(cur->val);
                    cur = cur->left;
                }
                else
                {
                    // If the predecessor's right child is already linked, remove the link and move to the right child
                    startPrev->right = NULL;
                    cur = cur->right;
                }
            }
        }
        return preorder;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);

    Solution sol;

    vector<int> preorder = sol.getPreorder(root);

    cout << "Binary Tree Morris Preorder Traveral: ";
    for (int i = 0; i < preorder.size(); i++)
    {
        cout << preorder[i] << " ";
    }
    cout << endl;

    return 0;
}