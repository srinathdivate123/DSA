// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
// https://takeuforward.org/data-structure/number-of-substring-containing-all-three-characters

// Given a string s consisting only of characters a, b and c.

// Return the number of substrings containing at least one occurrence of all these characters a, b and c.

#include <bits/stdc++.h>
using namespace std;

// TC = O(N*N), SC = O(1)
// Find all substrings
int brute(string &str)
{
    int cnt = 0;
    for (int i = 0; i < str.size(); i++)
    {
        vector<int> hash = {0, 0, 0};
        for (int j = i; j < str.size(); j++)
        {
            hash[str[j] - 'a'] = 1;
            if (hash[0] + hash[1] + hash[2] == 3)
            {
                // If you have reached until a certain point in string, and you know that it is one of your answers. So the substrings formed after adding the remaining chars in the str will also be your answer. So you do the: + (str.size() - j)
                cnt = cnt + (str.size() - j);
                break;
            }
        }
    }
    return cnt;
}


// With every character, there is a substring hat starts.
// But also, with every character, there is a substring that ends. So we are generating all the substrings smartly in this problem
// Refer video for complete explanation as it is very long: https://youtu.be/xtqN4qlgr8s?t=400
// TC = O(N), SC = O(1)
int best(string str)
{
    int cnt = 0;
    vector<int> lastSeen = {-1, -1, -1};
    for(int i = 0; i<str.size(); i++)
    {
        lastSeen[str[i] - 'a'] = i;
        // You can actually omit the below check. If all three chars have not be seen, then one of them will have -1. The min condition will result in -1 and the +1 -1 will result in zero. So cnt will remain 0
        if(lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1)
        {
            cnt += 1 + min(lastSeen[0], min(lastSeen[1], lastSeen[2]));
        }
    }
    return cnt;
}


int main()
{
    string str = "bbacba";
    cout << brute(str) << endl;
    cout << best(str) << endl;
    return 0;
}