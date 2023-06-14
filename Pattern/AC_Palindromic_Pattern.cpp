#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter n - ";
    cin >> n;
    // My way
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
            cout << "  ";
        for (int k = i; k >= 1; k--)
            cout << k << " ";
        for (int m = 2; m <= i; m++)
            cout << m << " ";
        cout << endl;
    }
    return 0;
}