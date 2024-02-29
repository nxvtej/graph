#include <iostream>
#include <vector>

#define vi vector<int>
#define vb vector<bool>
#define pb push_back
#define qi queue<int>
#define vvi vector<vector<int>>

using namespace std;

class Solution
{

public:
    static void dfs(int node, vvi &adj, vb &visited)
    {
        visited[node] = true;
        for (int i = 0; i < adj.size(); i++)
        {
            if (adj[node][i] == 1 && !visited[i])
            {
                dfs(i, adj, visited);
            }
        }
    }

    static int numProvinces(vvi adj, int V)
    {
        // trying with adj matrix
        vb visited(V, false);
        int count = 0;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                count++;
                dfs(i, adj, visited);
            }
        }
        return count;
    }
};

int main()
{
    Solution solution;
    vvi isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};

    int (*pProvinces)(vvi, int);
    pProvinces = Solution::numProvinces;
    int numberofComponents = (*pProvinces)(isConnected, 3);
    cout << numberofComponents;
    return 0;
}