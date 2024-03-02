
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
    bool solve(int node, int col, vi &color, vi adj[])
    {
        color[node] = col;

        for (auto it : adj[node])
        {
            if (color[it] == -1)
            {
                if (!solve(it, !col, color, adj))
                    return false;
            }
            else if (color[it] == col)
                return false;
        }

        return true;
    }

public:
    bool isBipartite(int V, vi adj[])
    {
        vi color(V, -1);

        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                if (!solve(i, 0, color, adj))
                    return false;
            }
        }
        return true;
    }
};
int main()
{
    Solution solution;
    vector<int> adj[] = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    int V = 4, E = 2;
    cout << (solution.isBipartite(V, adj));
    return 0;
}