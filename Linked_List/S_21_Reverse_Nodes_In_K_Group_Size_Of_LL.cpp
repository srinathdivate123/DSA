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

    // Easy way to remember below loop: Note that in a given line, the expression which is in the right side of the '=', comes to the left side of the '=' in the next line. Which means, what we use to assign the value to a variable, that itself is changed in the next line!
    while (temp != nullptr)
    {
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

// IMP
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
            // Once you have reversed the next section (assuming you're reading this while standing at the last node of the previosuly reversed section), point the end of the previously reversed section to the start of the newly reversed section
            prevLast->next = kthNode;
        }
        prevLast = temp;
        temp = nextNode;
    }
    return head;
}

// Work on this!!!
Node *myReverse(Node *head, int k)
{
    Node *temp = head;
    Node *prev = nullptr;
    Node *front = nullptr;
    Node *start = nullptr;
    int count = 0;


    while (temp != nullptr)
    {
        if(count == 0)
            start = temp;
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
        count++;
        if(count == k)
        {
            start->next = temp;
            count = 0;
        }
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
    Node *head = new Node(0);
    Node *temp = head;
    for (int i = 1; i < 10; i++)
    {
        temp->next = new Node(i);
        temp = temp->next;
    }

    cout << "Original Linked List: " << endl;
    printLinkedList(head);

    head = kReverse(head, 3);

    cout << "Reversed Linked List: " << endl;
    printLinkedList(head);

    /*   MY REVERSE FUNCTION */

    myReverse(head, 3);

    cout << "Re-reversed Linked List by my reverse function: " << endl;
    printLinkedList(head);
    return 0;
}