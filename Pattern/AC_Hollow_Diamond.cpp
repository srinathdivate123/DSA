#include <iostream>
using namespace std;

int main()
{
    int n = 4; // no of rows in upper half

    // Upper half of the diamond
    for (int i = 0; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
            cout << " ";
        for (int k = 1; k <= 2 * i - 1; k++)
        {
            if (k == 1 || k == 2 * i - 1) // Print * only in the start (k = 1) and end (k = 2*i-1)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }

    // Lower half of the diamond
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 1; j <= n - i; j++)
            cout << " ";
        for (int k = 1; k <= 2 * i - 1; k++)
        {
            if (k == 1 || k == 2 * i - 1) // Print * only in the start (k = 1) and end (k = 2*i-1)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}
