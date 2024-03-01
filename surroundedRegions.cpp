#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
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
    static void bfs(int row, int col, vvi &visited, vvc &mat, int delrow[], int delcol[])
    {
        // first step mark them visited
        visited[row][col] = 1;
        int n = mat.size();
        int m = mat[0].size();

        // start traversing ofr the 4 neighbours
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if (nrow < n && nrow >= 0 && ncol < m && ncol >= 0 && !visited[nrow][ncol] && mat[nrow][ncol] == 'O')
            {
                bfs(nrow, ncol, visited, mat, delrow, delcol);
            }
        }
    }

public:
    static vvc regionProblem(int n, int m, vvc &mat)
    {
        // storing del values
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        // somthiugn to store visited;
        vvi visited(n, vi(m, 0));

        // traversing all the boundries
        for (int i = 0; i < m; i++)
        { // for rows

            // frist row done
            if (mat[i][0] == 'O' && !visited[i][0])
            {
                bfs(i, 0, visited, mat, delrow, delcol);
            }

            // last row
            if (mat[i][m - 1] && !visited[i][m - 1])
            {
                bfs(i, m - 1, visited, mat, delrow, delcol);
            }
        }

        // for col
        for (int i = 0; i < n; i++)
        {
            // for first col
            if (mat[0][i] == 'O' && !visited[0][i])
            {
                bfs(0, i, visited, mat, delrow, delcol);
            }

            // for last col
            if (mat[n - 1][i] == 'O' && !visited[n - 1][i])
            {
                bfs(n - 1, i, visited, mat, delrow, delcol);
            }
        }

        return mat;
    }
};
int main()
{
    int n = 5, m = 4;
    vvc mat = {{'X', 'X', 'X', 'X'},
               {'X', 'O', 'X', 'X'},
               {'X', 'O', 'O', 'X'},
               {'X', 'O', 'X', 'X'},
               {'X', 'X', 'O', 'O'}};

    vvc (*pregionProblem)(int, int, vvc &);
    pregionProblem = Solution::regionProblem;
    vvc output = (*pregionProblem)(n, m, mat);
    for (auto it : output)
    {
        for (auto neighbour : it)
        {
            cout << "'" << neighbour << "' ";
        }
        cout << "\n";
    }
    return 0;
}