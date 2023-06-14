#include <bits/stdc++.h>
using namespace std;
#define n 20

class Queue
{
    int *arr;
    int front;
    int back;

public:
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
    Queue q1, q2;

public:
    void push(int x)
    {
        if (q1.isFull() || q2.isFull())
        {
            cout << "\nEither of the queues have overflowed!\n";
            return;
        }

        // Push x first in empty q2
        q2.enqueue(x);


        // Push all the remaining elements, one by one, from q1 to q2.
        while (!q1.isEmpty())
        {
            q2.enqueue(q1.peek());
            q1.dequeue();
        }


        // swap the two queues
       swap(q1,q2);
    }
    void pop()
    {
        // if no elements are there in q1
        if (q1.isEmpty())
        {
            cout << "\nQ1 empty! Can't pop!\n";
            return;
        }
        q1.dequeue();
    }

    int Top()
    {
        if (q1.isEmpty())
        {
            cout << "\nQ1 EMPTY\n";
            return -1;
        }
        return q1.peek();
    }
    bool isEmpty()
    {
        return q1.isEmpty();
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