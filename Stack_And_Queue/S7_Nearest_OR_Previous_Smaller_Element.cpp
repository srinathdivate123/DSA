// SPOILER ALERT - This problem is only available on TUF YouTube. It is neither available on LeetCode and nor on TUF website.
// GFG link for this exact problem - https://www.geeksforgeeks.org/dsa/find-the-nearest-smaller-numbers-on-left-side-in-an-array

#include <bits/stdc++.h>
using namespace std;

vector<int> prevSmaller(vector<int> &arr)
{
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        // pop elements from stack until a smaller element is found or stack becomes empty
        while (!st.empty() && st.top() >= arr[i])
        {
            st.pop();
        }

        // if stack is not empty, top is the nearest smaller element
        if (!st.empty())
        {
            result[i] = st.top();
        }
        // Lol there is no else here because the array is initialized with -1

        // push current element to stack
        st.push(arr[i]);
    }
    return result;
}

int main()
{
    vector<int> arr = {1, 5, 0, 3, 4, 5};
    vector<int> ans = prevSmaller(arr);

    for (int x : ans)
        cout << x << " ";
    return 0;
}