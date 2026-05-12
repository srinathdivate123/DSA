// https://takeuforward.org/data-structure/serialize-and-deserialize-a-binary-tree
// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description

// Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

// Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

// Clarification: The input/output format is the same as "how LeetCode serializes a binary tree". You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

// How LeetCode serializes a binary tree: https://support.leetcode.com/hc/en-us/articles/32442719377939-How-to-create-test-cases-on-LeetCode#h_01J5EGREAW3NAEJ14XC07GRW1A

// Here, we use level order traversal for serializing and deserializing

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

void inorder(TreeNode *root)
{
    if (!root)
    {
        return;
    }

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

class Solution
{
public:
    string serialize(TreeNode *root)
    {
        if (!root)
        {
            return "";
        }

        string s = "";
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *curNode = q.front();
            q.pop();

            // If current node is null, append "#" to string
            if (curNode == nullptr)
            {
                s += "#,";
            }
            else
            {
                // Append node value to string
                s += to_string(curNode->val) + ",";

                // We're not checking whether the left & right are null
                // We're just adding them into the queue
                // If it happens to be a nullptr, then #, will be added in the next iteration
                q.push(curNode->left);
                q.push(curNode->right);
            }
        }

        return s;
    }

    TreeNode *deserialize(string data)
    {
        if (data.empty())
        {
            return nullptr;
        }

        // Use stringstream to parse the input data
        // This allows the string to be iterated over as objects
        stringstream s(data);
        string str;

        // Read the root value from the stream with ',' as the delimiter
        getline(s, str, ',');

        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            // Read the left child value
            getline(s, str, ',');

            // If value is not "#", create left node and attach to current node
            if (str != "#")
            {
                TreeNode *leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

            // Read the right child value
            getline(s, str, ',');

            // If value is not "#", create right node and attach to current node
            if (str != "#")
            {
                TreeNode *rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }

        return root;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Solution solution;

    cout << "Orignal Tree: ";
    inorder(root);
    cout << endl;

    string serialized = solution.serialize(root);
    cout << "Serialized: " << serialized << endl;

    TreeNode *deserialized = solution.deserialize(serialized);

    cout << "Tree after deserialisation: ";
    inorder(deserialized);
    cout << endl;

    return 0;
}
