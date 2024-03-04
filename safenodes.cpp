/*
A directed graph of V vertices and E edges is given in the form of an adjacency list adj. Each node of the graph is labelled with a distinct integer in the range 0 to V - 1.

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node.

You have to return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

Example 1:

Input:


Output:
2 4 5 6
Explanation:
The given graph is shown above.
Nodes 5 and 6 are terminal nodes as there are no
outgoing edges from either of them.
Every path starting at nodes 2, 4, 5, and 6 all
lead to either node 5 or 6.
Example 2:

Input:


Output:
3
Explanation:
Only node 3 is a terminal node, and every path
starting at node 3 leads to node 3.
Your Task:
You don't need to read or print anything. Your task is to complete the function eventualSafeNodes() which takes an integer V denoting no. of vertices and adj denoting adjacency list of the graph and returns an array of safe nodes.

Expected Time Complexity: O(V + E)

Expected Space Complexity: O(V)
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <set>

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
    static bool dfs(int node, vi &path, vi &check, vvi adj)
    {
        path[node] = 2;
        check[node] = 0;

        for (auto neighbour : adj[node])
        {
            if (!path[neighbour])
            {
                if (dfs(neighbour, path, check, adj))
                {
                    check[node] = 0;
                    return true;
                }
            }
            else if (path[neighbour] == 2)
            {
                check[node] = 0;
                return true;
            }
        }

        path[node] = 1;
        check[node] = 1;
        return false;
    }

public:
    static vi safenodes(int V, vvi adj)
    {
        vi path(V, 0);
        vi check(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!path[i])
            {
                dfs(i, path, check, adj);
            }
        }

        vi ans;

        for (int i = 0; i < V; i++)
        {
            if (check[i])
                ans.pb(i);
        }

        return ans;
    }
};
int main()
{
    // Solution solution;
    vi (*pisCycle)(int, vvi);
    pisCycle = Solution::safenodes;

    int V = 5; // Number of vertices

    // Create an empty adjacency list
    vector<vector<int>> adj(V);

    // Add edges to the adjacency list
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(4);

    vi ans = (*pisCycle)(V, adj);
    for (auto in : ans)
    {
        cout << in << " ";
    }
    return 0;
}