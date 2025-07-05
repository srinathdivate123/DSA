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
void delete_head(node *&head);

void insertAtTail(node *&head, int val) // Here we take head by reference and not by value because we're going to modify our LL here.
{
    node *n = new node(val);
    if (head == nullptr) // This is true if not even one node is there in our LL.
    {
        head = n;
        return;
    }
    // Below is to traverse the LL till the last node!
    node *temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = n;
}

void insertAtHead(node *&head, int val) // Here we take head by reference and not by value because we're going to modify our LL here.
{
    node *n = new node(val);
    n->next = head;
    head = n;
}

void insertByIndex(node *&head)
{
    int i, loc, val;
    node *temp = head;
    cout << "Enter element value - ";
    cin >> val;
    node *ptr = new node(val);
    cout << "Enter the location index at which you want to insert - ";
    cin >> loc;
    for (i = 0; i < loc; i++)
    {
        temp = temp->next;
        if (temp == nullptr)
        {
            cout << "\nCan't insert at location " << loc << " because reached the end!!\n";
            return;
        }
    }
    ptr->next = temp->next;
    temp->next = ptr;
    printf("\nNode inserted");
}

void display(node *head) // Here we take head by value and not by reference because we're not going to modify our LL here.
{
    cout << "\nDisplaying Linked List\n\n";
    node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

void deleteByValue(node *&head, int val)
{
    if (head == nullptr) // If there is no data (not even the head node) in the LL
    {
        cout << "\nDeletion not possible because the list is empty!";
        return;
    }
    if (head->next == nullptr) // If there is only one node in the LL
    {
        delete_head(head);
        return;
    }
    node *temp = head;
    while (temp->next->data != val)
        temp = temp->next;
    node *todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

void delete_head(node *&head) // This is to delete the head. Note that this is different from the case where there is only one node in the entire LL.
// This is only for when you want to delete head node when the LL has other further nodes as well.
{
    node *todelete = head;
    head = head->next;
    delete todelete;
}

void deleteAtLast(node *&head)
{
    int returnVal;
    node *temp = head;
    if (head == nullptr)
    {
        cout << "\nDeletion not possible because the list is empty!";
    }
    else if (head->next == nullptr)
    {
        returnVal = temp->data;
        delete_head(head);
        cout << "\nThe only one node of the list " << returnVal << " was deleted!";
    }
    else
    {
        while (temp->next->next != nullptr)
            temp = temp->next;
        returnVal = temp->next->data;
        node *todelete = temp->next->next;
        temp->next = nullptr;
        delete todelete;
        cout << "\nThe last node of the list, \'" << returnVal << "\' was deleted!";
    }
}

void deleteByIndex(node *&head)
{
    node *ptr, *ptr1;
    int loc, i;
    printf("Enter the location of the node after which you want to perform deletion - ");
    scanf("%d", &loc);
    ptr = head;
    for (i = 0; i <= loc; i++)
    {
        ptr1 = ptr;
        ptr = ptr->next;

        if (ptr == nullptr)
        {
            printf("\nCan't delete because reached the end of index!");
            return;
        }
    }
    ptr1->next = ptr->next;
    delete ptr;
    printf("\nDeleted node is at  %d ", loc + 1);
}
void search(node *&head)
{
    node *ptr = head;
    int item, i = 0;
    bool flag = true;
    if (ptr == nullptr)
    {
        printf("\nThe list is empty. Searching not possible!!\n");
    }
    else
    {
        printf("Enter item which you want to search - ");
        scanf("%d", &item);
        while (ptr != nullptr)
        {
            if (ptr->data == item)
            {
                flag = true;
                printf("\nItem found at index %d ", i);
                break;
            }
            else
                flag = false;
            i++;
            ptr = ptr->next;
        }
        if (flag == false)
        {
            printf("\nItem not found\n");
        }
    }
}

int main()
{
    node *head = nullptr;
    int choice = 0;
    int value;
    do
    {
        cout << "\n\n-- INSERT OPERATIONS -- \n\n1. Insert at head\n2. Insert at tail\n3. Insert at a particular index\n\n-- DELETE OPERATIONS --\n\n4. Delete head node\n5. Delete node by its value\n6. Delete from tail\n7. Delete node after specified location\n\n-- OTHER OPERATIONS --\n\n8. Search for an node\n9. Display entire Linked List\n10. Exit\n";
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
            insertByIndex(head);
            break;
        case 4:
            delete_head(head);
            cout << "\nThe head node has been deleted successfully!";
            break;
        case 5:
            cout << "Enter the value of the element which you want to delete - ";
            cin >> value;
            deleteByValue(head, value);
            cout << "\nElement " << value << " has been deleted successfully!";
            break;
        case 6:
            deleteAtLast(head);
            break;
        case 7:
            deleteByIndex(head);
            break;
        case 8:
            search(head);
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