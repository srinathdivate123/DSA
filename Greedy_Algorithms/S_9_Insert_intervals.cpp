/*
You are given an array of non-overlapping intervals 'intervals' where intervals{i} = {starti, endi} represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval 'newInterval' = {start, end} that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and 'intervals' still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Note that you don't need to modify intervals in-place. You can make a new array and return it.
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    vector<vector<int>> ans;
    int i = 0, n = intervals.size();
    // Starting part of the answer, where there is no overlap
    while (i < n && intervals[i][1] < newInterval[0])
    {
        ans.push_back(intervals[i]);
        i++;
    }

    // Middle part of the answer, where there may be overlap
    while (i < n && intervals[i][0] <= newInterval[1])
    {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }

    ans.push_back(newInterval);

    // Last part of the answer, after the interval has been put into ans
    while (i < n)
    {
        ans.push_back(intervals[i]);
        i++;
    }
    return ans;
}

int main()
{
    vector<vector<int>> intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    vector<int> newInterval = {4, 8};
    vector<vector<int>> ans = insert(intervals, newInterval);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }
    return 0;
}