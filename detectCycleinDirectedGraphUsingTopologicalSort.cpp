
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
    int topoSort(int v, vvi adj)
    {
        vi indegree(v, 0);
        for (int i = 0; i < v; i++)
        {
            for (auto it : adj[i])
                indegree[it]++;
        }

        qi q;
        for (int i = 0; i < v; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }
        int cnt = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cnt++;
            for (auto neighbour : adj[node])
            {
                indegree[neighbour]--;
                if (indegree[neighbour] == 0)
                    q.push(neighbour);
            }
        }

        if (cnt == v)
            return false;
        return true;
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
    cout << solution.topoSort(V, adj);

    // // Print the result
    // for (int i : result)
    // {
    //     cout << i << " ";
    // }

    return 0;
}