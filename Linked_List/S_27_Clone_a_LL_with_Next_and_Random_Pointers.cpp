// https://leetcode.com/problems/copy-list-with-random-pointer/description/
// https://takeuforward.org/data-structure/clone-linked-list-with-random-and-next-pointer/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *random;
    Node() : data(0), next(nullptr), random(nullptr) {};
    Node(int x) : data(x), next(nullptr), random(nullptr) {}
    Node(int x, Node *nextNode, Node *randomNode) : data(x), next(nextNode), random(randomNode) {}
};

// Function to insert a copy of each node in between the original nodes
void insertCopyInBetween(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        // Create a new node with the same data
        Node *copy = new Node(temp->data);

        // Point the copy's next to the original node's next
        copy->next = temp->next;

        // Point the original node's next to the copy
        temp->next = copy;

        // Move to the next original node
        temp = copy->next;
    }
}

// Function to connect random pointers of the copied nodes
void connectRandomPointers(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        // Access the copied node
        Node *copyNode = temp->next;

        if (temp->random)
        {
            Node* actualRandomNodePointedBy_temp = temp->random;
            Node* clonedNodeToBePointedBy_copyNode = actualRandomNodePointedBy_temp->next;
            copyNode->random = clonedNodeToBePointedBy_copyNode;
        }
        else
            copyNode->random = nullptr;
        // Move to the next original node
        temp = temp->next->next;
    }
}

// Function to retrieve the deep copy of the linked list
Node *getDeepCopyList(Node *head)
{
    Node *temp = head;
    Node *dummyNode = new Node(-1);
    Node *res = dummyNode;

    while (temp != nullptr)
    {
        // Creating a new List by pointing to copied nodes
        res->next = temp->next;
        res = res->next;

        // Disconnect and revert back to the initial state of the original linked list
        temp->next = temp->next->next;
        temp = temp->next;
    }

    return dummyNode->next;
}

Node *cloneLL(Node *head)
{
    if (!head)
        return nullptr;

    // Step 1: Insert copy of nodes in between
    insertCopyInBetween(head);

    // Step 2: Connect random pointers of copied nodes
    connectRandomPointers(head);

    // Step 3: Retrieve the deep copy of the linked list
    return getDeepCopyList(head);
}

void printClonedLinkedList(Node *head)
{
    while (head != nullptr)
    {
        cout << "Data: " << head->data;
        if (head->random != nullptr)
            cout << ", Random: " << head->random->data;
        else
            cout << ", Random: nullptr";
        cout << endl;
        head = head->next;
    }
}

int main()
{
    // Example linked list: 7 -> 14 -> 21 -> 28
    Node *head = new Node(7);
    head->next = new Node(14);
    head->next->next = new Node(21);
    head->next->next->next = new Node(28);

    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next;
    head->next->next->next->random = head->next;

    cout << "Original :" << endl;
    printClonedLinkedList(head);

    Node *clonedList = cloneLL(head);

    cout << "\nCloned :" << endl;
    printClonedLinkedList(clonedList);

    return 0;
}