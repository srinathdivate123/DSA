// https://takeuforward.org/data-structure/preorder-inorder-postorder-traversals-in-one-traversal
// Refer TUF blog for complete notes

// Time Complexity: O(3*N), we process each node thrice, once for every traversal.
// Space Complexity: O(4*N), extra space used for storing postorder, inorder, preorder traversal and stack.
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
    vector<vector<int>> preInPostTraversal(Node *root)
    {
        vector<int> pre, in, post;
        if (root == NULL)
        {
            return {};
        }

        // Stack to maintain nodes and their traversal state
        stack<pair<Node *, int>> st;

        // Start with the root node in state 1 (preorder)
        st.push({root, 1});

        while (!st.empty())
        {
            auto it = st.top();
            st.pop();

            // this is part of pre
            if (it.second == 1)
            {
                // Store the node's data  in the preorder traversal
                pre.push_back(it.first->data);
                // Move to state 2 (inorder) for this node
                it.second = 2;
                // Push the updated state back onto the stack
                st.push(it);

                // Push left child onto the stack for processing
                if (it.first->left != NULL)
                {
                    st.push({it.first->left, 1});
                }
            }

            // this is a part of in
            else if (it.second == 2)
            {
                // Store the node's data in the inorder traversal
                in.push_back(it.first->data);
                // Move to state 3 (postorder) for this node
                it.second = 3;
                // Push the updated state back onto the stack
                st.push(it);

                // Push right child onto the stack for processing
                if (it.first->right != NULL)
                {
                    st.push({it.first->right, 1});
                }
            }

            // this is part of post
            else
            {
                // Store the node's data in the postorder traversal
                post.push_back(it.first->data);
            }
        }

        // Returning the traversals
        vector<vector<int>> result;
        result.push_back(pre);
        result.push_back(in);
        result.push_back(post);
        return result;
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

    vector<int> pre, in, post;
    vector<vector<int>> traversals = sol.preInPostTraversal(root);

    pre = traversals[0];
    in = traversals[1];
    post = traversals[2];

    cout << "Preorder traversal: ";
    for (int val : pre)
    {
        cout << val << " ";
    }
    cout << endl;

    cout << "Inorder traversal: ";
    for (int val : in)
    {
        cout << val << " ";
    }
    cout << endl;

    cout << "Postorder traversal: ";
    for (int val : post)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
