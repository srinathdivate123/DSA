/*
You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

- You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
- Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
- Once you reach a tree with fruit that cannot fit in your baskets, you must stop.

Given the integer array fruits, return the maximum number of fruits you can pick.
*/

// It is like max length of subarray with at most 2 types of numbers

#include <bits/stdc++.h>
using namespace std;

// Generate all the subarrays
// TC: O(N^2), SC: O(3)
// st.size() also takes some time, but here the max size can only be 3, hence it is as good as constant. Hence, it can be ignored

int brute(vector<int> &fruits)
{
    int maxi = 0;
    for (int i = 0; i < fruits.size(); i++)
    {
        set<int> st;
        for (int j = i; j < fruits.size(); j++)
        {
            st.insert(fruits[j]);
            if (st.size() <= 2)
            {
                maxi = max(maxi, j - i + 1);
            }
            else
                break;
        }
    }
    return maxi;
}

// TC: O(N+N), SC: O(3) --> for the map
// The map has 3 elements at max, so accessing & deleting elements take constant time
int better(vector<int> &fruits)
{
    int l = 0, r = 0, maxi = 0;
    map<int, int> mpp; // Number, frequency
    while (r < fruits.size())
    {
        mpp[fruits[r]]++;
        if (mpp.size() > 2)
        {
            while (mpp.size() > 2) // mpp can have at most 2 fruits
            {
                mpp[fruits[l]]--;
                if (mpp[fruits[l]] == 0)
                    mpp.erase(fruits[l]);
                l++;
            }
        }
        else
        {
            maxi = max(maxi, r - l + 1);
        }
        r++;
    }
    return maxi;
}

// Explanation is same as the one to the previous problem's optimal solution
int best(vector<int> &fruits)
{
    int l = 0, r = 0, maxi = 0;
    map<int, int> mpp; // Number, frequency
    while (r < fruits.size())
    {
        mpp[fruits[r]]++;
        if (mpp.size() > 2) // mpp can have at most 2 fruits
        {
            mpp[fruits[l]]--;
            if (mpp[fruits[l]] == 0)
                mpp.erase(fruits[l]);
            l++;
        }
        else
        {
            maxi = max(maxi, r - l + 1);
        }
        r++;
    }
    return maxi;
}

int main()
{
    vector<int> fruits = {1, 2, 3, 2, 2};
    cout << brute(fruits) << endl;
    cout << better(fruits) << endl;
    cout << best(fruits) << endl;
    return 0;
}