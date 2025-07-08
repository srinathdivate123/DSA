// Given the head of a sorted doubly linked list of positive distinct integers, and a target integer, return a 2D array containing all unique pairs of nodes (a, b) such that a + b == target.

// Each pair should be returned as a 2-element array [a, b] with a < b. The list is sorted in ascending order. If there are no such pairs, return an empty list.

#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode *prev;

    ListNode(int value) : val(value), next(nullptr), prev(nullptr) {}

    ~ListNode()
    {
        delete next;
    }
};

class Solution
{
public:
    vector<vector<int>> findPairsWithGivenSum(ListNode *head, int target)
    {
        vector<vector<int>> ans;
        if (!head)
            return ans;

        ListNode *temp = head;
        while (temp->next)
            temp = temp->next;
        ListNode *right = temp;
        ListNode *left = head;

        while (left->val < right->val)
        {
            int sum = left->val + right->val;
            if (sum == target)
            {
                ans.push_back({left->val, right->val});
                left = left->next;
                right = right->prev;
            }
            else if (sum < target)
                left = left->next;
            else
                right = right->prev;
        }
        return ans;
    }
};

int main()
{

    return 0;
}