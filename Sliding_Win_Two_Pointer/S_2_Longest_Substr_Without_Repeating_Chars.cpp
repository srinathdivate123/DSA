// Given a string s, find the length of the longest substring  without repeating characters.

#include <bits/stdc++.h>
using namespace std;

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
int optimized_2(string str)
{
    if (str.size() == 0)
        return 0;

    int left = 0, right = 0, maxi = INT_MIN;
    vector<int> mpp(255, -1);
    while (right < str.size())
    {
        if (mpp[str[right]] != -1)
            left = max(mpp[str[right]] + 1, left);

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
    cout << optimized_2(str) << endl;
}