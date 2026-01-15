// https://takeuforward.org/data-structure/accounts-merge-dsu-g-50
// https://leetcode.com/problems/accounts-merge/
// Striver says that this is a LC hard problem even though it is tagged as a medium

// Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

// Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

// After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

// Time Complexity: O(N+E) + O(E*4ɑ) + O(N*(ElogE + E)) where N = no. of indices or nodes and E = no. of emails. The first term is for visiting all the emails. The second term is for merging the accounts. And the third term is for sorting the emails and storing them in the answer array.

// Space Complexity: O(N)+ O(N) +O(2N) ~ O(N) where N = no. of nodes/indices. The first and second space is for the ‘mergedMail’ and the ‘ans’ array. The last term is for the parent and size array used inside the Disjoint set data structure.

#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> parent, size;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1);
        // Initialize every node
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    // Function to find ultimate parent with path compression
    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        parent[node] = findUPar(parent[node]);
        return parent[node];
    }


    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &details)
    {
        int n = details.size();

        DisjointSet ds(n);

        // Make a mapping of email -> account index (use account index instead of Name)
        unordered_map<string, int> mapMailNode;

        // Step 1: Union accounts having common emails
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < details[i].size(); j++)
            {
                string mail = details[i][j];

                if (mapMailNode.find(mail) == mapMailNode.end())
                {
                    // If it does not exist then add in map
                    mapMailNode[mail] = i;
                }
                else
                {
                    // If you find an email that already exists in map, then you need to do the union of that index to the mapMailNode[mail]
                    // i.e. connect the graph i to mapMailNode[mail] because you've found a common mail in bw them
                    ds.unionBySize(i, mapMailNode[mail]);
                    // Note that you do not add i in the map. If you do so then there will be duplicate entries in the map for the same email (although their index are different)
                    // If there is some other non-common mail for this same person which is not there in the map, then it will be merged with the parent which is taken care in the next step of grouping the emails wherein the DisJointSet will be used!
                }
            }
        }
        // The DisJointSet is now created, yay!

        // Step 2: Group emails under ultimate parent
        vector<vector<string>> mergedMail(n);
        for (auto it : mapMailNode)
        {
            string mail = it.first;
            int index = it.second;
            int ultimateParent = ds.findUPar(index);
            mergedMail[ultimateParent].push_back(mail);
        }

        // Step 3: Prepare final merged result
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++)
        {
            if (mergedMail[i].empty())
            {
                // Means this particular person has already been merged with someone else because a common email had been found
                continue;
            }

            sort(mergedMail[i].begin(), mergedMail[i].end());

            // Using temp so that we have the person's name in the first
            vector<string> temp;
            temp.push_back(details[i][0]);

            for (auto &mail : mergedMail[i])
            {
                temp.push_back(mail);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

int main()
{
    vector<vector<string>> accounts = {
        {"John", "j1@com", "j2@com", "j3@com"},
        {"John", "j4@com"},
        {"Raj", "r1@com", "r2@com"},
        {"John", "j1@com", "j5@com"},
        {"Raj", "r2@com", "r3@com"},
        {"Mary", "m1@com"}};

    Solution obj;

    vector<vector<string>> ans = obj.accountsMerge(accounts);

    for (auto &acc : ans)
    {
        cout << acc[0] << ":";
        for (int i = 1; i < acc.size(); i++)
        {
            cout << acc[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
