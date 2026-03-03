#include <bits/stdc++.h>
using namespace std;

// This prints all the subsequences which sum up to sum.
void func1(int index, vector<int> &elements, vector<int> &arr, int sum, int target_sum)
{
    if (index == arr.size())
    {
        if (sum == target_sum)
        {
            for (int element : elements)
                cout << element << " ";
            cout << endl;
        }
        return;
    }
    // TAKE the element
    elements.emplace_back(arr[index]);
    sum += arr[index];
    func1(index + 1, elements, arr, sum, target_sum);
    // NOT-TAKE the element
    elements.pop_back();
    sum -= arr[index];
    func1(index + 1, elements, arr, sum, target_sum);
}

// This prints only 1 subsequence (the first one which it encounters) which sums up to sum.
bool func2(int index, vector<int> &elements, vector<int> &arr, int sum, int target_sum)
{
    if (index == arr.size())
    {
        if (sum == target_sum) // Condition satisfied
        {
            for (int element : elements)
                cout << element << " ";
            return true; // Avoiding future recursion calls
        }
        return false;
    }
    elements.emplace_back(arr[index]);
    sum += arr[index];
    if (func2(index + 1, elements, arr, sum, target_sum) == true)
        return true; // Avoiding future recursion calls
    elements.pop_back();
    sum -= arr[index];
    if (func2(index + 1, elements, arr, sum, target_sum) == true)
        return true; // Avoiding future recursion calls
    return false;
}

// This prints no of subsequences which sums up to sum.
int func3(int index, vector<int> &arr, int sum, int target_sum)
{
    if (index == arr.size())
    {
        if (sum == target_sum)
            return 1;
        return 0;
    }
    sum += arr[index];
    int left = func3(index + 1, arr, sum, target_sum);
    sum -= arr[index];
    int right = func3(index + 1, arr, sum, target_sum);
    return left + right;
}

int main()
{
    vector<int> arr = {1, 2, 1};
    vector<int> elements;
    int target_sum = 2;
    // func1(0, elements, arr, 0, target_sum);
    // func2(0, elements, arr, 0, target_sum);
    cout << func3(0, arr, 0, target_sum);
    return 0;
}