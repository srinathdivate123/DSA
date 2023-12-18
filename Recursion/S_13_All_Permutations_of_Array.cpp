// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order
#include <bits/stdc++.h>
using namespace std;

// TC = n! (total no of permutations will be n!) * n (for looping through all elements in visited)
// SC = n for ds and n for visited
void brute(vector<int> &ds, vector<int> &nums, vector<int> &visited)
{
    if (ds.size() == nums.size())
    {
        for (int element : ds)
            cout << element << " ";
        cout << endl;
        return;
    }
    for (int i = 0; i < nums.size(); ++i)
        if (!visited[i])
        {
            ds.emplace_back(nums[i]);
            visited[i] = 1;
            brute(ds, nums, visited);
            visited[i] = 0;
            ds.pop_back();
        }
}

void better(int index, vector<int> &nums)
{
    if (index == nums.size())
    {
        for (int element : nums)
            cout << element << " ";
        cout << endl;
        return;
    }
    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[index], nums[i]);
        better(index + 1, nums);
        swap(nums[index], nums[i]); 
    }
}

int main()
{
    vector<int> ds, nums = {1, 2, 3}, visited(nums.size(), 0);
    // brute(ds, nums, visited);
    better(0, nums);
    return 0;
}