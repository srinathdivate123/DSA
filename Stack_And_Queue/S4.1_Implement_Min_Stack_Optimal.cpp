// https://takeuforward.org/data-structure/implement-min-stack-o2n-and-on-space-complexity
// https://leetcode.com/problems/min-stack/description/

// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// Implement the MinStack class:

// MinStack() initializes the stack object.
// void push(int val) pushes the element val onto the stack.
// void pop() removes the element on the top of the stack.
// int top() gets the top element of the stack.
// int getMin() retrieves the minimum element in the stack.
// You must implement a solution with O(1) time complexity for each function.

// NOTE that you cannot invent or discover this method out of nowhere, so you must by-heart it.

// -----------------------------------------------------------------------------------

// To see the derivation of the modified value below, refer: https://youtu.be/NdDIaH91P0g?t=805

#include <bits/stdc++.h>
using namespace std;

class MinStack
{
private:
    stack<int> st;
    int mini;

public:
    MinStack()
    {
    }

    void push(int value)
    {
        if (st.empty())
        {
            mini = value; // Because this is the first value you're inserting
            st.push(value);
            return;
        }

        // If the value is greater than the minimum
        if (value > mini)
        {
            st.push(value);
        }
        else
        {
            // If it is a new minimum, add the modified value to stack
            // To see the derivation of the modified value, refer: https://youtu.be/NdDIaH91P0g?t=805
            int modified_value = 2 * value - mini;
            st.push(modified_value);
            // Update the minimum with 'value' (and NOT modified_value)
            mini = value;
        }
    }

    void pop()
    {
        if (st.empty())
            return;

        int x = st.top();
        st.pop();

        // If the value that is being taken out is lesser than the minimum
        // Then it means the value was a modified value added into the stack
        // So now you need to update the minimum
        if (x < mini)
        {
            mini = 2 * mini - x;
        }
    }

    int top()
    {
        if (st.empty())
            return -1;

        int x = st.top();

        // Return top if it is greater than the minimum
        if (x > mini)
            return x;

        // Otherwise return mini
        return mini;
    }

    int getMin()
    {
        return mini;
    }
};

int main()
{
    MinStack s;
    s.push(-2);
    s.push(0);
    s.push(-3);
    cout << s.getMin() << " ";
    s.pop();
    cout << s.top() << " ";
    s.pop();
    cout << s.getMin();
    return 0;
}