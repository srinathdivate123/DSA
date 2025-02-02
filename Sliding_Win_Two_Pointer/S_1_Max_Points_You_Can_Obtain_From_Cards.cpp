/* 
There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

You can take a card from front, back or both, but they should be consecutive
*/

#include <bits/stdc++.h>
using namespace std;

// The brute is the only solution
int brute(vector<int> &cardPoints, int k)
{
    int lsum = 0, rsum = 0, maxsum = 0;
    for (int i = 0; i < k; i++)
    {
        lsum += cardPoints[i];
    }

    maxsum = lsum;
    int rightIndex = cardPoints.size() - 1;

    for (int i = k - 1; i >= 0; i--)
    {
        lsum -= cardPoints[i];
        rsum += cardPoints[rightIndex];
        rightIndex--;
        maxsum = max(maxsum, lsum + rsum);
    }
    return maxsum;
}

int main()
{
    vector<int> cardPoints = {6, 2, 3, 4, 7, 2, 1, 7, 1};
    int k = 4;
    cout << brute(cardPoints, k);
    return 0;
}