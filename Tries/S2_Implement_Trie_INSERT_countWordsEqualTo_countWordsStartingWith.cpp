// https://takeuforward.org/data-structure/implement-trie-ii

// Problem Statement: Implement "TRIE” data structure from scratch with the following functions.

// Trie(): Initialize the object of this “TRIE” data structure.
// insert(“WORD”): Insert the string “WORD” into this “TRIE” data structure.
// countWordsEqualTo(“WORD”): Return how many times this “WORD” is present in this “TRIE”.
// countWordsStartingWith(“PREFIX”): Return how many words are there in this “TRIE” that have the string “PREFIX” as a prefix.
// erase(“WORD”): Delete one occurrence of the string “WORD” from the “TRIE”.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    // Array to store links to child nodes
    Node *links[26];
    // Number of words that end at this node
    int cntEndWith = 0;
    // Number of words that have this node as a prefix
    int cntPrefix = 0;

    // Function to check if the node contains a specific key
    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }

    // Function to get the child node corresponding to a key
    Node *get(char ch)
    {
        // Return the link corresponding to the character
        return links[ch - 'a'];
    }

    // Function to insert a child node with a specific key
    void put(char ch, Node *node)
    {
        // Set the link corresponding to the character to the provided node
        links[ch - 'a'] = node;
    }

    void increaseEnd()
    {
        cntEndWith++;
    }

    void increasePrefix()
    {
        cntPrefix++;
    }

    void deleteEnd()
    {
        cntEndWith--;
    }

    void reducePrefix()
    {
        cntPrefix--;
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

    // Function to insert a word into the trie
    void insert(string word)
    {
        // Start from the root node
        Node *tempNode = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!tempNode->containsKey(word[i]))
            {
                tempNode->put(word[i], new Node());
            }
            tempNode = tempNode->get(word[i]); // Get's the next tempNode (which is currently blank)
            tempNode->increasePrefix();
        }
        tempNode->increaseEnd();
    }

    // Function to count the number of words equal to a given word
    int countWordsEqualTo(string word)
    {
        Node *tempNode = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (tempNode->containsKey(word[i]))
            {
                // Move to the child tempNode corresponding to the character
                tempNode = tempNode->get(word[i]);
            }
            else
            {
                // Return 0 if the character is not found
                return 0;
            }
        }
        // Once you reach the end, return the count of words
        return tempNode->cntEndWith;
    }

    // Function to count the number of words starting with a given prefix
    int countWordsStartingWith(string word)
    {
        Node *tempNode = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (tempNode->containsKey(word[i]))
            {
                // Move to the child tempNode corresponding to the character
                tempNode = tempNode->get(word[i]);
            }
            else
            {
                // Return 0 if the character is not found
                return 0;
            }
        }
        // Return the count of words with the prefix
        return tempNode->cntPrefix;
    }

    // Function to erase a word from the trie
    void erase(string word)
    {
        Node *tempNode = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (tempNode->containsKey(word[i]))
            {
                // Move to the child tempNode corresponding to the character
                tempNode = tempNode->get(word[i]);
                // Decrement the prefix count for the tempNode
                tempNode->reducePrefix();
            }
            else
            {
                // Return if the character is not found
                return;
            }
        }
        // Decrement the end count for the last tempNode of the word
        tempNode->deleteEnd();
    }
};

int main()
{
    Trie trie;
    trie.insert("apple");
    trie.insert("apple");
    cout << "Inserting strings 'apple' twice into Trie" << endl;
    cout << "Count Words Equal to 'apple': ";
    cout << trie.countWordsEqualTo("apple") << endl;
    cout << "Count Words Starting With 'app': ";
    cout << trie.countWordsStartingWith("app") << endl;
    cout << "Erasing word 'apple' from trie" << endl;
    trie.erase("apple");
    cout << "Count Words Equal to 'apple': ";
    cout << trie.countWordsEqualTo("apple") << endl;
    cout << "Count Words Starting With 'app': ";
    cout << trie.countWordsStartingWith("app") << endl;
    cout << "Erasing word 'apple' from trie" << endl;
    trie.erase("apple");
    cout << "Count Words Starting With 'app': ";
    cout << trie.countWordsStartingWith("app") << endl;
    return 0;
}