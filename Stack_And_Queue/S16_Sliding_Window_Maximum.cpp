// https://takeuforward.org/data-structure/sliding-window-maximum
// https://leetcode.com/problems/sliding-window-maximum

// You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
// Return the max sliding window.

// Brute is to loop through every K consecutive elements

// OPTIMAL:
// Sliding window problems often lead to repeated work when recalculating the maximum in each window. To identify inefficiencies, consider this: if we move from the window [1,2,3] to [2,3,2], we recalculate the max even though the outgoing element (1) wasn't the maximum.

// The real concern is only when the outgoing element was the maximum. To optimize, we use a double-ended queue (deque) to maintain elements in a way that always keeps track of the current maximum efficiently. When a new element enters, we push it to the back of the deque, but before that, we remove all smaller elements from the back since they're not useful anymore. Also, if the element at the front is outside the window's range, we remove it. This ensures that the element at the front of the deque always represents the maximum of the current window.

// --> Initialize an empty deque and a result list
// --> Loop through the array from start to end
// --> Remove front of deque if it's outside the current window
// --> Remove all elements smaller than the current one from the back of the deque
// --> Insert the current index at the back of the deque
// --> If the window has at least k elements, append the front element's value to the result
// --> Return the result list

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> dq;
        vector<int> result;

        // Loop through each element in the array
        for (int i = 0; i < nums.size(); i++)
        {
            // Remove elements from the front if they are out of this window's leftmost range
            if (!dq.empty() && dq.front() <= i - k)
            {
                dq.pop_front();
            }

            // Remove all elements from the back that are smaller than current incoming element
            while (!dq.empty() && nums[dq.back()] < nums[i])
            {
                dq.pop_back();
            }

            // Add the current index to the deque
            dq.push_back(i);

            // Only once the first window is completed, add front element to result
            // The below check prevents any element from being inserted into the answer if the first window has not yet been formed
            if (i >= k - 1)
            {
                result.push_back(nums[dq.front()]);
            }
        }
        return result;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {4, 0, -1, 3, 5, 3, 6, 8};
    int k = 3;
    vector<int> ans = obj.maxSlidingWindow(arr, k);
    for (int num : ans)
    {
        cout << num << " ";
    }
    return 0;
}
