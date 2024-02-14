// https://youtu.be/g5mmW0GOTx8

// We can solve using priority queue also.
// Maintain min heap of size k.
// Remove the top element and push new element if sixe exceeds k.
// Return heap.top()

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k = 4;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto x : nums)
    {
        pq.push(x);
        if(pq.size() > k)
            pq.pop();
    }
    cout << pq.top();
    return 0;
}