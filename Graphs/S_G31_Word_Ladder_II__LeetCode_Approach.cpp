// This is for LeetCode and CP

// Part 1: Follow Word Ladder 1, find the minimum steps and store the steps/level for which every word from the wordList was used (you need to store this in a map)

// Part 2: Backtrack in the map from end to begin to get the answer
// To understand why backtracking is needed: https://www.youtube.com/watch?v=AD4SFl7tu7I&t=691s

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

class Solution
{
    // Declaring few variables as global as per CP rules
    unordered_map<string, int> mpp;
    vector<vector<string>> ans;
    string b;
    vector<string> seq;

private:
    void dfs(string word, vector<string> &seq)
    {
        if (word == b)
        {
            // If you reach the beginWord, the seq is your answer
            // But the seq is currently stored in a reverse order, from the endWord to the beginWord
            // So you need to reverse it
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);

            // You need to re-reverse it again because it will be used in the dfs in later calls
            reverse(seq.begin(), seq.end());
            return;
        }

        int steps = mpp[word];
        int wordSize = word.size();

        for (int i = 0; i < wordSize; i++)
        {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (mpp.find(word) != mpp.end() && mpp[word] + 1 == steps)
                {
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord); // We don't want to use the beginWord again

        queue<string> q;
        q.push({beginWord});

        b = beginWord;      // Just to assign it to the global b
        mpp[beginWord] = 1; // beginWord was taken at level 1

        int wordSize = beginWord.size();

        // Part 1:
        while (!q.empty())
        {
            string word = q.front();
            q.pop();

            // Once you reach the endWord, your job is done and you no longer need to iterate
            if (word == endWord)
            {
                break;
            }

            int steps = mpp[word];

            for (int i = 0; i < wordSize; i++)
            {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if (st.count(word)) // If word is found in the st
                    {
                        q.push(word);
                        st.erase(word);
                        mpp[word] = steps + 1;
                    }
                }
                word[i] = original;
            }
        }

        // Part 2:
        if (mpp.find(endWord) != mpp.end()) // Check if you have indeed reached the endWord
        {
            seq.push_back(endWord);
            dfs(endWord, seq);
        }
        return ans;
    }
};
int main()
{

    return 0;
}