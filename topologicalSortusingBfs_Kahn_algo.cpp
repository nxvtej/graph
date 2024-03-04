
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <stack>

using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define vpi vector<pair<int, int>>
// #define via vector<int> []
#define qi queue<int>
#define qp queue<pair<int, int>>
#define qpf queue<pair<pair<int, int>, int>>

#define si set<int>
#define sii set<pair<int, int>>
#define sp set<pair<int, int>>
#define svii set<vector<pair<int, int>>>

#define pb push_back
#define ff front().first
#define fff front().first.first
#define ffs front().first.second
#define fs front().second

class Solution
{
public:
    vi topoSort(int V, vvi adj)
    {
        vi indegree(V, 0);

        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }

        qi q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        vi topo;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.pb(node);

            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }
        return topo;
    }
};
int main()
{
    // Create an instance of Solution
    Solution solution;

    // Define the number of vertices
    int V = 6; // Number of vertices

    // Create an empty adjacency list
    vector<vector<int>> adj(V);

    // Add edges to the adjacency list
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[3].push_back(5);
    adj[4].push_back(5);

    // Call the topoSort function and store the result
    vector<int> result = solution.topoSort(V, adj);

    // Print the result
    for (int i : result)
    {
        cout << i << " ";
    }

    return 0;
}