#include <iostream>
using namespace std;

int main()
{
    int n=5;
    // My way
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
            cout << "  ";
        for (int k = 1; k <= n; k++)
            cout << "* ";
        cout << endl;
    }
    return 0;
}
