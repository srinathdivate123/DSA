// You are given a read-only array of N integers with values also in the range [1, N] both inclusive. Each integer appears exactly once except A which appears twice and B which is missing. The task is to find the repeating and missing numbers A and B where A repeats twice and B is missing

// Better is using hashSet

#include <bits/stdc++.h>
using namespace std;

// Better  using mathematical formulae
// Sn -> Summation of n natural numbers
// S2n -> Summation of squares of n natural numbers
// x -> Repeating number
// y -> Missing number
// This is sufficient for clearing interview
vector<int> mathematical_way_optimal(vector<int> arr)
{
    // S - Sn = x - y
    long long n = arr.size();
    long long Sn = (n * (n + 1)) / 2;
    long long S2n = (n * (n + 1) * (2 * n + 1)) / 6;
    long long S = 0, S2 = 0; // Summation and summation of squares respectively
    for (int i = 0; i < n; i++)
    {
        S += arr[i];
        S2 += (long long)arr[i] * (long long)arr[i];
    }
    long long val_1 = S - Sn;   // This is x - y
    long long val_2 = S2 - S2n; // This is x^2 - y^2
    val_2 = val_2 / val_1;      // This is x + y
    long long x = (val_1 + val_2) / 2;
    long long y = x - val_1;
    return {(int)x, (int)y};
}


// This is not required in interview but it is good to tell this. 
vector<int> XOR_way_optimal(vector<int> arr)
{
    long long n = arr.size();
    int xr = 0;
    for (int i = 0; i < n; i++)
    {
        xr ^= arr[i];
        xr ^= (i + 1);
    }
    int bitNumber = 0;
    while (1)
    {
        if ((xr & (1 << bitNumber)) != 0)
            break;
        bitNumber++;
    }
    int zero = 0, one = 0;
    for (int i = 0; i < n; i++)
    {

        if ((arr[i] & (1 << bitNumber)) != 0) // Part of one's club
            one ^= arr[i];
        else
            zero ^= arr[i]; // Part of the zero's club
    }

    for (int i = 1; i <= n; i++)
    {

        if ((i & (1 << bitNumber)) != 0) // Part of one's club
            one ^= i;
        else
            zero ^= i; // Part of the zero's club
    }
    int count = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] == zero)
            count++;

    if (count == 2)
        return {zero, one};
    return {one, zero};
}

int main()
{
    vector<int> arr = {4, 3, 6, 2, 1, 1};
    vector<int> ans = mathematical_way_optimal(arr);
    cout << "Repeating: " << ans[0] << "\nMissing: " << ans[1] << endl;
    return 0;
}