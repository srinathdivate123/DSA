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

ListNode *findMiddleOfLL(ListNode *head)
{
    if (head == NULL)
        return head;
    if (head->next == NULL)
        return head;

    ListNode *fast = head;
    ListNode *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 2, 1};
    ListNode *headNode = convertArr2DLL(arr);
    cout << "Before:  " << endl;
    print(headNode);
    cout << endl;

    ListNode *ans = findMiddleOfLL(headNode);
    cout << ans->val;
}