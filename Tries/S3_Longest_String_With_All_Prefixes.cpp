// https://takeuforward.org/trie/longest-string-with-all-prefixes
// PREMIUM: https://leetcode.com/problems/longest-word-with-all-prefixes/description/
// https://www.lintcode.com/problem/3728/

// Given an array of strings 'words', find the string 's' in 'words' where all prefixes are also in 'words' and such that the string 's' is the longest, e.g.:
// words = ['app', 'a', 'ap'], the string 'app' has the prefixes 'a', 'ap' in words and is the longest
// Returns the string that meets the requirement, if there are multiple strings that meet the condition and have the same length, returns the smallest string in the dictionary order, if there is no string that meets the condition, then returns the empty string ''.

// ----------------- ANS --------------------

// Insert all the words into a Trie, and mark each end of a word during insertion.
// Now go through each word in the input list.
// For every word, check in the Trie if all its prefixes exist and are marked as complete words.
// If all prefixes are found, keep track of this word if it's longer or lexicographically smaller than the previously stored result.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[26] = {nullptr};

    bool flag = false;

    bool containsKey(char ch)
    {
        return (links[ch - 'a']);
    }

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *node = root;
        for (char ch : word)
        {
            if (!node->containsKey(ch))
            {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }

    bool allPrefixesExist(string word)
    {
        Node *node = root;
        for (auto ch : word)
        {
            if (node->containsKey(ch))
            {
                node = node->get(ch);
                if (!node->isEnd())
                {
                    // If you happen to reach the end before all the ch in the word are iterated, then return false
                    return false;
                }
            }
        }
        return true;
    }
};

class Solution
{
public:
    string longestCompleteString(Trie *root, vector<string> &words)
    {
        Trie trie;
        // Insert all words into trie
        for (string word : words)
            trie.insert(word);

        string ans = "";

        // Check each word to see if it's a complete string
        for (string word : words)
        {
            if (trie.allPrefixesExist(word))
            {
                // Update if it's longer or lexicographically smaller than current answer
                if (word.length() > ans.length() || (word.length() == ans.length() && word < ans))
                    ans = word;
            }
        }
        return ans.empty() ? "" : ans;
    }
};

int main()
{
    Trie *root = new Trie();
    Solution sol;
    vector<string> words = {"n", "ni", "nin", "ninj", "ninja", "ninga"};
    cout << sol.longestCompleteString(root, words) << endl;
    return 0;
}
