#include <iostream>
using namespace std;
int main()
{
    int n = 5;
    // My way
    // This problem can be solved by the code pf previous problem also, just you have to print * instead of the numbers. Rest code is same. But below is an optimised code for this problem!
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
            cout << "  ";
        for (int k = 1; k <= 2 * i - 1; k++)
            cout << "* ";
        cout << endl;
    }
    for (int i = n; i >= 1; i--)
    {
        for (int j = i; j <= n; j++)
            cout << "  ";
        for (int k = 1; k <= 2 * i - 1; k++)
            cout << "* ";
        cout << endl;
    }
    return 0;
}