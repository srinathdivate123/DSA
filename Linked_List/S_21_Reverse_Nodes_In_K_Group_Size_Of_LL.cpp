// https://leetcode.com/problems/reverse-nodes-in-k-group/

// Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

// You may not alter the values in the list's nodes, only nodes themselves may be changed.

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

Node *reverseLinkedList(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    Node *temp = head;
    Node *prev = nullptr;
    Node *front = nullptr;

    while (temp != nullptr)
    {
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

Node *getKthNode(Node *temp, int k)
{
    while (--k && temp != nullptr)
        temp = temp->next;
    return temp;
}

Node *kReverse(Node *head, int k)
{
    Node *temp = head;
    Node *prevLast = nullptr;
    while (temp != nullptr)
    {
        Node *kthNode = getKthNode(temp, k);
        if (kthNode == nullptr)
        {
            if (prevLast)
                prevLast->next = temp;
            break;
        }
        Node *nextNode = kthNode->next;
        kthNode->next = nullptr;
        reverseLinkedList(temp);
        if (temp == head)
        {
            head = kthNode;
        }
        else
        {
            prevLast->next = kthNode;
        }
        prevLast = temp;
        temp = nextNode;
    }
    return head;
}

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

int main()
{
    Node *head = new Node(5);
    head->next = new Node(4);
    head->next->next = new Node(3);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(9);
    head->next->next->next->next->next = new Node(2);

    cout << "Original Linked List: ";
    printLinkedList(head);

    head = kReverse(head, 4);

    cout << "Reversed Linked List: ";
    printLinkedList(head);
    return 0;
}