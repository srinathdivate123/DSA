// https://takeuforward.org/data-structure/implement-queue-using-stack
// https://leetcode.com/problems/implement-queue-using-stacks/description/
// Note that you will need two Stacks here
// Here,
// push --> O(2N)
// pop ---> O(1)
// top ---> O(1)
// Here we optimized the push at the expense of the pop & top
// If you have a lot of push and few pop & top, then you can use below approach

#include <bits/stdc++.h>
using namespace std;

class StackQueue
{
public:
    stack<int> st1, st2;

    StackQueue() {}

    void push(int x)
    {
        st1.push(x);
    }

    int pop()
    {
        // If st2 is empty, push everything from st1 to st2
        if (st2.empty())
        {
            while (!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }

        // If st2 is still empty (meaning, nothing from st1 was pushed to st2), return -1
        if (st2.empty())
        {
            cout << "Queue is empty, cannot pop." << endl;
            return -1;
        }

        int x = st2.top();
        st2.pop();
        return x;
    }

    int top()
    {
        // If st2 is empty, push everything from st1 to st2
        if (st2.empty())
        {
            while (!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }

        // If st2 is still empty (meaning, nothing from st1 was pushed to st2), return -1
        if (st2.empty())
        {
            cout << "Queue is empty, cannot top." << endl;
            return -1;
        }

        return st2.top();
    }

    bool isEmpty()
    {
        return st1.empty() && st2.empty();
    }
};

int main()
{
    StackQueue q;
    q.push(3);
    q.push(4);
    cout << "The element popped is " << q.pop() << endl;
    q.push(5);
    cout << "The front of the queue is " << q.top() << endl;
    cout << "Is the queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;
    cout << "The element popped is " << q.pop() << endl;
    cout << "The element popped is " << q.pop() << endl;
    cout << "Is the queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
