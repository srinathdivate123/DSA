#include <bits/stdc++.h>
using namespace std;
// Calculate the n-th fibonacci number
double fibonacciNum(int n)
{
    if (n <= 1)
        return n;
    return fibonacciNum(n - 1) + fibonacciNum(n - 2);
}

int main()
{
    int n = 7;
    cout << fibonacciNum(n);
    return 0;
}
// Time complexity is 2 power n.