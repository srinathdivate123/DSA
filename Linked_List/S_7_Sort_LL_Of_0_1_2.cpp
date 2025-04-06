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

void print(ListNode *headNode)
{
    while (headNode != NULL)
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

ListNode *sortList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *dummyZeroHead = new ListNode(-1);
    ListNode *dummyOneHead = new ListNode(-1);
    ListNode *dummyTwoHead = new ListNode(-1);

    ListNode *zeroTraversal = dummyZeroHead;
    ListNode *oneTraversal = dummyOneHead;
    ListNode *twoTraversal = dummyTwoHead;

    ListNode *temp = head;

    while (temp != NULL)
    {
        if (temp->val == 0)
        {
            zeroTraversal->next = temp;
            zeroTraversal = temp;
        }
        else if (temp->val == 1)
        {
            oneTraversal->next = temp;
            oneTraversal = temp;
        }
        else if (temp->val == 2)
        {
            twoTraversal->next = temp;
            twoTraversal = temp;
        }
        temp = temp->next;
    }
    zeroTraversal->next = (dummyOneHead->next) ? dummyOneHead->next : dummyTwoHead->next;

    oneTraversal->next = dummyTwoHead->next;

    twoTraversal->next = NULL;

    ListNode *newHead = dummyZeroHead->next;
    delete dummyZeroHead;
    delete dummyOneHead;
    delete dummyTwoHead;
    return newHead;
}

int main()
{
    vector<int> arr = {2, 0, 1, 1, 2, 0, 0, 2, 1};
    ListNode *headNode = convertArr2DLL(arr);
    cout << "Before:  " << endl;
    print(headNode);
    cout << endl;

    ListNode *ans = sortList(headNode);
    cout << "After:" << endl;
    print(ans);
}