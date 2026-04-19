// https://takeuforward.org/data-structure/merge-two-sorted-arrays-without-extra-space
// https://leetcode.com/problems/merge-sorted-array/description/

// Given two sorted integer arrays nums1 and nums2, merge both the arrays into a single array which is also sorted.
// The final sorted array should be stored in nums1 and it should be done in-place.
// Array nums1 has a length of m + n, where the first m elements denote the elements of nums1 and rest are 0s whereas nums2 has a length of n.

// NOTE: Both LC & TUF blog have this variation in the question where the nums1 has size m+n
// TUF video has the next question
// In the NEXT question you'll see that nums1 has size m and nums2 has size n (no extra space present)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (i >= 0 && j >= 0)
        {
            if (nums1[i] > nums2[j])
            {
                nums1[k--] = nums1[i--];
            }
            else
            {
                nums1[k--] = nums2[j--];
            }
        }

        while (j >= 0)
        {
            nums1[k--] = nums2[j--];
        }
        // No need to copy remaining nums1 elements, as they are already in place
    }
};

int main()
{
    vector<int> nums1 = {1, 3, 5, 0, 0, 0};
    vector<int> nums2 = {2, 4, 6};
    int m = 3, n = 3;

    Solution().merge(nums1, m, nums2, n);
    for (int num : nums1)
        cout << num << " ";
    return 0;
}
