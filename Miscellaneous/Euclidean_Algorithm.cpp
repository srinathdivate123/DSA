#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int main()
{
    // Intuition: Gcd is the greatest number which is divided by both a and b.If a number is divided by both a and b, it is should be divided by (a-b) and b as well

    // Euclidean Algorithm states
    //  GCD (a, b) = GCD (a%b, b) provided a>b

    // You have to go on applying Euclidean in recursion until one of the numbers in the brackets becomes zero. Th moment one number becomes zero, the other one is the GCD.
    int a = 3, b = 45;
    cout << "GCD is " << gcd(a, b);
    return 0;
}
