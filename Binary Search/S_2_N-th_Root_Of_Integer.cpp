// You have to return the n-th root of m
#include <bits/stdc++.h>
using namespace std;

// return 1, if calculatedSqrt == m:
// return 0, if calculatedSqrt < m:
// return 2, if calculatedSqrt > m:
int func(int mid, int n, int m)
{
    long long calculatedSqrt = 1;
    for (int i = 1; i <= n; i++)
    {
        calculatedSqrt *= mid;
        if (calculatedSqrt > m)
            return 2;
    }
    if (calculatedSqrt == m)
        return 1;
    return 0;
}

int NthRoot(int n, int m)
{
    int low = 1, high = m;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int midN = func(mid, n, m);
        if (midN == 1)
            return mid;
        else if (midN == 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int main()
{
    int n = 3, m = 27;
    cout << "The answer is: " << NthRoot(n, m) << endl;
    return 0;
}