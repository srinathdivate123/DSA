/*Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target. Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.*/
#include <bits/stdc++.h>
using namespace std;

// Brute is to use the code from prev example, just edit it so that you move to next index after using the current index. And declare the answer as a set of vectors to avoid duplicates. TC = 2^n * k * log(n). 2^n because at every index, we have 2 choices, k is the average length of each solution, log(n) because we are putting the solution into a set.

// If all the elements are unique, TC is 2^n * k. SC depends on the number of solutions and their size.
void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
{
    if (target == 0)
    {
        ans.push_back(ds);
        return;
    }
    for (int i = ind; i < arr.size(); i++)
    {
        if (i > ind && arr[i] == arr[i - 1])
            continue;
        if (arr[i] > target)
            break;
        ds.push_back(arr[i]);
        findCombination(i + 1, target - arr[i], arr, ans, ds);
        ds.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> ds;
    findCombination(0, target, candidates, ans, ds);
    return ans;
}

int main()
{
    vector<int> v{1, 2, 1, 2, 1};
    vector<vector<int>> comb = combinationSum2(v, 4);
    for (int i = 0; i < comb.size(); i++)
    {
        for (int j = 0; j < comb[i].size(); j++)
            cout << comb[i][j] << " ";
        cout << endl;
    }
}