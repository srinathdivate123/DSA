// Print all the subsequnces of the array.
// Refer pic in notes for recursion tree.
#include <bits/stdc++.h>
using namespace std;

// TC = 2^n(because for every element you have 2 choices: take/not take) * n(for printing)
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
    // TAKE : index is added to your subsequence
    subsequence.push_back(arr[index]);
    func(index + 1, subsequence, arr);
    // NOT TAKE : index is not added to your subsequence
    // When we try clothes in trial room, first we remove the cloth that we're currently wearing and then wear new cloth. Similarly, to try a different combination here, we have to remove the last added element.
    subsequence.pop_back();
    func(index + 1, subsequence, arr);
}

int main()
{
    vector<int> subsequence;
    vector<int> arr = {3, 1, 2};
    func(0, subsequence, arr);
    return 0;
}