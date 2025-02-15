/*
There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

1) Each child must have at least one candy.
2) Children with a higher rating get more candies than their neighbors.

Return the minimum number of candies you need to have to distribute the candies to the children
*/

#include <bits/stdc++.h>
using namespace std;

// TC = O(3N), SC = O(2N)
int brute(vector<int> &ratings)
{
    int n = ratings.size();

    vector<int> leftMax(n, 1), rightMax(n, 1); // Very imp to initialize 1 by default

    // Iterate the array from left and only consider the left neighbours for any child. First child has no left neighbour
    for (int i = 1; i < n; i++)
    {
        if (ratings[i] > ratings[i - 1])
            leftMax[i] = leftMax[i - 1] + 1;
    }

    // Iterate the array from right and only consider the right neighbours for any child. Last child has no right neibhbour
    for (int i = n - 2; i >= 0; i--)
    {
        if (ratings[i] > ratings[i + 1])
            rightMax[i] = rightMax[i + 1] + 1;
    }
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += max(leftMax[i], rightMax[i]);
    }
    return sum;
}

// TC = O(2N), SC = O(N)
int better(vector<int> ratings)
{
    int n = ratings.size();
    vector<int> leftMax(n, 1); // Very imp to initialize 1 by default

    // Iterate the array from left and only consider the left neighbours for any child. First child has no left neighbour
    for (int i = 1; i < n; i++)
    {
        if (ratings[i] > ratings[i - 1])
            leftMax[i] = leftMax[i - 1] + 1;
    }

    int sum = max(1, leftMax[n - 1]); // The last element
    int curr = 1, right = 1;

    // Iterate the array from right and only consider the right neighbours for any child. Last child has no right neibhbour
    for (int i = n - 2; i >= 0; i--)
    {
        if (ratings[i] > ratings[i + 1])
            curr = right + 1;
        else
            curr = 1;
        right = curr;
        sum += max(leftMax[i], curr);
    }

    return sum;
}

// Use the 'SLOPE' concept
// TC = O(N), SC = O(1)
int best(vector<int> ratings)
{
    int n = ratings.size();
    int sum = 1; // For the first element
    int i = 1;

    while (i < n)
    {
        // The slope is flat
        if (ratings[i] == ratings[i - 1])
        {
            sum++;
            i++;
            continue;
        }

        int peak = 1;

        // There might be a increasing slope
        while (i < n && ratings[i] > ratings[i - 1])
        {
            peak++;
            i++;
            sum += peak;
        }

        int down = 0;

        // There might be a decreasing slope
        while (i < n && ratings[i] < ratings[i - 1])
        {
            down++;
            i++;
            sum += down;
        }
        down++;

        if (down > peak)
            sum += down - peak;
    }
    return sum;
}

int main()
{
    vector<int> ratings = {0, 2, 4, 3, 2, 1, 1, 3, 5, 6, 4, 0, 0};
    cout << brute(ratings) << endl;
    cout << better(ratings) << endl;
    cout << best(ratings) << endl;
    return 0;
}