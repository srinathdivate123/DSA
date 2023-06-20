#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    cout << endl;
    cout << "Pattern - 14" << endl
         << endl;
    for (int i = 0; i < n; i++)
    {
        for (char ch = 'A'; ch <= 'A' + i; ch++) // ASCII value of A is 65
            cout << ch << " ";
        cout << endl;
    }
    
    cout << endl;
    cout << "Pattern - 15" << endl
         << endl;
    for (int i = 0; i < n; i++)
    {
        for (char ch = 'A'; ch <= 'A' + (n - i - 1); ch++)
            cout << ch << " ";
        cout << endl;
    }

    cout << endl;
    cout << "Pattern - 16" << endl
         << endl;
    for (char ch = 'A'; ch < 'A' + n; ch++)
    {
        for (int i = 0; i <= ch - 65; i++) // The ASCII of A is 65.
            cout << ch << " ";
        cout << endl;
    }
    // Another alternative for above is to define a character in outer for loop that is to be printed n times. And then print the character in the inner for loop n times

    cout << endl;
    cout << "Pattern - 17" << endl
         << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n - 1; j++)
            cout << " ";
        char ch = 'A';
        int breakpoint = (2 * i + 1) / 2;

        for (int j = 1; j <= 2 * i + 1; j++)
        {
            cout << ch;
            if (j <= breakpoint)
                ch++;
            else
                ch--;
        }
        cout << endl;
    }

    cout << endl;
    cout << "Pattern - 18" << endl
         << endl;

    for (int i = 0; i < n; i++)
    {
        // Inner loop for printing the alphabets from
        // A + N -1 -i (i is row no) to A + N -1 (E in this case).
        for (char ch = ('A' + n - 1) - i; ch <= ('A' + n - 1); ch++)
            cout << ch << " ";
        cout << endl;
    }
    return 0;
}