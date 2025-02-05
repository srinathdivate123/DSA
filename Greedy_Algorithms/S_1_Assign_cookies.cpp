/* Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.

Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.
*/

#include <bits/stdc++.h>
using namespace std;

// TC = (n*log(n) + m*log(m) + m)
int brute(vector<int> &g, vector<int> &s)
{
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int gPtr = 0, sPtr = 0;

    while (sPtr < s.size() && gPtr < g.size())
    {
        if (g[gPtr] <= s[sPtr])
            gPtr++;
        sPtr++;
    }
    return gPtr;
}

int main()
{
    vector <int> g = {1,5,3,3,4}, s = {4,2,1,2,1,3};
    cout << brute(g, s); 
    return 0;
}