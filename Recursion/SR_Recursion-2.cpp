#include <bits/stdc++.h>
using namespace std;

// Recursive function to print numbers from 1 to n
void f(int i, int n)
{
    if (i < 1)
        return;
    f(i - 1, n);
    cout << i << endl;
}

// Recursive function to print numbers in reverse order
void r(int n)
{
    if (n <= 0)
        return;
    cout << n << endl;
    r(n - 1);
}

int main()
{
    int n;
    cout << "Enter a number - ";
    cin >> n;
    cout << endl;
    f(n, n);
    cout << endl;
    r(n);
    return 0;
}