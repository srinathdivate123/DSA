// https://leetcode.com/problems/minimum-window-substring/
// https://takeuforward.org/data-structure/minimum-window-substring

// Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

// The testcases will be generated such that the answer is unique.

// Solution_Striver_Brute does not work for some reason!

#include <bits/stdc++.h>
using namespace std;

class Solution_TUF_Brute
{
public:
    // Helper function to check if the current window contains all characters of the target
    bool containsAll(unordered_map<char, int> &windowFreq, unordered_map<char, int> &targetFreq)
    {
        for (auto &entry : targetFreq)
        {
            if (windowFreq[entry.first] < entry.second)
                return false;
        }
        return true;
    }

    string minWindow(string s, string t)
    {
        // Frequency map to count occurrences of characters in target string
        unordered_map<char, int> targetFreq;
        for (char c : t)
        {
            targetFreq[c]++;
        }

        // Store the minimum window length found and the resulting substring
        int minLen = INT_MAX;
        string result = "";

        // Loop through all possible starting points in s
        for (int i = 0; i < s.size(); i++)
        {
            // Frequency map for the current window starting at i
            unordered_map<char, int> windowFreq;

            // Try to expand the window to the right
            for (int j = i; j < s.size(); j++)
            {
                // Add character to current window frequency
                windowFreq[s[j]]++;

                // Check if this window contains all characters of t
                if (containsAll(windowFreq, targetFreq))
                {
                    // If smaller than previous result, update
                    if ((j - i + 1) < minLen)
                    {
                        minLen = j - i + 1;
                        result = s.substr(i, j - i + 1);
                    }
                    break; // No need to expand this window anymore
                }
            }
        }
        return result;
    }
};

class Solution_TUF_Optimal
{
public:
    // Function to find the minimum window in s that contains all characters of t
    string minWindow(string s, string t)
    {
        // Frequency map to store required characters from target string
        unordered_map<char, int> targetFreq;
        for (char c : t)
        {
            targetFreq[c]++;
        }

        // Total unique characters required to match
        int required = targetFreq.size();

        // Sliding window pointers
        int left = 0, right = 0;

        // Counter to track how many unique characters in window match target
        int formed = 0;

        // Frequency map for characters in the current window
        unordered_map<char, int> windowFreq;

        // Track the minimum window length and its starting index
        int minLen = INT_MAX;
        int minLeft = 0;

        // Expand the window by moving right pointer
        while (right < s.size())
        {
            // Add the current character into window
            char c = s[right];
            windowFreq[c]++;

            // If current character is in target and frequency matches, increase formed
            if (targetFreq.count(c) && windowFreq[c] == targetFreq[c])
            {
                formed++;
            }

            // Try shrinking the window from the left
            while (left <= right && formed == required)
            {
                // Update the minimum window if this is smaller
                if ((right - left + 1) < minLen)
                {
                    minLen = right - left + 1;
                    minLeft = left;
                }

                // Remove the left character from window
                char leftChar = s[left];
                windowFreq[leftChar]--;

                // If leftChar is part of target and falls below required count, decrease formed
                if (targetFreq.count(leftChar) && windowFreq[leftChar] < targetFreq[leftChar])
                {
                    formed--;
                }

                // Move the left pointer forward
                left++;
            }

            // Expand the window to the right
            right++;
        }

        // Return the minimum window substring, or empty if not found
        return minLen == INT_MAX ? "" : s.substr(minLeft, minLen);
    }
};

// Generate all substrings
class Solution_Striver_Brute
{
public:
    string minWindow(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        int minLength = INT_MAX;
        int startIndex = -1;
        for (int i = 0; i < n; i++)
        {
            int hash[256] = {0};
            int cnt = 0;
            for (int j = 0; j < m; j++)
            {
                hash[t[j]]++;
            }
            for (int k = 0; k < n; k++)
            {
                // Was it pre-inserted in the previous iteration
                if (hash[s[k]] > 0)
                {
                    cnt++; // Means we found one pre-inserted character, means we have found one character of s in the t!
                    // Umm so now you have to insert this s[k] into the map which means reducing it's number by -1
                    // In this context, inserting into the map is reducing the count by 1
                }
                hash[s[k]]--;
                if (cnt == m)
                {
                    if (k - i + 1 < minLength)
                    {
                        minLength = k - i + 1;
                        startIndex = i;
                        break;
                    }
                }
            }
        }
        return s.substr(startIndex, minLength);
    }
};

// TC = O(m) for initial insertion +  O(2N) for while loop in worst case
// SC = O(256)
class Solution_Striver_Optimal
{
public:
    string minWindow(string s, string t)
    {
        if (s.empty() || t.empty())
            return "";

        int n = s.size();
        int m = t.size();
        int left = 0;
        int right = 0;
        int cnt = 0; // This is the number of characters of t which you have been able to figure out till now in s
        int minLen = INT_MAX;
        int startIndex = -1;
        int hash[256] = {0};

        // Pre-insert all characters of t in hash
        for (char ch : t)
        {
            hash[ch]++;
        }

        // Iterate through s
        while (right < n)
        {
            // If you find something from s already in hash, then it was inserted by t and hence you've found one of the characters of t, so cnt++
            if (hash[s[right]] > 0)
            {
                cnt++;
            }
            // Adding a char from s into the hash means -1 here in this context, because you're adding a char from s and not from t
            hash[s[right]]--;

            // If you have found all the chars of t (i.e. cnt==m) then you try to reduce the window and shrink
            while (cnt == m)
            {
                if (right - left + 1 < minLen)
                {
                    minLen = right - left + 1;
                    startIndex = left;
                }
                // You are removing the char of s from hash, so ++
                hash[s[left]]++;

                // At anytime if it bash becomes greater than 0, it means the occourence of hash ie because of t
                // if it were due to the occurence of s, then it should be -ve as we're decrementing -- as we add characters by s
                // So since the value is now >0 then it means that there is no occurence of s present so the window does not have the chars that are in t
                // Hence, cnt--
                if (hash[s[left]] > 0)
                {
                    cnt--;
                }
                // Move left++ because we want to shorten the window once we have found a suitable answer (cnt==m)
                left++;
            }
            right++;
        }

        if (startIndex == -1)
            return "";
        return s.substr(startIndex, minLen);
    }
};
int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";

    Solution_TUF_Brute solution_tuf_brute;
    Solution_TUF_Optimal solution_tuf_optimal;
    cout << solution_tuf_brute.minWindow(s, t) << endl;
    cout << solution_tuf_optimal.minWindow(s, t) << endl;

    Solution_Striver_Brute solution_striver_brute;
    Solution_Striver_Optimal solution_striver_optimal;
    cout << solution_striver_brute.minWindow(s, t) << endl;
    cout << solution_striver_optimal.minWindow(s, t) << endl;
    return 0;
}