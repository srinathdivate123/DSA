// https://takeuforward.org/data-structure/level-order-traversal-of-a-binary-tree
// https://leetcode.com/problems/binary-tree-level-order-traversal/description

// Time Complexity: O(N), where N is the number of nodes in the binary tree. Each node is visited once during the level-order traversal.
// Space Complexity: O(N), where N is the number of nodes in the binary tree. The space is used by the queue to store nodes at each level, and in the worst case, it can hold all nodes at the last level.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == nullptr)
        {
            return ans;
        }

        // Create a queue to store nodes for level-order traversal
        queue<TreeNode *> q;
        // Push the root node to the queue
        q.push(root);

        while (!q.empty())
        {
            // Get the size of the current level
            int size = q.size();
            // Create a vector to store nodes at the current level
            vector<int> level;

            for (int i = 0; i < size; i++)
            {
                // Get the front node in the queue
                TreeNode *node = q.front();
                // Remove the front node from the queue
                q.pop();
                // Store the node value in the current level vector
                level.push_back(node->data);

                // Enqueue the child nodes if they exist
                if (node->left != nullptr)
                {
                    q.push(node->left);
                }
                if (node->right != nullptr)
                {
                    q.push(node->right);
                }
            }
            ans.push_back(level);
        }
        return ans;
    }
};

void printVector(const vector<int> &vec)
{
    for (int num : vec)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution solution;
    vector<vector<int>> result = solution.levelOrder(root);

    cout << "Level Order Traversal of Tree: " << endl;

    for (const vector<int> &level : result)
    {
        printVector(level);
    }

    return 0;
}