#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << " How many numbers u want to enter in array - ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int hash[n] = {0};
    for (int i = 0; i < n; i++)
        hash[arr[i]] += 1;

    int no_of_queries;
    cout << " How many queries - ";
    cin >> no_of_queries;
    while (no_of_queries--)
    {
        int number;
        cin >> number;
        cout << "Number of entries of the above number is - " << hash[number] << endl;
    }
    return 0;
}