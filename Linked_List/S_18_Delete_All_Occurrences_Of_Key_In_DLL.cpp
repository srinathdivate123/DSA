// Given the head of a doubly linked list and an integer target. Delete all nodes in the linked list with the value target and return the head of the modified linked list

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode()
    {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *prev1)
    {
        val = data1;
        next = next1;
        prev = prev1;
    }
};

class Solution
{
public:
    ListNode *deleteAllOccurrences(ListNode *head, int target)
    {
        ListNode *temp = head;
        while (temp != nullptr)
        {
            if (temp->val == target)
            {
                // If this is the head of the LL, then post delete, the head will be updated
                if (temp == head)
                    head = temp->next;

                ListNode *nextNode = temp->next;
                ListNode *prevNode = temp->prev;

                if (nextNode)
                    nextNode->prev = prevNode;
                if (prevNode)
                    prevNode->next = nextNode;

                free(temp);
                temp = nextNode;
            }
            else
                temp = temp->next;
        }
    }
};

int main()
{

    return 0;
}