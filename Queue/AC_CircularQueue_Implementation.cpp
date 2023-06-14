#include <bits/stdc++.h>
using namespace std;
class Queue
{
    int rear, front;
    int size;
    int *arr;

public:
    Queue(int s)
    {
        front = rear = -1;
        size = s;
        arr = new int[s];
    }

    void enQueue(int value);
    int deQueue();
    void displayQueue();
};

void Queue::enQueue(int value)
{
    if ((front == 0 && rear == size - 1) ||
        (rear == (front - 1) % (size - 1)))
    {
        printf("\nQueue is Full");
        return;
    }

    else if (front == -1) /* Insert First Element */
    {
        front = rear = 0;
        arr[rear] = value;
    }

    else if (rear == size - 1 && front != 0)
    {
        rear = 0;
        arr[rear] = value;
    }

    else
    {
        rear++;
        arr[rear] = value;
    }
}

int Queue::deQueue()
{
    if (front == -1)
    {
        printf("\nQueue is Empty");
        return INT_MIN;
    }
    int data = arr[front];
    arr[front] = -1;
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == size - 1)
        front = 0;
    else
        front++;
    return data;
}

void Queue::displayQueue()
{
    if (front == -1)
    {
        printf("\n Queue is Empty");
        return;
    }
    printf("\n Elements in Circular Queue are: \n");
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            printf("%d ", arr[i]);
    }
    else
    {
        for (int i = front; i < size; i++)
            printf("%d ", arr[i]);

        for (int i = 0; i <= rear; i++)
            printf("%d ", arr[i]);
    }
    printf("\n");
}

/* Driver of the program */
int main()
{
    Queue q(5);
    int choice, insert, del, a;
    do
    {
        printf("\n Press 1: Insert an element");
        printf("\n Press 2: Delete an element");
        printf("\n Press 3: Display the elements");
        printf("\n Entering any other number would terminate the program!");
        printf("\n Enter your choice - ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            printf("\n Enter element to insert - ");
            scanf("%d", &insert);
            q.enQueue(insert);
        }

        break;
        case 2:
        {
            a = q.deQueue();
            printf("\n %d was removed successfully!\n", a);
        }
        break;
        case 3:
        {
            q.displayQueue();
        }
        break;

        default:
            break;
        }

    } while (choice == 1 || choice == 2 || choice == 3);
    return 0;
}
