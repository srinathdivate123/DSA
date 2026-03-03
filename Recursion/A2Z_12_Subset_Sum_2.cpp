// Given an array of integers that may contain duplicates the task is to return all possible subsets. Return only unique subsets and they can be in any order.

#include <bits/stdc++.h>
using namespace std;

// Brute is to generate all subsets using recursion, put them in set and then return them in vector. This will take an extra 2^n*log(2^n) TC to put in set and set will take up 2^n space.

// TC = k * 2^n. 2^n for generating every subset and k to insert every subset in another data structure if the average length of every subset is k.
// SC = 2^n * k to store every subset of average length k. Auxiliary space is n if n is the depth of the recursion tree.
void printAns(vector<vector<int>> &ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}

void findSubsets(int ind, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans)
{
    ans.push_back(ds);
    for (int i = ind; i < nums.size(); i++)
    {
        if (i != ind && nums[i] == nums[i - 1])
            continue;
        ds.push_back(nums[i]);
        findSubsets(i + 1, nums, ds, ans);
        ds.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> ds;
    sort(nums.begin(), nums.end());
    findSubsets(0, nums, ds, ans);
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> ans = subsetsWithDup(nums);
    printAns(ans);
    return 0;
}