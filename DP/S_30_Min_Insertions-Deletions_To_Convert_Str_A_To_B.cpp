/* We are given two strings, str1 and str2. We are allowed the following operations:

- Delete any number of characters from string str1.
- Insert any number of characters in string str1.
We need to tell the minimum operations required to convert str1 to str2. */

// Worst case is when you delete all characters in s1 and insert into it all the characters of s2. This will take n + m.

#include <bits/stdc++.h>
using namespace std;

// TC = n*m, SC = m
// Watch video for more clarity. https://youtu.be/yMnH0jrir0Q
int lcs(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<int> prev(m + 1, 0), cur(m + 1, 0);

    // Base Case is covered as we have initialized the prev and cur to 0.

    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                cur[ind2] = 1 + prev[ind2 - 1];
            else
                cur[ind2] = max(prev[ind2], cur[ind2 - 1]);
        }
        prev = cur;
    }

    // The value at prev[m] contains the length of the LCS
    return prev[m];
}

// Function to calculate the minimum operations required to convert str1 to str2
int canYouMake(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();
    int k = lcs(str1, str2);

    // Calculate the minimum operations required to convert str1 to str2
    return (n - k) + (m - k);
}

int main()
{
    string str1 = "abcd";
    string str2 = "anc";
    cout << canYouMake(str1, str2);
    return 0;
}
