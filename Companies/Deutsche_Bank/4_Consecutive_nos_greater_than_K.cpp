// Given an array consisting of N non-negative integers. You have to find sum of consecutive numbers that was greater than or equal to the K.
#include <bits/stdc++.h>
using namespace std;

int find_sum_consecutive_greater_than_k(vector<int> &arr, int K)
{
    int left = 0;
    int current_sum = 0;
    int total_sum = 0;

    for (int right = 0; right < arr.size(); right++)
    {
        current_sum += arr[right];

        while (current_sum >= K)
        {
            total_sum += (arr.size() - right);
            current_sum -= arr[left];
            left++;
        }
    }

    return total_sum;
}

int main()
{
    vector<int> arr = {1, 3, 4, 2, 5, 8};
    int K = 7;
    int result = find_sum_consecutive_greater_than_k(arr, K);
    cout << "Sum of consecutive numbers greater than or equal to " << K << ": " << result << endl;

    return 0;
}
