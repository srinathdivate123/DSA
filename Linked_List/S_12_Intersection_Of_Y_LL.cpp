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

void printList(ListNode *head)
{
    while (head->next != NULL)
    {
        cout << head->val << "->";
        head = head->next;
    }
    cout << head->val << endl;
}

void insertNode(ListNode *&head, int val)
{
    ListNode *newNode = new ListNode(val);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    ListNode *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return;
}

ListNode *checkIntersection(ListNode *l1, ListNode *l2)
{
}

int main()
{

    ListNode *head = NULL;
    insertNode(head, 1);
    insertNode(head, 3);
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 4);
    ListNode *head1 = head;
    head = head->next->next->next;
    ListNode *headSec = NULL;
    insertNode(headSec, 3);
    ListNode *head2 = headSec;
    headSec->next = head;

    cout << "List1: ";
    printList(head1);
    cout << "List2: ";
    printList(head2);

    ListNode *ans = checkIntersection(head1, head2);
    cout << ans->val << " " << ans;
    return 0;
}