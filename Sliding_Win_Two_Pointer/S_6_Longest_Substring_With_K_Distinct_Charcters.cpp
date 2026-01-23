// https://takeuforward.org/data-structure/longest-substring-with-at-most-k-distinct-characters
// https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/
// https://www.lintcode.com/problem/386/

// Given a string S, find the length of the longest substring that contains at most k distinct characters.

#include <bits/stdc++.h>
using namespace std;

// TC = O(N*N) -> The TC of map is O(1)
// Sc = O(256) -> At max you may have all the 256 chars in the map
int brute(string &str, int k)
{
    unordered_map<char, int> mpp;
    int maxi = 0;
    for (int i = 0; i < str.size(); i++)
    {
        mpp.clear();
        for (int j = i; j < str.size(); j++)
        {
            mpp[str[j]]++;
            if (mpp.size() > k) // Check if the current substr is valid
            {
                break;
            }
            else
            {
                maxi = max(maxi, j - i + 1);
            }
        }
    }
    return maxi;
}

// TC: O(N+N), SC: O(256)
int better(string &str, int k)
{
    int l = 0, r = 0, maxi = 0;
    unordered_map<char, int> mpp;

    while (r < str.size())
    {
        mpp[str[r]]++;
        while (mpp.size() > k)  // Run as long as the current substr is invalid and remove chars to make it valid
        {
            mpp[str[l]]--;
            if (mpp[str[l]] == 0)
                mpp.erase(str[l]);
            l++;
        }
        if (mpp.size() <= k)
        {
            maxi = max(maxi, r - l + 1);
        }
        r++;
    }
    return maxi;
}

// TC: O(N), SC: O(256)
int best(string &str, int k)
{
    int l = 0, r = 0, maxi = 0;
    unordered_map<char, int> mpp;

    while (r < str.size())
    {
        mpp[str[r]]++;
        if (mpp.size() > k) // Basically just remove one char, and keep window size same. Because if you shift l by some places, you will end up with a smaller window, which will not give you the max ans. So keep window size same by incrementing both l & r. But update maxi only if there are k distinct chars in map
        {
            mpp[str[l]]--;
            if (mpp[str[l]] == 0)
                mpp.erase(str[l]);
            l++;
        }
        else
        {
            maxi = max(maxi, r - l + 1);
        }
        r++;
    }
    return maxi;
}

int main()
{
    string str = "aaabbccd";
    cout << brute(str, 2) << endl;
    cout << better(str, 2) << endl;
    cout << best(str, 2) << endl;
}