#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define pb push_back
#define qi queue<int>

vvi createAdj(int n, int m)
{
    vvi adj(n + 1); // for 1 based indexing
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        adj[a].pb(b);
        adj[b].pb(a);
    }
    return adj;
}

void dfs(int node, vb &visited, vvi &adj, vi &result)
{

    visited[node] = true;
    result.pb(node);

    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            dfs(it, visited, adj, result);
        }
    }
    return;
}

vi solveDfs(int n, vvi &adj)
{
    // for this we need stack
    // new day
    // will solve this using recursion first then might give try to stack
    vb visited(n + 1, false);
    vi result;

    dfs(1, visited, adj, result);

    return result;
}

void printVector(vi &output)
{
    for (auto it : output)
    {
        cout << it << " ";
    }
    cout << "\ncode ends here!";
}
int main()
{
    int testCase;
    cin >> testCase;

    vvi (*pcreateAdj)(int, int);
    pcreateAdj = &createAdj;

    vi (*pdfs)(int, vvi &);
    pdfs = &solveDfs;

    void (*pprint)(vi &);
    pprint = &printVector;

    while (testCase--)
    {
        // taking input for number of nodes and edges;
        int n, m;
        cin >> n >> m;

        // creating adj list
        vvi adj = (*pcreateAdj)(n, m);

        // now lets solve this code
        vi dfs = (*pdfs)(n, adj);

        // printing values of bfs;
        (*pprint)(dfs);
    }
    return 0;
}