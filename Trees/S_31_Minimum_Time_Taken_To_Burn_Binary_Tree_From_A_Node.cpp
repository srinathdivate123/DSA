// https://takeuforward.org/data-structure/minimum-time-taken-to-burn-the-binary-tree-from-a-node
// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description

// LeetCode description is in terms of tree getting infected
// You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.
// Each minute, a node becomes infected if:
// --> The node is currently uninfected.
// --> The node is adjacent to an infected node.
// Return the number of minutes needed for the entire tree to be infected.

// --------------------------------------------------------------------------
// This is eerily similar to the rotting oranges problem in graphs

// NOTE: Below I've solved the problem using BFS (level order traversal). Other ways to solve this problem could be:

// 1) DFS: We can use DFS, since it is a tree not graph (ie acyclic), here ans would be max of all depths from start node, simply max of distance you can do from start, while maintaining visited. For parent mapping, obviously BFS is the only option. However, bfs is more natural as intuitive to come up with, but DFS is also possible approach to follow after parent mapping.

// 2) Convert it into a graph and then use BFS

// Below code is from: https://garmadon.notion.site/Time-needed-to-burn-the-tree-ff17bc7379e241ff98298d9ff8e03f2d

// Time Complexity: 2 * O(N)

// Space Complexity: 3 * O(N) (parent_map + visited map + queue)

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
    // This function "maps" a child node to it's parent node; returns address of starting node
    TreeNode *findParents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent_map, int startValue)
    {
        queue<TreeNode *> q;
        q.push(root);

        TreeNode *startNode;

        while (!q.empty())
        {
            TreeNode *currNode = q.front();
            q.pop();

            if (currNode->val == startValue)
            {
                startNode = currNode;
            }

            if (currNode->left)
            {
                q.push(currNode->left);
                parent_map[currNode->left] = currNode;
            }

            if (currNode->right)
            {
                q.push(currNode->right);
                parent_map[currNode->right] = currNode;
            }
        }

        return startNode;
    }

    int amountOfTime(TreeNode *root, int start)
    {
        if (root == NULL)
            return 0;

        unordered_map<TreeNode *, TreeNode *> parent_map;

        // Prepare the parent map, starting from the root;
        // and get address of node with value 'start'
        TreeNode *startNode = findParents(root, parent_map, start);

        // map to mark burned nodes
        unordered_map<TreeNode *, bool> burned;

        // queue for performing level order traversal
        queue<TreeNode *> q;

        q.push(startNode);
        burned[startNode] = true;

        // set initial time as -1 minutes; the fire hasn't started yet.
        int minutes = -1;

        while (!q.empty())
        {
            // Fire radius increases every minute; Yes, the fire rises!
            minutes++;

            int queueSize = q.size();

            // So that we can move level-wise (means, radially outwards)
            for (int iterator = 0; iterator < queueSize; iterator++)
            {
                TreeNode *currNode = q.front();
                q.pop();

                if (currNode->left && !burned[currNode->left])
                {
                    q.push(currNode->left);
                    burned[currNode->left] = true;
                }

                if (currNode->right && !burned[currNode->right])
                {
                    q.push(currNode->right);
                    burned[currNode->right] = true;
                }

                if (parent_map[currNode] && !burned[parent_map[currNode]])
                {
                    q.push(parent_map[currNode]);
                    burned[parent_map[currNode]] = true;
                }
            }
        }
        return minutes;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->left->right = new TreeNode(7);

    Solution sol;
    int target = 1;
    cout << "Minimum time to burn the tree: " << sol.amountOfTime(root, target) << endl;
    return 0;
}
