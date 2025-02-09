// Given an array of intervals 'intervals' where intervals{i} = {starti, endi}, return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

// Note that intervals which only touch at a point are non-overlapping. For example, {1, 2} and {2, 3} are non-overlapping.

#include <bits/stdc++.h>
using namespace std;

bool static comparator(vector<int> a, vector<int> b)
{
    return a[1] < b[1];
}

// TC = N*log(N) + N
// SC = O(1)
int best(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end(), comparator);

    int getsFreedAt = intervals[0][1]; // Meeting room gets freed at
    int cnt = 1;
    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i][0] >= getsFreedAt)
        {
            getsFreedAt = intervals[i][1];
            cnt++;
        }
    }
    return intervals.size() - cnt;
}


int main()
{
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    cout << best(intervals) << endl;
}