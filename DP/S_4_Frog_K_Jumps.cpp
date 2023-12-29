// This is a follow-up question to “Frog Jump”. In the previous question, the frog was allowed to jump either one or two steps at a time. In this question, the frog is allowed to jump up to ‘K’ steps at a time. If K=4, the frog can jump i+1, i+2, i+3, or i+4 steps at every index.

#include <bits/stdc++.h>
using namespace std;

// TC = N*k, SC = N for dp array.
int memoization(int ind, vector<int> &height, vector<int> &dp, int k)
{
    if (ind == 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    int mmSteps = INT_MAX;
    for (int j = 1; j <= k; j++)
        if (ind - j >= 0)
        {
            int jump = memoization(ind - j, height, dp, k) + abs(height[ind] - height[ind - j]);
            mmSteps = min(jump, mmSteps);
        }
    return dp[ind] = mmSteps;
}

// TC = N*k, SC = N for dp array.
int tabulation(int n, vector<int> &height, vector<int> &dp1, int k)
{
    dp1[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int mmSteps = INT_MAX;
        for (int j = 1; j <= k; j++)
            if (i - j >= 0)
            {
                int jump = dp1[i - j] + abs(height[i] - height[i - j]);
                mmSteps = min(jump, mmSteps);
            }
        dp1[i] = mmSteps;
    }
    return dp1[n - 1];
}

// Space optimised approach also exists, but it takes TC = N & SC = N in worst case.

int main()
{
    vector<int> height{30, 10, 60, 15, 35, 20, 15, 10, 30};
    int n = height.size();
    int k = 3;
    vector<int> dp(n, -1);
    vector<int> dp1(n, -1);
    cout << memoization(n - 1, height, dp, k) << endl;
    cout << tabulation(n, height, dp1, k) << endl;
    return 0;
}