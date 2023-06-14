#include <bits/stdc++.h>
using namespace std;
#define n 20

class Queue
{
public:
    int *arr;
    int front;
    int back;
    Queue()
    {
        arr = new int[n];
        front = -1;
        back = -1;
    }

    void enqueue(int x)
    {
        if (back == n - 1)
        {
            cout << "Queue Overflow!!\n";
            return;
        }
        back++;
        arr[back] = x;
        if (front == -1) // Suppose the element we're adding is the first element.
            front++;
    }

    void dequeue()
    {
        if (front == -1 || front > back)
        {
            cout << "No elements in Queue\n";
            return;
        }
        front++;
    }
    int peek()
    {
        if (front == -1 || front > back)
        {
            cout << "No elements in Queue\n";
            return -1;
        }
        return arr[front];
    }

    bool isEmpty()
    {
        if (front == -1 || front > back)
            return true;
        return false;
    }
    bool isFull()
    {
        if (back == n - 1)
            return true;
        return false;
    }
};

class Stack
{

public:
    Queue q;
    void push(int x)
    {
        if (q.isFull())
        {
            cout << "\nQueue has overflowed!\n";
            return;
        }
        q.enqueue(x);
        for (int k = 0; k < (q.back - q.front); k++)
        {
            q.enqueue(q.peek());
            q.dequeue();
        }
    }
    void pop()
    {
        // if no elements are there in q1
        if (q.isEmpty())
        {
            cout << "\nQ1 empty! Can't pop!\n";
            return;
        }
        q.dequeue();
    }

    int Top()
    {
        if (q.isEmpty())
        {
            cout << "\nQ1 EMPTY\n";
            return -1;
        }
        return q.peek();
    }
    bool isEmpty()
    {
        return q.isEmpty();
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout << "Top element: " << s.Top() << endl;
    s.pop();
    cout << "Top element: " << s.Top() << endl;
    s.pop();
    cout << "Top element: " << s.Top() << endl;
    s.pop();
    cout << "s.isEmpty: " << s.isEmpty() << endl;
    s.pop();
    s.pop();
    cout << "s.isEmpty: " << s.isEmpty() << endl;

    return 0;
}