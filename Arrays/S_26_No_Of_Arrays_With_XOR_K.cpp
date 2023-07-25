#include <bits/stdc++.h>
using namespace std;

// Let's say the XOR of first part is x
// The XOR of second part, that we're searching is K
// Prefix XOR till index i = XR
// Thus
// x ^ K = XR
// x ^ K ^ K = XR ^ K
// x = XR ^ K
// Hence the XOR of first part must be x = XR ^ K
int main()
{
    vector<int> arr = {4, 2, 2, 6, 4};
    int n = arr.size();
    int XR = 0;
    int cnt = 0;
    int K = 6;
    unordered_map<int, int> mpp;
    mpp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        XR = XR ^ arr[i];
        // Find K
        int x = XR ^ K;
        cnt += mpp[x];
        mpp[XR]++;
    }
    cout << cnt;
    return 0;
}