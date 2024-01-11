// We are given an array arr of size n and a number Target. Our task is to build an expression from the given array where we can place a '+' or '-' sign in front of an integer. We want to place a sign in front of every integer of the array and get our required target. We need to count the number of ways in which we can achieve our required target.

// This boils down to - given an arr divide elements into two arrays (+ and -) such that the difference between the two is target. This is same as S-18. Only the language is changed to confuse you!

#include <bits/stdc++.h>
using namespace std;

const int mod = (int)1e9 + 7;

int findWays(vector<int> &num, int tar)
{
    int n = num.size();

    vector<int> prev(tar + 1, 0);

    if (num[0] == 0)
        prev[0] = 2; // 2 cases - pick and not pick
    else
        prev[0] = 1; // 1 case - not pick

    if (num[0] != 0 && num[0] <= tar)
        prev[num[0]] = 1; // 1 case - pick

    for (int ind = 1; ind < n; ind++)
    {
        vector<int> cur(tar + 1, 0);
        for (int target = 0; target <= tar; target++)
        {
            int notTaken = prev[target];

            int taken = 0;
            if (num[ind] <= target)
                taken = prev[target - num[ind]];

            cur[target] = (notTaken + taken) % mod;
        }
        prev = cur;
    }
    return prev[tar];
}

int targetSum(int n, int target, vector<int> &arr)
{
    int totSum = 0;
    for (int i = 0; i < n; i++)
        totSum += arr[i];

    // Checking for edge cases
    if (totSum - target < 0 || (totSum - target) % 2 != 0)
        return 0; // Not possible to achieve the target sum

    return findWays(arr, (totSum - target) / 2);
}

int main()
{
    vector<int> arr = {1, 2, 3, 1};
    int n = arr.size();
    int target = 3;

    cout << targetSum(n, target, arr) << endl;

    return 0;
}
