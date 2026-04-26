// https://takeuforward.org/data-structure/zig-zag-traversal-of-binary-tree
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description

// Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

// Time Complexity: O(N)

// Space Complexity: O(N) where N is the number of nodes in the binary tree. In the worst case, the queue has to hold all the nodes of the last level of the binary tree, the last level could at most hold N/2 nodes hence the space complexity of the queue is proportional to O(N). The resultant vector answer also stores the values of the nodes level by level and hence contains all the nodes of the tree contributing to O(N) space as well.

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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        if (!root)
            return result;

        queue<TreeNode *> q;
        q.push(root);

        // Boolean flag to control traversal direction: true for left-to-right, false for right-to-left
        bool leftToRight = true;

        while (!q.empty())
        {
            int size = q.size();

            vector<int> level(size);

            // Process each node in the current level
            for (int i = 0; i < size; i++)
            {
                // Get the front node from the queue
                TreeNode *node = q.front();
                q.pop();

                // Either insert it from the front or back
                int index = leftToRight ? i : size - 1 - i;
                level[index] = node->val;

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            // Toggle the direction for the next level
            leftToRight = !leftToRight;

            result.push_back(level);
        }
        return result;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    Solution sol;

    vector<vector<int>> ans = sol.zigzagLevelOrder(root);

    cout << "[";
    for (auto &level : ans)
    {
        cout << "[";
        for (int i = 0; i < level.size(); i++)
        {
            cout << level[i];
            if (i != level.size() - 1)
                cout << ", ";
        }
        cout << "]";
    }
    cout << "]" << endl;

    return 0;
}
