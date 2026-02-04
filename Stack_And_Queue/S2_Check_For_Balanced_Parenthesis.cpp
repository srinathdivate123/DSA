// https://takeuforward.org/data-structure/check-for-balanced-parentheses
// https://leetcode.com/problems/valid-parentheses/description/

// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st; // Stack to store ONLY opening brackets

        for (auto it : s)
        {
            if (it == '(' || it == '{' || it == '[')
                st.push(it); // Push opening brackets to stack
            else
            {
                // You've found a closing bracket but you need to check if there is any opening bracket at all in the stack
                // If it is empty then there is no opening bracket at all in the stack
                if (st.empty())
                    return false;
                char ch = st.top();
                st.pop();

                // Check for matching pair
                if ((it == ')' && ch == '(') ||
                    (it == ']' && ch == '[') ||
                    (it == '}' && ch == '{'))
                    continue;
                else
                    return false;
            }
        }
        return st.empty(); // True if all brackets matched
    }
};

int main()
{
    Solution sol;
    string s = "()[{}()]";

    if (sol.isValid(s))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}
