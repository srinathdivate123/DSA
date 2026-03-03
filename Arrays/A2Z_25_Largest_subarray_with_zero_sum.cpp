#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> A = {1, -1, 3, 2, -2, -8, 1, 7, 10, 23};
    int n = A.size();
    unordered_map<int, int> mpp;
    int maxi = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += A[i];
        if (sum == 0)
            maxi = i + 1;
        else
            if (mpp.find(sum) != mpp.end())
                maxi = max(maxi, i - mpp[sum]);
            else
                mpp[sum] = i;
    }

    cout<< maxi;
    return 0;
}