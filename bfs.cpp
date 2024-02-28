#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define vi vector<int>
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

vi solveBfs(int n, vvi &adj)
{
    vi bfs;

    // queue, visited
    qi q;
    vi visited(n + 1, 0);

    visited[1] = 1;
    q.push(1);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        bfs.pb(node);

        for (auto neighbour : adj[node])
        {
            if (visited[neighbour] != 1)
            {
                visited[neighbour] = 1;
                q.push(neighbour);
            }
        }
    }
    return bfs;
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

    vi (*pbfs)(int, vvi &);
    pbfs = &solveBfs;

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
        vi bfs = (*pbfs)(n, adj);

        // printing values of bfs;
        (*pprint)(bfs);
    }
    return 0;
}