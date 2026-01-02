// https://takeuforward.org/graph/g-30-word-ladder-ii
// https://leetcode.com/problems/word-ladder-ii/description/
// https://youtu.be/AD4SFl7tu7I

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
            // If you reach the beginWord, the seq now has your answer
            // But the seq is currently stored in a reverse order, from the endWord to the beginWord
            // So you need to reverse it
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);

            // You need to re-reverse it again because it will be popped back after the dfs (check the dfs call)
            // If you do not re-reverse it, then the wrong word will be popped back
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
                // The word should exist in the mpp and it's step should be 1 greater than the previous one
                if (mpp.find(word) != mpp.end() && mpp[word] + 1 == steps)
                {
                    seq.push_back(word); // Add the word into the seq
                    dfs(word, seq);
                    seq.pop_back(); // Pop it back once you have made the dfs calls
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
            // You need to backtrack in reverse from the endWord to beginWord
            // So you push the endWord into the seq and run the dfs until you reach beginWord
            seq.push_back(endWord);
            dfs(endWord, seq);
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
    vector<vector<string>> ans = obj.findLadders(startWord, targetWord, wordList);

    // If no transformation sequence is possible.
    if (ans.size() == 0)
    {
        cout << -1 << endl;
    }
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