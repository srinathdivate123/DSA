// https://takeuforward.org/graph/word-ladder-i-g-29
// https://leetcode.com/problems/word-ladder/description/

// A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

// --> Every adjacent pair of words differs by a single letter.
// --> Every si for 1 <= i <= k is present in the wordList. Note that beginWord does not need to be in wordList.
// --> sk == endWord

// Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

// NOTE:
// --> A word can only consist of lowercase characters.
// --> Only one letter can be changed in each transformation.
// --> Each transformed word must exist in the wordList including the endWord.
// --> startWord may or may not be part of the wordList

// -----------------------------------------------------------------------------------------

// The problem aims to transform a startWord into an endWord by changing one character at a time, with each intermediate word present in a given wordList. The shortest sequence length is sought. We can model this problem as a graph:

// --> Each word is a node.
// --> An edge exists between two words if they differ by exactly one character and if the words  exist in the wordList.

// Breadth-First Search (BFS) ensures the shortest path is found from startWord to targetWord.
// --> Initialize a queue with a pair {startWord, 1} representing the startWord and its current transformation steps.
// --> Insert all words from wordList into a unordered_set for O(1) lookups.
// --> While the queue is not empty:
// -----> Pop a word and its step count.
// -----> If this word is the targetWord, return the step count.
// -----> For each character in the word, try replacing it with all letters 'a' to 'z':
// ---------> If the new word exists in the set, erase it from the set and push it into the queue with steps + 1.

// --> If no transformation sequence is found, return 0.

// TC: O(N * L * 26), where N is the number of words in the list and L is the length of each word. For each word, we attempt to change each of its L characters to 26 possible characters.

// SC: O(N * L), for the set storing all words and the queue used for BFS.

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int wordLadderLength(string startWord, string targetWord, vector<string> &wordList)
    {
        // Queue for BFS storing {current word, steps taken}
        queue<pair<string, int>> q;
        q.push({startWord, 1});

        // Set for quick lookup and deletion
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(startWord);

        while (!q.empty())
        {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            // If target word is found, return steps
            if (word == targetWord)
            {
                return steps;
            }

            // Try changing every character in the current word
            for (int i = 0; i < word.size(); i++)
            {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if (st.find(word) != st.end())
                    {
                        st.erase(word);
                        q.push({word, steps + 1});
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};

int main()
{
    vector<string> wordList = {"des", "der", "dfr", "dgt", "dfs"};
    string startWord = "der", targetWord = "dfs";

    Solution obj;
    cout << obj.wordLadderLength(startWord, targetWord, wordList) << endl;
    return 0;
}