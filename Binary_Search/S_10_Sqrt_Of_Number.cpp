// You are given a positive integer n. Your task is to find and return its square root. If n is not a perfect square, then return the floor value of sqrt(n).

// Note: The question explicitly states that if the given number, n, is not a perfect square, our objective is to find the maximum number, x, such that x squared is less than or equal to n (x*x <= n). In other words, we need to determine the floor value of the square root of n.

#include <bits/stdc++.h>
using namespace std;

int floorSqrt(int n)
{
    int low = 1, high = n;
    while (low <= high)
    {
        long long mid = (low + high) / 2;
        if (mid * mid <= n) // Eliminate left half
            low = mid + 1;
        else // Eliminate right half
            high = mid - 1;
    }
    return high;
    // The high will be the answer because the high moves from the 'not possible' part of the array to the 'possible' part of the array. The low moves from the 'possible' to the 'not possible' part of the array. The low moves from left to right and high moves from right to left. The low ends up pointing at the first place which is not possible. The high ends up pointing at the first place which is possible. So when the while loop ends, the high will be having the answer.
}

int main()
{
    int n = 28;
    cout << floorSqrt(n);
    return 0;
}
