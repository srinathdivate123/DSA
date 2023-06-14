#include <iostream>
using namespace std;

int main()
{
    int n;
    bool value;
    cout << "Enter n - ";
    cin >> n;
    // My way
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 != 0)
            value = true;
        else
            value = false;
        for (int j = 1; j <= i; j++)
        {
            cout << int(value) << " ";
            if (value == true)
                value = false;
            else
                value = true;
        }
        cout << endl;
    }
        cout << endl;

    // Highway
    for(int i=1; i<=n; i++)
    {
        for(int j=1;j<=i;j++ ){
            if((i+j)%2==0)
            cout<<"1 ";
            else
            cout<<"0 ";
        }
        cout<<endl;
    }
    return 0;
}