#include <iostream>
#include <vector>

using namespace std;

class Solution
{

public:
    static void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited)
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

    static int numProvinces(vector<vector<int>> adj, int V)
    {
        // trying with adj matrix
        vector<bool> visited(V, false);
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
    vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};

    int (*pProvinces)(vector<vector<int>>, int);
    pProvinces = Solution::numProvinces;
    int numberofComponents = (*pProvinces)(isConnected, 3);
    cout << numberofComponents;
    return 0;
}