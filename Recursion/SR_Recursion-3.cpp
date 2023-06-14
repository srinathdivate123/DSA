#include <bits/stdc++.h>
using namespace std;

// Sum of first n numbers using parameterised recursion way
void Sum_parameterised(int i, int sum)
{
    if (i < 1)
    {
        cout << sum;
        return;
    }
    Sum_parameterised(i - 1, sum + i);
}

// Sum of first n numbers using functional recursion way
int Sum_functional(int n)
{
    if (n == 0)
        return 0;
    return n + Sum_functional(n - 1);
}

// Finding the factorial of n
int factorial(int n)
{
    if (n == 1)
        return 1;
    return n * factorial(n - 1);
}


int main()
{
    int n;
    cout << "Enter a number - ";
    cin >> n;

    Sum_parameterised(n, 0);
    cout << endl;

    cout << Sum_functional(n);
    cout << endl;
    
    cout<< factorial(n);
    cout << endl;
;
    return 0;
}
