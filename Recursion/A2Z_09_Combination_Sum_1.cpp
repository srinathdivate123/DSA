/* Given an array of distinct integers and a target, you have to return the list of all unique combinations where the chosen numbers sum to target. You may return the combinations in any order.
The same number may be chosen from the given array an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input. */
#include <bits/stdc++.h>
using namespace std;

// Suppose it was given that you cannot pick the same element again, the the TC would be 2^n * k. 2^n because for each element, you had 2 choices: pick/not-pick. And k to put the ds into answer, if it is a correct solution.

// But here, the TC is 2^t * k, where t is the target. 2^t because if you choose to pick an index, you still stay on that index and do not move forward because you can shoose that index again. This is again, average-ised TC for all indexes combined.

// SC = Space taken by answer depends on the number of solutions. Recursion stack space is variable depending on the input.
void recursion_func(int index, int target, vector<int> &arr, vector<int> &ds, vector<vector<int>> &answer)
{
    if (index == arr.size())
    {
        if (target == 0)
            answer.emplace_back(ds);
        return;
    }
    // PICK
    if (arr[index] <= target)
    {
        ds.emplace_back(arr[index]);
        recursion_func(index, target - arr[index], arr, ds, answer);
        ds.pop_back();
    }
    recursion_func(index + 1, target, arr, ds, answer);
}

int main()
{
    vector<int> arr = {2, 3, 6, 7};
    vector<int> ds = {};
    vector<vector<int>> answer;
    recursion_func(0, 7, arr, ds, answer);
    for (auto solution : answer)
    {
        for (int element : solution)
            cout << element << " ";
        cout << endl;
    }
    return 0;
}