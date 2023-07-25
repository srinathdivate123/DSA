// Given an array arr[] of positive integers, the task is to find whether it is possible to make this array strictly increasing by modifying atmost one element.
#include <iostream>
using namespace std;

bool check(int arr[], int n)
{
    int modify = 0; // To store the number of modifications

    // Check whether the first element needs
    // to be modify or not
    if (arr[0] > arr[1])
    {
        arr[0] = arr[1] / 2;
        modify++;
    }

    // Loop from 2nd element to the 2nd last element
    for (int i = 1; i < n - 1; i++)
    {
        // Check whether arr[i] needs to be modified
        if ((arr[i - 1] < arr[i] && arr[i + 1] < arr[i]) || (arr[i - 1] > arr[i] && arr[i + 1] > arr[i]))
        {
            // Modifying arr[i]
            arr[i] = (arr[i - 1] + arr[i + 1]) / 2;

            // Check if arr[i] is equal to any of arr[i-1] or arr[i+1]
            if (arr[i] == arr[i - 1] || arr[i] == arr[i + 1])
                return false;
            modify++;
        }
    }
    // Check whether the last element needs to be modify or not
    if (arr[n - 2] > arr[n - 1])
        modify++;
    if (modify > 1)
        return false;
    return true;
}

// Driver code
int main()
{
    int arr[] = {2, 4, 8, 6, 9, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (check(arr, n))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
