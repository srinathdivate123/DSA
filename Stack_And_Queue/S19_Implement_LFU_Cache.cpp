// https://takeuforward.org/data-structure/lfu-cache
// https://leetcode.com/problems/lfu-cache/description

// Design and implement a data structure for a Least Frequently Used (LFU) cache.

// Implement the LFUCache class:

// --> LFUCache(int capacity) Initializes the object with the capacity of the data structure.
// --> int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
// --> void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.
// To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with the smallest use counter is the least frequently used key.

// When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use counter for a key in the cache is incremented either a get or put operation is called on it.

// The functions get and put must each run in O(1) average time complexity.

// ----------------------------------------------------------------------------------------------------

// Initialize the cache with a specified capacity
// Create dummy head and tail nodes for each frequency list to simplify edge case handling
// For updating frequency, when a node is accessed or updated:
// --> Remove the node from its current frequency list
// --> If this was the only node in the minimum frequency list, increment the minimum frequency
// --> Increment the node's frequency and add it to the front of the list corresponding to the new frequency
// --> Update both hash maps (keyNode and freqNode) to reflect the changes
// For the "get" operation, check if the key exists in the keyNode map:
// --> If present, retrieve the node, update its frequency, and return its value
// --> If not present, return -1
// For the "put" operation:
// --> If the key already exists in keyNode, update its value, update its frequency, and return
// --> If not present, check if the cache is at capacity
// --> If at capacity, remove the least frequently used node (node with the minimum frequency and least recent usage)
// --> Create a new node for the key-value pair, set its frequency to 1, and add it to the front of the frequency list for nodes with frequency 1
// --> Update both hash maps to reflect the addition of the new node

// ----------------------------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

// To implement a node in doubly linked list that will store data items
struct Node
{
    int key, value, cnt;
    Node *next;
    Node *prev;
    Node(int _key, int _value)
    {
        key = _key;
        value = _value;
        cnt = 1;
    }
};

// To implement the doubly linked list
struct List
{
    int size;   // Size
    Node *head; // Dummy head
    Node *tail; // Dummy tail

    // Constructor
    List()
    {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    // Function to add node in front
    void addFront(Node *node)
    {
        Node *temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++;
    }

    // Function to remove node from the list
    void removeNode(Node *delnode)
    {
        Node *prevNode = delnode->prev;
        Node *nextNode = delnode->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        size--;
    }
};

// Class to implement LFU cache
class LFUCache
{
private:
    // Hashmap to store the key-nodes pairs
    map<int, Node *> keyNode;

    // Hashmap to maintain the lists having different frequencies
    map<int, List *> freqListMap;

    int maxSizeCache; // Max size of cache

    // To store the frequency of least frequently used data-item
    int minFreq;

    // To store current size of cache
    int curSize;

public:
    // Constructor
    LFUCache(int capacity)
    {
        // Set the capacity
        maxSizeCache = capacity;
        minFreq = 0; // Set minimum frequency
        curSize = 0; // Set current frequency
    }

    // Method to update frequency of data-items
    void updateFreqListMap(Node *node)
    {
        // Remove from Hashmap
        keyNode.erase(node->key);

        // Update the frequency list hashmap
        freqListMap[node->cnt]->removeNode(node);

        // If node was the last node having it's frequency
        if (node->cnt == minFreq &&
            freqListMap[node->cnt]->size == 0)
        {
            // Update the minimum frequency
            minFreq++;
        }

        // Creating a dummy list for next higher frequency
        List *nextHigherFreqList = new List();

        // If the next higher frequency list already exists
        if (freqListMap.find(node->cnt + 1) != freqListMap.end())
        {
            // Update pointer to already existing list
            nextHigherFreqList = freqListMap[node->cnt + 1];
        }

        // Increment the count of data-item
        node->cnt += 1;

        // Add the node in front of higher frequency list
        nextHigherFreqList->addFront(node);

        // Update the
        freqListMap[node->cnt] = nextHigherFreqList;
        keyNode[node->key] = node;
    }

    // Method to get the value of key from LFU cache
    int get(int key)
    {
        // Return the value if key exists
        if (keyNode.find(key) != keyNode.end())
        {
            Node *node = keyNode[key]; // Get the node
            int val = node->value;     // Get the value
            updateFreqListMap(node);   // Update the frequency

            // Return the value
            return val;
        }

        // Return -1 if key is not found
        return -1;
    }

    void put(int key, int value)
    {
        // If the size of Cache is 0, no data-items can be inserted
        if (maxSizeCache == 0)
        {
            return;
        }

        // If key already exists
        if (keyNode.find(key) != keyNode.end())
        {
            // Get the node
            Node *node = keyNode[key];

            // Update the value
            node->value = value;

            // Update the frequency
            updateFreqListMap(node);
        }

        // Else if the key does not exist
        else
        {

            // If cache limit is reached
            if (curSize == maxSizeCache)
            {

                // Remove the least frequently used data-item
                List *list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);

                // Update the frequency map
                freqListMap[minFreq]->removeNode(
                    list->tail->prev);

                // Decrement the current size of cache
                curSize--;
            }

            // Increment the current cache size
            curSize++;

            // Adding new value to the cache
            minFreq = 1; // Set its frequency to 1

            // Create a dummy list
            List *listFreq = new List();

            // If the list already exist
            if (freqListMap.find(minFreq) !=
                freqListMap.end())
            {
                // Update the pointer to already present list
                listFreq = freqListMap[minFreq];
            }

            // Create the node to store data-item
            Node *node = new Node(key, value);

            // Add the node to dummy list
            listFreq->addFront(node);

            // Add the node to Hashmap
            keyNode[key] = node;

            // Update the frequency list map
            freqListMap[minFreq] = listFreq;
        }
    }
};

int main()
{
    LFUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << " ";
    cache.put(3, 3);
    cout << cache.get(2) << " ";
    cout << cache.get(3) << " ";
    cache.put(4, 4);
    cout << cache.get(1) << " ";
    cout << cache.get(3) << " ";
    cout << cache.get(4) << " ";
    return 0;
}