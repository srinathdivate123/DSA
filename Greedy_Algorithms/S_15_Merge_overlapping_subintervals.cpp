// Given an array of intervals where intervals{i} = {starti, endi}, merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    if (intervals.size() == 0)
    {
        return intervals;
    }

    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    vector<int> tempInterval;

    tempInterval = intervals[0]; // Put the first interval into it

    for(auto it : intervals)
    {
        if(it[0] <= tempInterval[1]) // Merging
        {
            tempInterval[1] = max(it[1], tempInterval[1]);
        }
        else
        {
            ans.push_back(tempInterval);
            tempInterval = it;
        }
    }
    ans.push_back(tempInterval);
    return ans;
}

int main()
{
    // The intervals may or may not be sorted

    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> ans = merge(intervals);

    for (auto it : ans)
        cout << it[0] << " " << it[1] << endl;
}