// https://takeuforward.org/data-structure/bottom-view-of-a-binary-tree
// There is no LeetCode or LintCode question for this

// Given a Binary Tree, return its Bottom View. The Bottom View of a Binary Tree is the set of nodes visible when we see the tree from the bottom.

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Time Complexity: O(N) nodes
// Space Complexity: O(N) nodes

class Solution
{
public:
    vector<int> bottomView(Node *root)
    {
        vector<int> ans;

        if (root == NULL)
        {
            return ans;
        }
        // Create a map to store (column, node value) (only last encountered)
        map<int, int> mpp;
        // Create a queue for BFS that stores {node, vertical_level}
        queue<pair<Node *, int>> q;

        q.push({root, 0});

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            Node *node = it.first;
            int line = it.second;

            // Update the map with the node's data for the current vertical position
            mpp[line] = node->data;

            if (node->left != NULL)
            {
                q.push({node->left, line - 1});
            }

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

    vector<int> bottomView = solution.bottomView(root);

    cout << "Bottom View Traversal: " << endl;
    for (auto node : bottomView)
    {
        cout << node << " ";
    }

    return 0;
}
