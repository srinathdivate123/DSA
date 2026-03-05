// https://takeuforward.org/data-structure/check-if-an-array-is-sorted
// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated

#include <bits/stdc++.h>
using namespace std;
// As we know, a sorted array of n elements (which can contain duplicates) follows the property where the previous element is smaller or equal to the current element. So, if we rotate it by some point (Clockwise or Anticlockwise) , there exists a pivot where the previous element is greater or equal to the current element. If there is at most one occurrence of pivot then we can say array is rotated and sorted.

class Solution
{
public:
    bool check(vector<int> &arr)
    {
        int n = arr.size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > arr[(i + 1) % n])
            {
                count++;
            }
        }
        return count <= 1;
    }
};