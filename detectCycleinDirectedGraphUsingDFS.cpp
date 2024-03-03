/*
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.


Example 1:

Input:



Output: 1
Explanation: 3 -> 3 is a cycle

Example 2:

Input:


Output: 0
Explanation: no cycle in the graph

Your task:
You dont need to read input or print anything. Your task is to complete the function isCyclic() which takes the integer V denoting the number of vertices and adjacency list adj as input parameters and returns a boolean value denoting if the given directed graph contains a cycle or not.
In the adjacency list adj, element adj[i][j] represents an edge from i to j.


Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V)
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
    /*
bool dfs(int node, vi &visited, vi &path, vvi adj){
    visited[node]=1;
    path[node]=1;

    for(auto neighbour: adj[node]){
        if(!visited[neighbour]){
            if(dfs(neighbour, visited, path, adj)) return true;
        }
        else if(path[neighbour]==1) return true;
    }

    path[node]=0;
    return false;


}



public:
    bool isCycle(int V, vvi adj){
        vi visited(V, 0);
        vi path(V, 0);

        for(int i=0;i<V;i++){
            if(!visited[i]) if(dfs(i, visited, path, adj)) return true;
        }

        return false;

    }
    */
    // now optimal with only one vector visited

private:
    static bool dfs(int node, vi &visited, vvi &adj)
    {
        visited[node] = 2;

        for (auto neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                if (dfs(neighbour, visited, adj))
                    return true;
            }
            else if (visited[neighbour] == 2)
            {
                return true;
            }
        }

        visited[node] = 1;
        return false;
    }

public:
    static bool isCycle(int V, vvi adj)
    {
        vi visited(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                if (dfs(i, visited, adj))
                    return true;
        }

        return false;
    }
};

int main()
{
    // Solution solution;
    bool (*pisCycle)(int, vvi);
    pisCycle = Solution::isCycle;
    int V = 10; // Number of vertices

    // Create an empty adjacency list
    vector<vector<int>> adj(V);

    // Add edges to the adjacency list
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(1); // This edge creates a cycle: 1 -> 2 -> 3 -> 1
    adj[2].push_back(4);
    adj[4].push_back(0);
    adj[5].push_back(6);
    adj[6].push_back(7);
    adj[7].push_back(8);
    adj[8].push_back(5); // This edge creates a cycle: 5 -> 6 -> 7 -> 8 -> 5
    adj[7].push_back(9);
    adj[9].push_back(5);

    cout << (*pisCycle)(V, adj);
    return 0;
}