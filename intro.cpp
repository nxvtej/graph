#include <iostream>
#include <vector>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define qi queue<int>

int main()
{
    // both matrix and adj list

    // first matrix
    // for 1 based indexing 5
    // n= total number of nodes m= total number of edges
    int n, m;
    cin >> n >> m;

    int matrix[n + 1][n + 1] = {0};
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        matrix[u][v] = 1;
        matrix[v][u] = 1;
    }

    // trying to print
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}