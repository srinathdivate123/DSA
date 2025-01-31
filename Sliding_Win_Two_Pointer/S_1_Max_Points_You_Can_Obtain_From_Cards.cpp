// You can take a card from front, back or both.but they should be consecutive

#include <bits/stdc++.h>
using namespace std;

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