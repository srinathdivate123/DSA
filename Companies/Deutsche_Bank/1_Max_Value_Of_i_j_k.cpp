// Given an array find maximum value of a[i]+(a[j]*a[k]) such that i<j<k and a[i]<a[j]<a[k] are satisfied.
#include <bits/stdc++.h>
using namespace std;

int find_maximum_sum(vector<int> &arr)
{
    int n = arr.size();
    int max_sum = INT_MIN;
    int max_j_product = INT_MIN;
    int max_k = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        max_j_product = max(max_j_product, arr[i + 1] * max_k);
        max_k = max(max_k, arr[i + 1]);
        for (int j = i + 1; j < n; j++)
            if (arr[i] < arr[j])
                max_sum = max(max_sum, arr[i] + (arr[j] * max_k));
    }
    return max_sum;
}

int find_maximum_sum1(vector<int> &arr)
{
    int n = arr.size();
    if (n < 3)
        return 0; // If there are less than 3 elements, the condition is not satisfied.
    vector<int> max_product_to_right(n);
    vector<int> max_sum_to_right(n);

    max_product_to_right[n - 1] = arr[n - 1];
    max_sum_to_right[n - 1] = 0;

    for (int i = n - 2; i >= 0; i--)
    {
        max_product_to_right[i] = max(max_product_to_right[i + 1], arr[i + 1]);
        max_sum_to_right[i] = max(max_sum_to_right[i + 1], arr[i + 1] + max_product_to_right[i]);
    }
    int max_sum = 0;
    for (int i = 0; i < n - 2; i++)
        if (arr[i] < arr[i + 1])
        {
            int current_sum = arr[i] + arr[i + 1] * max_product_to_right[i];
            max_sum = max(max_sum, current_sum + max_sum_to_right[i + 1]);
        }
    return max_sum;
}

int answer(vector<int> &arr)
{
    int n = arr.size();
    int i, j, k = n - 1;
    for (int it = n - 2; it > 0; it++)
    {
        if (arr[it] > k)
            k = it;
    }
}
int main()
{
    vector<int> arr = {3, 1, 4, 5, 9, 10, 8, 6};
    cout << find_maximum_sum(arr) << endl;  // Output will be 93 (5 + (9 * 10) = 93)
    cout << find_maximum_sum1(arr) << endl; // Output will be 93 (5 + (9 * 10) = 93)
    return 0;
}