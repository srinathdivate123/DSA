// https://takeuforward.org/linked-list/merge-k-sorted-linked-lists
// https://leetcode.com/problems/merge-k-sorted-lists/description/

// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order. Merge all the linked-lists into one sorted linked-list and return it.

// Use the concept of min-heap here!

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

Node* mergeKLists(vector<Node*>& listArray){
    // Priority queue to maintain sorted order based on node values
    // Pairs store node value and pointer to the node
    priority_queue<pair<int, Node*>,
        vector<pair<int, Node*>>, greater<pair<int, Node*>>> pq;
    
    // Push the heads of the 'k' linked lists into the priority queue
    for(int i = 0; i < listArray.size(); i++){
        // The below condition check is required because, as said in LeetCode, the listArray could also be like: [[]]
        if(listArray[i]){
            pq.push({listArray[i]->data, listArray[i]});
        }
    }
    
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;
    
    // Merge the lists present in the priority queue
    while(!pq.empty()){
        // Get the top element (minimum node value) from the priority queue
        auto it = pq.top();
        pq.pop();
        
        if(it.second->next){
            pq.push({it.second->next->data, it.second->next});
        }
        temp->next = it.second;
        temp = temp->next;
    }
    
    return dummyNode->next;
}


void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " "; 
        temp = temp->next; 
    }
    cout << endl;
}

int main() {
    Node* head1 = new Node(2, new Node(4, new Node(6)));
    Node* head2 = new Node(1, new Node(5));
    Node* head3 = new Node(1, new Node(1, new Node(3, new Node(7))));
    Node* head4 = new Node(8);

    vector<Node*> lists = {head1, head2, head3, head4};
    
    cout << "Original Linked Lists:" << endl;
    for (int i = 0; i < lists.size(); ++i) {
        cout << "List " << i + 1 << ": ";
        printLinkedList(lists[i]);
    }

    Node* mergedList = mergeKLists(lists);

    cout << "Merged Linked List: ";
    printLinkedList(mergedList);
    return 0;
}