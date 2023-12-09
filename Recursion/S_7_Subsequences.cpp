// Print all the subsequnces of the array.
// Refer pic in notes for recursion tree.
#include <bits/stdc++.h>
using namespace std;

// TC = 2^n(because for every element you have 2 choices: take/not take) * n(fro printing)
// SC = n (for auxiliary stack space, becasue the depth of the tree will be n and at max only n recursion calls will be waiting in the stack space)
void func(int index, vector<int> &subsequence, vector<int> &arr)
{
    if (index == arr.size())
    {
        for (int element : subsequence)
            cout << element << " ";
        if (subsequence.size() == 0)
            cout << "{}";
        cout << endl;
        return;
    }
    // This element is added to your subsequence
    subsequence.push_back(arr[index]);
    func(index + 1, subsequence, arr);
    subsequence.pop_back();
    // This element is not added to your subsequence
    func(index + 1, subsequence, arr);
}

int main()
{
    vector<int> subsequence;
    vector<int> arr = {3, 1, 2};
    func(0, subsequence, arr);
    return 0;
}