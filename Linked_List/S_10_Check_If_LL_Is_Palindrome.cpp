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


ListNode *reverseIterative(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode *temp = head;
    ListNode *prev = nullptr;
    ListNode *front = nullptr;

    while (temp != nullptr)
    {
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}


bool isPalindrome(ListNode *head)
{
    // First find the middle of the LL
    if (head == nullptr || head->next == nullptr)
        return true;

    ListNode *fast = head;
    ListNode *slow = head;

    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // After the while loop, the slow pointer will be standing at the first half
    // The head of the second half is slow->next
    ListNode *reversedSecondHalfHead = reverseIterative(slow->next);

    ListNode *firstHalf = head;
    ListNode *secondHalf = reversedSecondHalfHead;

    while(secondHalf != nullptr)
    {
        if(firstHalf->val != secondHalf->val)
            return false;
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }
    return true;
}


int main()
{
    vector<int> arr = {1, 2, 3, 4, 2, 1};
    ListNode *headNode = convertArr2DLL(arr);
    cout << isPalindrome(headNode);
}