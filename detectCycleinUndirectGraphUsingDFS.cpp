#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
// #define via vector<int> []
#define qi queue<int>
#define qp queue<pair<int, int>>
#define qpf queue<pair<pair<int, int>, int>>

#define pb push_back
#define ff front().first
#define fff front().first.first
#define ffs front().first.second
#define fs front().second

class Solution
{
private:
    bool solve(int node, int parent, vi &visited, vi adj[])
    {
        // cout<<"inside solve"<<"\n";
        visited[node] = 1;

        for (auto neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                if (solve(neighbour, node, visited, adj))
                    return true;
            }

            else if (parent != neighbour)
                return true;
        }

        return false;
    }

public:
    int isCycle(int V, vi adj[])
    {
        vi visited(V, 0);
        // cout<<"inside iscylic "<<solve(0,0,visited,adj)<<"\n";
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (solve(i, -1, visited, adj))
                    return true;
            }
        }

        return false;
    }
};
int main()
{
    Solution solution;
    vector<int> adj[] = {{}, {2}, {1, 3}, {2}};
    int V = 4, E = 2;
    cout << solution.isCycle(V, adj);
    return 0;
}