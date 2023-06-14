/// Here the Push takes o(N) and TOP and POP take o(1)
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
    Stack s1, s2;

public:
    void enqueue(int x)
    {
        if (s1.top == n - 1 || s2.top == n - 1)
        {
            cout << "Queue Overflow!!\n";
            return;
        }

        while (!s1.isEmpty())
        {
            s2.push(s1.Top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.isEmpty())
        {
            s1.push(s2.Top());
            s2.pop();
        }
    }

    void dequeue()
    {
        if (s1.isEmpty())
        {
            cout << "No elements in Queue\n";
            return;
        }
        s1.pop();
    }
    int peek()
    {
        if (s1.isEmpty())
        {
            cout << "No elements in Queue\n";
            return -1;
        }
        return s1.Top();
    }

    bool isEmpty()
    {
        if (s1.isEmpty())
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