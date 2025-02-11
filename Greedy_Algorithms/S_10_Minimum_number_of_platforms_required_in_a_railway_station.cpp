// We are given two arrays that represent the arrival and departure times of trains that stop at the platform. We need to find the minimum number of platforms needed at the railway station so that no train has to wait.

#include <bits/stdc++.h>
using namespace std;

// Find the maximum number of intersections
// TC = O(N*N), SC = O(1)
int brute(int n, vector<int> arr, vector<int> dep)
{
    int ans = 1; // final value
    for (int i = 0; i <= n - 1; i++)
    {
        int count = 1; // count of overlapping interval of only this iteration
        for (int j = i + 1; j <= n - 1; j++)
        {
            if ((arr[i] >= arr[j] && arr[i] <= dep[j]) ||
                (arr[j] >= arr[i] && arr[j] <= dep[i]))
            {
                count++;
            }
        }
        ans = max(ans, count); // updating the value
    }
    return ans;
}

// TC = O(2*N*log(N) + 2*N)
int best(int n, vector<int> arr, vector<int> dep)
{
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    int a = 0, d = 0, cnt = 0, platforms = 0;

    // The TC of below is not O(N). It is O(2N) because sometimes you're traversing in the first array and sometimes in the second
    while (a < n)
    {
        if (arr[a] < dep[d])
        {
            a++;
            cnt++;
        }
        else
        {
            d++;
            cnt--;
        }
        platforms = max(platforms, cnt);
    }
    return platforms;
}

int main()
{
    vector<int> arr = {900, 945, 955, 1100, 1500, 1800};
    vector<int> dep = {920, 1200, 1130, 1150, 1900, 2000};
    int n = dep.size();
    cout << brute(n, arr, dep) << endl;
    cout << best(n, arr, dep) << endl;
}
