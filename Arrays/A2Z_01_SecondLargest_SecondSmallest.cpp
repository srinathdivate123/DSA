// Brute: sort the array and then find the answer.
// Better: in first for loop find the largest and in the second for loop find the second largest
// Best is below!

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {3, 4, 6, 2, 8, 67, 65};
    int n = arr.size();
    int largest = arr[0], slargest = INT_MIN; // We put INT_MIN so that our code will be fool proof if the array has negative numbers also.
    int smallest = arr[0], ssmallest = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            slargest = largest;
            largest = arr[i];
        }
        else if (arr[i] < largest && arr[i] > slargest)
            slargest = arr[i];

        if (arr[i] < smallest)
        {
            ssmallest = smallest;
            smallest = arr[i];
        }
        else if (arr[i] > smallest && arr[i] < ssmallest)
            ssmallest = arr[i];
    }

    cout << " Smallest - " << smallest << endl;
    cout << " Second smallest - " << ssmallest << endl
         << endl;
    cout << " Second largest - " << slargest << endl;
    cout << " Largest - " << largest << endl;
    return 0;
}