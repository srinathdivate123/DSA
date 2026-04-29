// https://takeuforward.org/data-structure/boundary-traversal-of-a-binary-tree
// https://leetcode.com/problems/boundary-of-binary-tree/description
// https://www.lintcode.com/problem/878/

// Given a binary tree, return the values of its boundary in anti-clockwise direction starting from root. Boundary includes left boundary, leaves, and right boundary in order without duplicate nodes.

// Left boundary is defined as the path from root to the left-most node. Right boundary is defined as the path from root to the right-most node. If the root doesn't have left subtree or right subtree, then the root itself is left boundary or right boundary. Note this definition only applies to the input binary tree, and not applies to any subtrees.

// The left-most node is defined as a leaf node you could reach when you always firstly travel to the left subtree if exists. If not, travel to the right subtree. Repeat until you reach a leaf node.

// The right-most node is also defined by the same way with left and right exchanged.

// -----------------------------------------------------------

// So we need: Left boundary excluding leaf (top to bottom), leaf and right boundary excluding leaf in reverse order (bottom to top)

// SOLUTION:
// Left Boundary: Traverse the left boundary of the tree. Start from the root and keep moving to the left child; if unavailable, move to the right child. Continue this until we reach a leaf node.

// Bottom Boundary: Traverse the bottom boundary of the tree by traversing the leaf nodes using a simple preorder traversal. We check if the current node is a lead, and if so, its value is added to the boundary traversal array.

// Right Boundary: The right boundary is traversed in the reverse direction, similar to the left boundary traversal starting from the root node and keep moving to the right child; if unavailable, move to the left child. Nodes that are not leaves are pushed into the right boundary array from end to start to ensure that they are added in the reverse direction.


// Time Complexity: O(N) where N is the number of nodes in the Binary Tree.
// Space Complexity: O(N) (N = nodes). O(H) or O(log2N) Recursive stack space while traversing the tree. In the worst case scenario the tree is skewed and the auxiliary recursion stack space would be stacked up to the maximum depth of the tree, resulting in an O(N) auxiliary space complexity.

#include <iostream>
#include <vector>

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
    bool isLeaf(Node *root)
    {
        return !root->left && !root->right;
    }

    void addLeftBoundary(Node *root, vector<int> &res)
    {
        Node *curr = root->left;
        while (curr)
        {
            if (!isLeaf(curr))
            {
                res.push_back(curr->data);
            }
            // Move to the left child if it exists, otherwise move to the right child
            if (curr->left)
            {
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
        }
    }

    void addRightBoundary(Node *root, vector<int> &res)
    {
        Node *curr = root->right;
        vector<int> temp;
        while (curr)
        {
            if (!isLeaf(curr))
            {
                temp.push_back(curr->data);
            }
            // Move to the right child if it exists, otherwise move to the left child
            if (curr->right)
            {
                curr = curr->right;
            }
            else
            {
                curr = curr->left;
            }
        }
        // Reverse and add the values from the temporary vector to the result
        for (int i = temp.size() - 1; i >= 0; --i)
        {
            res.push_back(temp[i]);
        }
    }

    // This is a simple pre-order traversal
    void addLeaves(Node *root, vector<int> &res)
    {
        // If the current node is a leaf, add its value to the result
        if (isLeaf(root))
        {
            res.push_back(root->data);
            return;
        }
        // Recursively add leaves of the left and right subtrees
        if (root->left)
        {
            addLeaves(root->left, res);
        }
        // NOTE that there is a "if" below and not an "else"
        if (root->right)
        {
            addLeaves(root->right, res);
        }
    }

    vector<int> printBoundary(Node *root)
    {
        vector<int> res;
        if (!root)
        {
            return res;
        }
        // If the root is not a leaf, add its value to the result
        if (!isLeaf(root))
        {
            res.push_back(root->data);
        }

        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);

        return res;
    }
};


void printResult(const vector<int> &result)
{
    for (int val : result)
    {
        cout << val << " ";
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
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution solution;
    vector<int> result = solution.printBoundary(root);

    cout << "Boundary Traversal: ";
    printResult(result);
    return 0;
}