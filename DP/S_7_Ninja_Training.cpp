/* A Ninja has an ‘N’ Day training schedule. He has to perform one of these three activities (Running, Fighting Practice, or Learning New Moves) each day. There are merit points associated with performing an activity each day. The same activity can’t be performed on two consecutive days. We need to find the maximum merit points the ninja can attain in N Days.

We are given a 2D Array POINTS of size ‘N*3’ which tells us the merit point of specific activity on that particular day. Our task is to calculate the maximum number of merit points that the ninja can earn. */
#include <bits/stdc++.h>
using namespace std;

// TC = N*4*3, SC = N for auxiliary stack space + N*4 for dp vector
int memoization(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if (dp[day][last] != -1)
        return dp[day][last];

    if (day == 0) // Base case: When we reach the first day (day == 0)
    {
        int maxi = 0;
        // Calculate the maximum points for the first day by choosing an activity different from last one
        for (int i = 0; i <= 2; i++)
            if (i != last)
                maxi = max(maxi, points[0][i]);
        return dp[day][last] = maxi;
    }

    int maxi = 0;
    for (int i = 0; i <= 2; i++) // Iterate through the activities for the current day
        if (i != last)
        {
            // Calculate the points for the current activity and add it to the
            // maximum points obtained so far (recursively calculated)
            int activity = points[day][i] + memoization(day - 1, i, points, dp);
            maxi = max(maxi, activity);
        }
    return dp[day][last] = maxi;
}

// TC = N*4*3, SC = N*4
int tabulation(int n, vector<vector<int>> &points)
{
    // Create a 2D DP table to store the maximum points dp[i][j] representing the maximum points at day i, considering the last activity as j
    vector<vector<int>> dp(n, vector<int>(4, 0));

    // Initialize the DP table for the first day (day 0)
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    // Iterate through the days starting from day 1
    for (int day = 1; day < n; day++)
        for (int last = 0; last <= 3; last++)
        {
            dp[day][last] = 0;
            for (int task = 0; task <= 2; task++) // Iterate through the tasks for the current day
                if (task != last)
                {
                    // Calculate the points for the current activity and add it to the
                    // maximum points obtained on the previous day (recursively calculated)
                    int point = points[day][task] + dp[day - 1][task];
                    // Update the maximum points for the current day and last activity
                    dp[day][last] = max(dp[day][last], point);
                }
        }
    // The maximum points for the last day with any activity can be found in dp[n-1][3]
    return dp[n - 1][3];
}

int space_optimised(int n, vector<vector<int>> &points)
{
    vector<int> prev(4, 0); // Vector to store the max points for the prev day's activities

    // For the first day (day 0)
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int day = 1; day < n; day++)
    {
        vector<int> temp(4, 0); // Store the maximum points for the current day's activities
        for (int last = 0; last <= 3; last++)
        {
            temp[last] = 0;
            for (int task = 0; task <= 2; task++) // Tasks for the current day
                if (task != last)
                    // Calculate the points for the current activity and add it to the maximum points obtained on the previous day (stored in prev)
                    temp[last] = max(temp[last], points[day][task] + prev[task]);
        }
        // Update prev with the maximum points for the current day
        prev = temp;
    }

    // The maximum points for the last day with any activity can be found in prev[3]
    return prev[3];
}
int main()
{
    vector<vector<int>> points = {{10, 40, 70},
                                  {20, 50, 80},
                                  {30, 60, 90}};

    int n = points.size();
    vector<vector<int>> dp(n, vector<int>(4, -1));
    cout << memoization(n - 1, 3, points, dp) << endl;
    cout << tabulation(n, points) << endl;
    cout << space_optimised(n, points) << endl;
}