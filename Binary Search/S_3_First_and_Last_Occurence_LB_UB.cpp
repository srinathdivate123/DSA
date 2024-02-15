// Given a sorted array arr of n integers and a target value k. Find the indices of the first and the last occurrences of the target value. If the target is not found then return -1 as indices.

#include <bits/stdc++.h>
using namespace std;

// Here we are solving using LB and UB concept
int upperBound(vector<int> &arr, int n, int x)
{
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > x)
            ans = mid, high = mid - 1;
        else
            low = mid + 1;
    }
    return ans;
}

int lowerBound(vector<int> &arr, int n, int x)
{
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= x)
            ans = mid, high = mid - 1;
        else
            low = mid + 1;
    }
    return ans;
}

pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k)
{
    int lb = lowerBound(arr, n, k);

    if (lb == n || arr[lb] != k) // Suppose we find that the lb is n (means that element is )
        return {-1, -1};
    int ub = upperBound(arr, n, k);
    return {lb, ub - 1};
}

int main()
{
    vector<int> arr = {2, 4, 6, 8, 8, 8, 11, 13};
    int n = 8, k = 8;
    pair<int, int> ans = firstAndLastPosition(arr, n, k);
    cout << ans.first << " " << ans.second << "\n";
    return 0;
}
