// Given the head of a linked list, determine the length of a loop present in the linked list; if not present, return 0.

// https://takeuforward.org/linked-list/length-of-loop-in-linked-list

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

int findLength(Node *slow, Node *fast)
{

    // count to keep track of nodes encountered in loop
    int cnt = 1;
    fast = fast->next;

    while (slow != fast)
    {
        // Increase count by 1 and move fast by one step
        cnt++;
        fast = fast->next;
    }
    return cnt;
}

int lengthOfLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    // Traverse the list to detect a loop
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return findLength(slow, fast);
        }
    }
    return 0;
}

int main()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);
    Node *fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    fifth->next = second;

    int loopLength = lengthOfLoop(head);
    cout << "Length of the loop: " << loopLength << endl;
    return 0;
}