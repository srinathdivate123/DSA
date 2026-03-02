#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Using Brian Kerninghan's Algorithm to find the hamming weight of a number
    static int findWeight(int num)
    {
        int weight = 0;

        while (num > 0)
        {
            weight++;
            // The below sets ONLY the LSB, where ever it is, to 0
            // https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/editorial
            num &= (num - 1);
        }

        return weight;
    }

    static bool compare(int a, int b)
    {
        if (findWeight(a) == findWeight(b))
        {
            return a < b;
        }

        return findWeight(a) < findWeight(b);
    }

    vector<int> sortByBits(vector<int> &arr)
    {
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};