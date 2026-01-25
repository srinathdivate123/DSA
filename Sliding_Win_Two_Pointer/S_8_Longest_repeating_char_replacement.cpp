// https://leetcode.com/problems/longest-repeating-character-replacement/description/
// https://takeuforward.org/data-structure/longest-repeating-character-replacement

// You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase english character. You can perform this operation at most k times.

// Return the length of the longest substring containing the same letter you can get after performing the above operations.

// The number of changes required for any substring => substring length - occourence of the max occourence character

#include <bits/stdc++.h>
using namespace std;

// Generate all subarrays
// TC = O(N*N), SC = O(26)
int brute(string s, int k)
{
    int maxLen = 0;
    for (int i = 0; i < s.size(); i++)
    {
        vector<int> hash(26, 0);
        int max_freq = 0;
        for (int j = i; j < s.size(); j++)
        {
            hash[s[j] - 'A']++;
            max_freq = max(max_freq, hash[s[j] - 'A']);
            int changes_required = (j - i + 1) - max_freq;
            if (changes_required <= k)
                maxLen = max(maxLen, (j - i + 1));
            else
                break;
        }
    }
    return maxLen;
}

// TC = O(N + N)*26, SC = O(26)
// Need to check why below is going in infinite loop!
int better(string &s, int k)
{
    int l = 0, r = 0, max_len = 0, max_freq = 0;
    vector<int> hash(26, 0);

    while (r < s.size())
    {
        hash[s[r] - 'A']++;
        max_freq = max(max_freq, hash[s[r] - 'A']);
        int changes_required = (r - l + 1) - max_freq;
        // AABABBA
        while (changes_required > k)
        // we replace while with if, this helps in keeping the window size as the same i.e. r-l+1 ; If this window becomes valid anytime, then we update the max_len. Because we always want a longer window
        {
            hash[s[l] - 'A']--;
            max_freq = 0;
            for (int i = 0; i < 26; i++)
                max_freq = max(max_freq, hash[i]);
            l++;
            changes_required = (r - l + 1) - max_freq;
        }
        if (changes_required <= k)
        {
            max_len = max(max_len, r - l + 1);
        }
        r++;
    }
    return max_len;
}

// TC = O(N + 26), SC = O(26)
int best(string s, int k)
{
    int l = 0, r = 0, max_len = 0, max_freq = 0;
    vector<int> hash(26, 0);

    while (r < s.size())
    {
        hash[s[r] - 'A']++;
        max_freq = max(max_freq, hash[s[r] - 'A']);
        int changes_required = (r - l + 1) - max_freq;
        if (changes_required > k)
        // We replace while with if, this helps in keeping the window size as the same i.e. r-l+1 ; If this window becomes valid anytime, then we update the max_len. Because we always want a longer window
        {
            hash[s[l] - 'A']--;
            max_freq = 0;
            for (int i = 0; i < 26; i++)
                max_freq = max(max_freq, hash[i]);
            l++;
            changes_required = (r - l + 1) - max_freq;
        }
        if (changes_required <= k)
        {
            max_len = max(max_len, r - l + 1);
        }
        r++;
    }
    return max_len;
}
int main()
{
    string str = "AABABBA";
    cout << brute(str, 2) << endl;
    cout << better(str, 2) << endl;
    cout << best(str, 2) << endl;
}