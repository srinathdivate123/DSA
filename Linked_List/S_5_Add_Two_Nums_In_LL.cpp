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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *dummyHead = new ListNode();
    ListNode *temp = dummyHead;
    int carryOver = 0;

    while (l1 || l2 || carryOver)
    {
        int sum = 0;
        if (l1)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2)
        {
            sum += l2->val;
            l2 = l2->next;
        }

        sum += carryOver;
        carryOver = sum / 10;
        ListNode *newNode = new ListNode(sum % 10);
        temp->next = newNode;
        temp = temp->next;
    }
    return dummyHead->next;
}

int main()
{
    vector<int> arr1 = {9, 9, 9, 9, 9, 9, 9};
    vector<int> arr2 = {9, 9, 9, 9};
    ListNode *headNode1 = convertArr2DLL(arr1);
    ListNode *headNode2 = convertArr2DLL(arr2);
    cout << endl
         << "Initially:  " << endl;
    print(headNode1);
    cout << endl;
    print(headNode2);
    cout << endl;
    ListNode *ans = addTwoNumbers(headNode1, headNode2);
    cout << "Answer:" << endl;
    print(ans);
    return 0;
}