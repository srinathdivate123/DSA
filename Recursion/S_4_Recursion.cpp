#include <bits/stdc++.h>
using namespace std;

// Reverse an array with one pointer. TC = n/2
void reverseArray_1_Pointer(int i, int n, int arr[])
{
    if (i >= n / 2)
        return;
    swap(arr[i], arr[n - i - 1]);
    reverseArray_1_Pointer(i + 1, n, arr);
}

// Reverse array using 2 pointers. TC = n/2
void reverseArray_2_Pointers(int l, int r, int arr[])
{
    if (l >= r)
        return;
    swap(arr[l], arr[r]);
    reverseArray_2_Pointers(l + 1, r - 1, arr);
}

// Check if the string is palindrome
bool isStringPalindrome(int i, int n, string str)
{
    if (i >= str.length() / 2)
        return true;
    if (str[i] != str[n - i - 1])
        return false;
    return isStringPalindrome(i + 1, n, str);
}

int main()
{
    int n = 7;
    int arr[n] = {1, 2, 3, 4, 5, 6, 7};
    reverseArray_2_Pointers(0, n - 1, arr);
    cout << endl;
    cout << "After reversing - " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i];

    reverseArray_1_Pointer(0, n, arr);
    cout << endl << "After re-reversing - " << endl;
    for (int i = 0; i < n; i++)
        cout <<  arr[i];

    cout << endl;

    string str = "Srinath";
    cout << isStringPalindrome(0, str.length(), str);

    return 0;
}