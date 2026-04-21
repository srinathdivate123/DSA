// https://takeuforward.org/data-structure/preorder-traversal-of-binary-tree
// https://leetcode.com/problems/binary-tree-preorder-traversal/description/

// Time Complexity: O(N), we process each node once for traversal.
// Space Complexity: O(N), extra space used for storing preorder traversal and recursive stack.

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
    void preorder(Node *root, vector<int> &arr)
    {
        if (root == nullptr)
        {
            return;
        }
        arr.push_back(root->data);
        preorder(root->left, arr);
        preorder(root->right, arr);
    }
};

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution sol;

    vector<int> ans;
    sol.preorder(root, ans);

    for (int val : ans)
    {
        cout << val << " ";
    }

    return 0;
}
