/* We are given an array of strings (sat words[]), and we need to return the longest string chain. This longest string chain is defined as:

- A subsequence of words[] of the string.
- Every element of this subsequence (a string) except the first one can be formed by inserting a single character into the previous element.
- The first element of this subsequence can be any string from the words[] array.
*/

#include <bits/stdc++.h>
using namespace std;

// TC = len of max length string
bool compare(string &s1, string &s2)
{
    if (s1.size() != s2.size() + 1)
        return false;

    int first = 0, second = 0;

    while (first < s1.size())
        if (second < s2.size() && s1[first] == s2[second])
        {
            first++;
            second++;
        }
        else
            first++;
    if (first == s1.size() && second == s2.size()) // Both pointers have reached end
        return true;
    return false;
}

bool comp(string &s1, string &s2)
{
    return s1.size() < s2.size();
}

// TC = n*n*len of max length string for compare func + n*log(n) for sorting
// SC = n
int longestStrChain(vector<string> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end(), comp);
    vector<int> dp(n, 1);
    int maxi = 1;

    for (int i = 0; i <= n - 1; i++)
    {
        for (int prev_index = 0; prev_index <= i - 1; prev_index++)
            if (compare(arr[i], arr[prev_index]) && 1 + dp[prev_index] > dp[i])
                dp[i] = 1 + dp[prev_index];

        if (dp[i] > maxi)
            maxi = dp[i];
    }
    return maxi;
}

int main()
{
    vector<string> words = {"a", "b", "ba", "bca", "bda", "bdca"};
    cout << longestStrChain(words);
}