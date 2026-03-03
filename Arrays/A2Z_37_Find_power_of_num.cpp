// Given a double x and integer n, calculate x raised to power n.
// Ask the interviewer if n can be negative!
#include <bits/stdc++.h>
using namespace std;

// Brute is to loop from 1 to n and calculate the answer.
// If n is negative, then also loop. And at last do 1/ans. Because x^(-n) = 1/(x^n)

double myPow(double x, int n)
{
    double ans = 1.0;
    long long nn = n;
    if (nn < 0) // If it is a negative value. Make it positive!
        nn *= -1;
    while (nn) // Continue algo until nn becomes 0
    {
        if (nn % 2 == 0) // If nn is even
        {
            x = x * x;
            nn = nn / 2;
        }
        else
        {
            ans = ans * x;
            nn--;
        }
    }
    if (n < 0)
        ans = (double)(1.0) / (double)ans;
    return ans;
}
int main()
{
    cout << myPow(2.1, 3);
    return 0;
}