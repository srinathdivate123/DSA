// https://takeuforward.org/data-structure/implement-queue-using-linked-list

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node(int d)
    {
        val = d;
        next = NULL;
    }
};

class LinkedListQueue
{
private:
    Node *start; // Start of the queue
    Node *end;   // End of the queue
    int size;    // Size of the queue

public:
    LinkedListQueue()
    {
        start = end = NULL;
        size = 0;
    }

    void push(int x)
    {
        Node *element = new Node(x);

        if (start == NULL)
        {
            start = end = element;
        }
        else
        {
            end->next = element;
            end = element;
        }
        size++;
    }

    int pop()
    {
        if (start == NULL)
        {
            return -1;
        }

        int value = start->val;
        Node *temp = start;
        start = start->next;
        // If while poppiing, you popped out all the elements then move end to NULL
        if (start == NULL)
        {
            end = NULL;
        }
        delete temp;
        size--;
        return value;
    }

    int top()
    {
        if (start == NULL)
        {
            return -1;
        }
        return start->val;
    }

    bool isEmpty()
    {
        return (size == 0);
    }
};

int main()
{
    LinkedListQueue q;
    vector<string> commands = {"LinkedListQueue", "push", "push", "top", "pop", "isEmpty"};
    vector<vector<int>> inputs = {{}, {3}, {7}, {}, {}, {}};

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
        else if (commands[i] == "LinkedListQueue")
        {
            cout << "null ";
        }
    }
    return 0;
}