// Given an array of N integers. Find the elements that appear more than floor(N/3) times in the array. If no such element exists, return an empty vector

// At max there can be floor(N/3) such integers that appear more than floor(N/3) times in an array.

// AT minimum there can be 0 such integers.
// Done until here!!
#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> v)
{

    int cnt1 = 0, cnt2 = 0; // counts
    int element_1 = INT_MIN;      // element 1
    int element_2 = INT_MIN;      // element 2

    // applying the Extended Boyer Moore's Voting Algorithm:
    for (int i = 0; i < v.size(); i++)
        if (cnt1 == 0 && element_2 != v[i])
        {
            cnt1 = 1;
            element_1 = v[i];
        }
        else if (cnt2 == 0 && element_1 != v[i])
        {
            cnt2 = 1;
            element_2 = v[i];
        }
        else if (v[i] == element_1)
            cnt1++;
        else if (v[i] == element_2)
            cnt2++;
        else
            cnt1--, cnt2--;

    vector<int> ans;

    // Manually check if the stored elements in element_1 and element_2 are the majority elements:
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == element_1)
            cnt1++;
        if (v[i] == element_2)
            cnt2++;
    }

    int mini = int(v.size() / 3) + 1;
    if (cnt1 >= mini)
        ans.push_back(element_1);
    if (cnt2 >= mini)
        ans.push_back(element_2);
    return ans;
}
int main()
{
    vector<int> arr = {1, 1, 1, 1, 3, 2, 2, 2};
    vector<int> ans = majorityElement(arr);
    cout << "The majority elements are: ";
    for (auto it : ans)
        cout << it << " ";
    return 0;
}