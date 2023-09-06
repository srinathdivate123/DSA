#include <iostream>
using namespace std;

int main()
{
    int h = 9;
    for (int i = 1; i <= h; i++)
    {
        for (int j = i; j <= h; j++)
            cout << "  ";
        for (int k = i; k >= 1; k--)
            cout << "* ";
        cout << endl;
    }
    // Optimal Solution
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= h; j++)
        {
            if (j <= h - i)
                cout << "  ";
            else
                cout << "* ";
        }
        cout << endl;
    }
    return 0;
}