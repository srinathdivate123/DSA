#include <bits/stdc++.h>
using namespace std;

// Numbers from 1 to n
void f_1_n__recursion(int i, int n)
{
    if (i > n)
        return;
    cout << i;
    f_1_n__recursion(i + 1, n);
}

void f_1_n__backtracking(int i)
{
    if (i < 1)
        return;
    f_1_n__backtracking(i - 1);
    cout << i;
}

// Numbers from n to 1
void f_n_1__recursion(int i)
{
    if (i < 1)
        return;
    cout << i;
    f_n_1__recursion(i - 1);
}

void f_n_1__backtracking(int i, int n)
{
    if (i > n)
        return;
    f_n_1__backtracking(i + 1, n);
    cout << i;
}

int main()
{
    int n = 7;
    f_1_n__recursion(1, n);
    cout << endl;
    f_1_n__backtracking(n);
    cout << endl;
    f_n_1__recursion(n);
    cout << endl;
    f_n_1__backtracking(1, n);
    return 0;
}