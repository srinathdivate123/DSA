#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class queue
{
    node *front;
    node *back;

public:
    queue()
    {
        front = nullptr;
        back = nullptr;
    }

    void push(int x)
    {
        node *n = new node(x);
        if (front == nullptr) // For empty queue
        {
            back = n;
            front = n;
            return;
        }
        back->next = n;
        back = n;
    }

    void pop()
    {
        if (front == nullptr)
        {
            cout << "Queue Underflow";
            return;
        }
        node *todelete = front;
        front = front->next;
        delete todelete;
    }

    int peek()
    {
        if (front == nullptr)
        {
            cout << "No element in queue";
            return -1;
        }
        return front->data;
    }

    bool empty()
    {
        if (front == nullptr)
            return true;
        return false;
    }
};

int main()
{
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;
    q.pop();
    cout << "Empty - " << q.empty() << endl;

    return 0;
}