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
private:
    void dfs(int node, vector<int> &visited, stack<int> &st, vvi adj)
    {
        visited[node] = 1;

        for (auto neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                dfs(neighbour, visited, st, adj);
            }
        }

        st.push(node);
    }

public:
    vector<int> topoSort(int V, vvi adj)
    {
        vector<int> visited(V, 0);
        stack<int> st;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                dfs(i, visited, st, adj);
        }

        vector<int> ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};
int main()
{
    // Create an instance of Solution
    Solution solution;

    // Define the number of vertices
    int V = 6;

    // Create an adjacency list for a directed acyclic graph
    vector<vector<int>> adj(V);
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(4);
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