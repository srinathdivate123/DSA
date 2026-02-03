// https://takeuforward.org/trie/maximum-xor-queries-trie
// https://leetcode.com/problems/maximum-xor-with-an-element-from-array/

// You are given an array nums consisting of non-negative integers. You are also given a queries array, where queries[i] = [xi, mi].

// The answer to the ith query is the maximum bitwise XOR value of xi and any element of nums that does not exceed mi. In other words, the answer is max(nums[j] ^ xi) for all j such that nums[j] <= mi. If all elements in nums are larger than mi, then the answer is -1.

// Return an integer array answer where answer.length == queries.length and answer[i] is the answer to the ith query.

// Here we use the concept of Offline Queries. Refer the 'General' section of OneNote DSA notes.

// Instead of inserting all numbers into the Trie at once, we can insert numbers incrementally and only up to the value required by the current query. This reduces unnecessary operations.
// Create a Trie Node Structure. This structure represents a node in the Trie.
// It contains an array (‘links’) to store links to child nodes (0 and 1). It also contains methods for inserting numbers into the Trie and finding the maximum XOR value achievable with a given number.
// Initialise a vector to store the result of queries. Sort the array of numbers and queries based on their end points.
// We sort the queries based on their end point so that we insert numbers into the Trie only up to the point where it is necessary for answering the current query.
// Iterate through the array of numbers and queries and for each query, insert numbers into the Tree until the current query’s endpoint then find the maximum XOR value for the query range using the Trie.

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *links[2]; // For 0 and 1

    bool containsKey(int bit)
    {
        return links[bit] != NULL;
    }

    Node *get(int bit)
    {
        return links[bit];
    }

    void put(int bit, Node *node)
    {
        links[bit] = node;
    }
};

class Trie
{
public:
    Node *root;

    Trie()
    {
        root = new Node();
    }

    // Insert the binary form of a number into the Trie
    void insert(int num)
    {
        // Always start from the root
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        {
            // Get the i-th bit
            int bit = (num >> i) & 1;

            if (!node->containsKey(bit))
            {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    // Get max XOR for a given number
    int getMaxXOR(int num)
    {
        Node *node = root;
        int maxXor = 0;

        for (int i = 31; i >= 0; i--)
        {
            // Get the i-th bit
            int bit = (num >> i) & 1;

            // Try to go opposite bit to maximize XOR
            if (node->containsKey(1 - bit))
            {
                // If available, go to the opposite bit
                node = node->get(1 - bit);
                maxXor |= (1 << i); // Set the ith bit of the maxXor, because we're taking this bit into our answer
            }
            else
            {
                // If opposite bit is not present, then you just need to go to the same bit in the next node as well. You do not have the choice
                node = node->get(bit);
            }
        }

        return maxXor;
    }
};

class Solution
{
public:
    // Function to perform offline max XOR queries
    vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries)
    {
        vector<int> ans(queries.size(), 0);

        // Vector to store online queries in offline format {m, {x, original_index}} format
        vector<pair<int, pair<int, int>>> offlineQueries;

        // Sort the array in ascending order
        sort(arr.begin(), arr.end());

        // Store queries with index for mapping answers later
        int index = 0;
        for (auto &it : queries)
        {
            offlineQueries.push_back({it[1], {it[0], index++}});
        }

        // Sort queries based on 'm' so that queries which have a lower m (maxnum limit) are executed first
        sort(offlineQueries.begin(), offlineQueries.end());

        int i = 0;
        int n = arr.size();

        Trie trie;

        // Process each query in sorted order of 'm'
        for (auto &it : offlineQueries)
        {
            int Mi = it.first;
            int Xi = it.second.first;
            int queryIdx = it.second.second;
            // Insert all elements ≤ m into the trie
            while (i < n && arr[i] <= Mi)
            {
                trie.insert(arr[i]);
                i++;
            }

            // If i has not moved at all
            if (i == 0)
                ans[queryIdx] = -1;
            else
                ans[queryIdx] = trie.getMaxXOR(Xi);
        }
        return ans;
    }
};

int main()
{
    vector<int> arr = {3, 10, 5, 25, 2, 8};

    cout << "Given Array: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    vector<vector<int>> queries = {
        {0, 1}, {1, 2}, {0, 3}, {3, 3}};

    cout << "Queries: ";
    for (auto query : queries)
    {
        cout << query[0] << " " << query[1] << ", ";
    }
    cout << endl;

    Solution obj;

    vector<int> result = obj.maxXorQueries(arr, queries);

    cout << "Result of Max XOR Queries:" << endl;
    for (int i = 0; i < result.size(); ++i)
    {
        cout << "Query " << i + 1 << ": " << result[i] << endl;
    }

    return 0;
}