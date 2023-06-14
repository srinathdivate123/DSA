// Here the push takes o(1). Top and Pop take o(1) mostly but sometimes may take o(N)
#include <bits/stdc++.h>
using namespace std;

#define n 100

class Stack
{

public:
    int *arr;
    int top;
    Stack()
    {
        arr = new int[n];
        top = -1;
    }
    void push(int x)
    {
        if (top == n - 1)
        {
            cout << "STACK OVERFLOW";
            return;
        }
        top++;
        arr[top] = x;
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "\nSTACK EMPTY! Can't pop!\n";
            return;
        }
        top--;
    }
    int Top()
    {
        if (top == -1)
        {
            cout << "\nSTACK EMPTY\n";
            return -1;
        }
        return arr[top];
    }
    bool isEmpty()
    {
        return (top == -1);
    }
};

class Queue
{
    Stack input, output;

public:
    void enqueue(int x)
    {
        if (input.top == n - 1 || output.top == n - 1)
        {
            cout << "Queue Overflow!!\n";
            return;
        }
        input.push(x);
    }

    void dequeue()
    {
        if (!output.isEmpty())
        {
            output.pop();
            return;
        }
        else
        {
            while (!input.isEmpty())
            {
                output.push(input.Top());
                input.pop();
            }
            output.pop();
        }
    }
    int peek()
    {
        if (!output.isEmpty())
            return output.Top();

        else
        {
            while (!input.isEmpty())
            {
                output.push(input.Top());
                input.pop();
            }
            return output.Top();
        }
    }

    bool isEmpty()
    {
        if (output.isEmpty())
            return true;
        return false;
    }
};

int main()
{

    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    cout << q.peek() << endl;
    q.dequeue();
    cout << q.peek() << endl;
    q.dequeue();
    cout << q.peek() << endl;
    q.dequeue();
    cout << "Empty: " << q.isEmpty() << endl;
    cout << q.peek() << endl;
    q.dequeue();
    cout << "Empty: " << q.isEmpty() << endl;
    return 0;
}