#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *nextPtr;
    Node *backPtr;

    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        nextPtr = next1;
        backPtr = back1;
    }

    Node(int data1)
    {
        data = data1;
        nextPtr = nullptr;
        backPtr = nullptr;
    }
};

Node *convertArr2DLL(vector<int> arr)
{
    Node *headNode = new Node(arr[0]);
    Node *prevNode = headNode;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *tempNode = new Node(arr[i], nullptr, prevNode);
        prevNode->nextPtr = tempNode;
        prevNode = tempNode;
    }
    return headNode;
}

void print(Node *headNode)
{
    while (headNode != nullptr)
    {
        cout << headNode->data << " ";
        headNode = headNode->nextPtr;
    }
}

Node *reverseDLL(Node *headNode)
{
    if (headNode == NULL || headNode->nextPtr == NULL)
        return headNode;
    Node *prevNode = NULL;

    Node *currentNode = headNode;

    while (currentNode != NULL)
    {
        prevNode = currentNode->backPtr;
        currentNode->backPtr = currentNode->nextPtr;
        currentNode->nextPtr = prevNode;
        currentNode = currentNode->backPtr;
    }
    return prevNode->backPtr;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *headNode = convertArr2DLL(arr);
    cout << endl
         << "Doubly Linked List Initially:  " << endl;
    print(headNode);
    cout << endl
         << "Doubly Linked List After Reversing " << endl;

    headNode = reverseDLL(headNode);
    print(headNode);
    return 0;
}