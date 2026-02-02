// http://takeuforward.org/data-structure/maximum-xor-of-two-numbers-in-an-array
// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/

// Given an integer array nums with +ve integers, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.
// If you the typical O(n^2) solution of trying every element of the array with every other element, then you get TLE on LeetCode. Hence it is not he expected solution

// To solve above, you must first understand the below problem by heart:
// Given an array of numbers and a number X, find the maximum value of (arr[i]^X)
// ANS:
// 1) Insert all the numbers in their binary format in the Trie. MSB=Head, LSB=Tail.
// 2) Take X and find the max number from the array where (arr[i]^X) is maximum

// ----> When we iterate through the bits of X, we select the opposite bit when available hence ensuring the highest possible XOR result.
// ----> Start from the root node and initialise the maximum XOR values as 0. Iterate through each bit of X (from left to right) and check if the complement of the current bit exists in the Trie.
// ----> If it exists, update the maximum XOR value with the current bit. Move to the child node corresponding to the complement of the current bit.
// ----> If the complement of the current bit doesn’t exist in the Trie, move to the child node corresponding to the current bit.

// Now, the above solution is for when you want to find the max of (arr[i]^X).
// When you want to find the maximum of (arr[i]^arr[j]) then you need to call the function for every arr[j] like it is X.

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

    // Insert the binary forma of a number into the Trie
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
                // If opposite bit is not present, then you just need to go to the same bit in the next node as well
                node = node->get(bit);
            }
        }

        return maxXor;
    }

    // Find the maximum XOR among all pairs
    int getMaxXOR_Array(vector<int> &nums)
    {
        for (int num : nums)
        {
            insert(num);
        }

        int maxResult = 0;
        for (int num : nums)
        {
            // Call the function for each element in nums
            maxResult = max(maxResult, getMaxXOR(num));
        }

        return maxResult;
    }
};

// Driver code
int main()
{
    vector<int> nums = {3, 10, 5, 25, 2, 8};
    Trie sol;
    cout << sol.getMaxXOR_Array(nums) << endl;
    return 0;
}