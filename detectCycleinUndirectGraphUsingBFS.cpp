#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define vi vector<int>
#define qp queue<pair<int, int>>
#define pb push_back

class Solution
{
private:
    static bool detect(int src, vector<int> adj[], vector<int> visited)
    {
        // marking visited
        visited[src] = 1;

        qp q;
        q.push({src, -1});

        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;

            q.pop();
            for (auto neighbour : adj[node])
            {
                if (!visited[neighbour])
                {
                    visited[neighbour] = 1;
                    q.push({neighbour, node});
                }
                else
                {
                    if (parent != neighbour)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }

public:
    static bool iscyclic(int V, vector<int> adj[])
    {
        vi visited(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (detect(i, adj, visited))
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    bool (*piscyclic)(int, vector<int>[]);
    piscyclic = Solution::iscyclic;

    vi adj[] = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}};
    int V = 5, E = 5;
    cout << (*piscyclic)(V, adj);
}