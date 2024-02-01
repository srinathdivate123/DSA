/*
We are given a stick of length N and a CUTS array of size C. The stick has markings as shown, and the CUTS array has indexes at which the stick needs to be cut (shown in red).

It is necessary to make cuts at all indexes in the CUTS array. Whenever we make a cut, we incur a cost. This cost is equal to the length of the stick on which we are making the cut.

We need to find the minimum cost incurred to cut the stick at all the cut points.
*/

#include <bits/stdc++.h>
using namespace std;

// TC = n*n*n, SC = n*n + n
int memoization(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
{
    // Base case: If i is greater than j, there are no cuts to consider.
    if (i > j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int mini = INT_MAX;

    for (int ind = i; ind <= j; ind++)
    {
        // Calculate the cost for making a cut at position 'ind'.
        int cost = cuts[j + 1] - cuts[i - 1] +
                   memoization(i, ind - 1, cuts, dp) +
                   memoization(ind + 1, j, cuts, dp);

        mini = min(mini, cost);
    }

    return dp[i][j] = mini;
}

int tabulation(int c, vector<int> &cuts)
{
    vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));

    for (int i = c; i >= 1; i--)
        for (int j = 1; j <= c; j++)
        {
            if (i > j)
                continue; // Because base case is already assigned into the dp itself.

            int mini = INT_MAX;

            for (int ind = i; ind <= j; ind++)
            {
                // Calculate the cost for making a cut at position 'ind'.
                int ans = cuts[j + 1] - cuts[i - 1] + dp[i][ind - 1] + dp[ind + 1][j];

                mini = min(mini, ans);
            }

            dp[i][j] = mini;
        }

    return dp[1][c];
}

int main()
{
    vector<int> cuts = {3, 5, 1, 4};
    int c = cuts.size();
    int n = 7;
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));

    cout << memoization(1, c, cuts, dp) << endl;
    cout << tabulation(c, cuts) << endl;

    return 0;
}
