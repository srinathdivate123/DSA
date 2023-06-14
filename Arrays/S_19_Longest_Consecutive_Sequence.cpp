#include <bits/stdc++.h>
using namespace std;
// This was asked in google interviews!!!
// You are given an array of ‘N’ integers. You need to find the length of the longest sequence which contains the consecutive elements. The elements may be picked up from array in any order. But they must be consecutive and sorted in the answer array!

// Take each element and find if the next consecutive element is in array and if yes then increase the counter
void brute() {}

// Sort the array and then find the consecutive sequence by using longestSequence, CurrentSequenceCount and lastSmaller variables.
void better() {}

// Put everthing into set
// Tc = N (for putting elements into set assuming there are no collisions) + N (iterations of the for loop) + N (The total no of iterations that you would make in the while loop at worst case)
// So TC = 3N
// SC = 
void best(vector<int> &arr, int n)
{
    int longest = 1;
    unordered_set<int> st;
    for (int it : arr)
        st.insert(it);

    for (auto element : st)
    {
        if (st.find(element - 1) == st.end()) // We check if the element-1 exists in the set. If it exists, we don't need to start the current sequence from 'element' onwards. So we can move to the next element. But if element-1 doesn't exist then we can start the current sequence from element onwards
        // It is O(1) time complexity for searching an element in an unordered set 
        {
            int cnt=1;
            int x = element;
            while(st.find(x+1)!=st.end())
            {
                x++;
                cnt++;
            }
            longest=max(longest, cnt);
        }
    }
    cout << longest;
}

int main()
{
    vector<int> arr = {102, 4, 100, 1, 101, 3, 2, 1, 1};
    best(arr, arr.size());
    return 0;
}