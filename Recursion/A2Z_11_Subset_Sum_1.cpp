// Given an array print all the sum of the subset generated from it, in the increasing order.

#include <bits/stdc++.h>
using namespace std;

// TC = O(2^n)+O(2^n log(2^n)). Each index has two choices - pick/not-pick. For sorting it will take (2^n log(2^n)).
// SC = 2^n
void subsetSumsHelper(int ind, vector<int> &arr, int n, vector<int> &ans, int sum)
{
    if (ind == n)
    {
        ans.push_back(sum);
        return;
    }
    // element is picked
    subsetSumsHelper(ind + 1, arr, n, ans, sum + arr[ind]);
    // element is not picked
    subsetSumsHelper(ind + 1, arr, n, ans, sum);
}
vector<int> subsetSums(vector<int> arr, int n)
{
    vector<int> ans;
    subsetSumsHelper(0, arr, n, ans, 0);
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<int> arr{3, 1, 2};
    vector<int> ans = subsetSums(arr, arr.size());
    sort(ans.begin(), ans.end());
    for (auto sum : ans)
        cout << sum << " ";

    return 0;
}