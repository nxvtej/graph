
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
    bool solve(int n, vi &color, vi adj[])
    {
        color[n] = 0;
        qi q;
        q.push(n);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto neighbour : adj[node])
            {
                if (color[neighbour] == -1)
                {
                    color[neighbour] = !color[node];
                    q.push(neighbour);
                }
                else if (color[neighbour] == color[node])
                    return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(int v, vector<int> adj[])
    {
        vi color(v, -1);
        for (int i = 0; i < v; i++)
        {
            if (color[i] == -1)
            {
                if (!solve(i, color, adj))
                    return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution solution;
    vector<int> adj[] = {{}, {2}, {1, 3}, {2}};
    int V = 4, E = 2;
    cout << solution.isBipartite(V, adj);
    return 0;
}