#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "How many numbers u want to enter in array - ";
    cin >> n;
    int arr[n];
    map<int, int> mpp;
    // You can do pre-computation while taking input also
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mpp[arr[i]]++;
    }

    int no_of_queries;
    cout << " How many queries - ";
    cin >> no_of_queries;
    while (no_of_queries--)
    {
        int number;
        cin >> number;
        cout << mpp[number] << endl;
    }


    string str;
    cout<<"Enter string - ";
    cin>>str;
    map <char, int> mp;
    for(int i=0; i<str.size();i++)
        mp[str[i]]++;
    cout<<endl;
    // For showing that map stores keys in sorted order
    for (auto it : mp)
        cout << it.first << " --> " << it.second << endl;
    return 0;
}