#include <iostream>
using namespace std;

int main()
{
    int n=5;
    // My way
    for(int i = n; i>=1;i--)
    {
        for(int j = 1; j<=i;j++)
        cout<<j<<" ";
        cout<<endl;
    }
    cout<<endl;
    // Highway
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n+1-i;j++)
        cout<<j<<" ";
        cout<<endl;
    }
    
return 0;
}