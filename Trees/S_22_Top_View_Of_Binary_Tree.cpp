// https://takeuforward.org/data-structure/top-view-of-a-binary-tree
// There is no LeetCode or LintCode question for this

// Given a Binary Tree, return its Top View. The Top View of a Binary Tree is the set of nodes visible when we see the tree from the top.

// So here basically we do a vertical order traversal and the first node that appears in the vertical order traversal of each column is the top view position of that column

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }

        // Create a map to store vertical level -> node value (only first encountered)
        // There is no need to use a multiset here because we only want the first (topmost) node in the column
        map<int, int> mpp;

        // Create a queue for BFS that stores {node, vertical_level}
        queue<pair<Node *, int>> q;

        // Push the root node with vertical level 0
        q.push({root, 0});

        // Start BFS traversal
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            // Get the node and its vertical position
            Node *node = it.first;
            int line = it.second;

            // If this vertical position is being visited for the first time, store it
            if (mpp.find(line) == mpp.end())
            {
                mpp[line] = node->data;
            }

            // If there is a left child, push it with vertical level - 1
            if (node->left != NULL)
            {
                q.push({node->left, line - 1});
            }

            // If there is a right child, push it with vertical level + 1
            if (node->right != NULL)
            {
                q.push({node->right, line + 1});
            }
        }

        for (auto it : mpp)
        {
            ans.push_back(it.second);
        }

        return ans;
    }
};

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(10);
    root->right->left = new Node(9);

    Solution solution;

    vector<int> result = solution.topView(root);

    cout << "Top View Traversal: ";
    for (auto node : result)
    {
        cout << node << " ";
    }
    return 0;
}
