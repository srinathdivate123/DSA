// https://takeuforward.org/data-structure/next-greater-element-2
// https://leetcode.com/problems/next-greater-element-ii/description/

// Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

// The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Create an array to store the answer of the same size as the input array, filled with -1.
    // Iterate through each element at index i from 0 to n-1.
    // For each element, start a second loop from 1 to n-1 to check the next elements in circular order using (i + j) % n.
    // If a greater element than the current one is found during the inner loop, assign it to answer[i] and exit the inner loop.
    // After completing both loops, return the answer array containing the next greater elements.

    vector<int> brute(vector<int> arr)
    {
        int n = arr.size();
        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++)
        {
            int currEle = arr[i];

            // Nested loop to get the next greater element
            for (int j = 1; j < n; j++)
            {
                // Getting the hypothetical index (if i+j exceeds n, then it wraps around to the first index)
                // In this way, you can circularly check
                int ind = (j + i) % n;

                // If the next greater element is found
                if (arr[ind] > currEle)
                {
                    ans[i] = arr[ind];
                    // Break from the loop
                    break;
                }
            }
        }
        return ans;
    }

    // Initialize an answer array with default values of -1
    // Initialize an empty stack to keep track of elements
    // Traverse from 2n - 1 down to 0 using modulus to simulate circular indexing
    // It is as if you've duplicated n elements from 0 to n-1 after n-1
    // While stack is not empty and top of stack is less than or equal to current element, pop from stack
    // If index is in the actual array range, assign top of stack to answer if stack is not empty, else keep -1
    // Push the current element onto the stack
    // After traversal ends, return the answer array

    vector<int> optimal(vector<int> arr)
    {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        // Start traversing from the back
        for (int i = 2 * n - 1; i >= 0; i--)
        {
            // Get the actual index
            int ind = i % n;
            int currEle = arr[ind];

            // Pop the elements in the stack until the stack is not empty and the top element is not the greater element
            while (!st.empty() && st.top() <= currEle)
            {
                st.pop();
            }

            // Only if i comes in the actual array range (i.e. < n)
            if (i < n)
            {

                // If the greater element is not found, stack will be empty
                if (st.empty())
                    ans[i] = -1;
                // Else store the answer
                else
                    ans[i] = st.top();
            }

            // Push the current element in the stack maintaining the decreasing order
            st.push(currEle);
        }
        return ans;
    }
};

int main()
{
    int n = 6;
    vector<int> arr = {5, 7, 1, 7, 6, 0};
    Solution sol;
    vector<int> ans1 = sol.brute(arr);
    vector<int> ans2 = sol.optimal(arr);
    for (int i = 0; i < n; i++)
        cout << ans1[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << ans2[i] << " ";
    return 0;
}