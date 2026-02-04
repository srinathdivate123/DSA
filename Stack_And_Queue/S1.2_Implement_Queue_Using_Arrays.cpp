// https://takeuforward.org/data-structure/implement-queue-using-array

#include <bits/stdc++.h>
using namespace std;

class ArrayQueue
{
    int *arr;
    int start, end;
    int currSize, maxSize;

public:
    ArrayQueue()
    {
        arr = new int[10];
        start = -1;
        end = -1;
        currSize = 0;
        maxSize = 10;
    }

    void push(int x)
    {
        if (currSize == maxSize)
        {
            cout << "Queue is full" << endl;
            exit(1);
        }

        // If the queue is empty, initialize start and end
        if (end == -1)
        {
            start = 0;
            end = 0;
        }
        else
        {
            // Circular increment of end
            // If it so happens that by pop-pop, the start has been moved to the mid of the array and the end is at the end
            // Then there is still some memory in the beginning of the array to store the queue elements
            // So you do (end+1) % maxSize so that the end comes to the beginning of the array (start remains in the mid only)
            end = (end + 1) % maxSize;
        }

        arr[end] = x;
        currSize++;
    }

    int pop()
    {
        if (start == -1 || currSize == 0)
        {
            cout << "Queue Empty" << endl;
            exit(1);
        }
        int popped = arr[start];

        // If the queue has only one element, reset start and end
        if (currSize == 1)
        {
            start = -1;
            end = -1;
        }
        else
        {
            // Circular increment of start
            // Reason is the same as the one for 'push' above
            start = (start + 1) % maxSize;
        }

        currSize--;
        return popped;
    }

    // Method to get the front element of the queue
    int top()
    {
        if (start == -1)
        {
            cout << "Queue is Empty" << endl;
            exit(1);
        }
        return arr[start];
    }

    int size()
    {
        return currSize;
    }

    bool isEmpty()
    {
        return (currSize == 0);
    }
};

int main()
{
    ArrayQueue queue;
    vector<string> commands = {"ArrayQueue", "push", "push",
                               "top", "pop", "isEmpty"};
    vector<vector<int>> inputs = {{}, {5}, {10}, {}, {}, {}};

    for (int i = 0; i < commands.size(); ++i)
    {
        if (commands[i] == "push")
        {
            queue.push(inputs[i][0]);
            cout << "null ";
        }
        else if (commands[i] == "pop")
        {
            cout << queue.pop() << " ";
        }
        else if (commands[i] == "top")
        {
            cout << queue.top() << " ";
        }
        else if (commands[i] == "isEmpty")
        {
            cout << (queue.isEmpty() ? "true" : "false") << " ";
        }
        else if (commands[i] == "ArrayQueue")
        {
            cout << "null ";
        }
    }

    return 0;
}