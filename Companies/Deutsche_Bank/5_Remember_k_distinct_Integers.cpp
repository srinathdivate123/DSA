#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, x, count = 1;
        cin >> n >> k >> x;
        int arr[n + 1];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        sort(arr, arr + n);
        // Finding unique elements
        for (int i = 0; i < n - 1; i++)
            if (arr[i] != arr[i + 1])
                count++;

        long ans = 0;
        if (count <= k)
            ans = 0;
        else
        {
            ans = abs(count - k);
            ans = ans * x;
        }
        cout << ans << endl;
    }
}