// https://takeuforward.org/data-structure/implement-stack-using-single-queue
// https://leetcode.com/problems/implement-stack-using-queues/
// Note that you only use one Queue here!

#include <bits/stdc++.h>
using namespace std;

class QueueStack
{
    queue<int> q;

public:
    void push(int x)
    {
        int s = q.size();
        q.push(x);

        // Move elements before new element to back
        // Kind of reverse the queue
        // Run to <s instead of <=s so that you do not move the newly inserted element to the last as well
        for (int i = 0; i < s; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        int n = q.front();
        q.pop();
        return n;
    }

    int top()
    {
        return q.front();
    }

    int size()
    {
        return q.size();
    }

    bool isEmpty()
    {
        return q.empty();
    }
};

int main()
{
    QueueStack st;
    vector<string> commands = {"QueueStack", "push", "push", "pop", "top", "isEmpty"};
    vector<vector<int>> inputs = {{}, {4}, {8}, {}, {}, {}};

    for (int i = 0; i < commands.size(); ++i)
    {
        if (commands[i] == "push")
        {
            st.push(inputs[i][0]);
            cout << "null ";
        }
        else if (commands[i] == "pop")
        {
            cout << st.pop() << " ";
        }
        else if (commands[i] == "top")
        {
            cout << st.top() << " ";
        }
        else if (commands[i] == "isEmpty")
        {
            cout << (st.isEmpty() ? "true" : "false") << " ";
        }
        else if (commands[i] == "QueueStack")
        {
            cout << "null ";
        }
    }
    return 0;
}