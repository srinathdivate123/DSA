#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i]==key)
        return i;
        
    }
return -1;
}

int main()
{
    int n, key;
    cout << "Enter array size - ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter key - ";
    cin >> key;
    cout<<"Element found at index "<<linearSearch(arr,n,key);
    return 0;
}