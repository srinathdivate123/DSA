#include <bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int n)
{
    if (n <= 0)
        return false;
    return (n & (n - 1)) == 0;
}

int main()
{
    cout << isPowerOfTwo(4);
}