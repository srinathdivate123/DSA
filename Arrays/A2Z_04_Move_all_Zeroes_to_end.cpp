// Brute force is to store all non-zero elements in temp array. Then fill the original array with temp array. Fill remaining places of original array with 0's.

// For best
// TC = n
// SC = No extra space used
#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n)
{
    cout << "Printing array:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n\n";
}

// Using two-pointer approach
void movezeroes(int arr[], int n)
{
    int j = -1;
    // TC of below = x (where the first 0 is found)
    for (int i = 0; i < n; i++) // Loop to get the index of first '0' element
        if (arr[i] == 0)
        {
            j = i;
            break;
        }
    // TC of below is n-x 
    for (int i = j+1; i < n; i++)
        if (arr[i] != 0)
        {
            swap(arr[i],arr[j]);
            j++;
        }
}

int main()
{
    int arr[] = {0,1,0,0,1,1,1,0,0,1,0,1,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    movezeroes(arr, n);
    cout << "After moving zeroes - " << endl;
    printArray(arr, n);
    return 0;
}