// https://takeuforward.org/data-structure/flattening-a-linked-list/

/*
Given a linked list containing ‘N’ head nodes where every node in the linked list contains two pointers:

‘Next’ points to the next node in the list
‘Child’ pointer to a linked list where the current node is the head
Each of these child linked lists is in sorted order and connected by a 'child' pointer. Your task is to flatten this linked list such that all nodes appear in a single layer or level in a 'sorted order'.
*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *child;

    Node() : data(0), next(nullptr), child(nullptr) {};
    Node(int x) : data(x), next(nullptr), child(nullptr) {}
    Node(int x, Node *nextNode, Node *childNode) : data(x), next(nextNode), child(childNode) {}
};

// Merges two linked lists in a particular order based on the data value
Node *merge(Node *list1, Node *list2)
{
    // Create a dummy node as a placeholder for the result
    Node *dummyNode = new Node(-1);
    Node *res = dummyNode;

    while (list1 != nullptr && list2 != nullptr)
    {
        if (list1->data < list2->data)
        {
            res->child = list1;
            res = list1;
            list1 = list1->child;
        }
        else
        {
            res->child = list2;
            res = list2;
            list2 = list2->child;
        }
        res->next = nullptr;
    }

    // Connect the remaining elements if any
    if (list1)
        res->child = list1;
    else
        res->child = list2;

    // Break the first node's link to prevent cycles
    if (dummyNode->child)
        dummyNode->child->next = nullptr;

    return dummyNode->child;
}

Node *flattenLinkedList(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    // Recursively flatten the rest of the linked list
    Node *mergedHead = flattenLinkedList(head->next);

    return merge(head, mergedHead);
}

void printLinkedList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->child;
    }
    cout << endl;
}

void printOriginalLinkedList(Node *head, int depth)
{
    while (head != nullptr)
    {
        cout << head->data;

        if (head->child)
        {
            cout << " -> ";
            printOriginalLinkedList(head->child, depth + 1);
        }
        if (head->next)
        {
            cout << endl;
            for (int i = 0; i < depth; ++i)
                cout << "| ";
        }
        head = head->next;
    }
}

int main()
{
    Node *head = new Node(5);
    head->child = new Node(14);

    head->next = new Node(4);
    head->next->child = new Node(10);

    head->next->next = new Node(12);
    head->next->next->child = new Node(13);
    head->next->next->child->child = new Node(20);

    head->next->next->next = new Node(7);
    head->next->next->next->child = new Node(17);

    cout << "Original linked list:" << endl;
    printOriginalLinkedList(head, 0);
    cout << endl;

    Node *flattened = flattenLinkedList(head);
    cout << "\nFlattened linked list: ";
    printLinkedList(flattened);

    return 0;
}