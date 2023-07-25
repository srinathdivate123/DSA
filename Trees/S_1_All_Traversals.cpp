#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

vector<int> preorder_Iterative(node *curr, vector<int> &ans)
{
    if (curr == NULL)
        return ans;
    stack<node *> s;
    s.push(curr);
    while (!s.empty())
    {
        node *topNode = s.top();
        ans.push_back(topNode->data);
        s.pop();
        // We're using stack which is LIFO so we push right first and then left
        if (topNode->right != NULL)
            s.push(topNode->right);
        if (topNode->left != NULL)
            s.push(topNode->left);
    }
    return ans;
}

vector<int> preorder_Recursive(node *curr, vector<int> &ans)
{
    if (curr == NULL)
        return ans;
    ans.push_back(curr->data);
    preorder_Recursive(curr->left, ans);
    preorder_Recursive(curr->right, ans);
    return ans;
}

vector<int> inorder_Iterative(node *curr, vector<int> &ans)
{
    if (curr == NULL)
        return ans;
    stack<node *> s;
    while (true)
    {
        if (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        else
        {
            if (s.empty())
                break;
            curr = s.top();
            ans.push_back(curr->data);
            s.pop();
            curr = curr->right;
        }
    }
    return ans;
}

vector<int> inorder_Recursive(node *curr, vector<int> &ans)
{
    if (curr == NULL)
        return ans;
    inorder_Recursive(curr->left, ans);
    ans.push_back(curr->data);
    inorder_Recursive(curr->right, ans);
    return ans;
}

// TC = N
// SC = N + N
vector<int> postorder_Iterative_2_Stacks(node *curr, vector<int> &ans)
{
    vector<int> postOrder;
    if (curr == NULL)
        return postOrder;

    stack<node *> s1, s2;
    s1.push(curr);
    while (!s1.empty())
    {
        curr = s1.top();
        s1.pop();
        s2.push(curr);
        if (curr->left != NULL)
            s1.push(curr->left);
        if (curr->right != NULL)
            s1.push(curr->right);
    }
    while (!s2.empty())
    {
        postOrder.push_back(s2.top()->data);
        s2.pop();
    }
    return postOrder;
}

// TC = 2N because
// SC = N
vector<int> postorder_Iterative_1_Stack(node *curr, vector<int> &ans)
{
    vector<int> postOrder;
    if (curr == NULL)
        return postOrder;

    stack<node *> st;
    while (curr != NULL || !st.empty())
    {

        if (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            node *temp = st.top()->right;
            if (temp == NULL)
            {
                temp = st.top();
                st.pop();
                postOrder.push_back(temp->data);
                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    postOrder.push_back(temp->data);
                }
            }
            else
                curr = temp;
        }
    }
    return postOrder;
}

vector<int> postorder_Recursive(node *curr, vector<int> &ans)
{
    if (curr == NULL)
        return ans;
    postorder_Recursive(curr->left, ans);
    postorder_Recursive(curr->right, ans);
    ans.push_back(curr->data);
    return ans;
}

vector<vector<int>> levelorder_Traversal(node *curr)
{
    vector<vector<int>> ans;
    if (curr == NULL)
        return ans;
    queue<node *> q;
    q.push(curr);
    while (!q.empty())
    {
        int queueSize = q.size();
        vector<int> elements_at_this_level;
        for (int i = 0; i < queueSize; i++)
        {
            node *currentNode = q.front();
            q.pop();
            if (currentNode->left != NULL)
                q.push(currentNode->left);
            if (currentNode->right != NULL)
                q.push(currentNode->right);
            elements_at_this_level.push_back(currentNode->data);
        }
        ans.push_back(elements_at_this_level);
    }
    return ans;
}

void all_traversals_in_one(node *root, vector<int> &pre, vector<int> &in, vector<int> &post)
{
    stack<pair<node *, int>> st;
    st.push({root, 1});
    if (root == NULL)
        return;

    while (!st.empty())
    {
        auto it = st.top();
        st.pop();

        // this is part of pre
        // increment 1 to 2
        // push the left side of the tree
        if (it.second == 1)
        {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->left != NULL)
                st.push({it.first->left, 1});
        }

        // this is a part of in
        // increment 2 to 3
        // push right
        else if (it.second == 2)
        {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->right != NULL)
                st.push({it.first->right, 1});
        }
        // don't push it back again
        else if (it.second == 3)
            post.push_back(it.first->data);
    }
}

int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->left = newNode(6);
    root->right->left = newNode(7);
    root->right->right = newNode(8);
    root->right->right->left = newNode(9);
    root->right->right->right = newNode(10);
    vector<int> ans;
    cout << endl;

    // Pre-Order
    ans = preorder_Iterative(root, ans);
    cout << "The preorder Traversal iteratively is : ";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    ans.clear();
    cout << endl;
    ans = preorder_Recursive(root, ans);
    cout << "The preorder Traversal recursively is : ";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    ans.clear();

    cout << endl;
    cout << endl;

    // In-Order
    ans = inorder_Iterative(root, ans);
    cout << "The inorder Traversal iteratively is : ";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    ans.clear();
    cout << endl;
    ans = inorder_Recursive(root, ans);
    cout << "The inorder Traversal recursively is : ";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    ans.clear();

    cout << endl;
    cout << endl;

    // Post-Order
    ans = postorder_Iterative_2_Stacks(root, ans);
    cout << "The postorder Traversal using 2 stacks is : ";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    ans.clear();
    cout << endl;
    ans = postorder_Iterative_1_Stack(root, ans);
    cout << "The postorder Traversal using 1 stack is  : ";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    ans.clear();
    cout << endl;
    ans = postorder_Recursive(root, ans);
    cout << "The postorder Traversal recursively is    : ";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    ans.clear();

    cout << endl;
    cout << endl;

    vector<vector<int>> levelOrder;
    levelOrder = levelorder_Traversal(root);
    cout << "The level order traversal is : " << endl;
    for (auto level : levelOrder)
    {
        for (auto element : level)
            cout << element << " ";
        cout << endl;
    }

    cout << endl;
    cout << endl;
    vector<int> pre, in, post;
    all_traversals_in_one(root, pre, in, post);
    cout << "All traversals in one shot - " << endl;
    cout << "The preorder Traversal is  : ";
    for (auto nodeVal : pre)
        cout << nodeVal << " ";
    cout << endl;
    cout << "The inorder Traversal is   : ";
    for (auto nodeVal : in)
        cout << nodeVal << " ";
    cout << endl;
    cout << "The postorder Traversal is : ";
    for (auto nodeVal : post)
        cout << nodeVal << " ";

    return 0;
}