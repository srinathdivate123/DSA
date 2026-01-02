// https://takeuforward.org/data-structure/dijkstras-algorithm-using-set-g-33

// TC: O(E log V), as each edge leads to at most one insertion in the priority queue, which takes log V time.

// SC: O(V + E), due to the distance array and adjacency list storing all vertices and edges.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // set stores the nodes in ascending order of the distances.
        set<pair<int, int>> st; // {dist, node}
        st.insert({0, S});      // Source is at distance 0

        vector<int> dist(V, 1e9);
        dist[S] = 0;

        while (!st.empty())
        {
            // Extract the node with the minimum distance which is on the top
            auto it = *(st.begin());
            int node = it.second;
            int dis = it.first;
            st.erase(it);

            // Check for all adjacent nodes of the extracted node
            for (auto it : adj[node])
            {
                int adjNode = it[0];
                int edgWeight = it[1];

                // If the new distance is smaller, update it
                if (dis + edgWeight < dist[adjNode])
                {
                    // Erase the previous entry of the adjacent node
                    // if it was visited previously with a larger cost.
                    if (dist[adjNode] != 1e9) // If it's not equal to 1e9 then someone had reached it earlier
                    {
                        st.erase({dist[adjNode], adjNode});
                    }

                    // Update the distance for the adjacent node
                    dist[adjNode] = dis + edgWeight;

                    // Insert the adjacent node with the updated distance into the set
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};

int main()
{
    int V = 3, E = 3, S = 2; // Number of vertices, edges, and source vertex
    vector<vector<int>> adj[3];

    // Example graph with edges and weights
    vector<int> v1{1, 1}, v2{2, 6}, v3{2, 3}, v4{0, 1}, v5{1, 3}, v6{0, 6};
    adj[0].push_back(v1);
    adj[0].push_back(v2);
    adj[1].push_back(v3);
    adj[1].push_back(v4);
    adj[2].push_back(v5);
    adj[2].push_back(v6);

    Solution obj;
    vector<int> res = obj.dijkstra(V, adj, S);

    for (int i = 0; i < V; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
