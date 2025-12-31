// https://takeuforward.org/graph/g-30-word-ladder-ii
// https://leetcode.com/problems/word-ladder-ii/description/
// https://youtu.be/DREutrv2XD0

// Given two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. Find all shortest transformation sequence(s) from startWord to targetWord. You can return them in any order possible.

// In this problem statement, we need to keep the following conditions in mind:
// --> A word can only consist of lowercase characters.
// --> Only one letter can be changed in each transformation.
// --> Each transformed word must exist in the wordList including the targetWord.
// --> startWord may or may not be part of the wordList.
// --> Return an empty list if there is no such transformation sequence.

// -------------------------------------------------------------------------------------

// This problem is an extension of the Word Ladder I problem. Here, instead of finding the length of the shortest transformation sequence, we need to find all shortest sequences that transform beginWord to endWord using words from the wordList.

// --> Insert all words from wordList into an unordered_set for O(1) lookups.
// --> Use a queue of vectors to store sequences of words leading from beginWord to the current word.
// --> Perform BFS:
// --> At each level, maintain a vector 'usedOnLevel' which has the words used in that level and erase them from the set at the start of the next level. Refer video for more explanation

// -----> It is very important that you delete the word only when you have worked on all the sequences in the queue for that particular level. If there happen to be two sequences that are at level 2, then you must work on the last words of both these sequences before removing the used words from the set!
// -----> If you have startWord = bat, endWord = coz and wordLiat = {pat, bot, pot, poz, coz}
// -----> Then you have two answers: {bat, bot, pot, poz, coz} and {bat, pat, pot, poz, coz}
// -----> So you see that the same word can be used in the same level for two different sequences.
// -----> Hence, it is very important to delete a word from the wordList only when you have worked on all the sequences in the queue for that particular level.

// --> For each word at the end of a sequence, try changing every character to a-z. If the resulting word exists in the set:
// -----> Create a new sequence with this word appended.
// -----> Push the new sequence to the queue.
// -----> If a sequence reaches the endWord, store it. Only sequences with minimal length are stored.
// -----> Return all sequences of minimal length after BFS ends.

// --------------------------------------------------------------------------------------

// TC: O(N × L × 26 + S × L) → dominated by generating all transformations (N = words, L = word length, S = number of shortest sequences).

// SC: O(N × L + S × L) → for queue storing paths, set for unused words, and final sequences.

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string> &wordList)
    {
        // Set for quick lookup and deletion
        unordered_set<string> st(wordList.begin(), wordList.end());

        // Creating a queue which stores the words in a sequence which is
        // required to reach the targetWord after successive transformations.
        queue<vector<string>> q;

        q.push({beginWord});

        // This vector stores the words being currently used on a level during BFS.
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        int level = 0; // Currently we're at level 0

        vector<vector<string>> ans;

        while (!q.empty())
        {
            vector<string> vec = q.front();
            q.pop();

            // Erase all words that have been used in the previous levels to make a transformation
            // We need to delete the words only when we have reached the next level
            // Refer video for more explanation
            if (vec.size() > level)
            {
                for (auto it : usedOnLevel)
                {
                    st.erase(it);
                }
                level++; // Move to the next level after you have deleted all the words that were used in the previous level
                usedOnLevel.clear(); // Not sure why!
            }

            // This is the word that we have to transform!
            string word = vec.back();

            // store the answers if the end word matches with targetWord.
            if (word == endWord)
            {
                // the first sequence where we reached end
                if (ans.size() == 0)
                {
                    ans.push_back(vec);
                }
                // If this is not the first sequence in the answer, then we have to make sure that we store only those sequences which are as short as our first sequence
                // We do not want to store any sequences that are long even though they may be a correct sequence
                else if (ans[0].size() == vec.size())
                {
                    ans.push_back(vec);
                }
            }

            for (int i = 0; i < word.size(); i++)
            {
                char original = word[i];
                for (char c = 'a'; c <= 'z'; c++)
                {
                    word[i] = c;
                    if (st.find(word) != st.end())
                    {
                        // Check if the word is present in the wordList and
                        // push the word along with the new sequence in the queue.
                        vec.push_back(word);
                        q.push(vec);

                        // We have used this word in this level
                        usedOnLevel.push_back(word);

                        // We need to pop it out as there may be more transformations possible with 'word' and we need to try for those possible transformations with the original vec
                        // Watch video if you didn't understand
                        vec.pop_back();
                    }
                }
                word[i] = original;
            }
        }
        return ans;
    }
};

// A comparator function to sort the answer.
bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for (string i : a)
        x += i;
    for (string i : b)
        y += i;

    return x < y;
}

int main()
{

    vector<string> wordList = {"des", "der", "dfr", "dgt", "dfs"};
    string startWord = "der", targetWord = "dfs";
    Solution obj;
    vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);

    // If no transformation sequence is possible.
    if (ans.size() == 0)
        cout << -1 << endl;
    else
    {
        sort(ans.begin(), ans.end(), comp);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}