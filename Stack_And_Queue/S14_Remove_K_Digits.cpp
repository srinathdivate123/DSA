// https://takeuforward.org/data-structure/remove-k-digits
// https://leetcode.com/problems/remove-k-digits/description/

// Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

// Use a stack to store digits of the resulting number
// Iterate through each digit of the input string
// While the stack is not empty, the "current digit is smaller than the top of the stack", and k is greater than 0, pop from the stack and decrement k
// Push the current digit onto the stack
// If k is still greater than 0 after the iteration, remove digits from the end of the stack
// Collect the remaining digits from the stack to form the result
// Remove any leading zeroes from the result
// If the result is empty after removing zeroes, return "0"

// -----------------------------------------------------------------------------------------------------------

// Edge Cases:
// --> If k is equal to the length of the input string, return "0" as all digits will anyways be removed
// --> If the result contains leading zeroes, remove them before returning
// --> If no digits were removed during iteration (because successive digits were in increasing order) and k is still greater than 0, remove the last k digits from the stack

// Time Complexity: O(N), since traversing the given string takes O(N) time, each element is pushed onto and popped from the stack at most once in worst-case taking o(N) time, removing the remaining digits (if k > 0) takes O(k) time which can go upto O(N) in worst-case and forming the result, trimming the zeros and reversing the digits takes O(N) time.

// Space Complexity: O(N), since we are using a stack to store the digits of the resulting number, in the worst case, the stack can contain all the digits of the input string.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeKdigits(string nums, int k)
    {
        stack<char> st;
        for (int i = 0; i < nums.size(); i++)
        {
            char digit = nums[i];

            // Pop last digits from stack if a smaller digit is found on string
            while (!st.empty() && k > 0 && st.top() > digit)
            {
                st.pop(); // Pop the last digit
                k--;      // Decrement K by 1
            }
            st.push(digit);
        }

        // If we have not yet removed k digits
        while (!st.empty() && k > 0)
        {
            st.pop(); // Pop the last added digits
            k--;      // Decrement K by 1
        }

        // Handling edge case
        if (st.empty())
            return "0";

        string res = "";

        // Adding digits in stack to result
        while (!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }

        // Trimming the zeroes at the back
        while (res.size() > 0 && res.back() == '0')
        {
            res.pop_back();
        }

        // Reverse to get the actual number
        reverse(res.begin(), res.end());

        // Edge case
        if (res.empty())
            return "0";

        return res;
    }
};

int main()
{
    string nums = "541892";
    int k = 2;
    Solution sol;
    cout << sol.removeKdigits(nums, k);
    return 0;
}