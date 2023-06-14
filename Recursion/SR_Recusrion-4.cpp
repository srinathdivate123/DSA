#include <bits/stdc++.h>
using namespace std;
string str;

// Reverse an array with one pointer
void reverseArray_1_Pointer(int i, int n, int arr[])
{
    if (i >= n / 2)
        return;
    swap(arr[i], arr[n - i - 1]);
    reverseArray_1_Pointer(i + 1, n, arr);
}

// Reverse array using 2 pointers
void reverseArray_2_Pointers(int l, int r, int arr[])
{
    if (l >= r)
        return;
    swap(arr[l], arr[r]);
    reverseArray_2_Pointers(l + 1, r - 1, arr);
}

// Check if the string is palindrome
bool isStringPalindrome(int i, int n)
{
    if (i >= str.length() / 2)
        return true;
    if (str[i] != str[n - i - 1]) // Checking 
        return false;
    return isStringPalindrome(i + 1,n);
}


int main()
{
    int n;
    cout << "Enter array size - ";
    cin >> n;
    int arr[n];
    cout << "Enter elements of array - " << endl;

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    reverseArray_2_Pointers(0, n - 1, arr);
    cout << endl;
    cout << "After reversing - " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;

    reverseArray_1_Pointer(0, n, arr);
    cout << "After re-reversing - " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;

    cout << endl;

    cout << "Enter string - ";
    cin >> str;
    cout << isStringPalindrome(0,str.length());

    return 0;
}