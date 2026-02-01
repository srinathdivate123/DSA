// https://takeuforward.org/data-structure/number-of-distinct-substrings-in-a-string-using-trie
// PREMIUM - https://leetcode.com/problems/number-of-distinct-substrings-in-a-string
// https://www.lintcode.com/problem/3717/

// Given a string s, you need to return the number of distinct substrings in s.

// We define a substring of a string as a string formed by deleting a certain number of characters from the beginning and a certain number of characters from the end of the original string. Here, "a certain number of characters" can be zero characters.

// Brute force is to generate all substrings and put them into the set
// But set will take a lot of space. Assume you have to store aba and abab then you'll need to store both of them in the set
// But in trie, you'll need to store only abab

// Using Trie
// Initialise a counter to keep track of the number of distinct substrings.
// Iterate through all possible starting positions ‘i’ of the substring. Start from the ‘root’ node for each substring. For each character at index ‘j’ in the substring starting from position ‘i’:
// --> Check if the current node has a child node corresponding to the character at index j.
// --> If not, insert a new child node for character at index j and increment the counter since a new substring is found.
// --> Move to the child node corresponding to the character at index i.
// Repeat this process for all substrings starting from position ‘i’.
// Return the total count of distinct substrings + 1 added to account for the input string itself.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[26];
    // Flag is not needed
    bool containsKey(char ch)
    {
        return links[ch - 'a'];
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
};

// Once you've written the Node class, you actually do not need the Trie class
class Solution
{
public:
    int countDistinctSubstrings(string &s)
    {
        Node *root = new Node();
        int cnt = 0;
        int n = s.size();

        // Iterate through each starting position of the substring
        for (int i = 0; i < n; i++)
        {
            // Start from the root for each substring
            Node *node = root;
            for (int j = i; j < n; j++)
            {
                // Iterate through each character of the substring. The substring begins at i
                // If the current character is not a child of the current node, insert it as a new child node
                if (!node->containsKey(s[j]))
                {
                    for (int k = i; k <= j; k++)
                        cout << s[k];

                    node->put(s[j], new Node());
                    // Insert a new child  node for character s[j]
                    cnt++;
                }
                node = node->get(s[j]);
                cout << endl;
            }
        }
        // +1 to account for the input string
        // Note that the empty string
        return cnt + 1;
    }
};

int main()
{
    // Main function to test the
    // countDistinctSubstrings function
    string s = "striver";
    Solution sol;
    // Input string
    cout << "Number of distinct substrings: " << sol.countDistinctSubstrings(s) << endl;
    return 0;
}
