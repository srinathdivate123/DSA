// https://youtu.be/b7AYbpM5YrE
// Given a string, find all the possible subsequences of the string.
// Generate all the possible substrings of the string
/*
5 in binary is 101. To check if the left-most bit is set or not we do
101
100
and then do a & and get 100
100 is a non zero number, hence we conclude that the first bit is set
*/
#include <bits/stdc++.h>
using namespace std;
void AllPossibleStrings(string s)
{
    int n = s.length();
    for (int num = 0; num < (1 << n); num++) // (1 << n) means 2^n
    {
        string sub = "";
        for (int i = 0; i < n; i++)
            // check if the ith bit is set or not
            if (num & (1 << i))
                sub += s[i];
        if (sub.length() > 0)
            cout << sub << " ";
        else
            cout << "{} ";
    }
}
int main()
{
    string s = "abc";
    AllPossibleStrings(s);
}