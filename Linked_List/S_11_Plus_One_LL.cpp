// Add one to a number represented by a LL

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *convertArr2DLL(vector<int> arr)
{
    ListNode *headNode = new ListNode(arr[0]);
    ListNode *prevNode = headNode;

    for (int i = 1; i < arr.size(); i++)
    {
        ListNode *tempNode = new ListNode(arr[i]);
        prevNode->next = tempNode;
        prevNode = tempNode;
    }
    return headNode;
}

void print(ListNode *headNode)
{
    while (headNode != NULL)
    {
        cout << headNode->val << " ";
        headNode = headNode->next;
    }
}

ListNode *reverseIterative(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *temp = head;
    ListNode *prev = NULL;
    ListNode *front = NULL;

    while (temp != NULL)
    {
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

ListNode *plusOneBruteForce(ListNode *head)
{
    head = reverseIterative(head);
    ListNode *temp = head;
    int carry = 1;
    while (temp != NULL)
    {
        carry += temp->val;
        temp->val = carry % 10;
        carry = carry / 10;
        temp = temp->next;
    }
    head = reverseIterative(head);
    if (carry != 0)
    {
        ListNode *newNode = new ListNode(carry % 10);
        newNode->next = head;
        return newNode;
    }
    return head;
}

int helperRecursion(ListNode *temp)
{
    if (temp == NULL)
        return 1;
    int carry = helperRecursion(temp->next);
    temp->val += carry;
    if (temp->val < 10)
        return 0; // This will be the carry
    temp->val = 0;
    return 1;
}

ListNode *plusOneRecursion(ListNode *head)
{
    int carry = helperRecursion(head);
    if (carry == 1)
    {
        ListNode *newNode = new ListNode(carry);
        newNode->next = head;
        return newNode;
    }
    return head;
}

int main()
{
    vector<int> arr = {9, 9, 9};
    ListNode *headNode = convertArr2DLL(arr);
    cout << "Before:  " << endl;
    print(headNode);
    cout << endl;
    ListNode *ans = plusOneBruteForce(headNode);
    cout << "After:  " << endl;
    print(ans);

    // Using recursion
    arr = {9, 9, 9};
    headNode = convertArr2DLL(arr);
    cout << endl << endl
         << "Before:  " << endl;
    print(headNode);
    cout << endl;
    ans = plusOneRecursion(headNode);
    cout << "After:  " << endl;
    print(ans);
}