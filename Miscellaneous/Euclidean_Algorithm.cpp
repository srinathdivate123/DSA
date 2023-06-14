#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Euclidean Algorithm states
    //  GCD (a, b) = GCD (a%b, b) provided a>b

    // You have to go on applying Euclidean in recursion until one of the numbers in the beackets becomes zero. Th emoment one number becomes zero, the other one is the GCD.
    int a, b;
    cin >> a;
    cin >> b;
    while (a > 0 && b > 0)
    {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }
    if (a == 0)
        cout << "GCD - " << b;
    else
        cout << "GCD - " << a;
    return 0;
}