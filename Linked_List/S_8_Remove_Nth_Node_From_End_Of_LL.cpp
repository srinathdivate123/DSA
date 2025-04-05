#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print(ListNode *headNode)
{
    while (headNode != nullptr)
    {
        cout << headNode->val << " ";
        headNode = headNode->next;
    }
}

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

// Use the concept of fast pointer and slow pointer. Fast pointer is initially at the n-th index from the starting
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *fastp = head;
    ListNode *slowp = head;

    for (int i = 0; i < n; i++)
        fastp = fastp->next;

    if (fastp == NULL)
        return head->next;

    while (fastp->next != NULL)
    {
        fastp = fastp->next;
        slowp = slowp->next;
    }

    ListNode *delNode = slowp->next;
    slowp->next = slowp->next->next;
    delete delNode;
    return head;
}

//  Brute Force: https://takeuforward.org/data-structure/remove-n-th-node-from-the-end-of-a-linked-list/
int main()
{
    vector<int> arr = {1,2,3,4,5,6,7,8,9,};
    ListNode *headNode = convertArr2DLL(arr);
    cout << "Before:  " << endl;
    print(headNode);
    cout << endl;

    ListNode *ans = removeNthFromEnd(headNode, 7);
    cout << "After:" << endl;
    print(ans);
}