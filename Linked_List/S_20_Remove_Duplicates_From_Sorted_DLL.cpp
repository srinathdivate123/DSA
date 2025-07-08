// Given the head of a doubly linked list with its values sorted in ascending order. Remove all duplicate occurrences of any value in the list so that only distinct values are present in the list.

// Return the head of the modified linked list.

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
    ListNode *removeDuplicates(ListNode *head)
    {
        ListNode *temp = head;
        while (temp && temp->next)
        {
            ListNode *nextNode = temp->next;
            while (nextNode != nullptr && nextNode->val == temp->val)
            {
                ListNode *duplicate = nextNode;
                nextNode = nextNode->next;
                free(duplicate);
            }
            
            temp->next = nextNode;
            if (nextNode)
                nextNode->prev = temp;
            temp = temp->next;
        }
        return head;
    }
};

int main()
{

    return 0;
}