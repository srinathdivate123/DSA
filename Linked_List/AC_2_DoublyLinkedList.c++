// In this program, the head has position 0. i.e. indexing starts from 0.
#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};
void deleteAtHead(node *&head);

void insertAtTail(node *&head, int val)
{
    if (head == NULL)
    {
        node *n = new node(val);
        n->next = head;
        if (head != NULL)
            head->prev = n;
        head = n;
        return;
    }
    node *n = new node(val);
    node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = n;
    n->prev = temp;
}

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    if (head != NULL)
        head->prev = n;
    head = n;
}

void display(node *head)
{
    cout << "Displaying all the elements -\n\n";
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

void deleteByIndex(node *&head, int position)
{
    if (position == 0)
    {
        deleteAtHead(head);
        return;
    }
    node *temp = head;
    int count=0;
    while (temp != NULL && count != position)
    {
        temp = temp->next;
        count++;
    }
    temp->prev->next = temp->next;
    if (temp->next != NULL) // Suppose if we're deleting the last node, then we wouldn't be able to access its next node as its next node doesn't exist.
        temp->next->prev = temp->prev;
    delete temp;
}

void deleteAtHead(node *&head)
{
    node *todelete = head;
    head = head->next;
    head->prev = NULL;
    delete todelete;
}

int main()
{
    node *head = NULL;
    int choice = 0;
    int value;
    do
    {
        cout << "\n\n-- INSERT OPERATIONS -- \n\n1. Insert at head\n2. Insert at tail\n3. Insert at a particular index\n\n-- DELETE OPERATIONS --\n\n4. Delete head node\n5. Delete node by its value\n6. Delete from tail\n7. Delete node at specified index\n\n-- OTHER OPERATIONS --\n\n8. Search for an node\n9. Display entire Linked List\n10. Exit\n";
        cout << "\nEnter your choice - ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the value to insert at beginning - ";
            cin >> value;
            insertAtHead(head, value);
            cout << "Value " << value << " has been inserted successfully!";
            break;
        case 2:
            cout << "Enter the value to insert at tail - ";
            cin >> value;
            insertAtTail(head, value);
            cout << "Value " << value << " has been inserted successfully!";
            break;
        case 3:
            // insertByIndex(head);
            break;
        case 4:
            deleteAtHead(head);
            cout << "\nThe head node has been deleted successfully!";
            break;
        case 5:
            // cout << "Enter the value of the element which you want to delete - ";
            cin >> value;
            // deleteByValue(head, value);
            cout << "\nElement " << value << " has been deleted successfully!";
            break;
        case 6:
            // deleteAtLast(head);
            break;
        case 7:
            cout << "Enter the index of the element that you want to delete - ";
            cin >> value;
            deleteByIndex(head, value);
            cout << "Element at index " << value << " was deleted successfully!";
            break;
        case 8:
            // search(head);
            break;
        case 9:
            display(head);
            break;
        case 10:
            exit(0);
            break;
        default:

            cout << "Please enter a valid choice..";
        }
    } while (choice < 10);
    cout << "\nProgram terminated successfully!";
    return 0;
}