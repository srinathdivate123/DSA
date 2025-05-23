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

ListNode *oddEvenList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *evenHead = head->next;

    while (even != NULL && even->next != NULL)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    ListNode *headNode = convertArr2DLL(arr);
    cout << "Before:  " << endl;
    print(headNode);
    cout << endl;

    ListNode *ans = oddEvenList(headNode);
    cout << "After:" << endl;
    print(ans);
}