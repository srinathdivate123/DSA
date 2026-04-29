// https://takeuforward.org/data-structure/vertical-order-traversal-of-binary-tree
// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree

// Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

// For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

// The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

// Return the vertical order traversal of the binary tree.

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
    vector<vector<int>> findVertical(Node *root)
    {
        // A map is used to store nodes grouped by column, row, node value
        // Node that multiple nodes could be in the same [row, col] hence we use a multiset
        // Multiset stores elements in a sorted order
        // <col, <row, <node1, node2>>
        map<int, map<int, multiset<int>>> nodes;

        // A queue is used for BFS, storing node and its coordinates
        queue<pair<Node *, pair<int, int>>> todo;

        // Push the root node with vertical = 0 and level = 0
        todo.push({root, {0, 0}});

        // Perform BFS traversal
        while (!todo.empty())
        {
            auto p = todo.front();
            todo.pop();

            Node *temp = p.first;
            int x = p.second.first;
            int y = p.second.second;

            // Insert the node into map by vertical and level
            nodes[x][y].insert(temp->data);

            // If left child exists, push with updated coordinates
            if (temp->left)
            {
                todo.push({temp->left, {x - 1, y + 1}});
            }

            // If right child exists, push with updated coordinates
            if (temp->right)
            {
                todo.push({temp->right, {x + 1, y + 1}});
            }
        }

        vector<vector<int>> ans;

        for (auto p : nodes)
        {
            vector<int> col;
            // Collect all nodes in order of levels
            for (auto q : p.second)
            {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            // Push the column into result
            ans.push_back(col);
        }

        return ans;
    }
};

void printResult(const vector<vector<int>> &result)
{
    for (auto level : result)
    {
        for (auto node : level)
        {
            cout << node << " ";
        }
        cout << endl;
    }
    cout << endl;
}

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

    vector<vector<int>> verticalTraversal = solution.findVertical(root);

    cout << "Vertical Traversal:" << endl;
    printResult(verticalTraversal);

    return 0;
}
