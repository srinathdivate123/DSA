// Given an array of N integers, your task is to find "unique" triplets that add up to give a sum of zero. In short, you need to return an array of all the unique triplets [arr[a], arr[b], arr[c]] such that i!=j, j!=k, k!=i, and their sum is equal to zero.

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> brute(int n, vector<int> &arr)
{
    set<vector<int>> st;

    // check all possible triplets:
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            for (int k = j + 1; k < n; k++)
                if (arr[i] + arr[j] + arr[k] == 0)
                {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }

    // store the set elements in the answer:
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// We need : arr[k] + arr[i] + arr[j] = 0
// => arr[k] = - (arr[i] + arr[j])
vector<vector<int>> better(int n, vector<int> &arr)
{
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        set<int> hashset;
        for (int j = i + 1; j < n; j++)
        {
            // Calculate the 3rd element:
            int third = -(arr[i] + arr[j]);

            // Find the element in the set:
            if (hashset.find(third) != hashset.end())
            {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }

    // store the set in the answer:
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}


// TC of n*log(n) for sorting and near about n*2 for the while loop
vector<vector<int>> best(int n, vector<int> &num)
{
    vector<vector<int>> ans;
    sort(num.begin(), num.end());
    for (int i = 0; i < n; i++)
    {
        // Avoid the duplicates while moving i:
        if (i > 0 && num[i] == num[i - 1])
            continue;
        int j = i + 1; // Assuming j = i + 1
        int k = n - 1; // Assuming k = n - 1
        while (j < k)
        {
            int sum = num[i] + num[j] + num[k];
            if (sum < 0)
                j++;
            else if (sum > 0)
                k--;
            else // sum == 0, which is what we wanted.
            {
                vector<int> temp = {num[i], num[j], num[k]};
                ans.push_back(temp);
                j++, k--;
                while (j < k && num[j] == num[j - 1]) // Avoid duplicates so we do this
                    j++;
                while (j < k && num[k] == num[k + 1]) // Avoid duplicates so we do this
                    k--;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    int n = arr.size();
    vector<vector<int>> ans = best(n, arr);
    for (auto it : ans)
    {
        cout << "[";
        for (auto i : it)
            cout << i << " ";
        cout << "] ";
    }
    cout << "\n";
    return 0;
    return 0;
}