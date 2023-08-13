#include <bits/stdc++.h>
using namespace std;
void print(vector<vector<int>> arr);
// Given an arr of intervals, merge all the overlapping intervals and return an arr of non-overlapping intervals.

// First Sort
// TC = n*log(n) for sorting + in total we visit every element twice inside the parent for loop so 2n
void brute(vector<vector<int>> arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        int start = arr[i][0];
        int end = arr[i][1];
        if (!ans.empty() and end <= ans.back()[1])
            continue;
        for (int j = i + 1; j < n; j++)
            if (arr[j][0] <= end)
                end = max(end, arr[j][1]);
            else
                break;
        ans.push_back({start, end});
    }
    print(ans);
}

// Here we sort and solve in single pass
// Tc = n*log(n) + n
void best(vector<vector<int>> arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
        if (ans.empty() || arr[i][0] > ans.back()[1])
            ans.push_back(arr[i]);
        else
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
    print(ans);
}

void print(vector<vector<int>> arr)
{
    for (auto it : arr)
        cout << it[0] << " " << it[1] << endl;
}

int main()
{
    vector<vector<int>> arr = {{1, 3}, {2, 6}, {8, 9}, {9, 11}, {8, 10}, {2, 4}, {15, 18}, {16, 17}};
    // brute(arr);
    best(arr);
    return 0;
}