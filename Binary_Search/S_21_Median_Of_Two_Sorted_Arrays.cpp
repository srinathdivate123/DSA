// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays. They mabye of different sizes.
// The overall run time complexity should be O(log (m+n))

#include <bits/stdc++.h>
using namespace std;

// Merge two arrays and then find median
double brute(vector<int> &a, vector<int> &b)
{
    int n1 = a.size(), n2 = b.size();

    vector<int> arr3;
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
            arr3.push_back(a[i++]);
        else
            arr3.push_back(b[j++]);
    }

    // copy the left-out elements:
    while (i < n1)
        arr3.push_back(a[i++]);
    while (j < n2)
        arr3.push_back(b[j++]);

    // Find the median:
    int n = n1 + n2;
    if (n % 2 == 1)
    {
        return (double)arr3[n / 2];
    }

    double median = ((double)arr3[n / 2] + (double)arr3[(n / 2) - 1]) / 2.0;
    return median;
}

double better(vector<int> &a, vector<int> &b)
{
    int n1 = a.size(), n2 = b.size();
    int n = n1 + n2;

    // required indices:
    int ind2 = n / 2;
    int ind1 = ind2 - 1;
    int cnt = 0;
    int ind1el = -1, ind2el = -1;

    // apply the merge step:
    // you can also add the optimization that once you find ind1el and ind2el, you can break out
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            if (cnt == ind1)
                ind1el = a[i];
            if (cnt == ind2)
                ind2el = a[i];
            cnt++;
            i++;
        }
        else
        {
            if (cnt == ind1)
                ind1el = b[j];
            if (cnt == ind2)
                ind2el = b[j];
            cnt++;
            j++;
        }
    }

    // copy the left-out elements:
    while (i < n1)
    {
        if (cnt == ind1)
            ind1el = a[i];
        if (cnt == ind2)
            ind2el = a[i];
        cnt++;
        i++;
    }
    while (j < n2)
    {
        if (cnt == ind1)
            ind1el = b[j];
        if (cnt == ind2)
            ind2el = b[j];
        cnt++;
        j++;
    }

    // Find the median:
    if (n % 2 == 1)
    {
        return (double)ind2el;
    }

    return (double)((double)(ind1el + ind2el)) / 2.0;
}

// Best using Binary Search
double best(vector<int> &a, vector<int> &b)
{
    int n1 = a.size(), n2 = b.size();
    // if n1 is bigger swap the arrays, because we want to do BS on the smaller array to reduce time
    if (n1 > n2)
        return best(b, a);

    int n = n1 + n2;                     // total length
    int lenLeftHalf = (n1 + n2 + 1) / 2; // length of left half

    // apply binary search:
    int low = 0, high = n1;
    while (low <= high)
    {
        int mid1 = (low + high) >> 1; // Dividing by 1
        int mid2 = lenLeftHalf - mid1;
        // calculate l1, l2, r1 and r2;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if (mid1 < n1)
            r1 = a[mid1];
        if (mid2 < n2)
            r2 = b[mid2];
        if (mid1 - 1 >= 0)
            l1 = a[mid1 - 1];
        if (mid2 - 1 >= 0)
            l2 = b[mid2 - 1];

        if (l1 <= r2 && l2 <= r1)
        {
            if (n % 2 == 1)
                return max(l1, l2);
            return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
        }

        // eliminate the halves:
        else if (l1 > r2)
            high = mid1 - 1;
        else
            low = mid1 + 1;
    }
}

int main()
{
    vector<int> a = {1, 4, 7, 10, 12};
    vector<int> b = {2, 3, 6, 15};
    cout << fixed << setprecision(1) << brute(a, b) << endl;
    cout << fixed << setprecision(1) << better(a, b) << endl;
    cout << fixed << setprecision(1) << best(a, b) << endl;
}
