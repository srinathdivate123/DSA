// https://takeuforward.org/data-structure/iterative-postorder-traversal-of-binary-tree-using-1-stack
// https://leetcode.com/problems/binary-tree-postorder-traversal

// Time Complexity: O(N), where N is the number of nodes in the binary tree. Each node is visited once during the traversal.
// Space Complexity: O(H), where H is the height of the binary tree. The space is used by the stack to store nodes during traversal.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to return the postOrder traversal of a binary tree using one stack
vector<int> postOrder(Node *root)
{
    // Check if the tree is empty, return an empty result
    if (root == NULL)
        return {};

    Node *curr = root;
    stack<Node *> st;      // Stack to store nodes during traversal
    vector<int> postorder; // Vector to store the postorder traversal

    // Traverse the tree until current node is null or the stack is empty
    while (curr != NULL || !st.empty())
    {
        // If current node is not null, push it onto the stack and move to its left child
        if (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            // If current node is null, check the right child of the top node in the stack
            Node *temp = st.top()->right;

            // If right child is null or already visited, process the top node
            if (temp == NULL)
            {
                // Get the top node from the stack
                temp = st.top();
                st.pop();
                // Add the node's data to the postorder list
                postorder.push_back(temp->data);

                // Check if there are more nodes to pop whose right subtree is also processed
                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->data);
                }
            }
            else
            {
                // If right child exists, set current node to the right child
                curr = temp;
            }
        }
    }

    // Return the postorder traversal result
    return postorder;
}

// Function to print the elements of a vector
void printVector(const vector<int> &vec)
{
    // Iterate through the vector and print each element
    for (int num : vec)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> result = postOrder(root);

    cout << "Postorder traversal: ";
    printVector(result);

    return 0;
}