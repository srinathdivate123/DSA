/*
The weight of N items and their corresponding values are given. We have to put these items in a knapsack of weight W such that the total value obtained is maximized.

Note: We can either take the item as a whole or break it into smaller units.
*/

#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

bool static comp(Item a, Item b)
{
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}


// TC = O(N*log(N) + N), SC = O(1)
double fractionalKnapsack(int W, Item arr[], int n)
{
    sort(arr, arr + n, comp); // Sort by the maximum value per weight which you get (value/weight)

    double totalvalue = 0.0;

    for (int i = 0; i < n; i++)
        if (arr[i].weight <= W)
        {
            totalvalue += arr[i].value;
            W = W - arr[i].weight;
        }
        else
        {
            totalvalue += (arr[i].value / (double)arr[i].weight) * (double)W;
            break;
        }
    return totalvalue;
}

int main()
{
    int n = 3, weight = 50;
    Item arr[n] = {{100, 20}, {60, 10}, {120, 30}};
    cout << setprecision(2) << fixed << fractionalKnapsack(weight, arr, n);
}