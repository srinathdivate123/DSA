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

// Below stack takes O(2N) space and constant time for all ops
#include <bits/stdc++.h>
using namespace std;

class MinStack
{
private:
    stack<pair<int, int>> st;
    // <Actual value to be inserted, minimum of all values we've seen till now>

public:
    MinStack()
    {
    }

    void push(int value)
    {
        if (st.empty())
        {
            st.push({value, value});
            return;
        }

        int mini = min(getMin(), value);
        st.push({value, mini});
    }

    void pop()
    {
        st.pop();
    }

    int top()
    {
        return st.top().first;
    }

    int getMin()
    {
        return st.top().second;
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