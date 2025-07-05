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

Node *rotateRight(Node *head, int k)
{
    if (head == nullptr || head->next == nullptr || k == 0)
        return head;

    Node *temp = head;
    int length = 1;
    while (temp->next != nullptr)
    {
        temp = temp->next;
        ++length;
    }
    k %= length;

    temp->next = head;
    int end = length - k;
    while (end--)
        temp = temp->next;
    head = temp->next;
    temp->next = nullptr;
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

    head = rotateRight(head, 4);

    cout << "Rotated Linked List: " << endl;
    printLinkedList(head);
}