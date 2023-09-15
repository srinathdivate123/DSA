#include <bits/stdc++.h>
using namespace std;

void countDigits(int num)
{
    cout << "Number of digits is : " << floor(log10(num) + 1) << endl;
}

void reverseNumber(int n)
{
    int num = n;
    int reverse = 0;
    while (n != 0)
    {
        int digit = n % 10;
        reverse = reverse * 10 + digit;
        n = n / 10;
    }
    cout << "The reverse is : " << reverse << endl;
}

void isPalindrome(int n)
{
    // You can do this by checking if the input num is same as its reverse.
}

void isArmstrongNumber(int n)
{
    // Check if the sum of the squares of digits in the number is equal to that number!
}

void find_all_divisors(int n)
{
    // Brute is to iterate upto the number and find all the divisors!
    // Below is optimal to iterate upto sqrt(n). But you will not get divsors in sorted order in this!
    for (int i = 1; i * i <= n; i++)
        if (n % i == 0)
        {
            cout << i << " ";
            if (i != n / i)
                cout << n / i << " ";
        }
}

void checkPrime(int n)
{
    // A Prime number is a number that has only two factors: 1 and itself.
    // Brute is to loop until n, find all factors. If it has exactly 2 factors, then n is prime!

    // Optimal is to check for factors until sqrt(n).
    int cnt = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cnt++;
            if ((n / i) != i)
                cnt++;
        }
    }
    if (cnt == 2)
        cout << "Prime Number it is!";
    else
        cout << "Not prime it is !";
}

void GCD(int n1, int n2)
{
    int gcd;
    // Time cimplexity = (min(n1, n2))
    for (int i = min(n1, n2); i >= 1; i--)
        if (n1 % i == 0 && n2 % i == 0)
        {
            cout << "GCD : " << i;
            break;
        }
}

int GCD_Euclidean(int a, int b)
{
    // Intuition: Gcd is the greatest number which is divided by both a and b.If a number is divided by both a and b, it is should be divided by (a-b) and b as well

    // Euclidean Algorithm states
    //  GCD (a, b) = GCD (a%b, b) provided a>b

    // You have to go on applying Euclidean in recursion until one of the numbers in the brackets becomes zero. The moment one number becomes zero, the other one is the GCD.

    if (b == 0)
        return a;
    return GCD_Euclidean(b, a % b);
}
int main()
{
    // countDigits(12345);
    // reverseNumber(12345);
    // find_all_divisors(36);
    // checkPrime(5);
    // GCD(12, 36);
    cout << "GCD is : " << GCD_Euclidean(36, 12);
    return 0;
}