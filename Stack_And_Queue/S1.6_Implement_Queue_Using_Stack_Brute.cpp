// https://takeuforward.org/data-structure/implement-queue-using-stack
// https://leetcode.com/problems/implement-queue-using-stacks/description/
// Note that you will need two Stacks here
// Here,
// push --> O(2N)
// pop ---> O(1)
// top ---> O(1)
// Here, we optimized the pop & top at the expense of the push
// If you have few push and lot of pop & top, then you can use the below approach

#include <bits/stdc++.h>
using namespace std;

class StackQueue
{
private:
    // st1 is our actual queue
    // st2 is just used as a temp buffer stack
    stack<int> st1, st2;

public:
    StackQueue()
    {
    }

    // push takes O(2N)
    void push(int x)
    {
        // Pop elements from st1 and push to st2
        while (!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }

        // Insert x in st1
        st1.push(x);

        // Pop elements from st2 and push to st1
        while (!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
    }

    int pop()
    {
        // Edge case
        if (st1.empty())
        {
            cout << "Stack is empty";
            return -1;
        }

        int topElement = st1.top();
        st1.pop();

        return topElement;
    }

    int top()
    {
        if (st1.empty())
        {
            cout << "Stack is empty";
            return -1;
        }
        return st1.top();
    }

    bool isEmpty()
    {
        return st1.empty();
    }
};

int main()
{
    StackQueue q;

    // List of commands
    vector<string> commands = {"StackQueue", "push", "push",
                               "pop", "top", "isEmpty"};
    // List of inputs
    vector<vector<int>> inputs = {{}, {4}, {8}, {}, {}, {}};

    for (int i = 0; i < commands.size(); ++i)
    {
        if (commands[i] == "push")
        {
            q.push(inputs[i][0]);
            cout << "null ";
        }
        else if (commands[i] == "pop")
        {
            cout << q.pop() << " ";
        }
        else if (commands[i] == "top")
        {
            cout << q.top() << " ";
        }
        else if (commands[i] == "isEmpty")
        {
            cout << (q.isEmpty() ? "true" : "false") << " ";
        }
        else if (commands[i] == "StackQueue")
        {
            cout << "null ";
        }
    }

    return 0;
}