// https://takeuforward.org/data-structure/length-of-longest-substring-without-any-repeating-character
// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

// Given a string s which can have any characters from a-z, find the length of the longest substring without repeating characters.

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

// Generate all substrings and check
int brute(string str)
{
    if (str.size() == 0)
        return 0;
    int maxans = INT_MIN;

    for (int i = 0; i < str.length(); i++)
    {
        unordered_set<int> set;
        for (int j = i; j < str.length(); j++)
        {
            if (set.find(str[j]) != set.end())
            {
                maxans = max(maxans, j - i);
                break;
            }
            set.insert(str[j]);
        }
    }
    return maxans;
}

// TC = O(N), SC = O(256)
int optimized(string str)
{
    if (str.size() == 0)
        return 0;

    int left = 0, right = 0, maxi = INT_MIN;
    vector<int> mpp(255, -1); // To store character and what index it was last seen
    while (right < str.size())
    {
        if (mpp[str[right]] != -1)
        {
            // If a character was seen earlier, then you need to shrink the window by moving the left to one position after the last seen position
            // You have to take a max with the left itself because the last seen position could be before left itself. In that case you do not want to move left bahind to the last seen position
            left = max(mpp[str[right]] + 1, left);
        }

        // Update the last seen position of the current character
        mpp[str[right]] = right;

        maxi = max(maxi, right - left + 1);
        right++;
    }
    return maxi;
}

int main()
{
    string str = "takeUforward";
    cout << brute(str) << endl;
    cout << optimized(str) << endl;
}