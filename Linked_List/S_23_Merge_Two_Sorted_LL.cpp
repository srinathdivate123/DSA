// https://leetcode.com/problems/merge-two-sorted-lists/description/

/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.
*/

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

Node *sortTwoLinkedLists(Node *list1, Node *list2)
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

// Function to print the linked list
void printLinkedList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        // Print the data of the current node
        cout << temp->data << " ";
        // Move to the next node
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *list1 = new Node(1);
    list1->next = new Node(3);
    list1->next->next = new Node(5);

    Node *list2 = new Node(2);
    list2->next = new Node(4);
    list2->next->next = new Node(6);

    cout << "First sorted linked list: ";
    printLinkedList(list1);

    cout << "Second sorted linked list: ";
    printLinkedList(list2);

    Node *mergedList = sortTwoLinkedLists(list1, list2);

    cout << "Merged sorted linked list: ";
    printLinkedList(mergedList);

    return 0;
}
