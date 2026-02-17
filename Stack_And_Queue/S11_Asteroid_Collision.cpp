// https://takeuforward.org/data-structure/asteroid-collision
// https://leetcode.com/problems/asteroid-collision/editorial

// We are given an array asteroids of integers representing asteroids in a row. The indices of the asteroid in the array represent their relative position in space.
// For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.
// Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        int n = asteroids.size();
        vector<int> st; // Declare it as vector so yo can return the answer in proper order

        for (int i = 0; i < n; i++)
        {
            // Push the asteroid in stack if a right moving asteroid is seen (+ve number)
            if (asteroids[i] > 0)
                st.push_back(asteroids[i]);

            // Else if the asteroid is moving left (-ve), perform the collisions
            else
            {
                // Until the right moving asteroids in stack are smaller in size than left moving asteriods in array, keep on destroying them
                while (!st.empty() && st.back() > 0 && st.back() < abs(asteroids[i]))
                {
                    st.pop_back();
                }

                // If there is right moving asteroid (-ve) in array which is of same size
                if (!st.empty() && st.back() == abs(asteroids[i]))
                {
                    // Destroy both the asteroids
                    st.pop_back();
                    // Do not push asteriods[i] into array
                }

                // If the stack is empty or already has a -ve element on top, then push the current -ve element to stack
                // This is the only scenerio where you will store the negative element
                else if (st.empty() || st.back() < 0)
                {
                    st.push_back(asteroids[i]);
                }
            }
        }
        return st;
    }
};

int main()
{
    vector<int> arr = {10, 20, -10};
    Solution sol;
    vector<int> ans = sol.asteroidCollision(arr);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}