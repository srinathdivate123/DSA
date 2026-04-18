// https://takeuforward.org/data-structure/length-of-the-longest-subarray-with-zero-sum

#include <bits/stdc++.h>
using namespace std;

// The below is a smaller version of the code
// sum += A[i];
// if (mpp.find(sum) == mpp.end()) // if prefix_sum, doesnot exist in hashmap
//     mpp[sum] = i;               // setting it's first occurance

// int curr_size = i - mpp[sum]; //
// maxi = max(maxi, curr_size);

int main()
{
    vector<int> A = {1, -1, 3, 2, -2, -8, 1, 7, 10, 23};
    int n = A.size();
    unordered_map<int, int> mpp;
    int maxi = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += A[i];
        if (sum == 0)
        {
            maxi = max(maxi, i + 1);
        }
        int remainder = sum - 0;

        if (mpp.find(remainder) != mpp.end())
        {
            int len = i - mpp[remainder];
            maxi = max(maxi, len);
        }
        else
        {
            mpp[sum] = i;
        }
    }

    cout << maxi;
    return 0;
}