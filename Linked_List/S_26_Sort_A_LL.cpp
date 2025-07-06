// https://leetcode.com/problems/sort-list/description/
// https://takeuforward.org/linked-list/sort-a-linked-list

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

void printLinkedList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *findMiddle(Node *head)
{
    Node *slow = head;
    Node *fast = head->next; // Usually we take it as head, but here we're taking it as head->next because in case of a even length LL, we need the middle to be the first of the the two middle's and not the second
    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node *mergeTwoSortedLinkedLists(Node *list1, Node *list2)
{
    // Create a dummy node to serve as the head of the merged list
    Node *dummyNode = new Node(-1);
    Node *temp = dummyNode;

    while (list1 != nullptr && list2 != nullptr)
    {
        if (list1->data <= list2->data)
        {
            temp->next = list1;
            list1 = list1->next;
        }
        else
        {
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }

    // If any list still has remaining elements, just point the temp to the remaining section of that LL (no need to append all the nodes in a for loop as they're already sorted & this is a LL)
    if (list1 != nullptr)
        temp->next = list1;
    else
        temp->next = list2;
    return dummyNode->next;
}

Node *sortLL(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    Node *middle = findMiddle(head);

    Node *right = middle->next;
    middle->next = nullptr;
    Node *left = head;

    // Sort the left and right halves
    left = sortLL(left);
    right = sortLL(right);

    return mergeTwoSortedLinkedLists(left, right);
}

int main()
{
    // Linked List: 3 2 5 4 1
    Node *head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(5);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(1);
    head->next->next->next->next->next = new Node(-3);

    cout << "Original Linked List: ";
    printLinkedList(head);

    // Sort the linked list
    head = sortLL(head);

    cout << "Sorted Linked List: ";
    printLinkedList(head);

    return 0;
}